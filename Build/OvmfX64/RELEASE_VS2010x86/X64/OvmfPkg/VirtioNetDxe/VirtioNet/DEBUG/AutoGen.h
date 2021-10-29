/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_A92CDB4B_82F1_4E0B_A516_8A655D371524
#define _AUTOGENH_A92CDB4B_82F1_4E0B_A516_8A655D371524

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Uefi.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0xA92CDB4B, 0x82F1, 0x4E0B, {0xA5, 0x16, 0x8A, 0x65, 0x5D, 0x37, 0x15, 0x24}}

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
VirtioNetEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
