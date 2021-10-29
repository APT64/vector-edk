/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_69FD8E47_A161_4550_B01A_5594CEB2B2B2
#define _AUTOGENH_69FD8E47_A161_4550_B01A_5594CEB2B2B2

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Uefi.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x69FD8E47, 0xA161, 0x4550, {0xB0, 0x1A, 0x55, 0x94, 0xCE, 0xB2, 0xB2, 0xB2}}

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
InitializeIdeBus (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
