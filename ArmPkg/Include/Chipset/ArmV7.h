/** @file

  Copyright (c) 2008 - 2009, Apple Inc. All rights reserved.<BR>
  Copyright (c) 2011-2013, ARM Ltd. All rights reserved.<BR>

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __ARM_V7_H__
#define __ARM_V7_H__

#include <Chipset/ArmV7Mmu.h>
#include <Chipset/ArmArchTimer.h>

// ARM Interrupt ID in Exception Table
#define ARM_ARCH_EXCEPTION_IRQ            EXCEPT_ARM_IRQ

// Domain Access Control Register
#define DOMAIN_ACCESS_CONTROL_MASK(a)     (3UL << (2 * (a)))
#define DOMAIN_ACCESS_CONTROL_NONE(a)     (0UL << (2 * (a)))
#define DOMAIN_ACCESS_CONTROL_CLIENT(a)   (1UL << (2 * (a)))
#define DOMAIN_ACCESS_CONTROL_RESERVED(a) (2UL << (2 * (a)))
#define DOMAIN_ACCESS_CONTROL_MANAGER(a)  (3UL << (2 * (a)))

// CPSR - Coprocessor Status Register definitions
#define CPSR_MODE_USER       0x10
#define CPSR_MODE_FIQ        0x11
#define CPSR_MODE_IRQ        0x12
#define CPSR_MODE_SVC        0x13
#define CPSR_MODE_ABORT      0x17
#define CPSR_MODE_HYP        0x1A
#define CPSR_MODE_UNDEFINED  0x1B
#define CPSR_MODE_SYSTEM     0x1F
#define CPSR_MODE_MASK       0x1F
#define CPSR_ASYNC_ABORT     (1 << 8)
#define CPSR_IRQ             (1 << 7)
#define CPSR_FIQ             (1 << 6)


// CPACR - Coprocessor Access Control Register definitions
#define CPACR_CP_DENIED(cp)     0x00
#define CPACR_CP_PRIV(cp)       ((0x1 << ((cp) << 1)) & 0x0FFFFFFF)
#define CPACR_CP_FULL(cp)       ((0x3 << ((cp) << 1)) & 0x0FFFFFFF)
#define CPACR_ASEDIS            (1 << 31)
#define CPACR_D32DIS            (1 << 30)
#define CPACR_CP_FULL_ACCESS    0x0FFFFFFF

// NSACR - Non-Secure Access Control Register definitions
#define NSACR_CP(cp)            ((1 << (cp)) & 0x3FFF)
#define NSACR_NSD32DIS          (1 << 14)
#define NSACR_NSASEDIS          (1 << 15)
#define NSACR_PLE               (1 << 16)
#define NSACR_TL                (1 << 17)
#define NSACR_NS_SMP            (1 << 18)
#define NSACR_RFR               (1 << 19)

// SCR - Secure Configuration Register definitions
#define SCR_NS                  (1 << 0)
#define SCR_IRQ                 (1 << 1)
#define SCR_FIQ                 (1 << 2)
#define SCR_EA                  (1 << 3)
#define SCR_FW                  (1 << 4)
#define SCR_AW                  (1 << 5)

// MIDR - Main ID Register definitions
#define ARM_CPU_TYPE_MASK       0xFFF
#define ARM_CPU_TYPE_A15        0xC0F
#define ARM_CPU_TYPE_A9         0xC09
#define ARM_CPU_TYPE_A5         0xC05

#define ARM_VECTOR_TABLE_ALIGNMENT ((1 << 5)-1)

VOID
EFIAPI
ArmEnableSWPInstruction (
  VOID
  );

UINTN 
EFIAPI
ArmReadCbar (
  VOID
  );

UINTN
EFIAPI
ArmReadTpidrurw (
  VOID
  );

VOID
EFIAPI
ArmWriteTpidrurw (
  UINTN Value
  );

UINT32
EFIAPI
ArmReadNsacr (
  VOID
  );

VOID
EFIAPI
ArmWriteNsacr (
  IN  UINT32   Nsacr
  );

#endif // __ARM_V7_H__
