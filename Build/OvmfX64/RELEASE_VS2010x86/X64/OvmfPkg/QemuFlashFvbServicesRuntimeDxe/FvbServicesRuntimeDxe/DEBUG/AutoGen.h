/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_733cbac2_b23f_4b92_bc8e_fb01ce5907b7
#define _AUTOGENH_733cbac2_b23f_4b92_bc8e_fb01ce5907b7

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <PiDxe.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x733cbac2, 0xb23f, 0x4b92, {0xbc, 0x8e, 0xfb, 0x01, 0xce, 0x59, 0x07, 0xb7}}

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdFlashNvStorageVariableSize  61U
#define _PCD_VALUE_PcdFlashNvStorageVariableSize  0x0000E000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdFlashNvStorageVariableSize;
#define _PCD_GET_MODE_32_PcdFlashNvStorageVariableSize  _gPcd_FixedAtBuild_PcdFlashNvStorageVariableSize
//#define _PCD_SET_MODE_32_PcdFlashNvStorageVariableSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFlashNvStorageFtwWorkingSize  111U
#define _PCD_VALUE_PcdFlashNvStorageFtwWorkingSize  0x00001000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdFlashNvStorageFtwWorkingSize;
#define _PCD_GET_MODE_32_PcdFlashNvStorageFtwWorkingSize  _gPcd_FixedAtBuild_PcdFlashNvStorageFtwWorkingSize
//#define _PCD_SET_MODE_32_PcdFlashNvStorageFtwWorkingSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFlashNvStorageFtwSpareSize  60U
#define _PCD_VALUE_PcdFlashNvStorageFtwSpareSize  0x00010000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdFlashNvStorageFtwSpareSize;
#define _PCD_GET_MODE_32_PcdFlashNvStorageFtwSpareSize  _gPcd_FixedAtBuild_PcdFlashNvStorageFtwSpareSize
//#define _PCD_SET_MODE_32_PcdFlashNvStorageFtwSpareSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdOvmfFlashNvStorageVariableBase  112U
#define _PCD_VALUE_PcdOvmfFlashNvStorageVariableBase  0xFFF00000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdOvmfFlashNvStorageVariableBase;
#define _PCD_GET_MODE_32_PcdOvmfFlashNvStorageVariableBase  _gPcd_FixedAtBuild_PcdOvmfFlashNvStorageVariableBase
//#define _PCD_SET_MODE_32_PcdOvmfFlashNvStorageVariableBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdOvmfFlashNvStorageFtwWorkingBase  113U
#define _PCD_VALUE_PcdOvmfFlashNvStorageFtwWorkingBase  0xFFF0F000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdOvmfFlashNvStorageFtwWorkingBase;
#define _PCD_GET_MODE_32_PcdOvmfFlashNvStorageFtwWorkingBase  _gPcd_FixedAtBuild_PcdOvmfFlashNvStorageFtwWorkingBase
//#define _PCD_SET_MODE_32_PcdOvmfFlashNvStorageFtwWorkingBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdOvmfFlashNvStorageFtwSpareBase  114U
#define _PCD_VALUE_PcdOvmfFlashNvStorageFtwSpareBase  0xFFF10000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdOvmfFlashNvStorageFtwSpareBase;
#define _PCD_GET_MODE_32_PcdOvmfFlashNvStorageFtwSpareBase  _gPcd_FixedAtBuild_PcdOvmfFlashNvStorageFtwSpareBase
//#define _PCD_SET_MODE_32_PcdOvmfFlashNvStorageFtwSpareBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdOvmfFlashNvStorageEventLogSize  115U
#define _PCD_VALUE_PcdOvmfFlashNvStorageEventLogSize  0x00001000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdOvmfFlashNvStorageEventLogSize;
#define _PCD_GET_MODE_32_PcdOvmfFlashNvStorageEventLogSize  _gPcd_FixedAtBuild_PcdOvmfFlashNvStorageEventLogSize
//#define _PCD_SET_MODE_32_PcdOvmfFlashNvStorageEventLogSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdOvmfFdBaseAddress  116U
#define _PCD_VALUE_PcdOvmfFdBaseAddress  0xFFF00000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdOvmfFdBaseAddress;
#define _PCD_GET_MODE_32_PcdOvmfFdBaseAddress  _gPcd_FixedAtBuild_PcdOvmfFdBaseAddress
//#define _PCD_SET_MODE_32_PcdOvmfFdBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdOvmfFirmwareFdSize  117U
#define _PCD_VALUE_PcdOvmfFirmwareFdSize  0x00100000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdOvmfFirmwareFdSize;
#define _PCD_GET_MODE_32_PcdOvmfFirmwareFdSize  _gPcd_FixedAtBuild_PcdOvmfFirmwareFdSize
//#define _PCD_SET_MODE_32_PcdOvmfFirmwareFdSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdOvmfFirmwareBlockSize  118U
#define _PCD_VALUE_PcdOvmfFirmwareBlockSize  0x1000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdOvmfFirmwareBlockSize;
#define _PCD_GET_MODE_32_PcdOvmfFirmwareBlockSize  _gPcd_FixedAtBuild_PcdOvmfFirmwareBlockSize
//#define _PCD_SET_MODE_32_PcdOvmfFirmwareBlockSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFlashNvStorageFtwWorkingBase  8U
#define _PCD_GET_MODE_32_PcdFlashNvStorageFtwWorkingBase  LibPcdGet32(_PCD_TOKEN_PcdFlashNvStorageFtwWorkingBase)
#define _PCD_SET_MODE_32_PcdFlashNvStorageFtwWorkingBase(Value)  LibPcdSet32(_PCD_TOKEN_PcdFlashNvStorageFtwWorkingBase, (Value))

