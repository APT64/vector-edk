#line 1 "c:\\vector-edk-master\\IntelFrameworkModulePkg\\Universal\\BdsDxe\\DeviceMngr\\DeviceManagerVfr.Vfr"
#line 1 "c:\\vector-edk-master\\Build\\OvmfX64\\RELEASE_VS2010x86\\X64\\IntelFrameworkModulePkg\\Universal\\BdsDxe\\BdsDxe\\DEBUG\\BdsDxeStrDefs.h"




























































































































































































































extern unsigned char BdsDxeStrings[];




#line 227 "c:\\vector-edk-master\\Build\\OvmfX64\\RELEASE_VS2010x86\\X64\\IntelFrameworkModulePkg\\Universal\\BdsDxe\\BdsDxe\\DEBUG\\BdsDxeStrDefs.h"
#line 1 "c:\\vector-edk-master\\IntelFrameworkModulePkg\\Universal\\BdsDxe\\DeviceMngr\\DeviceManagerVfr.Vfr"















#line 1 "c:\\vector-edk-master\\intelframeworkmodulepkg\\universal\\bdsdxe\\devicemngr\\DeviceManagerVfr.h"

















#line 1 "c:\\vector-edk-master\\IntelFrameworkModulePkg\\Include\\Guid/BdsHii.h"















































extern EFI_GUID gFrontPageFormSetGuid;
extern EFI_GUID gBootMaintFormSetGuid;
extern EFI_GUID gFileExploreFormSetGuid;
extern EFI_GUID gBootManagerFormSetGuid;
extern EFI_GUID gDeviceManagerFormSetGuid;
extern EFI_GUID gDriverHealthFormSetGuid;

#line 56 "c:\\vector-edk-master\\IntelFrameworkModulePkg\\Include\\Guid/BdsHii.h"
#line 19 "c:\\vector-edk-master\\intelframeworkmodulepkg\\universal\\bdsdxe\\devicemngr\\DeviceManagerVfr.h"


































extern UINT8  DeviceManagerVfrBin[];
extern UINT8  DriverHealthVfrBin[];

#line 57 "c:\\vector-edk-master\\intelframeworkmodulepkg\\universal\\bdsdxe\\devicemngr\\DeviceManagerVfr.h"
#line 17 "c:\\vector-edk-master\\IntelFrameworkModulePkg\\Universal\\BdsDxe\\DeviceMngr\\DeviceManagerVfr.Vfr"











formset
  guid      = { 0x3ebfa8e6, 0x511d, 0x4b5b, {0xa9, 0x5f, 0xfb, 0x38, 0x26, 0xf, 0x1c, 0x27} },
  title     = STRING_TOKEN(0x006E),
  help      = STRING_TOKEN(0x0076),
  classguid = { 0x3ebfa8e6, 0x511d, 0x4b5b, {0xa9, 0x5f, 0xfb, 0x38, 0x26, 0xf, 0x1c, 0x27} },
  class     = 0x0000,
  subclass  = 0x0003,

  form formid = 0x1000,
       title  = STRING_TOKEN(0x006E);

    subtitle text = STRING_TOKEN(0x006F);
    
    
    
    label 0x0001;


    label 0x0002;


    label 0x0004;


    label 0x0008;


    label 0x0010;




    label 0x1100;
    label 0xffff;
      
    subtitle text = STRING_TOKEN(0x0076);

    label 0x0040;
    label 0xffff;
    
    subtitle text = STRING_TOKEN(0x0076);
    subtitle text = STRING_TOKEN(0x0081);

  endform;

  form formid = 0x1001,
       title = STRING_TOKEN(0x008B);

    subtitle text = STRING_TOKEN(0x008C);

       label 0x1101;
       label 0xffff;
       subtitle text = STRING_TOKEN(0x0076);
    subtitle text = STRING_TOKEN(0x0081);
  endform;

  form formid = 0x1002,
       title = STRING_TOKEN(0x0088);

    subtitle text = STRING_TOKEN(0x0089);

       label 0x1102;
       label 0xffff;
       subtitle text = STRING_TOKEN(0x0076);
    subtitle text = STRING_TOKEN(0x0081);
  endform;
endformset;

