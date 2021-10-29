/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_E4F61863_FE2C_4b56_A8F4_08519BC439DF
#define _AUTOGENH_E4F61863_FE2C_4b56_A8F4_08519BC439DF

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Uefi.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0xE4F61863, 0xFE2C, 0x4b56, {0xA8, 0xF4, 0x08, 0x51, 0x9B, 0xC4, 0x39, 0xDF}}

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
VlanConfigDriverEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );



EFI_STATUS
EFIAPI
NetLibDefaultUnload (
  IN EFI_HANDLE        ImageHandle
  );

#include "VlanConfigDxeStrDefs.h"


#ifdef __cplusplus
}
#endif

#endif
