#
# DO NOT EDIT
# This file is auto-generated by build utility
#
# Module Name:
#
#   Makefile
#
# Abstract:
#
#   Auto-generated makefile for building modules, libraries or platform
#
    

#
# Platform Macro Definition
#
PLATFORM_NAME = AppPkg
PLATFORM_GUID = 0458dade-8b6e-4e45-b773-1b27cbda3e06
PLATFORM_VERSION = 0.01
PLATFORM_RELATIVE_DIR = AppPkg
PLATFORM_DIR = $(WORKSPACE)\AppPkg
PLATFORM_OUTPUT_DIR = Build\AppPkg

#
# Module Macro Definition
#
MODULE_NAME = LibGen
MODULE_GUID = CA599759-90A7-4fe4-BC8B-4B71C350DCAC
MODULE_VERSION = 1.0
MODULE_TYPE = UEFI_APPLICATION
MODULE_FILE = LibGen.inf
MODULE_FILE_BASE_NAME = LibGen
BASE_NAME = $(MODULE_NAME)
MODULE_RELATIVE_DIR = StdLib\PosixLib\Gen
MODULE_DIR = $(WORKSPACE)\StdLib\PosixLib\Gen

MODULE_ENTRY_POINT = _ModuleEntryPoint
ARCH_ENTRY_POINT = _ModuleEntryPoint
IMAGE_ENTRY_POINT = _ModuleEntryPoint

INF_VERSION = 0x00010006

#
# Build Configuration Macro Definition
#
ARCH = X64
TOOLCHAIN = VS2010x86
TOOLCHAIN_TAG = VS2010x86
TARGET = DEBUG

#
# Build Directory Macro Definition
#
# PLATFORM_BUILD_DIR = c:\vector-edk-master\Build\AppPkg\DEBUG_VS2010x86
BUILD_DIR = c:\vector-edk-master\Build\AppPkg\DEBUG_VS2010x86
BIN_DIR = $(BUILD_DIR)\X64
LIB_DIR = $(BIN_DIR)
MODULE_BUILD_DIR = c:\vector-edk-master\Build\AppPkg\DEBUG_VS2010x86\X64\StdLib\PosixLib\Gen\LibGen
OUTPUT_DIR = c:\vector-edk-master\Build\AppPkg\DEBUG_VS2010x86\X64\StdLib\PosixLib\Gen\LibGen\OUTPUT
DEBUG_DIR = c:\vector-edk-master\Build\AppPkg\DEBUG_VS2010x86\X64\StdLib\PosixLib\Gen\LibGen\DEBUG
DEST_DIR_OUTPUT = $(OUTPUT_DIR)
DEST_DIR_DEBUG = $(DEBUG_DIR)

#
# Shell Command Macro
#
RD = rmdir /s /q
RM = del /f /q
MD = mkdir
CP = copy /y
MV = move /y


#
# Tools definitions specific to this module
#

SYMRENAME =  echo
SYMRENAME_FLAGS = Symbol renaming not needed for

ASLDLINK =  C:\Program Files (x86)\Microsoft Visual Studio 10.0\Vc\bin\x86_amd64\link.exe
ASLDLINK_FLAGS = /NODEFAULTLIB /ENTRY:ReferenceAcpiTable /SUBSYSTEM:CONSOLE



VFR =  VfrCompile
VFR_FLAGS = -l -n

PP =  C:\Program Files (x86)\Microsoft Visual Studio 10.0\Vc\bin\x86_amd64\cl.exe
PP_FLAGS = /nologo /E /TC /FIAutoGen.h

LZMAF86 =  LzmaF86Compress
LZMAF86_GUID =  D42AE6BD-1352-4bfb-909A-CA72A6EAE889



GENFW =  GenFw
GENFW_FLAGS = 

OPTROM =  EfiRom
OPTROM_FLAGS = -e

SLINK =  C:\Program Files (x86)\Microsoft Visual Studio 10.0\Vc\bin\x86_amd64\lib.exe
SLINK_FLAGS = /NOLOGO /LTCG



RC =  c:\Program Files\Microsoft SDKs\Windows\v6.0A\bin\rc.exe


