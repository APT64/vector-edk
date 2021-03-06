/** @file
The module to produce Usb Bus PPI.

Copyright (c) 2006 - 2014, Intel Corporation. All rights reserved.<BR>
  
This program and the accompanying materials
are licensed and made available under the terms and conditions
of the BSD License which accompanies this distribution.  The
full text of the license may be found at
http://opensource.org/licenses/bsd-license.php

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include "UsbPeim.h"
#include "HubPeim.h"
#include "PeiUsbLib.h"

//
// UsbIo PPI interface function
//
PEI_USB_IO_PPI         mUsbIoPpi = {
  PeiUsbControlTransfer,
  PeiUsbBulkTransfer,
  PeiUsbGetInterfaceDescriptor,
  PeiUsbGetEndpointDescriptor,
  PeiUsbPortReset
};

EFI_PEI_PPI_DESCRIPTOR mUsbIoPpiList = {
  (EFI_PEI_PPI_DESCRIPTOR_PPI | EFI_PEI_PPI_DESCRIPTOR_TERMINATE_LIST),
  &gPeiUsbIoPpiGuid,
  NULL
};

/**
  The enumeration routine to detect device change.
  
  @param  PeiServices            Describes the list of possible PEI Services.
  @param  UsbHcPpi               The pointer of PEI_USB_HOST_CONTROLLER_PPI instance.
  @param  Usb2HcPpi              The pointer of PEI_USB2_HOST_CONTROLLER_PPI instance.

  @retval EFI_SUCCESS            The usb is enumerated successfully.
  @retval EFI_OUT_OF_RESOURCES   Can't allocate memory resource.
  @retval Others                 Other failure occurs.

**/
EFI_STATUS
PeiUsbEnumeration (
  IN EFI_PEI_SERVICES               **PeiServices,
  IN PEI_USB_HOST_CONTROLLER_PPI    *UsbHcPpi,
  IN PEI_USB2_HOST_CONTROLLER_PPI    *Usb2HcPpi
  );

/**
  Configure new detected usb device.
  
  @param  PeiServices            Describes the list of possible PEI Services.
  @param  PeiUsbDevice           The pointer of PEI_USB_DEVICE instance.
  @param  Port                   The port to be configured.
  @param  DeviceAddress          The device address to be configured.

  @retval EFI_SUCCESS            The new detected usb device is configured successfully.
  @retval EFI_OUT_OF_RESOURCES   Can't allocate memory resource.
  @retval Others                 Other failure occurs.

**/
EFI_STATUS
PeiConfigureUsbDevice (
  IN     EFI_PEI_SERVICES    **PeiServices,
  IN     PEI_USB_DEVICE      *PeiUsbDevice,
  IN     UINT8               Port,
  IN OUT UINT8               *DeviceAddress
  );

/**
  Get all configurations from a detected usb device.
  
  @param  PeiServices            Describes the list of possible PEI Services.
  @param  PeiUsbDevice           The pointer of PEI_USB_DEVICE instance.

  @retval EFI_SUCCESS            The new detected usb device is configured successfully.
  @retval EFI_OUT_OF_RESOURCES   Can't allocate memory resource.
  @retval Others                 Other failure occurs.

**/
EFI_STATUS
PeiUsbGetAllConfiguration (
  IN EFI_PEI_SERVICES   **PeiServices,
  IN PEI_USB_DEVICE     *PeiUsbDevice
  );

/**
  Get the start position of next wanted descriptor.
  
  @param  Buffer            Buffer containing data to parse.
  @param  Length            Buffer length.
  @param  DescType          Descriptor type.
  @param  DescLength        Descriptor length.
  @param  ParsedBytes       Bytes has been parsed.

  @retval EFI_SUCCESS       Get wanted descriptor successfully.
  @retval EFI_DEVICE_ERROR  Error occurred.

**/
EFI_STATUS
GetExpectedDescriptor (
  IN  UINT8       *Buffer,
  IN  UINTN       Length,
  IN  UINT8       DescType,
  IN  UINT8       DescLength,
  OUT UINTN       *ParsedBytes
  );

