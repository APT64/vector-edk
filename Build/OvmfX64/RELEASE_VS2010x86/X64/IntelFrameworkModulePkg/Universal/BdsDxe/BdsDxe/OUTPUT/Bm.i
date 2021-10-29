#line 1 "c:\\vector-edk-master\\IntelFrameworkModulePkg\\Universal\\BdsDxe\\BootMaint\\Bm.vfr"
#line 1 "c:\\vector-edk-master\\Build\\OvmfX64\\RELEASE_VS2010x86\\X64\\IntelFrameworkModulePkg\\Universal\\BdsDxe\\BdsDxe\\DEBUG\\BdsDxeStrDefs.h"




























































































































































































































extern unsigned char BdsDxeStrings[];




#line 227 "c:\\vector-edk-master\\Build\\OvmfX64\\RELEASE_VS2010x86\\X64\\IntelFrameworkModulePkg\\Universal\\BdsDxe\\BdsDxe\\DEBUG\\BdsDxeStrDefs.h"
#line 1 "c:\\vector-edk-master\\IntelFrameworkModulePkg\\Universal\\BdsDxe\\BootMaint\\Bm.vfr"















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

#line 17 "c:\\vector-edk-master\\IntelFrameworkModulePkg\\Universal\\BdsDxe\\BootMaint\\Bm.vfr"

