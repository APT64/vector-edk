/** @file

  Copyright (c) 2008 - 2009, Apple Inc. All rights reserved.<BR>
  Copyright (c) 2011 - 2013, ARM Ltd. All rights reserved.<BR>

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __CPU_DXE_ARM_EXCEPTION_H__
#define __CPU_DXE_ARM_EXCEPTION_H__

#include <Uefi.h>

#include <Library/ArmLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>
#include <Library/PcdLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/DxeServicesTableLib.h>
#include <Library/CacheMaintenanceLib.h>
#include <Library/PeCoffGetEntryPointLib.h>
#include <Library/UefiLib.h>
#include <Library/CpuLib.h>
#include <Library/DefaultExceptionHandlerLib.h>
#include <Library/DebugLib.h>

#include <Guid/DebugImageInfoTable.h>
#include <Protocol/Cpu.h>
#include <Protocol/DebugSupport.h>
#include <Protocol/DebugSupportPeriodicCallback.h>
#include <Protocol/VirtualUncachedPages.h>
#include <Protocol/LoadedImage.h>


#define EFI_MEMORY_CACHETYPE_MASK     (EFI_MEMORY_UC  | \
                                       EFI_MEMORY_WC  | \
                                       EFI_MEMORY_WT  | \
                                       EFI_MEMORY_WB  | \
                                       EFI_MEMORY_UCE   \
                                       )


/**
  This function registers and enables the handler specified by InterruptHandler for a processor 
  interrupt or exception type specified by InterruptType. If InterruptHandler is NULL, then the 
  handler for the processor interrupt or exception type specified by InterruptType is uninstalled. 
  The installed handler is called once for each processor interrupt or exception.

  @param  InterruptType    A pointer to the processor's current interrupt state. Set to TRUE if interrupts
                           are enabled and FALSE if interrupts are disabled.
  @param  InterruptHandler A pointer to a function of type EFI_CPU_INTERRUPT_HANDLER that is called
                           when a processor interrupt occurs. If this parameter is NULL, then the handler
                           will be uninstalled.

  @retval EFI_SUCCESS           The handler for the processor interrupt was successfully installed or uninstalled.
  @retval EFI_ALREADY_STARTED   InterruptHandler is not NULL, and a handler for InterruptType was
                                previously installed.
  @retval EFI_INVALID_PARAMETER InterruptHandler is NULL, and a handler for InterruptType was not
                                previously installed.
  @retval EFI_UNSUPPORTED       The interrupt specified by InterruptType is not supported.

**/
EFI_STATUS
RegisterInterruptHandler (
  IN EFI_EXCEPTION_TYPE             InterruptType,
  IN EFI_CPU_INTERRUPT_HANDLER      InterruptHandler
  );


/**
  This function registers and enables the handler specified by InterruptHandler for a processor 
  interrupt or exception type specified by InterruptType. If InterruptHandler is NULL, then the 
  handler for the processor interrupt or exception type specified by InterruptType is uninstalled. 
  The installed handler is called once for each processor interrupt or exception.

  @param  InterruptType    A pointer to the processor's current interrupt state. Set to TRUE if interrupts
                           are enabled and FALSE if interrupts are disabled.
  @param  InterruptHandler A pointer to a function of type EFI_CPU_INTERRUPT_HANDLER that is called
                           when a processor interrupt occurs. If this parameter is NULL, then the handler
                           will be uninstalled.

  @retval EFI_SUCCESS           The handler for the processor interrupt was successfully installed or uninstalled.
  @retval EFI_ALREADY_STARTED   InterruptHandler is not NULL, and a handler for InterruptType was
                                previously installed.
  @retval EFI_INVALID_PARAMETER InterruptHandler is NULL, and a handler for InterruptType was not
                                previously installed.
  @retval EFI_UNSUPPORTED       The interrupt specified by InterruptType is not supported.

**/
EFI_STATUS
RegisterDebuggerInterruptHandler (
  IN EFI_EXCEPTION_TYPE             InterruptType,
  IN EFI_CPU_INTERRUPT_HANDLER      InterruptHandler
  );


EFI_STATUS
EFIAPI
CpuSetMemoryAttributes (
  IN EFI_CPU_ARCH_PROTOCOL     *This,
  IN EFI_PHYSICAL_ADDRESS      BaseAddress,
  IN UINT64                    Length,
  IN UINT64                    Attributes
  );

EFI_STATUS
InitializeExceptions (
  IN EFI_CPU_ARCH_PROTOCOL    *Cpu
  );

EFI_STATUS
SyncCacheConfig (
  IN  EFI_CPU_ARCH_PROTOCOL *CpuProtocol
  );

EFI_STATUS 
ConvertSectionToPages (
  IN EFI_PHYSICAL_ADDRESS  BaseAddress
  );

/**
 * Publish ARM Processor Data table in UEFI SYSTEM Table.
 * @param  HobStart               Pointer to the beginning of the HOB List from PEI.
 *
 * Description : This function iterates through HOB list and finds ARM processor Table Entry HOB.
 *               If  the ARM processor Table Entry HOB is found, the HOB data is copied to run-time memory
 *               and a pointer is assigned to it in ARM processor table. Then the ARM processor table is
 *               installed in EFI configuration table.
**/
VOID
EFIAPI
PublishArmProcessorTable(
  VOID
  );

EFI_STATUS
SetMemoryAttributes (
  IN EFI_PHYSICAL_ADDRESS      BaseAddress,
  IN UINT64                    Length,
  IN UINT64                    Attributes,
  IN EFI_PHYSICAL_ADDRESS      VirtualMask
  );

// The ARM Attributes might be defined on 64-bit (case of the long format description table)
UINT64
EfiAttributeToArmAttribute (
  IN UINT64                    EfiAttributes
  );

EFI_STATUS
GetMemoryRegion (
  IN OUT UINTN                   *BaseAddress,
  OUT    UINTN                   *RegionLength,
  OUT    UINTN                   *RegionAttributes
  );

VOID
GetRootTranslationTableInfo (
  IN  UINTN    T0SZ,
  OUT UINTN   *TableLevel,
  OUT UINTN   *TableEntryCount
  );

EFI_STATUS
SetGcdMemorySpaceAttributes (
  IN EFI_GCD_MEMORY_SPACE_DESCRIPTOR    *MemorySpaceMap,
  IN UINTN                               NumberOfDescriptors,
  IN EFI_PHYSICAL_ADDRESS                BaseAddress,
  IN UINT64                              Length,
  IN UINT64                              Attributes
  );

extern VIRTUAL_UNCACHED_PAGES_PROTOCOL  gVirtualUncachedPages;

#endif // __CPU_DXE_ARM_EXCEPTION_H__