/**
  The entrypoint of the module, it will enumerate all HCs.
  
  @param  FileHandle             Handle of the file being invoked.
  @param  PeiServices            Describes the list of possible PEI Services.

  @retval EFI_SUCCESS            Usb initialization is done successfully.
  @retval EFI_OUT_OF_RESOURCES   Can't allocate memory resource.
  @retval EFI_UNSUPPORTED        Can't find required PPI.

**/
EFI_STATUS
EFIAPI
PeimInitializeUsb (
  IN EFI_PEI_FILE_HANDLE        FileHandle,
  IN CONST EFI_PEI_SERVICES     **PeiServices
  )
{
  EFI_STATUS                   Status;
  UINTN                        Index;
  PEI_USB_HOST_CONTROLLER_PPI  *UsbHcPpi;
  PEI_USB2_HOST_CONTROLLER_PPI *Usb2HcPpi;

  if (!EFI_ERROR (PeiServicesRegisterForShadow (FileHandle))) {
    return EFI_SUCCESS;
  }

  //
  // gPeiUsbHostControllerPpiGuid and gPeiUsb2HostControllerPpiGuid should not 
  // be produced at the same time
  //
  Index = 0;
  while (TRUE) {
    //
    // Get UsbHcPpi at first.
    //
    Status = PeiServicesLocatePpi (
               &gPeiUsbHostControllerPpiGuid,
               Index,
               NULL,
               (VOID **) &UsbHcPpi
               );
    if (EFI_ERROR (Status)) {
      //
      // No more host controller, break out
      //
      break;
    }
    PeiUsbEnumeration ((EFI_PEI_SERVICES **) PeiServices, UsbHcPpi, NULL);
    Index++;
  }

  if (Index == 0) {
    //
    // Then try to get Usb2HcPpi.
    //
    while (TRUE) {
      Status = PeiServicesLocatePpi (
                 &gPeiUsb2HostControllerPpiGuid,
                 Index,
                 NULL,
                 (VOID **) &Usb2HcPpi
                 );    
      if (EFI_ERROR (Status)) {
        //
        // No more host controller, break out
        //
        break;
      }   
      PeiUsbEnumeration ((EFI_PEI_SERVICES **) PeiServices, NULL, Usb2HcPpi);   
      Index++;
    }
  }
  
  if (Index == 0) {
    return EFI_UNSUPPORTED;
  }

  return EFI_SUCCESS;
}

