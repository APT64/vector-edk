/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_30EB0F26_FC0A_4fd2_B9C9_751EA2BB1980
#define _AUTOGENH_30EB0F26_FC0A_4fd2_B9C9_751EA2BB1980

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Uefi.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x30EB0F26, 0xFC0A, 0x4fd2, {0xB9, 0xC9, 0x75, 0x1E, 0xA2, 0xBB, 0x19, 0x80}}

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
