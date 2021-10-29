/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_11D92DFB_3CA9_4F93_BA2E_4780ED3E03B5
#define _AUTOGENH_11D92DFB_3CA9_4F93_BA2E_4780ED3E03B5

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Uefi.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x11D92DFB, 0x3CA9, 0x4F93, {0xBA, 0x2E, 0x47, 0x80, 0xED, 0x3E, 0x03, 0xB5}}

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
VirtioBlkEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