/**
  The Hub Enumeration just scans the hub ports one time. It also
  doesn't support hot-plug.
  
  @param  PeiServices            Describes the list of possible PEI Services.
  @param  PeiUsbDevice           The pointer of PEI_USB_DEVICE instance.
  @param  CurrentAddress         The DeviceAddress of usb device.

  @retval EFI_SUCCESS            The usb hub is enumerated successfully.
  @retval EFI_OUT_OF_RESOURCES   Can't allocate memory resource.
  @retval Others                 Other failure occurs.

**/
EFI_STATUS
PeiHubEnumeration (
  IN EFI_PEI_SERVICES               **PeiServices,
  IN PEI_USB_DEVICE                 *PeiUsbDevice,
  IN UINT8                          *CurrentAddress
  )
{
  UINTN                 Index;
  EFI_STATUS            Status;
  PEI_USB_IO_PPI        *UsbIoPpi;
  EFI_USB_PORT_STATUS   PortStatus;
  UINTN                 MemPages;
  EFI_PHYSICAL_ADDRESS  AllocateAddress;
  PEI_USB_DEVICE        *NewPeiUsbDevice;
  UINTN                 InterfaceIndex;
  UINTN                 EndpointIndex;


  UsbIoPpi    = &PeiUsbDevice->UsbIoPpi;

  for (Index = 0; Index < PeiUsbDevice->DownStreamPortNo; Index++) {

    Status = PeiHubGetPortStatus (
              PeiServices,
              UsbIoPpi,
              (UINT8) (Index + 1),
              (UINT32 *) &PortStatus
              );

    if (EFI_ERROR (Status)) {
      continue;
    }

    if (IsPortConnectChange (PortStatus.PortChangeStatus)) {
      PeiHubClearPortFeature (
        PeiServices,
        UsbIoPpi,
        (UINT8) (Index + 1),
        EfiUsbPortConnectChange
        );

      MicroSecondDelay (100 * 1000);

      if (IsPortConnect (PortStatus.PortStatus)) {

        PeiHubGetPortStatus (
          PeiServices,
          UsbIoPpi,
          (UINT8) (Index + 1),
          (UINT32 *) &PortStatus
          );

        //
        // Begin to deal with the new device
        //
        MemPages = sizeof (PEI_USB_DEVICE) / EFI_PAGE_SIZE + 1;
        Status = PeiServicesAllocatePages (
                   EfiBootServicesCode,
                   MemPages,
                   &AllocateAddress
                   );
        if (EFI_ERROR (Status)) {
          return EFI_OUT_OF_RESOURCES;
        }

        NewPeiUsbDevice = (PEI_USB_DEVICE *) ((UINTN) AllocateAddress);
        ZeroMem (NewPeiUsbDevice, sizeof (PEI_USB_DEVICE));

        NewPeiUsbDevice->Signature        = PEI_USB_DEVICE_SIGNATURE;
        NewPeiUsbDevice->DeviceAddress    = 0;
        NewPeiUsbDevice->MaxPacketSize0   = 8;
        NewPeiUsbDevice->DataToggle       = 0;
        CopyMem (
          &(NewPeiUsbDevice->UsbIoPpi),
          &mUsbIoPpi,
          sizeof (PEI_USB_IO_PPI)
          );
        CopyMem (
          &(NewPeiUsbDevice->UsbIoPpiList),
          &mUsbIoPpiList,
          sizeof (EFI_PEI_PPI_DESCRIPTOR)
          );
        NewPeiUsbDevice->UsbIoPpiList.Ppi = &NewPeiUsbDevice->UsbIoPpi;
        NewPeiUsbDevice->AllocateAddress  = (UINTN) AllocateAddress;
        NewPeiUsbDevice->UsbHcPpi         = PeiUsbDevice->UsbHcPpi;
        NewPeiUsbDevice->Usb2HcPpi        = PeiUsbDevice->Usb2HcPpi;
        NewPeiUsbDevice->IsHub            = 0x0;
        NewPeiUsbDevice->DownStreamPortNo = 0x0;

        PeiResetHubPort (PeiServices, UsbIoPpi, (UINT8)(Index + 1));

        PeiHubGetPortStatus (
           PeiServices,
           UsbIoPpi,
           (UINT8) (Index + 1),
           (UINT32 *) &PortStatus
           );

        NewPeiUsbDevice->DeviceSpeed = (UINT8)IsPortLowSpeedDeviceAttached (PortStatus.PortStatus);

        if(NewPeiUsbDevice->DeviceSpeed != EFI_USB_SPEED_HIGH) {
          if (PeiUsbDevice->DeviceSpeed == EFI_USB_SPEED_HIGH) {
            NewPeiUsbDevice->Translator.TranslatorPortNumber = (UINT8)Index;
            NewPeiUsbDevice->Translator.TranslatorHubAddress = *CurrentAddress;
          } else {
            CopyMem(&(NewPeiUsbDevice->Translator), &(PeiUsbDevice->Translator), sizeof(EFI_USB2_HC_TRANSACTION_TRANSLATOR));
          }
        }

        //
        // Configure that Usb Device
        //
        Status = PeiConfigureUsbDevice (
                  PeiServices,
                  NewPeiUsbDevice,
                  (UINT8) (Index + 1),
                  CurrentAddress
                  );

        if (EFI_ERROR (Status)) {
          continue;
        }

        Status = PeiServicesInstallPpi (&NewPeiUsbDevice->UsbIoPpiList);

        if (NewPeiUsbDevice->InterfaceDesc->InterfaceClass == 0x09) {
          NewPeiUsbDevice->IsHub  = 0x1;

          Status = PeiDoHubConfig (PeiServices, NewPeiUsbDevice);
          if (EFI_ERROR (Status)) {
            return Status;
          }

          PeiHubEnumeration (PeiServices, NewPeiUsbDevice, CurrentAddress);
        }

        for (InterfaceIndex = 1; InterfaceIndex < NewPeiUsbDevice->ConfigDesc->NumInterfaces; InterfaceIndex++) {
          //
          // Begin to deal with the new device
          //
          MemPages = sizeof (PEI_USB_DEVICE) / EFI_PAGE_SIZE + 1;
          Status = PeiServicesAllocatePages (
                     EfiBootServicesCode,
                     MemPages,
                     &AllocateAddress
                     );
          if (EFI_ERROR (Status)) {
            return EFI_OUT_OF_RESOURCES;
          }
          CopyMem ((VOID *)(UINTN)AllocateAddress, NewPeiUsbDevice, sizeof (PEI_USB_DEVICE));
          NewPeiUsbDevice = (PEI_USB_DEVICE *) ((UINTN) AllocateAddress);
          NewPeiUsbDevice->AllocateAddress  = (UINTN) AllocateAddress;
          NewPeiUsbDevice->UsbIoPpiList.Ppi = &NewPeiUsbDevice->UsbIoPpi;
          NewPeiUsbDevice->InterfaceDesc = NewPeiUsbDevice->InterfaceDescList[InterfaceIndex];
          for (EndpointIndex = 0; EndpointIndex < NewPeiUsbDevice->InterfaceDesc->NumEndpoints; EndpointIndex++) {
            NewPeiUsbDevice->EndpointDesc[EndpointIndex] = NewPeiUsbDevice->EndpointDescList[InterfaceIndex][EndpointIndex];
          }

          Status = PeiServicesInstallPpi (&NewPeiUsbDevice->UsbIoPpiList);

          if (NewPeiUsbDevice->InterfaceDesc->InterfaceClass == 0x09) {
            NewPeiUsbDevice->IsHub  = 0x1;

            Status = PeiDoHubConfig (PeiServices, NewPeiUsbDevice);
            if (EFI_ERROR (Status)) {
              return Status;
            }

            PeiHubEnumeration (PeiServices, NewPeiUsbDevice, CurrentAddress);
          }
        }
      }
    }
  }


  return EFI_SUCCESS;
}

