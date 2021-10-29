/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_80B92017_EC64_4923_938D_94FAEE85832E
#define _AUTOGENH_80B92017_EC64_4923_938D_94FAEE85832E

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <PiDxe.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;


// PCD definitions
#define _PCD_TOKEN_PcdBrowserSubtitleTextColor  144U
extern const UINT8 _gPcd_FixedAtBuild_PcdBrowserSubtitleTextColor;
#define _PCD_GET_MODE_8_PcdBrowserSubtitleTextColor  _gPcd_FixedAtBuild_PcdBrowserSubtitleTextColor
//#define _PCD_SET_MODE_8_PcdBrowserSubtitleTextColor  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdBrowserFieldTextColor  145U
extern const UINT8 _gPcd_FixedAtBuild_PcdBrowserFieldTextColor;
#define _PCD_GET_MODE_8_PcdBrowserFieldTextColor  _gPcd_FixedAtBuild_PcdBrowserFieldTextColor
//#define _PCD_SET_MODE_8_PcdBrowserFieldTextColor  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdBrowserFieldTextHighlightColor  146U
extern const UINT8 _gPcd_FixedAtBuild_PcdBrowserFieldTextHighlightColor;
#define _PCD_GET_MODE_8_PcdBrowserFieldTextHighlightColor  _gPcd_FixedAtBuild_PcdBrowserFieldTextHighlightColor
//#define _PCD_SET_MODE_8_PcdBrowserFieldTextHighlightColor  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdBrowserFieldBackgroundHighlightColor  147U
extern const UINT8 _gPcd_FixedAtBuild_PcdBrowserFieldBackgroundHighlightColor;
#define _PCD_GET_MODE_8_PcdBrowserFieldBackgroundHighlightColor  _gPcd_FixedAtBuild_PcdBrowserFieldBackgroundHighlightColor
//#define _PCD_SET_MODE_8_PcdBrowserFieldBackgroundHighlightColor  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

EFI_STATUS
EFIAPI
CustomizedDisplayLibConstructor (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

EFI_STATUS
EFIAPI
CustomizedDisplayLibDestructor (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );
#include "CustomizedDisplayLibStrDefs.h"


#ifdef __cplusplus
}
#endif

#endif
