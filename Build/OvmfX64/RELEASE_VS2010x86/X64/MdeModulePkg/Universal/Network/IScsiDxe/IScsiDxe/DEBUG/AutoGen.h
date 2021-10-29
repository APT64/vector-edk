/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_4579B72D_7EC4_4dd4_8486_083C86B182A7
#define _AUTOGENH_4579B72D_7EC4_4dd4_8486_083C86B182A7

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Uefi.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x4579B72D, 0x7EC4, 0x4dd4, {0x84, 0x86, 0x08, 0x3C, 0x86, 0xB1, 0x82, 0xA7}}

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
IScsiDriverEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );



EFI_STATUS
EFIAPI
EfiIScsiUnload (
  IN EFI_HANDLE        ImageHandle
  );

#include "IScsi4DxeStrDefs.h"


#ifdef __cplusplus
}
#endif

#endif
