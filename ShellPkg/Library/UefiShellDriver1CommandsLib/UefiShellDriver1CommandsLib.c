/** @file
  Main file for NULL named library for level 1 shell command functions.

  Copyright (c) 2010 - 2011, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include "UefiShellDriver1CommandsLib.h"

STATIC CONST CHAR16 mFileName[] = L"Driver1Commands";
EFI_HANDLE gShellDriver1HiiHandle = NULL;
BOOLEAN    gInReconnect = FALSE;

/**
  Function to translate the EFI_MEMORY_TYPE into a string.

  @param[in] Memory     The memory type.

  @retval               A string representation of the type allocated from BS Pool.
**/
CHAR16*
EFIAPI
ConvertMemoryType (
  IN CONST EFI_MEMORY_TYPE Memory
  )
{
  CHAR16 *RetVal;
  RetVal = NULL;

  switch (Memory) {
  case EfiReservedMemoryType:       StrnCatGrow(&RetVal, NULL, L"EfiReservedMemoryType", 0);        break;
  case EfiLoaderCode:               StrnCatGrow(&RetVal, NULL, L"EfiLoaderCode", 0);                break;
  case EfiLoaderData:               StrnCatGrow(&RetVal, NULL, L"EfiLoaderData", 0);                break;
  case EfiBootServicesCode:         StrnCatGrow(&RetVal, NULL, L"EfiBootServicesCode", 0);          break;
  case EfiBootServicesData:         StrnCatGrow(&RetVal, NULL, L"EfiBootServicesData", 0);          break;
  case EfiRuntimeServicesCode:      StrnCatGrow(&RetVal, NULL, L"EfiRuntimeServicesCode", 0);       break;
  case EfiRuntimeServicesData:      StrnCatGrow(&RetVal, NULL, L"EfiRuntimeServicesData", 0);       break;
  case EfiConventionalMemory:       StrnCatGrow(&RetVal, NULL, L"EfiConventionalMemory", 0);        break;
  case EfiUnusableMemory:           StrnCatGrow(&RetVal, NULL, L"EfiUnusableMemory", 0);            break;
  case EfiACPIReclaimMemory:        StrnCatGrow(&RetVal, NULL, L"EfiACPIReclaimMemory", 0);         break;
  case EfiACPIMemoryNVS:            StrnCatGrow(&RetVal, NULL, L"EfiACPIMemoryNVS", 0);             break;
  case EfiMemoryMappedIO:           StrnCatGrow(&RetVal, NULL, L"EfiMemoryMappedIO", 0);            break;
  case EfiMemoryMappedIOPortSpace:  StrnCatGrow(&RetVal, NULL, L"EfiMemoryMappedIOPortSpace", 0);   break;
  case EfiPalCode:                  StrnCatGrow(&RetVal, NULL, L"EfiPalCode", 0);                   break;
  case EfiMaxMemoryType:            StrnCatGrow(&RetVal, NULL, L"EfiMaxMemoryType", 0);             break;
  default: ASSERT(FALSE);
  }
  return (RetVal);
}

/**
  Function to return the name of the file containing help if HII will not be used.

  @return The filename.
**/
CONST CHAR16*
EFIAPI
ShellCommandGetManFileNameDriver1 (
  VOID
  )
{
  return (mFileName);
}

