#line 1 "c:\\vector-edk-master\\OvmfPkg\\Library\\LoadLinuxLib\\X64\\JumpToKernel.asm"
#line 1 "c:\\vector-edk-master\\Build\\OvmfX64\\RELEASE_VS2010x86\\X64\\OvmfPkg\\Library\\LoadLinuxLib\\LoadLinuxLib\\DEBUG\\AutoGen.h"















#line 1 "c:\\vector-edk-master\\MdePkg\\Include\\Base.h"



























#line 1 "c:\\vector-edk-master\\MdePkg\\Include\\X64\\ProcessorBind.h"


























#pragma pack()
#line 29 "c:\\vector-edk-master\\MdePkg\\Include\\X64\\ProcessorBind.h"



























#line 57 "c:\\vector-edk-master\\MdePkg\\Include\\X64\\ProcessorBind.h"












#pragma warning ( disable : 4214 )




#pragma warning ( disable : 4100 )





#pragma warning ( disable : 4057 )




#pragma warning ( disable : 4127 )




#pragma warning ( disable : 4505 )




#pragma warning ( disable : 4206 )

#line 98 "c:\\vector-edk-master\\MdePkg\\Include\\X64\\ProcessorBind.h"



  
  
  

  
  
  
  typedef unsigned __int64    UINT64;
  
  
  
  typedef __int64             INT64;
  
  
  
  typedef unsigned __int32    UINT32;
  
  
  
  typedef __int32             INT32;
  
  
  
  typedef unsigned short      UINT16;
  
  
  
  
  typedef unsigned short      CHAR16;
  
  
  
  typedef short               INT16;
  
  
  
  
  typedef unsigned char       BOOLEAN;
  
  
  
  typedef unsigned char       UINT8;
  
  
  
  typedef char                CHAR8;
  
  
  
  typedef signed char         INT8;















































#line 199 "c:\\vector-edk-master\\MdePkg\\Include\\X64\\ProcessorBind.h"





typedef UINT64  UINTN;




typedef INT64   INTN;









































  
  
  
  
















#line 272 "c:\\vector-edk-master\\MdePkg\\Include\\X64\\ProcessorBind.h"







#line 280 "c:\\vector-edk-master\\MdePkg\\Include\\X64\\ProcessorBind.h"













#line 294 "c:\\vector-edk-master\\MdePkg\\Include\\X64\\ProcessorBind.h"

#line 29 "c:\\vector-edk-master\\MdePkg\\Include\\Base.h"



















extern UINT8 _VerifySizeofBOOLEAN[(sizeof(BOOLEAN) == (1)) / (sizeof(BOOLEAN) == (1))];
extern UINT8 _VerifySizeofINT8[(sizeof(INT8) == (1)) / (sizeof(INT8) == (1))];
extern UINT8 _VerifySizeofUINT8[(sizeof(UINT8) == (1)) / (sizeof(UINT8) == (1))];
extern UINT8 _VerifySizeofINT16[(sizeof(INT16) == (2)) / (sizeof(INT16) == (2))];
extern UINT8 _VerifySizeofUINT16[(sizeof(UINT16) == (2)) / (sizeof(UINT16) == (2))];
extern UINT8 _VerifySizeofINT32[(sizeof(INT32) == (4)) / (sizeof(INT32) == (4))];
extern UINT8 _VerifySizeofUINT32[(sizeof(UINT32) == (4)) / (sizeof(UINT32) == (4))];
extern UINT8 _VerifySizeofINT64[(sizeof(INT64) == (8)) / (sizeof(INT64) == (8))];
extern UINT8 _VerifySizeofUINT64[(sizeof(UINT64) == (8)) / (sizeof(UINT64) == (8))];
extern UINT8 _VerifySizeofCHAR8[(sizeof(CHAR8) == (1)) / (sizeof(CHAR8) == (1))];
extern UINT8 _VerifySizeofCHAR16[(sizeof(CHAR16) == (2)) / (sizeof(CHAR16) == (2))];







  
  
  
  
  
  







#line 80 "c:\\vector-edk-master\\MdePkg\\Include\\Base.h"
















#line 97 "c:\\vector-edk-master\\MdePkg\\Include\\Base.h"







#line 105 "c:\\vector-edk-master\\MdePkg\\Include\\Base.h"
  
#line 107 "c:\\vector-edk-master\\MdePkg\\Include\\Base.h"








  
#line 117 "c:\\vector-edk-master\\MdePkg\\Include\\Base.h"





typedef struct {
  UINT32  Data1;
  UINT16  Data2;
  UINT16  Data3;
  UINT8   Data4[8];
} GUID;




typedef UINT64 PHYSICAL_ADDRESS;




typedef struct _LIST_ENTRY LIST_ENTRY;




