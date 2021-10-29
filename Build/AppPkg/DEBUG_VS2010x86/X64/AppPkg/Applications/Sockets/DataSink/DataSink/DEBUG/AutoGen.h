/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_A85DCA1B_198F_4e14_A673_874264687E85
#define _AUTOGENH_A85DCA1B_198F_4e14_A673_874264687E85

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Uefi.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0xA85DCA1B, 0x198F, 0x4e14, {0xA6, 0x73, 0x87, 0x42, 0x64, 0x68, 0x7E, 0x85}}

// Definition of PCDs used in this module

#define _PCD_TOKEN_DataSource_Port  14U
#define _PCD_VALUE_DataSource_Port  1234U
extern const  UINT16  _gPcd_FixedAtBuild_DataSource_Port;
#define _PCD_GET_MODE_16_DataSource_Port  _gPcd_FixedAtBuild_DataSource_Port
//#define _PCD_SET_MODE_16_DataSource_Port  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

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
