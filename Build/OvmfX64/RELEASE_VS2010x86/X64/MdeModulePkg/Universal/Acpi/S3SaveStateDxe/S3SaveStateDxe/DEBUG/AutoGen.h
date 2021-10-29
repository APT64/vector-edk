/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_BDCE85BB_FBAA_4f4e_9264_501A2C249581
#define _AUTOGENH_BDCE85BB_FBAA_4f4e_9264_501A2C249581

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <PiDxe.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0xBDCE85BB, 0xFBAA, 0x4f4e, {0x92, 0x64, 0x50, 0x1A, 0x2C, 0x24, 0x95, 0x81}}

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
InitializeS3SaveState (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
