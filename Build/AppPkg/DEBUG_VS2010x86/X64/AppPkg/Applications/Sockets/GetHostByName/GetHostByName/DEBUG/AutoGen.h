/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_70FB9CE0_2CB1_4fd7_80EE_AB4B6CF4B43F
#define _AUTOGENH_70FB9CE0_2CB1_4fd7_80EE_AB4B6CF4B43F

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Uefi.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x70FB9CE0, 0x2CB1, 0x4fd7, {0x80, 0xEE, 0xAB, 0x4B, 0x6C, 0xF4, 0xB4, 0x3F}}

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
