/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_9FB1A1F3_3B71_4324_B39A_745CBB015FFF
#define _AUTOGENH_9FB1A1F3_3B71_4324_B39A_745CBB015FFF

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Uefi.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x9FB1A1F3, 0x3B71, 0x4324, {0xB3, 0x9A, 0x74, 0x5C, 0xBB, 0x01, 0x5F, 0xFF}}

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
Ip4DriverEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );



EFI_STATUS
EFIAPI
NetLibDefaultUnload (
  IN EFI_HANDLE        ImageHandle
  );



#ifdef __cplusplus
}
#endif

#endif
