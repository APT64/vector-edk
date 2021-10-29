/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_33cb97af_6c33_4c42_986b_07581fa366d4
#define _AUTOGENH_33cb97af_6c33_4c42_986b_07581fa366d4

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Uefi.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x33cb97af, 0x6c33, 0x4c42, {0x98, 0x6b, 0x07, 0x58, 0x1f, 0xa3, 0x66, 0xd4}}

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
BlockMmioToBlockIoEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