ASM =  C:\Program Files (x86)\Microsoft Visual Studio 10.0\Vc\bin\x86_amd64\ml64.exe
ASM_FLAGS = /nologo /c /WX /W3 /Cx /Zd /Zi

ASL =  C:\ASL\iasl.exe
ASL_FLAGS = 
ASL_OUTFLAGS =  -p


MTOC =  /usr/local/bin/mtoc

CC =  C:\Program Files (x86)\Microsoft Visual Studio 10.0\Vc\bin\x86_amd64\cl.exe
CC_FLAGS = /nologo /c /WX /GS- /X /W4 /Gs32768 /D UNICODE /O1ib2s /GL /Gy /FIAutoGen.h /EHs-c- /GR- /GF /Zi /Gm /X /Zc:wchar_t /D UEFI_C_SOURCE

VFRPP =  C:\Program Files (x86)\Microsoft Visual Studio 10.0\Vc\bin\x86_amd64\cl.exe
VFRPP_FLAGS = /nologo /E /TC /DVFRCOMPILE /FI$(MODULE_NAME)StrDefs.h



LZMA =  LzmaCompress
LZMA_GUID =  EE4E5898-3914-4259-9D6E-DC7BD79403CF

ASM16 =  C:\Program Files (x86)\Microsoft Visual Studio 10.0\Vc\bin\ml.exe

ASLCC =  C:\Program Files (x86)\Microsoft Visual Studio 10.0\Vc\bin\x86_amd64\cl.exe
ASLCC_FLAGS = /nologo /c /FIAutoGen.h /TC /Dmain=ReferenceAcpiTable


APP =  C:\Program Files (x86)\Microsoft Visual Studio 10.0\Vc\bin\x86_amd64\cl.exe
APP_FLAGS = /nologo /E /TC


DLINK =  C:\Program Files (x86)\Microsoft Visual Studio 10.0\Vc\bin\x86_amd64\link.exe
DLINK_FLAGS = /NOLOGO /NODEFAULTLIB /IGNORE:4001 /OPT:REF /OPT:ICF=10 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /Machine:X64 /LTCG /DLL /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /DEBUG

TIANO =  TianoCompress
TIANO_GUID =  A31280AD-481E-41B6-95E8-127F4C984779

VPDTOOL =  BPDG
VPDTOOL_GUID =  8C3D856A-9BE6-468E-850A-24F7A8D38E08

CRC32 =  GenCrc32
CRC32_GUID =  FC1BCDB0-7D31-49AA-936A-A4600D9DD083

ASLPP =  C:\Program Files (x86)\Microsoft Visual Studio 10.0\Vc\bin\x86_amd64\cl.exe
ASLPP_FLAGS = /nologo /E /C /FIAutoGen.h

OBJCOPY_ADDDEBUGFLAG =  --add-gnu-debuglink=$(DEBUG_DIR)\$(MODULE_NAME).debug
OBJCOPY =  echo
OBJCOPY_FLAGS = objcopy not needed for

MAKE =  C:\Program Files (x86)\Microsoft Visual Studio 10.0\Vc\bin\nmake.exe

ASMLINK =  C:\WINDDK\3790.1830\bin\bin16\link16.exe
ASMLINK_FLAGS = /nologo /tiny


MAKE_FILE = $(MODULE_BUILD_DIR)\Makefile

#
# Build Macro
#
OBJECT_FILES =  \
    $(OUTPUT_DIR)\dirname.obj \
    $(OUTPUT_DIR)\opendir.obj \
    $(OUTPUT_DIR)\closedir.obj \
    $(OUTPUT_DIR)\readdir.obj \
    $(OUTPUT_DIR)\access.obj \
    $(OUTPUT_DIR)\utime.obj

INC =  \
    /I$(WORKSPACE)\StdLib\PosixLib\Gen \
    /I$(DEBUG_DIR) \
    /I$(WORKSPACE)\MdePkg \
    /I$(WORKSPACE)\MdePkg\Include \
    /I$(WORKSPACE)\MdePkg\Include\X64 \
    /I$(WORKSPACE)\StdLib \
    /I$(WORKSPACE)\StdLib\Include \
    /I$(WORKSPACE)\StdLib\Include\X64 \
    /I$(WORKSPACE)\StdLibPrivateInternalFiles \
    /I$(WORKSPACE)\StdLibPrivateInternalFiles\Include \
    /I$(WORKSPACE)\StdLibPrivateInternalFiles\Include\X64

