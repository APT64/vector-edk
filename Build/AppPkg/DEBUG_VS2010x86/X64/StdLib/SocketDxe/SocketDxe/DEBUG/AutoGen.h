/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_2A43BA5F_AC29_4fdc_8A3B_0328D0256F8C
#define _AUTOGENH_2A43BA5F_AC29_4fdc_8A3B_0328D0256F8C

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <PiDxe.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x2A43BA5F, 0xAC29, 0x4fdc, {0x8A, 0x3B, 0x03, 0x28, 0xD0, 0x25, 0x6F, 0x8C}}

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
EntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
