#line 1 "c:\\vector-edk-master\\IntelFrameworkModulePkg\\Universal\\BdsDxe\\BootMaint\\FE.vfr"
#line 1 "c:\\vector-edk-master\\Build\\OvmfX64\\RELEASE_VS2010x86\\X64\\IntelFrameworkModulePkg\\Universal\\BdsDxe\\BdsDxe\\DEBUG\\BdsDxeStrDefs.h"




























































































































































































































extern unsigned char BdsDxeStrings[];




#line 227 "c:\\vector-edk-master\\Build\\OvmfX64\\RELEASE_VS2010x86\\X64\\IntelFrameworkModulePkg\\Universal\\BdsDxe\\BdsDxe\\DEBUG\\BdsDxeStrDefs.h"
#line 1 "c:\\vector-edk-master\\IntelFrameworkModulePkg\\Universal\\BdsDxe\\BootMaint\\FE.vfr"















#line 1 "c:\\vector-edk-master\\intelframeworkmodulepkg\\universal\\bdsdxe\\bootmaint\\FormGuid.h"
















#line 1 "c:\\vector-edk-master\\IntelFrameworkModulePkg\\Include\\Guid/BdsHii.h"















































extern EFI_GUID gFrontPageFormSetGuid;
extern EFI_GUID gBootMaintFormSetGuid;
extern EFI_GUID gFileExploreFormSetGuid;
extern EFI_GUID gBootManagerFormSetGuid;
extern EFI_GUID gDeviceManagerFormSetGuid;
extern EFI_GUID gDriverHealthFormSetGuid;

#line 56 "c:\\vector-edk-master\\IntelFrameworkModulePkg\\Include\\Guid/BdsHii.h"
#line 18 "c:\\vector-edk-master\\intelframeworkmodulepkg\\universal\\bdsdxe\\bootmaint\\FormGuid.h"










































































typedef struct {
  
  
  
  
  UINT16  BootTimeOut;
  UINT16  BootNext;

  
  
  
  UINT8   COM1BaudRate;
  UINT8   COM1DataRate;
  UINT8   COM1StopBits;
  UINT8   COM1Parity;
  UINT8   COM1TerminalType;

  
  
  
  UINT8   COM2BaudRate;
  UINT8   COM2DataRate;
  UINT8   COM2StopBits;
  UINT8   COM2Parity;
  UINT8   COM2TerminalType;

  
  
  
  UINT16  DriverAddHandleDesc[100];
  UINT16  DriverAddHandleOptionalData[100];
  UINT8   DriverAddActive;
  UINT8   DriverAddForceReconnect;

  
  
  
  UINT8   ConsoleInputCOM1;
  UINT8   ConsoleInputCOM2;
  UINT8   ConsoleOutputCOM1;
  UINT8   ConsoleOutputCOM2;
  UINT8   ConsoleErrorCOM1;
  UINT8   ConsoleErrorCOM2;

  
  
  
  UINT8   ConsoleCheck[100];

  
  
  
  
  
  UINT32  OptionOrder[100];

  
  
  
  BOOLEAN OptionDel[100];

  
  
  
  UINT8   COMBaudRate;
  UINT8   COMDataRate;
  UINT8   COMStopBits;
  UINT8   COMParity;
  UINT8   COMTerminalType;
  UINT8   COMFlowControl;

  
  
  
  UINT8   LegacyFD[100];
  UINT8   LegacyHD[100];
  UINT8   LegacyCD[100];
  UINT8   LegacyNET[100];
  UINT8   LegacyBEV[100];

  
  
  
  
  
  
  UINT8   DisableMap[32];

  
  
  
  UINT16  ConsoleOutMode;

  
  
  
} BMM_FAKE_NV_DATA;












typedef struct {
  UINT16  DescriptionData[75];
  UINT16  OptionalData[127];
  UINT8   Active;
  UINT8   ForceReconnect;
} FILE_EXPLORER_NV_DATA;