OBJECT_FILES_LIST = c:\vector-edk-master\Build\AppPkg\DEBUG_VS2010x86\X64\StdLib\PosixLib\Gen\LibGen\OUTPUT\object_files.lst


COMMON_DEPS = $(WORKSPACE)\MdePkg\Include\Uefi\UefiSpec.h \
              $(WORKSPACE)\MdePkg\Include\Protocol\SimpleTextInEx.h \
              $(WORKSPACE)\MdePkg\Include\Uefi\UefiGpt.h \
              $(WORKSPACE)\StdLib\Include\sys\EfiCdefs.h \
              $(WORKSPACE)\MdePkg\Include\Uefi\UefiPxe.h \
              $(WORKSPACE)\MdePkg\Include\Guid\PcAnsi.h \
              $(WORKSPACE)\MdePkg\Include\Guid\HiiFormMapMethodGuid.h \
              $(WORKSPACE)\StdLib\Include\sys\featuretest.h \
              $(DEBUG_DIR)\AutoGen.h \
              $(WORKSPACE)\MdePkg\Include\Protocol\SimpleTextOut.h \
              $(WORKSPACE)\MdePkg\Include\Protocol\SimpleTextIn.h \
              $(WORKSPACE)\MdePkg\Include\Protocol\DevicePath.h \
              $(WORKSPACE)\MdePkg\Include\Uefi.h \
              $(WORKSPACE)\MdePkg\Include\X64\ProcessorBind.h \
              $(WORKSPACE)\MdePkg\Include\Base.h \
              $(WORKSPACE)\MdePkg\Include\Uefi\UefiBaseType.h \
              $(WORKSPACE)\MdePkg\Include\Uefi\UefiMultiPhase.h \
              $(WORKSPACE)\MdePkg\Include\Uefi\UefiInternalFormRepresentation.h \
              $(WORKSPACE)\StdLib\Include\sys\cdefs_aout.h \
              $(WORKSPACE)\MdePkg\Include\Guid\WinCertificate.h \
              

#
# Overridable Target Macro Definitions
#
FORCE_REBUILD = force_build
INIT_TARGET = init
PCH_TARGET =
BC_TARGET = 
CODA_TARGET = c:\vector-edk-master\Build\AppPkg\DEBUG_VS2010x86\X64\StdLib\PosixLib\Gen\LibGen\OUTPUT\LibGen.lib \
              

#
# Default target, which will build dependent libraries in addition to source files
#

all: mbuild


#
# Target used when called from platform makefile, which will bypass the build of dependent libraries
#

pbuild: $(INIT_TARGET) $(BC_TARGET) $(PCH_TARGET) $(CODA_TARGET)

#
# ModuleTarget
#

mbuild: $(INIT_TARGET) $(BC_TARGET) gen_libs $(PCH_TARGET) $(CODA_TARGET)

#
# Build Target used in multi-thread build mode, which will bypass the init and gen_libs targets
#

tbuild: $(BC_TARGET) $(PCH_TARGET) $(CODA_TARGET)

#
# Phony target which is used to force executing commands for a target
#
force_build:
	-@

#
# Target to update the FD
#

fds: mbuild gen_fds

#
# Initialization target: print build information and create necessary directories
#
init: info dirs

info:
	-@echo Building ... $(MODULE_DIR)\$(MODULE_FILE) [$(ARCH)]

dirs:
	-@if not exist $(DEBUG_DIR) $(MD) $(DEBUG_DIR)
	-@if not exist $(OUTPUT_DIR) $(MD) $(OUTPUT_DIR)


strdefs:
	-@$(CP) $(DEBUG_DIR)\AutoGen.h $(DEBUG_DIR)\$(MODULE_NAME)StrDefs.h

#
# GenLibsTarget
#
gen_libs:
	@cd $(MODULE_BUILD_DIR)

#
# Build Flash Device Image
#
gen_fds:
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BUILD_DIR)\Makefile fds
	@cd $(MODULE_BUILD_DIR)

