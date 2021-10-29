/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_F844172E_9985_44f2_BADE_0DD783462E95
#define _AUTOGENH_F844172E_9985_44f2_BADE_0DD783462E95

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <PiDxe.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;


// PCD definitions
#define _PCD_TOKEN_PcdPlatformBootTimeOut  4U
#define _PCD_GET_MODE_16_PcdPlatformBootTimeOut  LibPcdGet16(_PCD_TOKEN_PcdPlatformBootTimeOut)
#define _PCD_SET_MODE_16_PcdPlatformBootTimeOut(Value)  LibPcdSet16(_PCD_TOKEN_PcdPlatformBootTimeOut, (Value))
#define _PCD_TOKEN_PcdLogoFile  107U
extern const VOID* _gPcd_FixedAtBuild_PcdLogoFile[];
#define _PCD_GET_MODE_PTR_PcdLogoFile  (VOID *)_gPcd_FixedAtBuild_PcdLogoFile
//#define _PCD_SET_MODE_PTR_PcdLogoFile  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdEmuVariableEvent  6U
#define _PCD_GET_MODE_64_PcdEmuVariableEvent  LibPcdGet64(_PCD_TOKEN_PcdEmuVariableEvent)
#define _PCD_SET_MODE_64_PcdEmuVariableEvent(Value)  LibPcdSet64(_PCD_TOKEN_PcdEmuVariableEvent, (Value))
#define _PCD_TOKEN_PcdOvmfFlashVariablesEnable  7U
#define _PCD_GET_MODE_BOOL_PcdOvmfFlashVariablesEnable  LibPcdGetBool(_PCD_TOKEN_PcdOvmfFlashVariablesEnable)
#define _PCD_SET_MODE_BOOL_PcdOvmfFlashVariablesEnable(Value)  LibPcdSetBool(_PCD_TOKEN_PcdOvmfFlashVariablesEnable, (Value))
#define _PCD_TOKEN_PcdFSBClock  108U
extern const UINT32 _gPcd_FixedAtBuild_PcdFSBClock;
#define _PCD_GET_MODE_32_PcdFSBClock  _gPcd_FixedAtBuild_PcdFSBClock
//#define _PCD_SET_MODE_32_PcdFSBClock  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD


#ifdef __cplusplus
}
#endif

#endif