/**
  The enumeration routine to detect device change.
  
  @param  PeiServices            Describes the list of possible PEI Services.
  @param  UsbHcPpi               The pointer of PEI_USB_HOST_CONTROLLER_PPI instance.
  @param  Usb2HcPpi              The pointer of PEI_USB2_HOST_CONTROLLER_PPI instance.

  @retval EFI_SUCCESS            The usb is enumerated successfully.
  @retval EFI_OUT_OF_RESOURCES   Can't allocate memory resource.
  @retval Others                 Other failure occurs.

**/
EFI_STATUS
PeiUsbEnumeration (
  IN EFI_PEI_SERVICES               **PeiServices,
  IN PEI_USB_HOST_CONTROLLER_PPI    *UsbHcPpi,
  IN PEI_USB2_HOST_CONTROLLER_PPI   *Usb2HcPpi
  )
{
  UINT8                 NumOfRootPort;
  EFI_STATUS            Status;
  UINT8                 Index;
  EFI_USB_PORT_STATUS   PortStatus;
  PEI_USB_DEVICE        *PeiUsbDevice;
  UINTN                 MemPages;
  EFI_PHYSICAL_ADDRESS  AllocateAddress;
  UINT8                 CurrentAddress;
  UINTN                 InterfaceIndex;
  UINTN                 EndpointIndex;

  CurrentAddress = 0;
  if (Usb2HcPpi != NULL) {
    Usb2HcPpi->GetRootHubPortNumber (
                PeiServices,
                Usb2HcPpi,
                (UINT8 *) &NumOfRootPort
                );    
  } else if (UsbHcPpi != NULL) {
    UsbHcPpi->GetRootHubPortNumber (
                PeiServices,
                UsbHcPpi,
                (UINT8 *) &NumOfRootPort
                );
  } else {
    ASSERT (FALSE);
    return EFI_INVALID_PARAMETER;
  }

  for (Index = 0; Index < NumOfRootPort; Index++) {
    //
    // First get root port status to detect changes happen
    //
    if (Usb2HcPpi != NULL) {
      Usb2HcPpi->GetRootHubPortStatus (
                  PeiServices,
                  Usb2HcPpi,
                  (UINT8) Index,
                  &PortStatus
                  );      
    } else {
      UsbHcPpi->GetRootHubPortStatus (
                  PeiServices,
                  UsbHcPpi,
                  (UINT8) Index,
                  &PortStatus
                  );
    }
    DEBUG ((EFI_D_INFO, "USB Status --- ConnectChange[%04x] Status[%04x]\n", PortStatus.PortChangeStatus, PortStatus.PortStatus));
    if (IsPortConnectChange (PortStatus.PortChangeStatus)) {
      //
      // Changes happen, first clear this change status
      //
      if (Usb2HcPpi != NULL) {
        Usb2HcPpi->ClearRootHubPortFeature (
                    PeiServices,
                    Usb2HcPpi,
                    (UINT8) Index,
                    EfiUsbPortConnectChange
                    );        
      } else {
        UsbHcPpi->ClearRootHubPortFeature (
                    PeiServices,
                    UsbHcPpi,
                    (UINT8) Index,
                    EfiUsbPortConnectChange
                    );
      }
      MicroSecondDelay (100 * 1000);

      if (IsPortConnect (PortStatus.PortStatus)) {
        if (Usb2HcPpi != NULL) {
          Usb2HcPpi->GetRootHubPortStatus (
                      PeiServices,
                      Usb2HcPpi,
                      (UINT8) Index,
                      &PortStatus
                      );
        } else {
          UsbHcPpi->GetRootHubPortStatus (
                      PeiServices,
                      UsbHcPpi,
                      (UINT8) Index,
                      &PortStatus
                      );
        }

        //
        // Connect change happen
        //
        MemPages = sizeof (PEI_USB_DEVICE) / EFI_PAGE_SIZE + 1;
        Status = PeiServicesAllocatePages (
                   EfiBootServicesCode,
                   MemPages,
                   &AllocateAddress
                   );
        if (EFI_ERROR (Status)) {
          return EFI_OUT_OF_RESOURCES;
        }

        PeiUsbDevice = (PEI_USB_DEVICE *) ((UINTN) AllocateAddress);
        ZeroMem (PeiUsbDevice, sizeof (PEI_USB_DEVICE));

        PeiUsbDevice->Signature         = PEI_USB_DEVICE_SIGNATURE;
        PeiUsbDevice->DeviceAddress     = 0;
        PeiUsbDevice->MaxPacketSize0    = 8;
        PeiUsbDevice->DataToggle        = 0;
        CopyMem (
          &(PeiUsbDevice->UsbIoPpi),
          &mUsbIoPpi,
          sizeof (PEI_USB_IO_PPI)
          );
        CopyMem (
          &(PeiUsbDevice->UsbIoPpiList),
          &mUsbIoPpiList,
          sizeof (EFI_PEI_PPI_DESCRIPTOR)
          );
        PeiUsbDevice->UsbIoPpiList.Ppi  = &PeiUsbDevice->UsbIoPpi;
        PeiUsbDevice->AllocateAddress   = (UINTN) AllocateAddress;
        PeiUsbDevice->UsbHcPpi          = UsbHcPpi;
        PeiUsbDevice->Usb2HcPpi         = Usb2HcPpi;
        PeiUsbDevice->IsHub             = 0x0;
        PeiUsbDevice->DownStreamPortNo  = 0x0;

        ResetRootPort (
          PeiServices,
          PeiUsbDevice->UsbHcPpi,
          PeiUsbDevice->Usb2HcPpi,
          Index,
          0
          );

        if (Usb2HcPpi != NULL) {
          Usb2HcPpi->GetRootHubPortStatus (
                      PeiServices,
                      Usb2HcPpi,
                      (UINT8) Index,
                      &PortStatus
                      );
        } else {
          UsbHcPpi->GetRootHubPortStatus (
                      PeiServices,
                      UsbHcPpi,
                      (UINT8) Index,
                      &PortStatus
                      );
        }

        PeiUsbDevice->DeviceSpeed = (UINT8)IsPortLowSpeedDeviceAttached (PortStatus.PortStatus);
        DEBUG ((EFI_D_INFO, "Device Speed =%d\n", PeiUsbDevice->DeviceSpeed));

        //
        // Configure that Usb Device
        //
        Status = PeiConfigureUsbDevice (
                  PeiServices,
                  PeiUsbDevice,
                  Index,
                  &CurrentAddress
                  );

        if (EFI_ERROR (Status)) {
          continue;
        }
        DEBUG ((EFI_D_INFO, "PeiConfigureUsbDevice Success\n"));

        Status = PeiServicesInstallPpi (&PeiUsbDevice->UsbIoPpiList);

        if (PeiUsbDevice->InterfaceDesc->InterfaceClass == 0x09) {
          PeiUsbDevice->IsHub = 0x1;

          Status = PeiDoHubConfig (PeiServices, PeiUsbDevice);
          if (EFI_ERROR (Status)) {
            return Status;
          }

          PeiHubEnumeration (PeiServices, PeiUsbDevice, &CurrentAddress);
        }

        for (InterfaceIndex = 1; InterfaceIndex < PeiUsbDevice->ConfigDesc->NumInterfaces; InterfaceIndex++) {
          //
          // Begin to deal with the new device
          //
          MemPages = sizeof (PEI_USB_DEVICE) / EFI_PAGE_SIZE + 1;
          Status = PeiServicesAllocatePages (
                     EfiBootServicesCode,
                     MemPages,
                     &AllocateAddress
                     );
          if (EFI_ERROR (Status)) {
            return EFI_OUT_OF_RESOURCES;
          }
          CopyMem ((VOID *)(UINTN)AllocateAddress, PeiUsbDevice, sizeof (PEI_USB_DEVICE));
          PeiUsbDevice = (PEI_USB_DEVICE *) ((UINTN) AllocateAddress);
          PeiUsbDevice->AllocateAddress  = (UINTN) AllocateAddress;
          PeiUsbDevice->UsbIoPpiList.Ppi = &PeiUsbDevice->UsbIoPpi;
          PeiUsbDevice->InterfaceDesc = PeiUsbDevice->InterfaceDescList[InterfaceIndex];
          for (EndpointIndex = 0; EndpointIndex < PeiUsbDevice->InterfaceDesc->NumEndpoints; EndpointIndex++) {
            PeiUsbDevice->EndpointDesc[EndpointIndex] = PeiUsbDevice->EndpointDescList[InterfaceIndex][EndpointIndex];
          }

          Status = PeiServicesInstallPpi (&PeiUsbDevice->UsbIoPpiList);

          if (PeiUsbDevice->InterfaceDesc->InterfaceClass == 0x09) {
            PeiUsbDevice->IsHub = 0x1;

            Status = PeiDoHubConfig (PeiServices, PeiUsbDevice);
            if (EFI_ERROR (Status)) {
              return Status;
            }

            PeiHubEnumeration (PeiServices, PeiUsbDevice, &CurrentAddress);
          }
        }
      } else {
        //
        // Disconnect change happen, currently we don't support
        //
      }
    }
  }

  return EFI_SUCCESS;
}

