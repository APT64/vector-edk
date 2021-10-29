/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_38A0EC22_FBE7_4911_8BC1_176E0D6C1DBD
#define _AUTOGENH_38A0EC22_FBE7_4911_8BC1_176E0D6C1DBD

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Uefi.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x38A0EC22, 0xFBE7, 0x4911, {0x8B, 0xC1, 0x17, 0x6E, 0x0D, 0x6C, 0x1D, 0xBD}}

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdIsaAcpiCom1Enable  149U
#define _PCD_VALUE_PcdIsaAcpiCom1Enable  1U
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdIsaAcpiCom1Enable;
#define _PCD_GET_MODE_BOOL_PcdIsaAcpiCom1Enable  _gPcd_FixedAtBuild_PcdIsaAcpiCom1Enable
//#define _PCD_SET_MODE_BOOL_PcdIsaAcpiCom1Enable  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdIsaAcpiCom2Enable  150U
#define _PCD_VALUE_PcdIsaAcpiCom2Enable  1U
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdIsaAcpiCom2Enable;
#define _PCD_GET_MODE_BOOL_PcdIsaAcpiCom2Enable  _gPcd_FixedAtBuild_PcdIsaAcpiCom2Enable
//#define _PCD_SET_MODE_BOOL_PcdIsaAcpiCom2Enable  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdIsaAcpiPs2KeyboardEnable  151U
#define _PCD_VALUE_PcdIsaAcpiPs2KeyboardEnable  1U
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdIsaAcpiPs2KeyboardEnable;
#define _PCD_GET_MODE_BOOL_PcdIsaAcpiPs2KeyboardEnable  _gPcd_FixedAtBuild_PcdIsaAcpiPs2KeyboardEnable
//#define _PCD_SET_MODE_BOOL_PcdIsaAcpiPs2KeyboardEnable  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdIsaAcpiPs2MouseEnable  152U
#define _PCD_VALUE_PcdIsaAcpiPs2MouseEnable  1U
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdIsaAcpiPs2MouseEnable;
#define _PCD_GET_MODE_BOOL_PcdIsaAcpiPs2MouseEnable  _gPcd_FixedAtBuild_PcdIsaAcpiPs2MouseEnable
//#define _PCD_SET_MODE_BOOL_PcdIsaAcpiPs2MouseEnable  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdIsaAcpiFloppyAEnable  153U
#define _PCD_VALUE_PcdIsaAcpiFloppyAEnable  1U
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdIsaAcpiFloppyAEnable;
#define _PCD_GET_MODE_BOOL_PcdIsaAcpiFloppyAEnable  _gPcd_FixedAtBuild_PcdIsaAcpiFloppyAEnable
//#define _PCD_SET_MODE_BOOL_PcdIsaAcpiFloppyAEnable  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdIsaAcpiFloppyBEnable  154U
#define _PCD_VALUE_PcdIsaAcpiFloppyBEnable  1U
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdIsaAcpiFloppyBEnable;
#define _PCD_GET_MODE_BOOL_PcdIsaAcpiFloppyBEnable  _gPcd_FixedAtBuild_PcdIsaAcpiFloppyBEnable
//#define _PCD_SET_MODE_BOOL_PcdIsaAcpiFloppyBEnable  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
PcatIsaAcpiDriverEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
