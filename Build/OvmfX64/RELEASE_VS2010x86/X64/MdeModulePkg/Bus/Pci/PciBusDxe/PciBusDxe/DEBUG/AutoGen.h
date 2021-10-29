/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_93B80004_9FB3_11d4_9A3A_0090273FC14D
#define _AUTOGENH_93B80004_9FB3_11d4_9A3A_0090273FC14D

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Uefi.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x93B80004, 0x9FB3, 0x11d4, {0x9A, 0x3A, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D}}

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdPciBusHotplugDeviceSupport  77U
#define _PCD_VALUE_PcdPciBusHotplugDeviceSupport  ((BOOLEAN)1U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdPciBusHotplugDeviceSupport;
#define _PCD_GET_MODE_BOOL_PcdPciBusHotplugDeviceSupport  _gPcd_FixedAtBuild_PcdPciBusHotplugDeviceSupport
//#define _PCD_SET_MODE_BOOL_PcdPciBusHotplugDeviceSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPciBridgeIoAlignmentProbe  78U
#define _PCD_VALUE_PcdPciBridgeIoAlignmentProbe  ((BOOLEAN)0U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdPciBridgeIoAlignmentProbe;
#define _PCD_GET_MODE_BOOL_PcdPciBridgeIoAlignmentProbe  _gPcd_FixedAtBuild_PcdPciBridgeIoAlignmentProbe
//#define _PCD_SET_MODE_BOOL_PcdPciBridgeIoAlignmentProbe  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdUnalignedPciIoEnable  79U
#define _PCD_VALUE_PcdUnalignedPciIoEnable  ((BOOLEAN)0U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdUnalignedPciIoEnable;
#define _PCD_GET_MODE_BOOL_PcdUnalignedPciIoEnable  _gPcd_FixedAtBuild_PcdUnalignedPciIoEnable
//#define _PCD_SET_MODE_BOOL_PcdUnalignedPciIoEnable  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSrIovSystemPageSize  80U
#define _PCD_VALUE_PcdSrIovSystemPageSize  0x1U
extern const  UINT32  _gPcd_FixedAtBuild_PcdSrIovSystemPageSize;
#define _PCD_GET_MODE_32_PcdSrIovSystemPageSize  _gPcd_FixedAtBuild_PcdSrIovSystemPageSize
//#define _PCD_SET_MODE_32_PcdSrIovSystemPageSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSrIovSupport  81U
#define _PCD_VALUE_PcdSrIovSupport  1U
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdSrIovSupport;
#define _PCD_GET_MODE_BOOL_PcdSrIovSupport  _gPcd_FixedAtBuild_PcdSrIovSupport
//#define _PCD_SET_MODE_BOOL_PcdSrIovSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdAriSupport  82U
#define _PCD_VALUE_PcdAriSupport  1U
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdAriSupport;
#define _PCD_GET_MODE_BOOL_PcdAriSupport  _gPcd_FixedAtBuild_PcdAriSupport
//#define _PCD_SET_MODE_BOOL_PcdAriSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMrIovSupport  83U
#define _PCD_VALUE_PcdMrIovSupport  0U
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdMrIovSupport;
#define _PCD_GET_MODE_BOOL_PcdMrIovSupport  _gPcd_FixedAtBuild_PcdMrIovSupport
//#define _PCD_SET_MODE_BOOL_PcdMrIovSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPciDisableBusEnumeration  2U
#define _PCD_GET_MODE_BOOL_PcdPciDisableBusEnumeration  LibPcdGetBool(_PCD_TOKEN_PcdPciDisableBusEnumeration)
#define _PCD_SET_MODE_BOOL_PcdPciDisableBusEnumeration(Value)  LibPcdSetBool(_PCD_TOKEN_PcdPciDisableBusEnumeration, (Value))

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
PciBusEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
