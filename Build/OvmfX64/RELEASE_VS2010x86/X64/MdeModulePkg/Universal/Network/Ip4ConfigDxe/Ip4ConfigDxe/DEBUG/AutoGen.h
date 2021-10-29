/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_26841BDE_920A_4e7a_9FBE_637F477143A6
#define _AUTOGENH_26841BDE_920A_4e7a_9FBE_637F477143A6

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Uefi.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x26841BDE, 0x920A, 0x4e7a, {0x9F, 0xBE, 0x63, 0x7F, 0x47, 0x71, 0x43, 0xA6}}

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
Ip4ConfigDriverEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );



EFI_STATUS
EFIAPI
NetLibDefaultUnload (
  IN EFI_HANDLE        ImageHandle
  );

#include "Ip4ConfigDxeStrDefs.h"


#ifdef __cplusplus
}
#endif

#endif
