/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_FAB5D4F4_83C0_4AAF_8480_442D11DF6CEA
#define _AUTOGENH_FAB5D4F4_83C0_4AAF_8480_442D11DF6CEA

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Uefi.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0xFAB5D4F4, 0x83C0, 0x4AAF, {0x84, 0x80, 0x44, 0x2D, 0x11, 0xDF, 0x6C, 0xEA}}

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdVirtioScsiMaxTargetLimit  109U
#define _PCD_VALUE_PcdVirtioScsiMaxTargetLimit  31U
extern const  UINT16  _gPcd_FixedAtBuild_PcdVirtioScsiMaxTargetLimit;
#define _PCD_GET_MODE_16_PcdVirtioScsiMaxTargetLimit  _gPcd_FixedAtBuild_PcdVirtioScsiMaxTargetLimit
//#define _PCD_SET_MODE_16_PcdVirtioScsiMaxTargetLimit  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdVirtioScsiMaxLunLimit  110U
#define _PCD_VALUE_PcdVirtioScsiMaxLunLimit  7U
extern const  UINT32  _gPcd_FixedAtBuild_PcdVirtioScsiMaxLunLimit;
#define _PCD_GET_MODE_32_PcdVirtioScsiMaxLunLimit  _gPcd_FixedAtBuild_PcdVirtioScsiMaxLunLimit
//#define _PCD_SET_MODE_32_PcdVirtioScsiMaxLunLimit  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
VirtioScsiEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