/**
  Configure new detected usb device.
  
  @param  PeiServices            Describes the list of possible PEI Services.
  @param  PeiUsbDevice           The pointer of PEI_USB_DEVICE instance.
  @param  Port                   The port to be configured.
  @param  DeviceAddress          The device address to be configured.

  @retval EFI_SUCCESS            The new detected usb device is configured successfully.
  @retval EFI_OUT_OF_RESOURCES   Can't allocate memory resource.
  @retval Others                 Other failure occurs.

**/
EFI_STATUS
PeiConfigureUsbDevice (
  IN EFI_PEI_SERVICES   **PeiServices,
  IN PEI_USB_DEVICE     *PeiUsbDevice,
  IN UINT8              Port,
  IN OUT UINT8          *DeviceAddress
  )
{
  EFI_USB_DEVICE_DESCRIPTOR   DeviceDescriptor;
  EFI_STATUS                  Status;
  PEI_USB_IO_PPI              *UsbIoPpi;
  UINT8                       Retry;

  UsbIoPpi = &PeiUsbDevice->UsbIoPpi;
  Status   = EFI_SUCCESS;
  ZeroMem (&DeviceDescriptor, sizeof (EFI_USB_DEVICE_DESCRIPTOR));
  //
  // Get USB device descriptor
  //

  for (Retry = 0; Retry < 3; Retry ++) {

    PeiUsbDevice->MaxPacketSize0 = 8;

    Status = PeiUsbGetDescriptor (
               PeiServices,
               UsbIoPpi,
               (USB_DT_DEVICE << 8),
               0,
               8,
               &DeviceDescriptor
               );

    if (!EFI_ERROR (Status)) {
      DEBUG ((EFI_D_INFO, "PeiUsbGet Device Descriptor the %d time Sucess\n", Retry));
      break;
    }
  }

  if (Retry == 3) {
    DEBUG ((EFI_D_ERROR, "PeiUsbGet Device Descriptor fail\n", Retry));
    return Status;
  }

  PeiUsbDevice->MaxPacketSize0 = DeviceDescriptor.MaxPacketSize0;

  (*DeviceAddress) ++;

  Status = PeiUsbSetDeviceAddress (
            PeiServices,
            UsbIoPpi,
            *DeviceAddress
            );

  if (EFI_ERROR (Status)) {
    DEBUG ((EFI_D_ERROR, "PeiUsbSetDeviceAddress Failed\n"));
    return Status;
  }

  PeiUsbDevice->DeviceAddress = *DeviceAddress;

  //
  // Get whole USB device descriptor
  //
  Status = PeiUsbGetDescriptor (
            PeiServices,
            UsbIoPpi,
            (USB_DT_DEVICE << 8),
            0,
            (UINT16) sizeof (EFI_USB_DEVICE_DESCRIPTOR),
            &DeviceDescriptor
            );

  if (EFI_ERROR (Status)) {
    DEBUG ((EFI_D_ERROR, "PeiUsbGetDescriptor First Failed\n"));
    return Status;
  }

  //
  // Get its default configuration and its first interface
  //
  Status = PeiUsbGetAllConfiguration (
            PeiServices,
            PeiUsbDevice
            );
  if (EFI_ERROR (Status)) {
    return Status;
  }

  Status = PeiUsbSetConfiguration (
            PeiServices,
            UsbIoPpi
            );

  if (EFI_ERROR (Status)) {
    return Status;
  }

  return EFI_SUCCESS;
}

