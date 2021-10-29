/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_83381B06_2EEA_4cf3_9B5F_D75B9B5C93DE
#define _AUTOGENH_83381B06_2EEA_4cf3_9B5F_D75B9B5C93DE

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Uefi.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x83381B06, 0x2EEA, 0x4cf3, {0x9B, 0x5F, 0xD7, 0x5B, 0x9B, 0x5C, 0x93, 0xDE}}

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
