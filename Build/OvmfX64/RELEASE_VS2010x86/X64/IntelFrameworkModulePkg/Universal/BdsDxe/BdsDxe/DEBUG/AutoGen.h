/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_FC5C7020_1A48_4198_9BE2_EAD5ABC8CF2F
#define _AUTOGENH_FC5C7020_1A48_4198_9BE2_EAD5ABC8CF2F

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <PiDxe.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0xFC5C7020, 0x1A48, 0x4198, {0x9B, 0xE2, 0xEA, 0xD5, 0xAB, 0xC8, 0xCF, 0x2F}}

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdUefiVariableDefaultLangDeprecate  85U
#define _PCD_VALUE_PcdUefiVariableDefaultLangDeprecate  ((BOOLEAN)0U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdUefiVariableDefaultLangDeprecate;
#define _PCD_GET_MODE_BOOL_PcdUefiVariableDefaultLangDeprecate  _gPcd_FixedAtBuild_PcdUefiVariableDefaultLangDeprecate
//#define _PCD_SET_MODE_BOOL_PcdUefiVariableDefaultLangDeprecate  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdUgaConsumeSupport  70U
#define _PCD_VALUE_PcdUgaConsumeSupport  ((BOOLEAN)1U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdUgaConsumeSupport;
#define _PCD_GET_MODE_BOOL_PcdUgaConsumeSupport  _gPcd_FixedAtBuild_PcdUgaConsumeSupport
//#define _PCD_SET_MODE_BOOL_PcdUgaConsumeSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdBootlogoOnlyEnable  86U
#define _PCD_VALUE_PcdBootlogoOnlyEnable  ((BOOLEAN)0U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdBootlogoOnlyEnable;
#define _PCD_GET_MODE_BOOL_PcdBootlogoOnlyEnable  _gPcd_FixedAtBuild_PcdBootlogoOnlyEnable
//#define _PCD_SET_MODE_BOOL_PcdBootlogoOnlyEnable  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdUefiVariableDefaultLangCodes  87U
#define _PCD_PATCHABLE_PcdUefiVariableDefaultLangCodes_SIZE 13
#define _PCD_VALUE_PcdUefiVariableDefaultLangCodes  _gPcd_FixedAtBuild_PcdUefiVariableDefaultLangCodes
extern const UINT8 _gPcd_FixedAtBuild_PcdUefiVariableDefaultLangCodes[13];
#define _PCD_GET_MODE_PTR_PcdUefiVariableDefaultLangCodes  _gPcd_FixedAtBuild_PcdUefiVariableDefaultLangCodes
//#define _PCD_SET_MODE_PTR_PcdUefiVariableDefaultLangCodes  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdUefiVariableDefaultLang  88U
#define _PCD_PATCHABLE_PcdUefiVariableDefaultLang_SIZE 4
#define _PCD_VALUE_PcdUefiVariableDefaultLang  _gPcd_FixedAtBuild_PcdUefiVariableDefaultLang
extern const UINT8 _gPcd_FixedAtBuild_PcdUefiVariableDefaultLang[4];
#define _PCD_GET_MODE_PTR_PcdUefiVariableDefaultLang  _gPcd_FixedAtBuild_PcdUefiVariableDefaultLang
//#define _PCD_SET_MODE_PTR_PcdUefiVariableDefaultLang  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdUefiVariableDefaultPlatformLangCodes  89U
#define _PCD_PATCHABLE_PcdUefiVariableDefaultPlatformLangCodes_SIZE 18
#define _PCD_VALUE_PcdUefiVariableDefaultPlatformLangCodes  _gPcd_FixedAtBuild_PcdUefiVariableDefaultPlatformLangCodes
extern const UINT8 _gPcd_FixedAtBuild_PcdUefiVariableDefaultPlatformLangCodes[18];
#define _PCD_GET_MODE_PTR_PcdUefiVariableDefaultPlatformLangCodes  _gPcd_FixedAtBuild_PcdUefiVariableDefaultPlatformLangCodes
//#define _PCD_SET_MODE_PTR_PcdUefiVariableDefaultPlatformLangCodes  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdUefiVariableDefaultPlatformLang  90U
#define _PCD_PATCHABLE_PcdUefiVariableDefaultPlatformLang_SIZE 6
#define _PCD_VALUE_PcdUefiVariableDefaultPlatformLang  _gPcd_FixedAtBuild_PcdUefiVariableDefaultPlatformLang
extern const UINT8 _gPcd_FixedAtBuild_PcdUefiVariableDefaultPlatformLang[6];
#define _PCD_GET_MODE_PTR_PcdUefiVariableDefaultPlatformLang  _gPcd_FixedAtBuild_PcdUefiVariableDefaultPlatformLang
//#define _PCD_SET_MODE_PTR_PcdUefiVariableDefaultPlatformLang  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdHardwareErrorRecordLevel  3U
#define _PCD_GET_MODE_16_PcdHardwareErrorRecordLevel  LibPcdGet16(_PCD_TOKEN_PcdHardwareErrorRecordLevel)
#define _PCD_SET_MODE_16_PcdHardwareErrorRecordLevel(Value)  LibPcdSet16(_PCD_TOKEN_PcdHardwareErrorRecordLevel, (Value))