/**
  Get all configurations from a detected usb device.
  
  @param  PeiServices            Describes the list of possible PEI Services.
  @param  PeiUsbDevice           The pointer of PEI_USB_DEVICE instance.

  @retval EFI_SUCCESS            The new detected usb device is configured successfully.
  @retval EFI_OUT_OF_RESOURCES   Can't allocate memory resource.
  @retval Others                 Other failure occurs.

**/
EFI_STATUS
PeiUsbGetAllConfiguration (
  IN EFI_PEI_SERVICES   **PeiServices,
  IN PEI_USB_DEVICE     *PeiUsbDevice
  )
{
  EFI_STATUS                Status;
  EFI_USB_CONFIG_DESCRIPTOR *ConfigDesc;
  PEI_USB_IO_PPI            *UsbIoPpi;
  UINT16                    ConfigDescLength;
  UINT8                     *Ptr;
  UINTN                     SkipBytes;
  UINTN                     LengthLeft;
  UINTN                     InterfaceIndex;
  UINTN                     Index;
  UINTN                     NumOfEndpoint;

  UsbIoPpi = &PeiUsbDevice->UsbIoPpi;

  //
  // First get its 4-byte configuration descriptor
  //
  Status = PeiUsbGetDescriptor (
            PeiServices,
            UsbIoPpi,
            (USB_DT_CONFIG << 8), // Value
            0,      // Index
            4,      // Length
            PeiUsbDevice->ConfigurationData
            );

  if (EFI_ERROR (Status)) {
    DEBUG ((EFI_D_ERROR, "PeiUsbGet Config Descriptor First Failed\n"));
    return Status;
  }

  ConfigDesc        = (EFI_USB_CONFIG_DESCRIPTOR *) PeiUsbDevice->ConfigurationData;
  ConfigDescLength  = ConfigDesc->TotalLength;

  //
  // Then we get the total descriptors for this configuration
  //
  Status = PeiUsbGetDescriptor (
            PeiServices,
            UsbIoPpi,
            (USB_DT_CONFIG << 8),
            0,
            ConfigDescLength,
            PeiUsbDevice->ConfigurationData
            );

  if (EFI_ERROR (Status)) {
    DEBUG ((EFI_D_ERROR, "PeiUsbGet Config Descriptor all Failed\n"));
    return Status;
  }
  //
  // Parse this configuration descriptor
  // First get the current config descriptor;
  //
  Status = GetExpectedDescriptor (
            PeiUsbDevice->ConfigurationData,
            ConfigDescLength,
            USB_DT_CONFIG,
            (UINT8) sizeof (EFI_USB_CONFIG_DESCRIPTOR),
            &SkipBytes
            );

  if (EFI_ERROR (Status)) {
    return Status;
  }

  Ptr                       = PeiUsbDevice->ConfigurationData + SkipBytes;
  PeiUsbDevice->ConfigDesc  = (EFI_USB_CONFIG_DESCRIPTOR *) Ptr;

  Ptr += sizeof (EFI_USB_CONFIG_DESCRIPTOR);
  LengthLeft = ConfigDescLength - SkipBytes - sizeof (EFI_USB_CONFIG_DESCRIPTOR);

  for (InterfaceIndex = 0; InterfaceIndex < PeiUsbDevice->ConfigDesc->NumInterfaces; InterfaceIndex++) {

    //
    // Get the interface descriptor
    //
    Status = GetExpectedDescriptor (
              Ptr,
              LengthLeft,
              USB_DT_INTERFACE,
              (UINT8) sizeof (EFI_USB_INTERFACE_DESCRIPTOR),
              &SkipBytes
              );

    if (EFI_ERROR (Status)) {
      return Status;
    }

    Ptr += SkipBytes;
    if (InterfaceIndex == 0) {
      PeiUsbDevice->InterfaceDesc = (EFI_USB_INTERFACE_DESCRIPTOR *) Ptr;
    }
    PeiUsbDevice->InterfaceDescList[InterfaceIndex] = (EFI_USB_INTERFACE_DESCRIPTOR *) Ptr;

    Ptr += sizeof (EFI_USB_INTERFACE_DESCRIPTOR);
    LengthLeft -= SkipBytes;
    LengthLeft -= sizeof (EFI_USB_INTERFACE_DESCRIPTOR);

    //
    // Parse all the endpoint descriptor within this interface
    //
    NumOfEndpoint = PeiUsbDevice->InterfaceDescList[InterfaceIndex]->NumEndpoints;
    ASSERT (NumOfEndpoint <= MAX_ENDPOINT);

    for (Index = 0; Index < NumOfEndpoint; Index++) {
      //
      // Get the endpoint descriptor
      //
      Status = GetExpectedDescriptor (
                Ptr,
                LengthLeft,
                USB_DT_ENDPOINT,
                (UINT8) sizeof (EFI_USB_ENDPOINT_DESCRIPTOR),
                &SkipBytes
                );

      if (EFI_ERROR (Status)) {
        return Status;
      }

      Ptr += SkipBytes;
      if (InterfaceIndex == 0) {
        PeiUsbDevice->EndpointDesc[Index] = (EFI_USB_ENDPOINT_DESCRIPTOR *) Ptr;
      }
      PeiUsbDevice->EndpointDescList[InterfaceIndex][Index] = (EFI_USB_ENDPOINT_DESCRIPTOR *) Ptr;

      Ptr += sizeof (EFI_USB_ENDPOINT_DESCRIPTOR);
      LengthLeft -= SkipBytes;
      LengthLeft -= sizeof (EFI_USB_ENDPOINT_DESCRIPTOR);
    }
  }

  return EFI_SUCCESS;
}

