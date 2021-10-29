/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_FEDE0A1B_BCA2_4A9F_BB2B_D9FD7DEC2E9F
#define _AUTOGENH_FEDE0A1B_BCA2_4A9F_BB2B_D9FD7DEC2E9F

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <PiDxe.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0xFEDE0A1B, 0xBCA2, 0x4A9F, {0xBB, 0x2B, 0xD9, 0xFD, 0x7D, 0xEC, 0x2E, 0x9F}}

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdStatusCodeReplayIn  73U
#define _PCD_VALUE_PcdStatusCodeReplayIn  ((BOOLEAN)0U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdStatusCodeReplayIn;
#define _PCD_GET_MODE_BOOL_PcdStatusCodeReplayIn  _gPcd_FixedAtBuild_PcdStatusCodeReplayIn
//#define _PCD_SET_MODE_BOOL_PcdStatusCodeReplayIn  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStatusCodeUseOEM  46U
#define _PCD_VALUE_PcdStatusCodeUseOEM  ((BOOLEAN)0U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdStatusCodeUseOEM;
#define _PCD_GET_MODE_BOOL_PcdStatusCodeUseOEM  _gPcd_FixedAtBuild_PcdStatusCodeUseOEM
//#define _PCD_SET_MODE_BOOL_PcdStatusCodeUseOEM  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStatusCodeUseDataHub  74U
#define _PCD_VALUE_PcdStatusCodeUseDataHub  ((BOOLEAN)0U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdStatusCodeUseDataHub;
#define _PCD_GET_MODE_BOOL_PcdStatusCodeUseDataHub  _gPcd_FixedAtBuild_PcdStatusCodeUseDataHub
//#define _PCD_SET_MODE_BOOL_PcdStatusCodeUseDataHub  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStatusCodeUseMemory  47U
#define _PCD_VALUE_PcdStatusCodeUseMemory  ((BOOLEAN)1U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdStatusCodeUseMemory;
#define _PCD_GET_MODE_BOOL_PcdStatusCodeUseMemory  _gPcd_FixedAtBuild_PcdStatusCodeUseMemory
//#define _PCD_SET_MODE_BOOL_PcdStatusCodeUseMemory  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStatusCodeUseSerial  48U
#define _PCD_VALUE_PcdStatusCodeUseSerial  ((BOOLEAN)0U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdStatusCodeUseSerial;
#define _PCD_GET_MODE_BOOL_PcdStatusCodeUseSerial  _gPcd_FixedAtBuild_PcdStatusCodeUseSerial
//#define _PCD_SET_MODE_BOOL_PcdStatusCodeUseSerial  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStatusCodeMemorySize  49U
#define _PCD_VALUE_PcdStatusCodeMemorySize  1U
extern const  UINT16  _gPcd_FixedAtBuild_PcdStatusCodeMemorySize;
#define _PCD_GET_MODE_16_PcdStatusCodeMemorySize  _gPcd_FixedAtBuild_PcdStatusCodeMemorySize
//#define _PCD_SET_MODE_16_PcdStatusCodeMemorySize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
StatusCodeRuntimeDxeEntry (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
