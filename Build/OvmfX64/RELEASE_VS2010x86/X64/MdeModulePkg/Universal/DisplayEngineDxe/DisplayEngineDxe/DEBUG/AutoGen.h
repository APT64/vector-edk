/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_E660EA85_058E_4b55_A54B_F02F83A24707
#define _AUTOGENH_E660EA85_058E_4b55_A54B_F02F83A24707

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <PiDxe.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0xE660EA85, 0x058E, 0x4b55, {0xA5, 0x4B, 0xF0, 0x2F, 0x83, 0xA2, 0x47, 0x07}}

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdBrowserGrayOutTextStatement  142U
#define _PCD_VALUE_PcdBrowserGrayOutTextStatement  ((BOOLEAN)0U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdBrowserGrayOutTextStatement;
#define _PCD_GET_MODE_BOOL_PcdBrowserGrayOutTextStatement  _gPcd_FixedAtBuild_PcdBrowserGrayOutTextStatement
//#define _PCD_SET_MODE_BOOL_PcdBrowserGrayOutTextStatement  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdBrowerGrayOutReadOnlyMenu  143U
#define _PCD_VALUE_PcdBrowerGrayOutReadOnlyMenu  ((BOOLEAN)0U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdBrowerGrayOutReadOnlyMenu;
#define _PCD_GET_MODE_BOOL_PcdBrowerGrayOutReadOnlyMenu  _gPcd_FixedAtBuild_PcdBrowerGrayOutReadOnlyMenu
//#define _PCD_SET_MODE_BOOL_PcdBrowerGrayOutReadOnlyMenu  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
InitializeDisplayEngine (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );



EFI_STATUS
EFIAPI
UnloadDisplayEngine (
  IN EFI_HANDLE        ImageHandle
  );

#include "DisplayEngineStrDefs.h"


#ifdef __cplusplus
}
#endif

#endif
