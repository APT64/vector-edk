/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_49970331_E3FA_4637_9ABC_3B7868676970
#define _AUTOGENH_49970331_E3FA_4637_9ABC_3B7868676970

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <PiDxe.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x49970331, 0xE3FA, 0x4637, {0x9A, 0xBC, 0x3B, 0x78, 0x68, 0x67, 0x69, 0x70}}

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdAcpiTableStorageFile  170U
#define _PCD_PATCHABLE_PcdAcpiTableStorageFile_SIZE 16
#define _PCD_VALUE_PcdAcpiTableStorageFile  (VOID *)_gPcd_FixedAtBuild_PcdAcpiTableStorageFile
extern const UINT8 _gPcd_FixedAtBuild_PcdAcpiTableStorageFile[16];
#define _PCD_GET_MODE_PTR_PcdAcpiTableStorageFile  (VOID *)_gPcd_FixedAtBuild_PcdAcpiTableStorageFile
//#define _PCD_SET_MODE_PTR_PcdAcpiTableStorageFile  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCpuLocalApicBaseAddress  62U
#define _PCD_VALUE_PcdCpuLocalApicBaseAddress  0xfee00000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdCpuLocalApicBaseAddress;
#define _PCD_GET_MODE_32_PcdCpuLocalApicBaseAddress  _gPcd_FixedAtBuild_PcdCpuLocalApicBaseAddress
//#define _PCD_SET_MODE_32_PcdCpuLocalApicBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_Pcd8259LegacyModeEdgeLevel  76U
#define _PCD_VALUE_Pcd8259LegacyModeEdgeLevel  0x0E20U
extern const  UINT16  _gPcd_FixedAtBuild_Pcd8259LegacyModeEdgeLevel;
#define _PCD_GET_MODE_16_Pcd8259LegacyModeEdgeLevel  _gPcd_FixedAtBuild_Pcd8259LegacyModeEdgeLevel
//#define _PCD_SET_MODE_16_Pcd8259LegacyModeEdgeLevel  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdOvmfFdBaseAddress  116U
#define _PCD_VALUE_PcdOvmfFdBaseAddress  0xFFF00000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdOvmfFdBaseAddress;
#define _PCD_GET_MODE_32_PcdOvmfFdBaseAddress  _gPcd_FixedAtBuild_PcdOvmfFdBaseAddress
//#define _PCD_SET_MODE_32_PcdOvmfFdBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
AcpiPlatformEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
