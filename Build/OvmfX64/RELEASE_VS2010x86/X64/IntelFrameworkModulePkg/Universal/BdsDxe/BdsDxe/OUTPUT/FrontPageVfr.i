#line 1 "c:\\vector-edk-master\\IntelFrameworkModulePkg\\Universal\\BdsDxe\\FrontPageVfr.Vfr"
#line 1 "c:\\vector-edk-master\\Build\\OvmfX64\\RELEASE_VS2010x86\\X64\\IntelFrameworkModulePkg\\Universal\\BdsDxe\\BdsDxe\\DEBUG\\BdsDxeStrDefs.h"




























































































































































































































extern unsigned char BdsDxeStrings[];




#line 227 "c:\\vector-edk-master\\Build\\OvmfX64\\RELEASE_VS2010x86\\X64\\IntelFrameworkModulePkg\\Universal\\BdsDxe\\BdsDxe\\DEBUG\\BdsDxeStrDefs.h"
#line 1 "c:\\vector-edk-master\\IntelFrameworkModulePkg\\Universal\\BdsDxe\\FrontPageVfr.Vfr"















#line 1 "c:\\vector-edk-master\\IntelFrameworkModulePkg\\Include\\Guid/BdsHii.h"















































extern EFI_GUID gFrontPageFormSetGuid;
extern EFI_GUID gBootMaintFormSetGuid;
extern EFI_GUID gFileExploreFormSetGuid;
extern EFI_GUID gBootManagerFormSetGuid;
extern EFI_GUID gDeviceManagerFormSetGuid;
extern EFI_GUID gDriverHealthFormSetGuid;

#line 56 "c:\\vector-edk-master\\IntelFrameworkModulePkg\\Include\\Guid/BdsHii.h"
#line 17 "c:\\vector-edk-master\\IntelFrameworkModulePkg\\Universal\\BdsDxe\\FrontPageVfr.Vfr"






















formset
  guid     = { 0x9e0c30bc, 0x3f06, 0x4ba6, {0x82, 0x88, 0x9, 0x17, 0x9b, 0x85, 0x5d, 0xbe} },
  title    = STRING_TOKEN(0x008E),
  help     = STRING_TOKEN(0x0002),
  classguid = { 0x9e0c30bc, 0x3f06, 0x4ba6, {0x82, 0x88, 0x9, 0x17, 0x9b, 0x85, 0x5d, 0xbe} },
  class    = 0x0000,
  subclass = 0x0002,

  form formid = 0x1000,
       title  = STRING_TOKEN(0x008E);

    banner
      title = STRING_TOKEN(0x008F),
      line  1,
      align left;

    banner
      title = STRING_TOKEN(0x0090),
      line  2,
      align left;

    banner
      title = STRING_TOKEN(0x0091),
      line  2,
      align right;

    banner
      title = STRING_TOKEN(0x0093),
      line  3,
      align left;

    banner
      title = STRING_TOKEN(0x0092),
      line  3,
      align right;
































    text
      help    = STRING_TOKEN(0x009B),
      text    = STRING_TOKEN(0x009A),
      text    = STRING_TOKEN(0x0002),
      flags   = INTERACTIVE,
      key     = 0x1000;

    label 0x1000;
    
    
    
    
    label 0xffff;

    goto 0x0003,
      prompt  = STRING_TOKEN(0x009E),
      help    = STRING_TOKEN(0x009F),
      flags   = INTERACTIVE,
      key     = 0x1064;

    goto 0x0004,
      prompt  = STRING_TOKEN(0x00A2),
      help    = STRING_TOKEN(0x00A3),
      flags   = INTERACTIVE,
      key     = 0x8567;

    goto 0x0005,
      prompt  = STRING_TOKEN(0x00A0),
      help    = STRING_TOKEN(0x00A1),
      flags   = INTERACTIVE,
      key     = 0x9876;

  endform;

endformset;
