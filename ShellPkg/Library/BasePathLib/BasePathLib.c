/** @file
  Provides interface to path manipulation functions.

  Copyright (c) 2011 - 2014, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
**/

#include <Base.h>
#include <Library/BaseMemoryLib.h>
#include <Library/PathLib.h>
#include <Library/BaseLib.h>
#include <Protocol/SimpleTextIn.h> 

/**
  Removes the last directory or file entry in a path by changing the last
  L'\' to a CHAR_NULL.

  @param[in, out] Path    The pointer to the path to modify.

  @retval FALSE     Nothing was found to remove.
  @retval TRUE      A directory or file was removed.
**/
BOOLEAN
EFIAPI
PathRemoveLastItem(
  IN OUT CHAR16 *Path
  )
{
  CHAR16        *Walker;
  CHAR16        *LastSlash;
  //
  // get directory name from path... ('chop' off extra)
  //
  for ( Walker = Path, LastSlash = NULL
      ; Walker != NULL && *Walker != CHAR_NULL
      ; Walker++
     ){
    if (*Walker == L'\\' && *(Walker + 1) != CHAR_NULL) {
      LastSlash = Walker+1;
    }
  }
  if (LastSlash != NULL) {
    *LastSlash = CHAR_NULL;
    return (TRUE);
  }
  return (FALSE);
}

/**
  Function to clean up paths.  
  
  - Single periods in the path are removed.
  - Double periods in the path are removed along with a single parent directory.
  - Forward slashes L'/' are converted to backward slashes L'\'.

  This will be done inline and the existing buffer may be larger than required 
  upon completion.

  @param[in] Path       The pointer to the string containing the path.

  @retval NULL          An error occured.
  @return Path in all other instances.
**/
CHAR16*
EFIAPI
PathCleanUpDirectories(
  IN CHAR16 *Path
  )
{
  CHAR16  *TempString;
  UINTN   TempSize;
  if (Path==NULL) {
    return(NULL);
  }

  //
  // Fix up the '/' vs '\'
  //
  for (TempString = Path ; TempString != NULL && *TempString != CHAR_NULL ; TempString++) {
    if (*TempString == L'/') {
      *TempString = L'\\';
    }
  }

  //
  // Fix up the ..
  //
  while ((TempString = StrStr(Path, L"\\..\\")) != NULL) {
    *TempString = CHAR_NULL;
    TempString  += 4;
    PathRemoveLastItem(Path);
    TempSize = StrSize(TempString);
    CopyMem(Path+StrLen(Path), TempString, TempSize);
  }
  if ((TempString = StrStr(Path, L"\\..")) != NULL && *(TempString + 3) == CHAR_NULL) {
    *TempString = CHAR_NULL;
    PathRemoveLastItem(Path);
  }

  //
  // Fix up the .
  //
  while ((TempString = StrStr(Path, L"\\.\\")) != NULL) {
    *TempString = CHAR_NULL;
    TempString  += 2;
    TempSize = StrSize(TempString);
    CopyMem(Path+StrLen(Path), TempString, TempSize);
  }
  if ((TempString = StrStr(Path, L"\\.")) != NULL && *(TempString + 2) == CHAR_NULL) {
    *(TempString + 1) = CHAR_NULL;
  }



  return (Path);
}

