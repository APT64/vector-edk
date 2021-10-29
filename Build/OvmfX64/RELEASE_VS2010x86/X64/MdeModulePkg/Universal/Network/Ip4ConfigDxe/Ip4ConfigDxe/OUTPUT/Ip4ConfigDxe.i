#line 1 "c:\\vector-edk-master\\MdeModulePkg\\Universal\\Network\\Ip4ConfigDxe\\Ip4ConfigDxe.vfr"
#line 1 "c:\\vector-edk-master\\Build\\OvmfX64\\RELEASE_VS2010x86\\X64\\MdeModulePkg\\Universal\\Network\\Ip4ConfigDxe\\Ip4ConfigDxe\\DEBUG\\Ip4ConfigDxeStrDefs.h"






























extern unsigned char Ip4ConfigDxeStrings[];




#line 37 "c:\\vector-edk-master\\Build\\OvmfX64\\RELEASE_VS2010x86\\X64\\MdeModulePkg\\Universal\\Network\\Ip4ConfigDxe\\Ip4ConfigDxe\\DEBUG\\Ip4ConfigDxeStrDefs.h"
#line 1 "c:\\vector-edk-master\\MdeModulePkg\\Universal\\Network\\Ip4ConfigDxe\\Ip4ConfigDxe.vfr"













#line 1 "c:\\vector-edk-master\\mdemodulepkg\\universal\\network\\ip4configdxe\\Ip4NvData.h"

















#line 1 "c:\\vector-edk-master\\MdeModulePkg\\Include\\Guid/Ip4ConfigHii.h"






















extern EFI_GUID gNicIp4ConfigNvDataGuid;

#line 26 "c:\\vector-edk-master\\MdeModulePkg\\Include\\Guid/Ip4ConfigHii.h"
#line 19 "c:\\vector-edk-master\\mdemodulepkg\\universal\\network\\ip4configdxe\\Ip4NvData.h"




















typedef struct {
  UINT8           Configure;                         
  UINT8           DhcpEnable;                        
  CHAR16          StationAddress[16];  
  CHAR16          SubnetMask[16];      
  CHAR16          GatewayAddress[16];  
} IP4_CONFIG_IFR_NVDATA;

#line 48 "c:\\vector-edk-master\\mdemodulepkg\\universal\\network\\ip4configdxe\\Ip4NvData.h"

#line 15 "c:\\vector-edk-master\\MdeModulePkg\\Universal\\Network\\Ip4ConfigDxe\\Ip4ConfigDxe.vfr"



formset
  guid     = { 0x9d5b53f, 0xf4b0, 0x4f59, { 0xa0, 0xb1, 0x7b, 0x57, 0xd3, 0x5c, 0xe, 0x5 } },
  title    = STRING_TOKEN(0x0002),
  help     = STRING_TOKEN(0x0003),
  class    = 0x04,
  subclass = 0x03,

  varstore IP4_CONFIG_IFR_NVDATA,
    name = EfiNicIp4ConfigVariable,
    guid = { 0x9d5b53f, 0xf4b0, 0x4f59, { 0xa0, 0xb1, 0x7b, 0x57, 0xd3, 0x5c, 0xe, 0x5 } };

  form formid = 1,
    title  = STRING_TOKEN(0x0004);

    checkbox varid = EfiNicIp4ConfigVariable.Configure,
            prompt = STRING_TOKEN(0x0006),
            help   = STRING_TOKEN(0x0006),
            flags  = INTERACTIVE,
            key    = 0x100,
    endcheckbox;

    suppressif ideqval EfiNicIp4ConfigVariable.Configure == 0x00;

      checkbox varid = EfiNicIp4ConfigVariable.DhcpEnable,
              prompt = STRING_TOKEN(0x0007),
              help   = STRING_TOKEN(0x0007),
              flags  = INTERACTIVE,
              key    = 0x101,
      endcheckbox;
    endif;

    suppressif ideqval EfiNicIp4ConfigVariable.DhcpEnable == 0x01 OR ideqval EfiNicIp4ConfigVariable.Configure == 0x00;

      string  varid   = EfiNicIp4ConfigVariable.StationAddress,
              prompt  = STRING_TOKEN(0x0008),
              help    = STRING_TOKEN(0x000B),
              flags   = INTERACTIVE,
              key     = 0x102,
              minsize = 7,
              maxsize = 15,
      endstring;

      string  varid   = EfiNicIp4ConfigVariable.SubnetMask,
              prompt  = STRING_TOKEN(0x0009),
              help    = STRING_TOKEN(0x000B),
              flags   = INTERACTIVE,
              key     = 0x103,
              minsize = 7,
             maxsize = 15,
      endstring;

      string  varid   = EfiNicIp4ConfigVariable.GatewayAddress,
              prompt  = STRING_TOKEN(0x000A),
              help    = STRING_TOKEN(0x000B),
              flags   = INTERACTIVE,
              key     = 0x104,
              minsize = 7,
              maxsize = 15,
      endstring;

    endif;

    subtitle text = STRING_TOKEN(0x000D);
    
    text
      help   = STRING_TOKEN(0x000C),
      text   = STRING_TOKEN(0x000C),
        text   = STRING_TOKEN(0x000C),
      flags  = INTERACTIVE,
      key    = 0x105;
      
  endform;

endformset;

