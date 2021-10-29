/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_99E87DCF_6162_40c5_9FA1_32111F5197F7
#define _AUTOGENH_99E87DCF_6162_40c5_9FA1_32111F5197F7

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Uefi.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x99E87DCF, 0x6162, 0x40c5, {0x9F, 0xA1, 0x32, 0x11, 0x1F, 0x51, 0x97, 0xF7}}

// Definition of PCDs used in this module

#define _PCD_TOKEN_WebServer_HttpPort  15U
#define _PCD_VALUE_WebServer_HttpPort  80U
extern const  UINT16  _gPcd_FixedAtBuild_WebServer_HttpPort;
#define _PCD_GET_MODE_16_WebServer_HttpPort  _gPcd_FixedAtBuild_WebServer_HttpPort
//#define _PCD_SET_MODE_16_WebServer_HttpPort  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

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