#line 209 "c:\\vector-edk-master\\intelframeworkmodulepkg\\universal\\bdsdxe\\bootmaint\\FormGuid.h"

#line 17 "c:\\vector-edk-master\\IntelFrameworkModulePkg\\Universal\\BdsDxe\\BootMaint\\FE.vfr"

formset
  guid = { 0x1f2d63e1, 0xfebd, 0x4dc7, {0x9c, 0xc5, 0xba, 0x2b, 0x1c, 0xef, 0x9c, 0x5b} },
  title = STRING_TOKEN(0x0066),
  help = STRING_TOKEN(0x0002),
  classguid = { 0x1f2d63e1, 0xfebd, 0x4dc7, {0x9c, 0xc5, 0xba, 0x2b, 0x1c, 0xef, 0x9c, 0x5b} },
  class = 0,
  subclass = 0,

  varstore FILE_EXPLORER_NV_DATA,
    varid = 0x1000,
    name = FeData,
    guid = { 0x1f2d63e1, 0xfebd, 0x4dc7, {0x9c, 0xc5, 0xba, 0x2b, 0x1c, 0xef, 0x9c, 0x5b} };

  form formid = 0x101E,
       title = STRING_TOKEN(0x0066);

       label 0x101E;
       label 0xffff;
  endform;

  form formid = 0x101F,
       title = STRING_TOKEN(0x002A);

       label 0x101F;
       label 0xffff;

       subtitle text = STRING_TOKEN(0x0002);

       string    varid    = FeData.DescriptionData,
                 prompt   = STRING_TOKEN(0x0030),
                 help     = STRING_TOKEN(0x0002),
                 minsize  = 6,
                 maxsize  = 75,
       endstring;

       string    varid    = FeData.OptionalData,
       		prompt   = STRING_TOKEN(0x0063),
       		help     = STRING_TOKEN(0x0002),
       		minsize  = 0,
       		maxsize  = 120,
       endstring;

       subtitle text = STRING_TOKEN(0x0002);

       text
         help   = STRING_TOKEN(0x0032),
         text   = STRING_TOKEN(0x0032),
         text   = STRING_TOKEN(0x0002),
         flags  = INTERACTIVE,
         key    = 0x1000;

       text
         help   = STRING_TOKEN(0x0033),
         text   = STRING_TOKEN(0x0033),
         text   = STRING_TOKEN(0x0002),
         flags  = INTERACTIVE,
         key    = 0x1001;

  endform;

  form formid = 0x1020,
       title = STRING_TOKEN(0x002B);

       label 0x1020;
       label 0xffff;

       subtitle text = STRING_TOKEN(0x0002);

       string    varid    = FeData.DescriptionData,
                 prompt   = STRING_TOKEN(0x0030),
                 help     = STRING_TOKEN(0x0002),
                 minsize  = 6,
                 maxsize  = 75,
       endstring;

       string    varid    = FeData.OptionalData,
                 prompt   = STRING_TOKEN(0x0063),
                 help     = STRING_TOKEN(0x0002),
                 minsize  = 0,
                 maxsize  = 120,
       endstring;

       checkbox varid    = FeData.ForceReconnect,
               prompt   = STRING_TOKEN(0x0031),
               help     = STRING_TOKEN(0x0031),
               flags    = CHECKBOX_DEFAULT,
               key      = 0,
       endcheckbox;

       subtitle text = STRING_TOKEN(0x0002);

       text
         help   = STRING_TOKEN(0x0032),
         text   = STRING_TOKEN(0x0032),
         text   = STRING_TOKEN(0x0002),
         flags  = INTERACTIVE,
         key    = 0x1002;  

       text
         help   = STRING_TOKEN(0x0033),
         text   = STRING_TOKEN(0x0033),
         text   = STRING_TOKEN(0x0002),
         flags  = INTERACTIVE,
         key    = 0x1003;

  endform;

endformset;
