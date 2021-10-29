/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_3DC82376_637B_40a6_A8FC_A565417F2C38
#define _AUTOGENH_3DC82376_637B_40a6_A8FC_A565417F2C38

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Uefi.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x3DC82376, 0x637B, 0x40a6, {0xA8, 0xFC, 0xA5, 0x65, 0x41, 0x7F, 0x2C, 0x38}}

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdPs2KbdExtendedVerification  161U
#define _PCD_VALUE_PcdPs2KbdExtendedVerification  ((BOOLEAN)1U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdPs2KbdExtendedVerification;
#define _PCD_GET_MODE_BOOL_PcdPs2KbdExtendedVerification  _gPcd_FixedAtBuild_PcdPs2KbdExtendedVerification
//#define _PCD_SET_MODE_BOOL_PcdPs2KbdExtendedVerification  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFastPS2Detection  162U
#define _PCD_VALUE_PcdFastPS2Detection  0U
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdFastPS2Detection;
#define _PCD_GET_MODE_BOOL_PcdFastPS2Detection  _gPcd_FixedAtBuild_PcdFastPS2Detection
//#define _PCD_SET_MODE_BOOL_PcdFastPS2Detection  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
InitializePs2Keyboard (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
