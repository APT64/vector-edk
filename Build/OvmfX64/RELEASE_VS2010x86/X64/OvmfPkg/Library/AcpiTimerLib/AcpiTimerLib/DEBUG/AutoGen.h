/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_CDD9D74F_213E_4c28_98F7_8B4A167DB936
#define _AUTOGENH_CDD9D74F_213E_4c28_98F7_8B4A167DB936

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;


// PCD definitions
#define _PCD_TOKEN_PcdAcpiPmBaseAddress  53U
extern const UINT16 _gPcd_FixedAtBuild_PcdAcpiPmBaseAddress;
#define _PCD_GET_MODE_16_PcdAcpiPmBaseAddress  _gPcd_FixedAtBuild_PcdAcpiPmBaseAddress
//#define _PCD_SET_MODE_16_PcdAcpiPmBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

RETURN_STATUS
EFIAPI
AcpiTimerLibConstructor (
  VOID
  );


#ifdef __cplusplus
}
#endif

#endif
