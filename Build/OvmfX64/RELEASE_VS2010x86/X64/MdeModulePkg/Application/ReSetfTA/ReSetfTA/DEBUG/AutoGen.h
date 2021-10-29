/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_eaea9aec_c9c1_46e2_9d52_432ad25a9b0c
#define _AUTOGENH_eaea9aec_c9c1_46e2_9d52_432ad25a9b0c

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Uefi.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0xeaea9aec, 0xc9c1, 0x46e2, {0x9d, 0x52, 0x43, 0x2a, 0xd2, 0x5a, 0x9b, 0x0c}}

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
UefiMain (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
