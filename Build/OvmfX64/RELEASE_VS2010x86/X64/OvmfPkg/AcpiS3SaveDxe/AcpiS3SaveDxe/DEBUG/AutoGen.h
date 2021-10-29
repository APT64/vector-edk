/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_6B79BBC0_26B9_4FE9_B631_551D8AB078C6
#define _AUTOGENH_6B79BBC0_26B9_4FE9_B631_551D8AB078C6

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <PiDxe.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x6B79BBC0, 0x26B9, 0x4FE9, {0xB6, 0x31, 0x55, 0x1D, 0x8A, 0xB0, 0x78, 0xC6}}

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdPlatformCsmSupport  171U
#define _PCD_VALUE_PcdPlatformCsmSupport  ((BOOLEAN)1U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdPlatformCsmSupport;
#define _PCD_GET_MODE_BOOL_PcdPlatformCsmSupport  _gPcd_FixedAtBuild_PcdPlatformCsmSupport
//#define _PCD_SET_MODE_BOOL_PcdPlatformCsmSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDxeIplSwitchToLongMode  63U
#define _PCD_VALUE_PcdDxeIplSwitchToLongMode  ((BOOLEAN)0U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdDxeIplSwitchToLongMode;
#define _PCD_GET_MODE_BOOL_PcdDxeIplSwitchToLongMode  _gPcd_FixedAtBuild_PcdDxeIplSwitchToLongMode
//#define _PCD_SET_MODE_BOOL_PcdDxeIplSwitchToLongMode  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdS3AcpiReservedMemorySize  58U
#define _PCD_VALUE_PcdS3AcpiReservedMemorySize  0x00008000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdS3AcpiReservedMemorySize;
#define _PCD_GET_MODE_32_PcdS3AcpiReservedMemorySize  _gPcd_FixedAtBuild_PcdS3AcpiReservedMemorySize
//#define _PCD_SET_MODE_32_PcdS3AcpiReservedMemorySize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdS3BootScriptStackSize  172U
#define _PCD_VALUE_PcdS3BootScriptStackSize  0x8000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdS3BootScriptStackSize;
#define _PCD_GET_MODE_32_PcdS3BootScriptStackSize  _gPcd_FixedAtBuild_PcdS3BootScriptStackSize
//#define _PCD_SET_MODE_32_PcdS3BootScriptStackSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdUse1GPageTable  52U
#define _PCD_VALUE_PcdUse1GPageTable  0U
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdUse1GPageTable;
#define _PCD_GET_MODE_BOOL_PcdUse1GPageTable  _gPcd_FixedAtBuild_PcdUse1GPageTable
//#define _PCD_SET_MODE_BOOL_PcdUse1GPageTable  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
InstallAcpiS3Save (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
