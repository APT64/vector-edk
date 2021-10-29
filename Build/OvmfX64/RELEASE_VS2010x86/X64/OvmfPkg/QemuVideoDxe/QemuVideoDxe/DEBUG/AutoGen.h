/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_e3752948_b9a1_4770_90c4_df41c38986be
#define _AUTOGENH_e3752948_b9a1_4770_90c4_df41c38986be

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Uefi.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0xe3752948, 0xb9a1, 0x4770, {0x90, 0xc4, 0xdf, 0x41, 0xc3, 0x89, 0x86, 0xbe}}

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdDriverSupportedEfiVersion  148U
#define _PCD_VALUE_PcdDriverSupportedEfiVersion  0x0002000aU
extern const  UINT32  _gPcd_FixedAtBuild_PcdDriverSupportedEfiVersion;
#define _PCD_GET_MODE_32_PcdDriverSupportedEfiVersion  _gPcd_FixedAtBuild_PcdDriverSupportedEfiVersion
//#define _PCD_SET_MODE_32_PcdDriverSupportedEfiVersion  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
InitializeQemuVideo (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