#
# Individual Object Build Targets
#
$(OUTPUT_DIR)\LibGen.lib : $(OBJECT_FILES)
	"$(SLINK)" $(SLINK_FLAGS) /OUT:c:\vector-edk-master\Build\AppPkg\DEBUG_VS2010x86\X64\StdLib\PosixLib\Gen\LibGen\OUTPUT\LibGen.lib @$(OBJECT_FILES_LIST)

$(OUTPUT_DIR)\opendir.obj : $(MAKE_FILE)
$(OUTPUT_DIR)\opendir.obj : $(COMMON_DEPS)
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\sys\fd_set.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\ansi.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\sys\endian.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\stdlib.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLibPrivateInternalFiles\Include\reentrant.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\byte_swap.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\sys\stat.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\dirent.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\param.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLibPrivateInternalFiles\Include\namespace.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\bswap.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\sys\param.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\sys\sigtypes.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\signal.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\x86\limits.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\assert.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\sys\types.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\sys\syslimits.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\time.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\sys\fcntl.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\sys\time.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\int_limits.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\int_types.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\errno.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\types.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\sys\stdint.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\signal.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\fcntl.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\string.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\endian_machdep.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\sys\select.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\sys\dirent.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\limits.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLibPrivateInternalFiles\Include\extern.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\sys\errno.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\sys\EfiSysCall.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\unistd.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\sys\unistd.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\int_const.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\int_mwgwtypes.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\sys\bswap.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\sys\ansi.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\sys\signal.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\endian.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\Include\sys\cdefs.h
$(OUTPUT_DIR)\opendir.obj : $(WORKSPACE)\StdLib\PosixLib\Gen\opendir.c
	"$(CC)" /Foc:\vector-edk-master\Build\AppPkg\DEBUG_VS2010x86\X64\StdLib\PosixLib\Gen\LibGen\OUTPUT\.\opendir.obj $(CC_FLAGS) $(INC) c:\vector-edk-master\StdLib\PosixLib\Gen\opendir.c

$(OUTPUT_DIR)\dirname.obj : $(MAKE_FILE)
$(OUTPUT_DIR)\dirname.obj : $(COMMON_DEPS)
$(OUTPUT_DIR)\dirname.obj : $(WORKSPACE)\StdLib\Include\limits.h
$(OUTPUT_DIR)\dirname.obj : $(WORKSPACE)\StdLib\Include\X64\machine\limits.h
$(OUTPUT_DIR)\dirname.obj : $(WORKSPACE)\StdLib\Include\x86\limits.h
$(OUTPUT_DIR)\dirname.obj : $(WORKSPACE)\StdLib\Include\sys\syslimits.h
$(OUTPUT_DIR)\dirname.obj : $(WORKSPACE)\StdLibPrivateInternalFiles\Include\LibConfig.h
$(OUTPUT_DIR)\dirname.obj : $(WORKSPACE)\StdLib\Include\ctype.h
$(OUTPUT_DIR)\dirname.obj : $(WORKSPACE)\StdLib\Include\string.h
$(OUTPUT_DIR)\dirname.obj : $(WORKSPACE)\StdLib\Include\sys\_ctype.h
$(OUTPUT_DIR)\dirname.obj : $(WORKSPACE)\MdePkg\Include\Library\PcdLib.h
$(OUTPUT_DIR)\dirname.obj : $(WORKSPACE)\StdLib\Include\sys\cdefs.h
$(OUTPUT_DIR)\dirname.obj : $(WORKSPACE)\StdLib\PosixLib\Gen\dirname.c
	"$(CC)" /Foc:\vector-edk-master\Build\AppPkg\DEBUG_VS2010x86\X64\StdLib\PosixLib\Gen\LibGen\OUTPUT\.\dirname.obj $(CC_FLAGS) $(INC) c:\vector-edk-master\StdLib\PosixLib\Gen\dirname.c