/**
  Constructor for the Shell Driver1 Commands library.

  @param ImageHandle    the image handle of the process
  @param SystemTable    the EFI System Table pointer

  @retval EFI_SUCCESS        the shell command handlers were installed sucessfully
  @retval EFI_UNSUPPORTED    the shell level required was not found.
**/
EFI_STATUS
EFIAPI
UefiShellDriver1CommandsLibConstructor (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  //
  // check our bit of the profiles mask
  //
  if ((PcdGet8(PcdShellProfileMask) & BIT0) == 0) {
    return (EFI_SUCCESS);
  }

  //
  // install the HII stuff.
  //
  gShellDriver1HiiHandle = HiiAddPackages (&gShellDriver1HiiGuid, gImageHandle, UefiShellDriver1CommandsLibStrings, NULL);
  if (gShellDriver1HiiHandle == NULL) {
    return (EFI_DEVICE_ERROR);
  }

  //
  // install our shell command handlers that are always installed
  //
  ShellCommandRegisterCommandName(L"connect",    ShellCommandRunConnect               , ShellCommandGetManFileNameDriver1, 0, L"Driver1", TRUE, gShellDriver1HiiHandle, STRING_TOKEN(STR_GET_HELP_CONNECT)   );
  ShellCommandRegisterCommandName(L"devices",    ShellCommandRunDevices               , ShellCommandGetManFileNameDriver1, 0, L"Driver1", TRUE, gShellDriver1HiiHandle, STRING_TOKEN(STR_GET_HELP_DEVICES)   );
  ShellCommandRegisterCommandName(L"openinfo",   ShellCommandRunOpenInfo              , ShellCommandGetManFileNameDriver1, 0, L"Driver1", TRUE, gShellDriver1HiiHandle, STRING_TOKEN(STR_GET_HELP_OPENINFO)  );
  ShellCommandRegisterCommandName(L"disconnect", ShellCommandRunDisconnect            , ShellCommandGetManFileNameDriver1, 0, L"Driver1", TRUE, gShellDriver1HiiHandle, STRING_TOKEN(STR_GET_HELP_DISCONNECT));
  ShellCommandRegisterCommandName(L"reconnect",  ShellCommandRunReconnect             , ShellCommandGetManFileNameDriver1, 0, L"Driver1", TRUE, gShellDriver1HiiHandle, STRING_TOKEN(STR_GET_HELP_RECONNECT) );
  ShellCommandRegisterCommandName(L"unload",     ShellCommandRunUnload                , ShellCommandGetManFileNameDriver1, 0, L"Driver1", TRUE, gShellDriver1HiiHandle, STRING_TOKEN(STR_GET_HELP_UNLOAD)    );
  ShellCommandRegisterCommandName(L"drvdiag",    ShellCommandRunDrvDiag               , ShellCommandGetManFileNameDriver1, 0, L"Driver1", TRUE, gShellDriver1HiiHandle, STRING_TOKEN(STR_GET_HELP_DRVDIAG)   );
  ShellCommandRegisterCommandName(L"dh",         ShellCommandRunDh                    , ShellCommandGetManFileNameDriver1, 0, L"Driver1", TRUE, gShellDriver1HiiHandle, STRING_TOKEN(STR_GET_HELP_DH)        );
  ShellCommandRegisterCommandName(L"drivers",    ShellCommandRunDrivers               , ShellCommandGetManFileNameDriver1, 0, L"Driver1", TRUE, gShellDriver1HiiHandle, STRING_TOKEN(STR_GET_HELP_DRIVERS)   );
  ShellCommandRegisterCommandName(L"devtree",    ShellCommandRunDevTree               , ShellCommandGetManFileNameDriver1, 0, L"Driver1", TRUE, gShellDriver1HiiHandle, STRING_TOKEN(STR_GET_HELP_DEVTREE)   );
  ShellCommandRegisterCommandName(L"drvcfg",     ShellCommandRunDrvCfg                , ShellCommandGetManFileNameDriver1, 0, L"Driver1", TRUE, gShellDriver1HiiHandle, STRING_TOKEN(STR_GET_HELP_DRVCFG)    );

  return (EFI_SUCCESS);
}

/**
  Destructor for the library.  free any resources.

  @param ImageHandle            The image handle of the process.
  @param SystemTable            The EFI System Table pointer.
**/
EFI_STATUS
EFIAPI
UefiShellDriver1CommandsLibDestructor (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  if (gShellDriver1HiiHandle != NULL) {
    HiiRemovePackages(gShellDriver1HiiHandle);
  }
  return (EFI_SUCCESS);
}