#define _PCD_TOKEN_PcdConOutRow  91U
#define _PCD_PATCHABLE_VALUE_PcdConOutRow  ((UINT32)25U)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdConOutRow;
#define _PCD_GET_MODE_32_PcdConOutRow  _gPcd_BinaryPatch_PcdConOutRow
#define _PCD_SET_MODE_32_PcdConOutRow(Value)  (_gPcd_BinaryPatch_PcdConOutRow = (Value))

#define _PCD_TOKEN_PcdConOutColumn  92U
#define _PCD_PATCHABLE_VALUE_PcdConOutColumn  ((UINT32)80U)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdConOutColumn;
#define _PCD_GET_MODE_32_PcdConOutColumn  _gPcd_BinaryPatch_PcdConOutColumn
#define _PCD_SET_MODE_32_PcdConOutColumn(Value)  (_gPcd_BinaryPatch_PcdConOutColumn = (Value))

#define _PCD_TOKEN_PcdPlatformBootTimeOut  4U
#define _PCD_GET_MODE_16_PcdPlatformBootTimeOut  LibPcdGet16(_PCD_TOKEN_PcdPlatformBootTimeOut)
#define _PCD_SET_MODE_16_PcdPlatformBootTimeOut(Value)  LibPcdSet16(_PCD_TOKEN_PcdPlatformBootTimeOut, (Value))

#define _PCD_TOKEN_PcdBootState  5U
#define _PCD_GET_MODE_BOOL_PcdBootState  LibPcdGetBool(_PCD_TOKEN_PcdBootState)
#define _PCD_SET_MODE_BOOL_PcdBootState(Value)  LibPcdSetBool(_PCD_TOKEN_PcdBootState, (Value))

#define _PCD_TOKEN_PcdFirmwareVendor  93U
#define _PCD_PATCHABLE_PcdFirmwareVendor_SIZE 14
#define _PCD_VALUE_PcdFirmwareVendor  _gPcd_FixedAtBuild_PcdFirmwareVendor
extern const UINT16 _gPcd_FixedAtBuild_PcdFirmwareVendor[7];
#define _PCD_GET_MODE_PTR_PcdFirmwareVendor  _gPcd_FixedAtBuild_PcdFirmwareVendor
//#define _PCD_SET_MODE_PTR_PcdFirmwareVendor  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFirmwareRevision  94U
#define _PCD_VALUE_PcdFirmwareRevision  0x00010000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdFirmwareRevision;
#define _PCD_GET_MODE_32_PcdFirmwareRevision  _gPcd_FixedAtBuild_PcdFirmwareRevision
//#define _PCD_SET_MODE_32_PcdFirmwareRevision  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdVideoHorizontalResolution  95U
#define _PCD_PATCHABLE_VALUE_PcdVideoHorizontalResolution  ((UINT32)800U)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdVideoHorizontalResolution;
#define _PCD_GET_MODE_32_PcdVideoHorizontalResolution  _gPcd_BinaryPatch_PcdVideoHorizontalResolution
#define _PCD_SET_MODE_32_PcdVideoHorizontalResolution(Value)  (_gPcd_BinaryPatch_PcdVideoHorizontalResolution = (Value))