$(OUTPUT_DIR)\access.obj : $(MAKE_FILE)
$(OUTPUT_DIR)\access.obj : $(COMMON_DEPS)
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\sys\fd_set.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\X64\machine\ansi.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\sys\endian.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\X64\machine\byte_swap.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\sys\stat.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\X64\machine\int_mwgwtypes.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\X64\machine\bswap.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\sys\types.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\string.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\sys\syslimits.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\sys\sigtypes.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\sys\select.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\sys\time.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\X64\machine\int_limits.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\X64\machine\int_types.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLibPrivateInternalFiles\Include\LibConfig.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\errno.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\X64\machine\types.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\sys\stdint.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\ctype.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\X64\machine\endian_machdep.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\sys\_ctype.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\sys\errno.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\sys\EfiSysCall.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\unistd.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\sys\unistd.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\X64\machine\int_const.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\sys\bswap.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\sys\ansi.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\Include\X64\machine\endian.h
$(OUTPUT_DIR)\access.obj : $(WORKSPACE)\StdLib\PosixLib\Gen\access.c
	"$(CC)" /Foc:\vector-edk-master\Build\AppPkg\DEBUG_VS2010x86\X64\StdLib\PosixLib\Gen\LibGen\OUTPUT\.\access.obj $(CC_FLAGS) $(INC) c:\vector-edk-master\StdLib\PosixLib\Gen\access.c

$(OUTPUT_DIR)\utime.obj : $(MAKE_FILE)
$(OUTPUT_DIR)\utime.obj : $(COMMON_DEPS)
$(OUTPUT_DIR)\utime.obj : $(WORKSPACE)\StdLib\Include\sys\fd_set.h
$(OUTPUT_DIR)\utime.obj : $(WORKSPACE)\StdLib\Include\X64\machine\ansi.h
$(OUTPUT_DIR)\utime.obj : $(WORKSPACE)\StdLib\Include\sys\endian.h
$(OUTPUT_DIR)\utime.obj : $(WORKSPACE)\StdLib\Include\X64\machine\byte_swap.h
$(OUTPUT_DIR)\utime.obj : $(WORKSPACE)\StdLib\Include\X64\machine\endian_machdep.h
$(OUTPUT_DIR)\utime.obj : $(WORKSPACE)\StdLib\Include\X64\machine\int_mwgwtypes.h
$(OUTPUT_DIR)\utime.obj : $(WORKSPACE)\StdLib\Include\X64\machine\bswap.h
$(OUTPUT_DIR)\utime.obj : $(WORKSPACE)\StdLib\Include\assert.h
$(OUTPUT_DIR)\utime.obj : $(WORKSPACE)\StdLib\Include\sys\types.h
$(OUTPUT_DIR)\utime.obj : $(WORKSPACE)\StdLib\Include\sys\sigtypes.h
$(OUTPUT_DIR)\utime.obj : $(WORKSPACE)\StdLib\Include\sys\select.h
$(OUTPUT_DIR)\utime.obj : $(WORKSPACE)\StdLib\Include\sys\time.h
$(OUTPUT_DIR)\utime.obj : $(WORKSPACE)\StdLib\Include\X64\machine\int_limits.h
$(OUTPUT_DIR)\utime.obj : $(WORKSPACE)\StdLib\Include\X64\machine\int_types.h
$(OUTPUT_DIR)\utime.obj : $(WORKSPACE)\StdLib\Include\utime.h
$(OUTPUT_DIR)\utime.obj : $(WORKSPACE)\StdLibPrivateInternalFiles\Include\LibConfig.h
$(OUTPUT_DIR)\utime.obj : $(WORKSPACE)\StdLib\Include\errno.h
$(OUTPUT_DIR)\utime.obj : $(WORKSPACE)\StdLib\Include\X64\machine\types.h
$(OUTPUT_DIR)\utime.obj : $(WORKSPACE)\StdLib\Include\sys\stdint.h
$(OUTPUT_DIR)\utime.obj : $(WORKSPACE)\StdLib\Include\stddef.h
$(OUTPUT_DIR)\utime.obj : $(WORKSPACE)\StdLib\Include\sys\errno.h
$(OUTPUT_DIR)\utime.obj : $(WORKSPACE)\StdLib\Include\X64\machine\int_const.h
$(OUTPUT_DIR)\utime.obj : $(WORKSPACE)\StdLibPrivateInternalFiles\Include\namespace.h
$(OUTPUT_DIR)\utime.obj : $(WORKSPACE)\StdLib\Include\sys\bswap.h
$(OUTPUT_DIR)\utime.obj : $(WORKSPACE)\StdLib\Include\sys\ansi.h
$(OUTPUT_DIR)\utime.obj : $(WORKSPACE)\StdLib\Include\X64\machine\endian.h
$(OUTPUT_DIR)\utime.obj : $(WORKSPACE)\StdLib\Include\sys\cdefs.h
$(OUTPUT_DIR)\utime.obj : $(WORKSPACE)\StdLib\PosixLib\Gen\utime.c
	"$(CC)" /Foc:\vector-edk-master\Build\AppPkg\DEBUG_VS2010x86\X64\StdLib\PosixLib\Gen\LibGen\OUTPUT\.\utime.obj $(CC_FLAGS) $(INC) c:\vector-edk-master\StdLib\PosixLib\Gen\utime.c