/**
  Get the start position of next wanted descriptor.
  
  @param  Buffer            Buffer containing data to parse.
  @param  Length            Buffer length.
  @param  DescType          Descriptor type.
  @param  DescLength        Descriptor length.
  @param  ParsedBytes       Bytes has been parsed.

  @retval EFI_SUCCESS       Get wanted descriptor successfully.
  @retval EFI_DEVICE_ERROR  Error occurred.

**/
EFI_STATUS
GetExpectedDescriptor (
  IN  UINT8       *Buffer,
  IN  UINTN       Length,
  IN  UINT8       DescType,
  IN  UINT8       DescLength,
  OUT UINTN       *ParsedBytes
  )
{
  UINT16  DescriptorHeader;
  UINT8   Len;
  UINT8   *Ptr;
  UINTN   Parsed;

  Parsed  = 0;
  Ptr     = Buffer;

  while (TRUE) {
    //
    // Buffer length should not less than Desc length
    //
    if (Length < DescLength) {
      return EFI_DEVICE_ERROR;
    }

    DescriptorHeader  = (UINT16) (*Ptr + ((*(Ptr + 1)) << 8));

    Len               = Buffer[0];

    //
    // Check to see if it is a start of expected descriptor
    //
    if (DescriptorHeader == ((DescType << 8) | DescLength)) {
      break;
    }

    if ((UINT8) (DescriptorHeader >> 8) == DescType) {
      if (Len > DescLength) {
        return EFI_DEVICE_ERROR;
      }
    }
    //
    // Descriptor length should be at least 2
    // and should not exceed the buffer length
    //
    if (Len < 2) {
      return EFI_DEVICE_ERROR;
    }

    if (Len > Length) {
      return EFI_DEVICE_ERROR;
    }
    //
    // Skip this mismatch descriptor
    //
    Length -= Len;
    Ptr += Len;
    Parsed += Len;
  }

  *ParsedBytes = Parsed;

  return EFI_SUCCESS;
}