#define _PCD_TOKEN_PcdFlashNvStorageFtwSpareBase  9U
#define _PCD_GET_MODE_32_PcdFlashNvStorageFtwSpareBase  LibPcdGet32(_PCD_TOKEN_PcdFlashNvStorageFtwSpareBase)
#define _PCD_SET_MODE_32_PcdFlashNvStorageFtwSpareBase(Value)  LibPcdSet32(_PCD_TOKEN_PcdFlashNvStorageFtwSpareBase, (Value))

#define _PCD_TOKEN_PcdFlashNvStorageVariableBase  119U
#define _PCD_VALUE_PcdFlashNvStorageVariableBase  0x0U
extern const  UINT32  _gPcd_FixedAtBuild_PcdFlashNvStorageVariableBase;
#define _PCD_GET_MODE_32_PcdFlashNvStorageVariableBase  _gPcd_FixedAtBuild_PcdFlashNvStorageVariableBase
//#define _PCD_SET_MODE_32_PcdFlashNvStorageVariableBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdOvmfFlashNvStorageEventLogBase  120U
#define _PCD_VALUE_PcdOvmfFlashNvStorageEventLogBase  0xFFF0E000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdOvmfFlashNvStorageEventLogBase;
#define _PCD_GET_MODE_32_PcdOvmfFlashNvStorageEventLogBase  _gPcd_FixedAtBuild_PcdOvmfFlashNvStorageEventLogBase
//#define _PCD_SET_MODE_32_PcdOvmfFlashNvStorageEventLogBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFlashNvStorageVariableBase64  10U
#define _PCD_GET_MODE_64_PcdFlashNvStorageVariableBase64  LibPcdGet64(_PCD_TOKEN_PcdFlashNvStorageVariableBase64)
#define _PCD_SET_MODE_64_PcdFlashNvStorageVariableBase64(Value)  LibPcdSet64(_PCD_TOKEN_PcdFlashNvStorageVariableBase64, (Value))

#define _PCD_TOKEN_PcdOvmfFlashVariablesEnable  7U
#define _PCD_GET_MODE_BOOL_PcdOvmfFlashVariablesEnable  LibPcdGetBool(_PCD_TOKEN_PcdOvmfFlashVariablesEnable)
#define _PCD_SET_MODE_BOOL_PcdOvmfFlashVariablesEnable(Value)  LibPcdSetBool(_PCD_TOKEN_PcdOvmfFlashVariablesEnable, (Value))

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
FvbInitialize (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