$(OUTPUT_DIR)\closedir.obj : $(MAKE_FILE)
$(OUTPUT_DIR)\closedir.obj : $(COMMON_DEPS)
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\sys\fd_set.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\ansi.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\sys\endian.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\stdlib.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLibPrivateInternalFiles\Include\reentrant.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\byte_swap.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\endian_machdep.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\dirent.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\int_mwgwtypes.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\bswap.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\sys\sigtypes.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\signal.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\assert.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\sys\types.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\time.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\sys\select.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\sys\time.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\int_limits.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\int_types.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\types.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\sys\stdint.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\signal.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\errno.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\sys\dirent.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLibPrivateInternalFiles\Include\extern.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\sys\errno.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\sys\EfiSysCall.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\unistd.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\sys\unistd.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\int_const.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLibPrivateInternalFiles\Include\namespace.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\sys\bswap.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\sys\ansi.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\sys\signal.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\endian.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\Include\sys\cdefs.h
$(OUTPUT_DIR)\closedir.obj : $(WORKSPACE)\StdLib\PosixLib\Gen\closedir.c
	"$(CC)" /Foc:\vector-edk-master\Build\AppPkg\DEBUG_VS2010x86\X64\StdLib\PosixLib\Gen\LibGen\OUTPUT\.\closedir.obj $(CC_FLAGS) $(INC) c:\vector-edk-master\StdLib\PosixLib\Gen\closedir.c

$(OUTPUT_DIR)\readdir.obj : $(MAKE_FILE)
$(OUTPUT_DIR)\readdir.obj : $(COMMON_DEPS)
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\sys\fd_set.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\stdio.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\limits.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLibPrivateInternalFiles\Include\reentrant.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\byte_swap.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\ansi.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\endian_machdep.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\dirent.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\param.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLibPrivateInternalFiles\Include\namespace.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\sys\endian.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\bswap.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\sys\param.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\sys\sigtypes.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\signal.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\x86\limits.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\sys\types.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\sys\syslimits.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\time.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\sys\select.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\sys\time.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\int_limits.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\int_types.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\errno.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\types.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\sys\stdint.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\signal.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\stdarg.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\string.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\sys\bswap.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\sys\dirent.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\limits.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLibPrivateInternalFiles\Include\extern.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\sys\errno.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\sys\EfiSysCall.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\unistd.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\sys\unistd.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\int_const.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\int_mwgwtypes.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\MdePkg\Include\Library\PcdLib.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\sys\ansi.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\sys\signal.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\X64\machine\endian.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\Include\sys\cdefs.h
$(OUTPUT_DIR)\readdir.obj : $(WORKSPACE)\StdLib\PosixLib\Gen\readdir.c
	"$(CC)" /Foc:\vector-edk-master\Build\AppPkg\DEBUG_VS2010x86\X64\StdLib\PosixLib\Gen\LibGen\OUTPUT\.\readdir.obj $(CC_FLAGS) $(INC) c:\vector-edk-master\StdLib\PosixLib\Gen\readdir.c



#
# clean all intermediate files
#
clean:
	if exist $(OUTPUT_DIR) $(RD) $(OUTPUT_DIR)
	

#
# clean all generated files
#
cleanall:
	if exist $(DEBUG_DIR) $(RD) $(DEBUG_DIR)
	if exist $(OUTPUT_DIR) $(RD) $(OUTPUT_DIR)
	$(RM) *.pdb *.idb > NUL 2>&1
	$(RM) $(BIN_DIR)\$(MODULE_NAME).efi

#
# clean all dependent libraries built
#
cleanlib:
	@cd $(MODULE_BUILD_DIR)

