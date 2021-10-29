/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_240612B5_A063_11d4_9A3A_0090273FC14D
#define _AUTOGENH_240612B5_A063_11d4_9A3A_0090273FC14D

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Uefi.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x240612B5, 0xA063, 0x11d4, {0x9A, 0x3A, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D}}

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdIsaBusSupportedFeatures  155U
#define _PCD_VALUE_PcdIsaBusSupportedFeatures  0x05U
extern const  UINT8  _gPcd_FixedAtBuild_PcdIsaBusSupportedFeatures;
#define _PCD_GET_MODE_8_PcdIsaBusSupportedFeatures  _gPcd_FixedAtBuild_PcdIsaBusSupportedFeatures
//#define _PCD_SET_MODE_8_PcdIsaBusSupportedFeatures  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
InitializeIsaBus (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