/**
  Send reset signal over the given root hub port.
  
  @param  PeiServices       Describes the list of possible PEI Services.
  @param  UsbHcPpi          The pointer of PEI_USB_HOST_CONTROLLER_PPI instance.
  @param  Usb2HcPpi         The pointer of PEI_USB2_HOST_CONTROLLER_PPI instance.
  @param  PortNum           The port to be reset.
  @param  RetryIndex        The retry times.

**/
VOID
ResetRootPort (
  IN EFI_PEI_SERVICES               **PeiServices,
  IN PEI_USB_HOST_CONTROLLER_PPI    *UsbHcPpi,
  IN PEI_USB2_HOST_CONTROLLER_PPI   *Usb2HcPpi,
  IN UINT8                          PortNum,
  IN UINT8                          RetryIndex
  )
{
  EFI_STATUS             Status;


  if (Usb2HcPpi != NULL) {
    MicroSecondDelay (200 * 1000);
    
    //
    // reset root port
    //
    Status = Usb2HcPpi->SetRootHubPortFeature (
                         PeiServices,
                         Usb2HcPpi,
                         PortNum,
                         EfiUsbPortReset
                         );
    
    if (EFI_ERROR (Status)) {
      DEBUG ((EFI_D_ERROR, "SetRootHubPortFeature EfiUsbPortReset Failed\n"));
      return;
    }
    
    MicroSecondDelay (200 * 1000);
    
    //
    // clear reset root port
    //
    Status = Usb2HcPpi->ClearRootHubPortFeature (
                         PeiServices,
                         Usb2HcPpi,
                         PortNum,
                         EfiUsbPortReset
                         );
    
    if (EFI_ERROR (Status)) {
      DEBUG ((EFI_D_ERROR, "ClearRootHubPortFeature EfiUsbPortReset Failed\n"));
      return;
    }
    
    MicroSecondDelay (1 * 1000);
    
    Usb2HcPpi->ClearRootHubPortFeature (
                PeiServices,
                Usb2HcPpi,
                PortNum,
                EfiUsbPortConnectChange
                );
    
    //
    // Set port enable
    //
    Usb2HcPpi->SetRootHubPortFeature(
                PeiServices,
                Usb2HcPpi,
                PortNum,
                EfiUsbPortEnable
                );
    
    Usb2HcPpi->ClearRootHubPortFeature (
                PeiServices,
                Usb2HcPpi,
                PortNum,
                EfiUsbPortEnableChange
                );
    
    MicroSecondDelay ((RetryIndex + 1) * 50 * 1000);
  } else {
    MicroSecondDelay (200 * 1000);
    
    //
    // reset root port
    //
    Status = UsbHcPpi->SetRootHubPortFeature (
                         PeiServices,
                         UsbHcPpi,
                         PortNum,
                         EfiUsbPortReset
                         );
    
    if (EFI_ERROR (Status)) {
      DEBUG ((EFI_D_ERROR, "SetRootHubPortFeature EfiUsbPortReset Failed\n"));
      return;
    }
    
    MicroSecondDelay (200 * 1000);
    
    //
    // clear reset root port
    //
    Status = UsbHcPpi->ClearRootHubPortFeature (
                         PeiServices,
                         UsbHcPpi,
                         PortNum,
                         EfiUsbPortReset
                         );
    
    if (EFI_ERROR (Status)) {
      DEBUG ((EFI_D_ERROR, "ClearRootHubPortFeature EfiUsbPortReset Failed\n"));
      return;
    }
    
    MicroSecondDelay (1 * 1000);
    
    UsbHcPpi->ClearRootHubPortFeature (
                PeiServices,
                UsbHcPpi,
                PortNum,
                EfiUsbPortConnectChange
                );
    
    //
    // Set port enable
    //
    UsbHcPpi->SetRootHubPortFeature(
                PeiServices,
                UsbHcPpi,
                PortNum,
                EfiUsbPortEnable
                );
    
    UsbHcPpi->ClearRootHubPortFeature (
                PeiServices,
                UsbHcPpi,
                PortNum,
                EfiUsbPortEnableChange
                );
    
    MicroSecondDelay ((RetryIndex + 1) * 50 * 1000);
  }
  return;
}