#define _PCD_TOKEN_PcdVideoVerticalResolution  96U
#define _PCD_PATCHABLE_VALUE_PcdVideoVerticalResolution  ((UINT32)600U)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdVideoVerticalResolution;
#define _PCD_GET_MODE_32_PcdVideoVerticalResolution  _gPcd_BinaryPatch_PcdVideoVerticalResolution
#define _PCD_SET_MODE_32_PcdVideoVerticalResolution(Value)  (_gPcd_BinaryPatch_PcdVideoVerticalResolution = (Value))

#define _PCD_TOKEN_PcdConInConnectOnDemand  97U
#define _PCD_VALUE_PcdConInConnectOnDemand  0U
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdConInConnectOnDemand;
#define _PCD_GET_MODE_BOOL_PcdConInConnectOnDemand  _gPcd_FixedAtBuild_PcdConInConnectOnDemand
//#define _PCD_SET_MODE_BOOL_PcdConInConnectOnDemand  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSetupConOutColumn  98U
#define _PCD_PATCHABLE_VALUE_PcdSetupConOutColumn  ((UINT32)80U)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdSetupConOutColumn;
#define _PCD_GET_MODE_32_PcdSetupConOutColumn  _gPcd_BinaryPatch_PcdSetupConOutColumn
#define _PCD_SET_MODE_32_PcdSetupConOutColumn(Value)  (_gPcd_BinaryPatch_PcdSetupConOutColumn = (Value))

#define _PCD_TOKEN_PcdSetupConOutRow  99U
#define _PCD_PATCHABLE_VALUE_PcdSetupConOutRow  ((UINT32)25U)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdSetupConOutRow;
#define _PCD_GET_MODE_32_PcdSetupConOutRow  _gPcd_BinaryPatch_PcdSetupConOutRow
#define _PCD_SET_MODE_32_PcdSetupConOutRow(Value)  (_gPcd_BinaryPatch_PcdSetupConOutRow = (Value))

#define _PCD_TOKEN_PcdSetupVideoHorizontalResolution  100U
#define _PCD_PATCHABLE_VALUE_PcdSetupVideoHorizontalResolution  ((UINT32)800U)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdSetupVideoHorizontalResolution;
#define _PCD_GET_MODE_32_PcdSetupVideoHorizontalResolution  _gPcd_BinaryPatch_PcdSetupVideoHorizontalResolution
#define _PCD_SET_MODE_32_PcdSetupVideoHorizontalResolution(Value)  (_gPcd_BinaryPatch_PcdSetupVideoHorizontalResolution = (Value))

#define _PCD_TOKEN_PcdSetupVideoVerticalResolution  101U
#define _PCD_PATCHABLE_VALUE_PcdSetupVideoVerticalResolution  ((UINT32)600U)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdSetupVideoVerticalResolution;
#define _PCD_GET_MODE_32_PcdSetupVideoVerticalResolution  _gPcd_BinaryPatch_PcdSetupVideoVerticalResolution
#define _PCD_SET_MODE_32_PcdSetupVideoVerticalResolution(Value)  (_gPcd_BinaryPatch_PcdSetupVideoVerticalResolution = (Value))

#define _PCD_TOKEN_PcdShellFile  102U
#define _PCD_PATCHABLE_PcdShellFile_SIZE 16
#define _PCD_VALUE_PcdShellFile  (VOID *)_gPcd_FixedAtBuild_PcdShellFile
extern const UINT8 _gPcd_FixedAtBuild_PcdShellFile[16];
#define _PCD_GET_MODE_PTR_PcdShellFile  (VOID *)_gPcd_FixedAtBuild_PcdShellFile
//#define _PCD_SET_MODE_PTR_PcdShellFile  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
BdsInitialize (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );



#include "BdsDxeStrDefs.h"


#ifdef __cplusplus
}
#endif

#endif