struct _LIST_ENTRY {
  LIST_ENTRY  *ForwardLink;
  LIST_ENTRY  *BackLink;
};










































































































































































































































































































































#line 477 "c:\\vector-edk-master\\MdePkg\\Include\\Base.h"


















#line 496 "c:\\vector-edk-master\\MdePkg\\Include\\Base.h"




typedef CHAR8 *VA_LIST;






























































#line 564 "c:\\vector-edk-master\\MdePkg\\Include\\Base.h"




typedef UINTN  *BASE_LIST;

















































#line 619 "c:\\vector-edk-master\\MdePkg\\Include\\Base.h"

















































































































typedef UINTN RETURN_STATUS;































































































































































































































































































#line 1021 "c:\\vector-edk-master\\MdePkg\\Include\\Base.h"


#line 17 "c:\\vector-edk-master\\Build\\OvmfX64\\RELEASE_VS2010x86\\X64\\OvmfPkg\\Library\\LoadLinuxLib\\LoadLinuxLib\\DEBUG\\AutoGen.h"

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;







#line 28 "c:\\vector-edk-master\\Build\\OvmfX64\\RELEASE_VS2010x86\\X64\\OvmfPkg\\Library\\LoadLinuxLib\\LoadLinuxLib\\DEBUG\\AutoGen.h"
#line 1 "c:\\vector-edk-master\\OvmfPkg\\Library\\LoadLinuxLib\\X64\\JumpToKernel.asm"
;------------------------------------------------------------------------------
;
; Copyright (c) 2006 - 2013, Intel Corporation. All rights reserved.<BR>
;
; This program and the accompanying materials
; are licensed and made available under the terms and conditions of the BSD License
; which accompanies this distribution.  The full text of the license may be found at
; http:
;
; THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
; WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
;
;------------------------------------------------------------------------------

  .code

;------------------------------------------------------------------------------
; void
; __cdecl
; JumpToKernel (
;   void *KernelStart,         
;   void *KernelBootParams     
;   );
;------------------------------------------------------------------------------
JumpToKernel PROC

    ; Set up for executing kernel. BP in %esi, entry point on the stack
    ; (64-bit when the 'ret' will use it as 32-bit, but we're little-endian)
    mov    rsi, rdx
    push   rcx

    ; Jump into the compatibility mode CS
    push    10h
    lea     rax, @F
    push    rax
    DB 048h, 0cbh                      ; retfq

@@:
    ; Now in compatibility mode.

    DB 0b8h, 018h, 000h, 000h, 000h    ; movl    $0x18, %eax
    DB 08eh, 0d8h                      ; movl    %eax, %ds
    DB 08eh, 0c0h                      ; movl    %eax, %es
    DB 08eh, 0e0h                      ; movl    %eax, %fs
    DB 08eh, 0e8h                      ; movl    %eax, %gs
    DB 08eh, 0d0h                      ; movl    %eax, %ss

    ; Disable paging
    DB 00fh, 020h, 0c0h                ; movl    %cr0, %eax
    DB 00fh, 0bah, 0f8h, 01fh          ; btcl    $31, %eax
    DB 00fh, 022h, 0c0h                ; movl    %eax, %cr0

    ; Disable long mode in EFER
    DB 0b9h, 080h, 000h, 000h, 0c0h    ; movl    $0x0c0000080, %ecx
    DB 00fh, 032h                      ; rdmsr
    DB 00fh, 0bah, 0f8h, 008h          ; btcl    $8, %eax
    DB 00fh, 030h                      ; wrmsr

    ; Disable PAE
    DB 00fh, 020h, 0e0h                ; movl    %cr4, %eax
    DB 00fh, 0bah, 0f8h, 005h          ; btcl    $5, %eax
    DB 00fh, 022h, 0e0h                ; movl    %eax, %cr4

    DB 031h, 0edh                      ; xor     %ebp, %ebp
    DB 031h, 0ffh                      ; xor     %edi, %edi
    DB 031h, 0dbh                      ; xor     %ebx, %ebx
    DB 0c3h                            ; ret

JumpToKernel ENDP

;------------------------------------------------------------------------------
; void
; __cdecl
; JumpToUefiKernel (
;   EFI_HANDLE ImageHandle,        
;   EFI_SYSTEM_TABLE *SystemTable, 
;   void *KernelBootParams         
;   void *KernelStart,             
;   );
;------------------------------------------------------------------------------
JumpToUefiKernel PROC

    mov     rdi, rcx
    mov     rsi, rdx
    mov     rdx, r8
    xor     rax, rax
    mov     eax, [r8 + 264h]
    add     r9, rax
    add     r9, 200h
    call    r9
    ret

JumpToUefiKernel ENDP

END
