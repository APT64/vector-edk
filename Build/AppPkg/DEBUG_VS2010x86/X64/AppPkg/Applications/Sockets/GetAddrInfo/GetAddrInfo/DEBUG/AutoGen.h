/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_4C26DF71_EBE7_4dea_B5E2_0B5980433908
#define _AUTOGENH_4C26DF71_EBE7_4dea_B5E2_0B5980433908

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Uefi.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x4C26DF71, 0xEBE7, 0x4dea, {0xB5, 0xE2, 0x0B, 0x59, 0x80, 0x43, 0x39, 0x08}}

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
ShellCEntryLib (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
