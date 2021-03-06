/** @file
  Specific relocation fixups for ARM architecture.

  Copyright (c) 2006 - 2009, Intel Corporation. All rights reserved.<BR>
  Portions copyright (c) 2008 - 2010, Apple Inc. All rights reserved.<BR>
  Portions copyright (c) 2011 - 2013, ARM Ltd. All rights reserved.<BR>

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include "BasePeCoffLibInternals.h"
#include <Library/BaseLib.h>

//
// Note: Currently only large memory model is supported by UEFI relocation code.
//

/**
  Performs an AARCH64-based specific relocation fixup and is a no-op on other
  instruction sets.

  @param  Reloc       The pointer to the relocation record.
  @param  Fixup       The pointer to the address to fix up.
  @param  FixupData   The pointer to a buffer to log the fixups.
  @param  Adjust      The offset to adjust the fixup.

  @return Status code.

**/
RETURN_STATUS
PeCoffLoaderRelocateImageEx (
  IN UINT16      **Reloc,
  IN OUT CHAR8   *Fixup,
  IN OUT CHAR8   **FixupData,
  IN UINT64      Adjust
  )
{
  UINT64      *F64;

  switch ((**Reloc) >> 12) {

    case EFI_IMAGE_REL_BASED_DIR64:
      F64 = (UINT64 *) Fixup;
      *F64 = *F64 + (UINT64) Adjust;
      if (*FixupData != NULL) {
        *FixupData = ALIGN_POINTER(*FixupData, sizeof(UINT64));
        *(UINT64 *)(*FixupData) = *F64;
        *FixupData = *FixupData + sizeof(UINT64);
      }
      break;

    default:
      return RETURN_UNSUPPORTED;
  }

  return RETURN_SUCCESS;
}

/**
  Returns TRUE if the machine type of PE/COFF image is supported. Supported
  does not mean the image can be executed it means the PE/COFF loader supports
  loading and relocating of the image type. It's up to the caller to support
  the entry point.

  @param  Machine   Machine type from the PE Header.

  @return TRUE if this PE/COFF loader can load the image

**/
BOOLEAN
PeCoffLoaderImageFormatSupported (
  IN  UINT16  Machine
  )
{
  if ((Machine == IMAGE_FILE_MACHINE_ARM64) || (Machine ==  IMAGE_FILE_MACHINE_EBC)) {
    return TRUE;
  }

  return FALSE;
}

/**
  Performs an ARM-based specific re-relocation fixup and is a no-op on other
  instruction sets. This is used to re-relocated the image into the EFI virtual
  space for runtime calls.

  @param  Reloc       The pointer to the relocation record.
  @param  Fixup       The pointer to the address to fix up.
  @param  FixupData   The pointer to a buffer to log the fixups.
  @param  Adjust      The offset to adjust the fixup.

  @return Status code.

**/
RETURN_STATUS
PeHotRelocateImageEx (
  IN UINT16      **Reloc,
  IN OUT CHAR8   *Fixup,
  IN OUT CHAR8   **FixupData,
  IN UINT64      Adjust
  )
{
  UINT64  *Fixup64;

  switch ((**Reloc) >> 12) {
  case EFI_IMAGE_REL_BASED_DIR64:
    Fixup64     = (UINT64 *) Fixup;
    *FixupData  = ALIGN_POINTER (*FixupData, sizeof (UINT64));
    if (*(UINT64 *) (*FixupData) == *Fixup64) {
      *Fixup64 = *Fixup64 + (UINT64) Adjust;
    }

    *FixupData = *FixupData + sizeof (UINT64);
    break;

  default:
    DEBUG ((EFI_D_ERROR, "PeHotRelocateEx:unknown fixed type\n"));
    return RETURN_UNSUPPORTED;
  }

  return RETURN_SUCCESS;
}