formset
  guid = { 0x642237c7, 0x35d4, 0x472d, {0x83, 0x65, 0x12, 0xe0, 0xcc, 0xf2, 0x7a, 0x22} },
  title = STRING_TOKEN(0x0004),
  help = STRING_TOKEN(0x0002),
  classguid = { 0x642237c7, 0x35d4, 0x472d, {0x83, 0x65, 0x12, 0xe0, 0xcc, 0xf2, 0x7a, 0x22} },
  class = 0,
  subclass = 0,

  varstore BMM_FAKE_NV_DATA,
    varid = 0x1000,
    name = BmmData,
    guid = { 0x642237c7, 0x35d4, 0x472d, {0x83, 0x65, 0x12, 0xe0, 0xcc, 0xf2, 0x7a, 0x22} };

  form formid = 0x1001,
       title = STRING_TOKEN(0x0004);

    goto 0x1014,
         prompt = STRING_TOKEN(0x0005),
         help = STRING_TOKEN(0x0006),
         flags = INTERACTIVE,
         key = 0x1014;

    subtitle text = STRING_TOKEN(0x0002);

    goto 0x1015,
         prompt = STRING_TOKEN(0x0007),
         help = STRING_TOKEN(0x0008),
         flags = INTERACTIVE,
         key = 0x1015;

    subtitle text = STRING_TOKEN(0x0002);

    goto 0x1008,
         prompt = STRING_TOKEN(0x0017),
         help = STRING_TOKEN(0x0018),
         flags = INTERACTIVE,
         key = 0x1008;

    subtitle text = STRING_TOKEN(0x0002);

    goto 0x1022,
         prompt = STRING_TOKEN(0x0061),
         help   = STRING_TOKEN(0x0062),
         flags = INTERACTIVE,
         key = 0x110D;

    subtitle text = STRING_TOKEN(0x0002);



    goto 0x1011,
         prompt = STRING_TOKEN(0x0013),
         help = STRING_TOKEN(0x0014),
         flags = INTERACTIVE,
         key = 0x1011;

    goto 0x1012,
         prompt = STRING_TOKEN(0x0015),
         help = STRING_TOKEN(0x0016),
         flags = INTERACTIVE,
         key = 0x1012;

    subtitle text = STRING_TOKEN(0x0002);

    text
         help   = STRING_TOKEN(0x005F),
         text   = STRING_TOKEN(0x005F),
         text   = STRING_TOKEN(0x0002),
         flags  = INTERACTIVE,
         key    = 0x1013;

  endform;

  form formid = 0x1014,
       title = STRING_TOKEN(0x0005);

       goto 0x1001,
            prompt = STRING_TOKEN(0x0060),
            help = STRING_TOKEN(0x0060);
            
            

       goto 0x1002,
            prompt = STRING_TOKEN(0x0009),
            help = STRING_TOKEN(0x000A),
            flags = INTERACTIVE,
            key = 0x1002;

       goto 0x1003,
            prompt = STRING_TOKEN(0x000B),
            help = STRING_TOKEN(0x000C),
            flags = INTERACTIVE,
            key = 0x1003;

       goto 0x1004,
            prompt = STRING_TOKEN(0x000D),
            help = STRING_TOKEN(0x000C),
            flags = INTERACTIVE,
            key = 0x1004;

       subtitle text = STRING_TOKEN(0x0002);
           
	   
	   
	   
       label 0x1016;
       label 0xffff;

  endform;

  form formid = 0x1015,
       title = STRING_TOKEN(0x0007);

       goto 0x1001,
            prompt = STRING_TOKEN(0x0060),
            help = STRING_TOKEN(0x0060);
            
            
            

       goto 0x1005,
            prompt = STRING_TOKEN(0x000E),
            help = STRING_TOKEN(0x000F),
            flags = INTERACTIVE,
            key = 0x1005;

       goto 0x1006,
            prompt = STRING_TOKEN(0x0010),
            help = STRING_TOKEN(0x0012),
            flags = INTERACTIVE,
            key = 0x1006;

       goto 0x1007,
            prompt = STRING_TOKEN(0x0011),
            help = STRING_TOKEN(0x0012),
            flags = INTERACTIVE,
            key = 0x1007;
  endform;

  form formid = 0x1003,
       title = STRING_TOKEN(0x000B);

       label 0x1003;
       label 0xffff;
  endform;

  form formid = 0x1004,
       title = STRING_TOKEN(0x000D);

       label 0x1004;
       label 0xffff;

  endform;

  form formid = 0x1011,
       title = STRING_TOKEN(0x0013);

       label 0x1011;
       label 0xffff;
  endform;

  form formid = 0x1012,
       title = STRING_TOKEN(0x0015);

       label 0x1012;
       label 0xffff;
  endform;

  form formid = 0x1005,
       title = STRING_TOKEN(0x000E);

       goto 0x1001,
            prompt = STRING_TOKEN(0x0060),
            help = STRING_TOKEN(0x0060);
            
            

       goto 0x100E,
            prompt = STRING_TOKEN(0x0028),
            help = STRING_TOKEN(0x0028),
            flags = INTERACTIVE,
            key = 0x100E;

  endform;

  form formid = 0x1006,
       title = STRING_TOKEN(0x0010);

       label 0x1006;
       label 0xffff;

  endform;

  form formid = 0x1007,
       title = STRING_TOKEN(0x0011);

       label 0x1007;
       label 0xffff;

  endform;

  form formid = 0x1008,
       title = STRING_TOKEN(0x0017);

       goto 0x1001,
       prompt = STRING_TOKEN(0x0060),
       help = STRING_TOKEN(0x0060);
       
       

       goto 0x1009,
       prompt = STRING_TOKEN(0x0019),
       help = STRING_TOKEN(0x001A),
       flags = INTERACTIVE,
       key = 0x1009;

       goto 0x100A,
       prompt = STRING_TOKEN(0x0020),
       help = STRING_TOKEN(0x0021),
       flags = INTERACTIVE,
       key = 0x100A;

       goto 0x100B,
       prompt = STRING_TOKEN(0x0022),
       help = STRING_TOKEN(0x0023),
       flags = INTERACTIVE,
       key = 0x100B;

       goto 0x1021,
       prompt = STRING_TOKEN(0x0024),
       help = STRING_TOKEN(0x0025),
       flags = INTERACTIVE,
       key = 0x1021;

       goto 0x1017,
       prompt = STRING_TOKEN(0x0026),
       help = STRING_TOKEN(0x0027),
       flags = INTERACTIVE,
       key = 0x1017;
  endform;

  form formid = 0x1021,
       title = STRING_TOKEN(0x0024);

       label 0x1021;
       label 0xffff;
  endform;

  form formid = 0x1017,
       title = STRING_TOKEN(0x0026);

       label 0x1017;
       label 0xffff;
  endform;

  form formid = 0x1018,
       title = STRING_TOKEN(0x0035);

       label 0x1018;
       label 0xffff;
  endform;

  form formid = 0x100C,
       title = STRING_TOKEN(0x0009);

       label 0x100C;
       label 0xffff;
  endform;

  form formid = 0x100D,
       title = STRING_TOKEN(0x0009);

       label 0x100D;
       label 0xffff;
  endform;

  form formid = 0x100F,
       title = STRING_TOKEN(0x0029);

       label 0x100F;
       label 0xffff;
  endform;

  form formid = 0x1010,
       title = STRING_TOKEN(0x002B);

       label 0x1010;
       label 0xffff;

  endform;

  form formid = 0x1009,
       title = STRING_TOKEN(0x0019);

       label 0x1009;
       label 0xffff;

  endform;

  form formid = 0x100A,
       title = STRING_TOKEN(0x0020);

       label 0x100A;
       label 0xffff;

  endform;

  form formid = 0x100B,
       title = STRING_TOKEN(0x0022);

       label 0x100B;
       label 0xffff;

  endform;

  form formid = 0x1019,
       title = STRING_TOKEN(0x001B);

       label 0x1019;
       label 0xffff;
  endform;

  form formid = 0x101A,
       title = STRING_TOKEN(0x001C);

       label 0x101A;
       label 0xffff;
  endform;

  form formid = 0x101B,
       title = STRING_TOKEN(0x001D);

       label 0x101B;
       label 0xffff;
  endform;

  form formid = 0x101C,
       title = STRING_TOKEN(0x001E);

       label 0x101C;
       label 0xffff;
  endform;

  form formid = 0x101D,
       title = STRING_TOKEN(0x001F);

       label 0x101D;
       label 0xffff;
  endform;

endformset;
