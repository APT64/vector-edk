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
PLATFORM_NAME = Ovmf
PLATFORM_GUID = 5a9e7754-d81b-49ea-85ad-69eaa7b1539b
PLATFORM_VERSION = 0.1
PLATFORM_RELATIVE_DIR = OvmfPkg
PLATFORM_DIR = $(WORKSPACE)\OvmfPkg
PLATFORM_OUTPUT_DIR = Build\OvmfX64

#
# Module Macro Definition
#
MODULE_NAME = VlanConfigDxe
MODULE_GUID = E4F61863-FE2C-4b56-A8F4-08519BC439DF
MODULE_VERSION = 1.0
MODULE_TYPE = UEFI_DRIVER
MODULE_FILE = VlanConfigDxe.inf
MODULE_FILE_BASE_NAME = VlanConfigDxe
BASE_NAME = $(MODULE_NAME)
MODULE_RELATIVE_DIR = MdeModulePkg\Universal\Network\VlanConfigDxe
MODULE_DIR = $(WORKSPACE)\MdeModulePkg\Universal\Network\VlanConfigDxe

MODULE_ENTRY_POINT = VlanConfigDriverEntryPoint
ARCH_ENTRY_POINT = VlanConfigDriverEntryPoint
IMAGE_ENTRY_POINT = _ModuleEntryPoint

INF_VERSION = 0x00010005

#
# Build Configuration Macro Definition
#
ARCH = X64
TOOLCHAIN = VS2010x86
TOOLCHAIN_TAG = VS2010x86
TARGET = RELEASE

#
# Build Directory Macro Definition
#
# PLATFORM_BUILD_DIR = c:\vector-edk-master\Build\OvmfX64\RELEASE_VS2010x86
BUILD_DIR = c:\vector-edk-master\Build\OvmfX64\RELEASE_VS2010x86
BIN_DIR = $(BUILD_DIR)\X64
LIB_DIR = $(BIN_DIR)
MODULE_BUILD_DIR = c:\vector-edk-master\Build\OvmfX64\RELEASE_VS2010x86\X64\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfigDxe
OUTPUT_DIR = c:\vector-edk-master\Build\OvmfX64\RELEASE_VS2010x86\X64\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfigDxe\OUTPUT
DEBUG_DIR = c:\vector-edk-master\Build\OvmfX64\RELEASE_VS2010x86\X64\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfigDxe\DEBUG
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


SLINK =  C:\Program Files (x86)\Microsoft Visual Studio 10.0\Vc\bin\x86_amd64\lib.exe
SLINK_FLAGS = /NOLOGO /LTCG



RC =  c:\Program Files\Microsoft SDKs\Windows\v6.0A\bin\rc.exe


ASM =  C:\Program Files (x86)\Microsoft Visual Studio 10.0\Vc\bin\x86_amd64\ml64.exe
ASM_FLAGS = /nologo /c /WX /W3 /Cx /Zd

ASL =  C:\ASL\iasl.exe
ASL_FLAGS = 
ASL_OUTFLAGS =  -p


MTOC =  /usr/local/bin/mtoc

CC =  C:\Program Files (x86)\Microsoft Visual Studio 10.0\Vc\bin\x86_amd64\cl.exe
CC_FLAGS = /nologo /c /WX /GS- /X /W4 /Gs32768 /D UNICODE /O1ib2s /GL /Gy /FIAutoGen.h /EHs-c- /GR- /GF /D MDEPKG_NDEBUG

VFRPP =  C:\Program Files (x86)\Microsoft Visual Studio 10.0\Vc\bin\x86_amd64\cl.exe
VFRPP_FLAGS = /nologo /E /TC /DVFRCOMPILE /FI$(MODULE_NAME)StrDefs.h



LZMA =  LzmaCompress
LZMA_GUID =  EE4E5898-3914-4259-9D6E-DC7BD79403CF

ASM16 =  C:\Program Files (x86)\Microsoft Visual Studio 10.0\Vc\bin\ml.exe

ASLCC =  C:\Program Files (x86)\Microsoft Visual Studio 10.0\Vc\bin\x86_amd64\cl.exe
ASLCC_FLAGS = /nologo /c /FIAutoGen.h /TC /Dmain=ReferenceAcpiTable


APP =  C:\Program Files (x86)\Microsoft Visual Studio 10.0\Vc\bin\x86_amd64\cl.exe
APP_FLAGS = /nologo /E /TC

OPTROM =  EfiRom
OPTROM_FLAGS = -e

DLINK =  C:\Program Files (x86)\Microsoft Visual Studio 10.0\Vc\bin\x86_amd64\link.exe
DLINK_FLAGS = /NOLOGO /NODEFAULTLIB /IGNORE:4001 /IGNORE:4254 /OPT:REF /OPT:ICF=10 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /Machine:X64 /LTCG /DLL /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /MERGE:.data=.text /MERGE:.rdata=.text

TIANO =  TianoCompress
TIANO_GUID =  A31280AD-481E-41B6-95E8-127F4C984779

VPDTOOL =  BPDG
VPDTOOL_GUID =  8C3D856A-9BE6-468E-850A-24F7A8D38E08

CRC32 =  GenCrc32
CRC32_GUID =  FC1BCDB0-7D31-49AA-936A-A4600D9DD083

ASLPP =  C:\Program Files (x86)\Microsoft Visual Studio 10.0\Vc\bin\x86_amd64\cl.exe
ASLPP_FLAGS = /nologo /E /C /FIAutoGen.h

OBJCOPY_ADDDEBUGFLAG =  
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
    $(OUTPUT_DIR)\ComponentName.obj \
    $(OUTPUT_DIR)\VlanConfigDriver.obj \
    $(OUTPUT_DIR)\VlanConfigImpl.obj \
    $(OUTPUT_DIR)\VlanConfig.obj \
    $(OUTPUT_DIR)\AutoGen.obj

STATIC_LIBRARY_FILES =  \
    $(BIN_DIR)\MdePkg\Library\BasePcdLibNull\BasePcdLibNull\OUTPUT\BasePcdLibNull.lib \
    $(BIN_DIR)\MdePkg\Library\BaseMemoryLibRepStr\BaseMemoryLibRepStr\OUTPUT\BaseMemoryLibRepStr.lib \
    $(BIN_DIR)\MdePkg\Library\BaseLib\BaseLib\OUTPUT\BaseLib.lib \
    $(BIN_DIR)\MdePkg\Library\BaseDebugPrintErrorLevelLib\BaseDebugPrintErrorLevelLib\OUTPUT\BaseDebugPrintErrorLevelLib.lib \
    $(BIN_DIR)\MdePkg\Library\BaseIoLibIntrinsic\BaseIoLibIntrinsic\OUTPUT\BaseIoLibIntrinsic.lib \
    $(BIN_DIR)\MdePkg\Library\BasePrintLib\BasePrintLib\OUTPUT\BasePrintLib.lib \
    $(BIN_DIR)\OvmfPkg\Library\PlatformDebugLibIoPort\PlatformDebugLibIoPort\OUTPUT\PlatformDebugLibIoPort.lib \
    $(BIN_DIR)\MdePkg\Library\UefiBootServicesTableLib\UefiBootServicesTableLib\OUTPUT\UefiBootServicesTableLib.lib \
    $(BIN_DIR)\MdePkg\Library\UefiMemoryAllocationLib\UefiMemoryAllocationLib\OUTPUT\UefiMemoryAllocationLib.lib \
    $(BIN_DIR)\MdePkg\Library\UefiRuntimeServicesTableLib\UefiRuntimeServicesTableLib\OUTPUT\UefiRuntimeServicesTableLib.lib \
    $(BIN_DIR)\MdePkg\Library\UefiDevicePathLibDevicePathProtocol\UefiDevicePathLibDevicePathProtocol\OUTPUT\UefiDevicePathLibDevicePathProtocol.lib \
    $(BIN_DIR)\MdeModulePkg\Library\UefiHiiServicesLib\UefiHiiServicesLib\OUTPUT\UefiHiiServicesLib.lib \
    $(BIN_DIR)\MdePkg\Library\UefiLib\UefiLib\OUTPUT\UefiLib.lib \
    $(BIN_DIR)\MdeModulePkg\Library\UefiHiiLib\UefiHiiLib\OUTPUT\UefiHiiLib.lib \
    $(BIN_DIR)\MdePkg\Library\UefiDriverEntryPoint\UefiDriverEntryPoint\OUTPUT\UefiDriverEntryPoint.lib \
    $(BIN_DIR)\MdeModulePkg\Library\DxeNetLib\DxeNetLib\OUTPUT\DxeNetLib.lib \
    $(OUTPUT_DIR)\VlanConfigDxe.lib

INC =  \
    /I$(WORKSPACE)\MdeModulePkg\Universal\Network\VlanConfigDxe \
    /I$(DEBUG_DIR) \
    /I$(WORKSPACE)\MdePkg \
    /I$(WORKSPACE)\MdePkg\Include \
    /I$(WORKSPACE)\MdePkg\Include\X64 \
    /I$(WORKSPACE)\MdeModulePkg \
    /I$(WORKSPACE)\MdeModulePkg\Include

OBJECT_FILES_LIST = c:\vector-edk-master\Build\OvmfX64\RELEASE_VS2010x86\X64\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfigDxe\OUTPUT\object_files.lst
STATIC_LIBRARY_FILES_LIST = c:\vector-edk-master\Build\OvmfX64\RELEASE_VS2010x86\X64\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfigDxe\OUTPUT\static_library_files.lst


COMMON_DEPS = $(WORKSPACE)\MdePkg\Include\Uefi\UefiSpec.h \
              $(WORKSPACE)\MdePkg\Include\Guid\HiiFormMapMethodGuid.h \
              $(WORKSPACE)\MdePkg\Include\Protocol\DriverConfiguration.h \
              $(WORKSPACE)\MdePkg\Include\Library\BaseLib.h \
              $(WORKSPACE)\MdePkg\Include\Protocol\DriverBinding.h \
              $(WORKSPACE)\MdePkg\Include\Protocol\ComponentName2.h \
              $(WORKSPACE)\MdePkg\Include\Protocol\HiiConfigRouting.h \
              $(WORKSPACE)\MdePkg\Include\Protocol\DriverDiagnostics.h \
              $(WORKSPACE)\MdePkg\Include\X64\ProcessorBind.h \
              $(WORKSPACE)\MdePkg\Include\Library\PrintLib.h \
              $(WORKSPACE)\MdePkg\Include\Protocol\DevicePath.h \
              $(WORKSPACE)\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfigImpl.h \
              $(WORKSPACE)\MdePkg\Include\Library\MemoryAllocationLib.h \
              $(WORKSPACE)\MdePkg\Include\Library\UefiLib.h \
              $(WORKSPACE)\MdePkg\Include\Guid\PcAnsi.h \
              $(WORKSPACE)\MdePkg\Include\Protocol\Ip6.h \
              $(WORKSPACE)\MdePkg\Include\Library\DebugLib.h \
              $(WORKSPACE)\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfigNvData.h \
              $(DEBUG_DIR)\VlanConfigDxeStrDefs.h \
              $(WORKSPACE)\MdePkg\Include\Protocol\ManagedNetwork.h \
              $(WORKSPACE)\MdePkg\Include\Protocol\SimpleTextIn.h \
              $(WORKSPACE)\MdeModulePkg\Include\Guid\VlanConfigHii.h \
              $(DEBUG_DIR)\AutoGen.h \
              $(WORKSPACE)\MdeModulePkg\Include\Library\NetLib.h \
              $(WORKSPACE)\MdePkg\Include\Protocol\SimpleTextInEx.h \
              $(WORKSPACE)\MdePkg\Include\Uefi\UefiGpt.h \
              $(WORKSPACE)\MdePkg\Include\Guid\HiiPlatformSetupFormset.h \
              $(WORKSPACE)\MdePkg\Include\Protocol\FormBrowser2.h \
              $(WORKSPACE)\MdePkg\Include\Protocol\SimpleNetwork.h \
              $(WORKSPACE)\MdePkg\Include\Uefi\UefiInternalFormRepresentation.h \
              $(WORKSPACE)\MdePkg\Include\Uefi.h \
              $(WORKSPACE)\MdePkg\Include\Base.h \
              $(WORKSPACE)\MdePkg\Include\Uefi\UefiBaseType.h \
              $(WORKSPACE)\MdePkg\Include\Uefi\UefiMultiPhase.h \
              $(WORKSPACE)\MdePkg\Include\Protocol\DriverDiagnostics2.h \
              $(WORKSPACE)\MdePkg\Include\Uefi\UefiPxe.h \
              $(WORKSPACE)\MdeModulePkg\Include\Guid\MdeModuleHii.h \
              $(WORKSPACE)\MdePkg\Include\Protocol\HiiConfigAccess.h \
              $(WORKSPACE)\MdePkg\Include\Library\BaseMemoryLib.h \
              $(WORKSPACE)\MdePkg\Include\Library\UefiBootServicesTableLib.h \
              $(WORKSPACE)\MdePkg\Include\Protocol\DriverConfiguration2.h \
              $(WORKSPACE)\MdePkg\Include\Protocol\VlanConfig.h \
              $(WORKSPACE)\MdePkg\Include\Protocol\SimpleTextOut.h \
              $(WORKSPACE)\MdeModulePkg\Include\Library\HiiLib.h \
              $(WORKSPACE)\MdePkg\Include\Protocol\GraphicsOutput.h \
              $(WORKSPACE)\MdePkg\Include\Protocol\ComponentName.h \
              $(WORKSPACE)\MdePkg\Include\Library\DevicePathLib.h \
              $(WORKSPACE)\MdePkg\Include\Guid\WinCertificate.h \
              

#
# Overridable Target Macro Definitions
#
FORCE_REBUILD = force_build
INIT_TARGET = init
PCH_TARGET =
BC_TARGET = 
CODA_TARGET = c:\vector-edk-master\Build\OvmfX64\RELEASE_VS2010x86\X64\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfigDxe\DEBUG\VlanConfigDxe.efi \
              

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
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdePkg\Library\BasePcdLibNull\BasePcdLibNull\Makefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdePkg\Library\BaseMemoryLibRepStr\BaseMemoryLibRepStr\Makefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdePkg\Library\BaseLib\BaseLib\Makefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdePkg\Library\BaseDebugPrintErrorLevelLib\BaseDebugPrintErrorLevelLib\Makefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdePkg\Library\BaseIoLibIntrinsic\BaseIoLibIntrinsic\Makefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdePkg\Library\BasePrintLib\BasePrintLib\Makefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\OvmfPkg\Library\PlatformDebugLibIoPort\PlatformDebugLibIoPort\Makefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdePkg\Library\UefiBootServicesTableLib\UefiBootServicesTableLib\Makefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdePkg\Library\UefiMemoryAllocationLib\UefiMemoryAllocationLib\Makefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdePkg\Library\UefiRuntimeServicesTableLib\UefiRuntimeServicesTableLib\Makefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdePkg\Library\UefiDevicePathLibDevicePathProtocol\UefiDevicePathLibDevicePathProtocol\Makefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdeModulePkg\Library\UefiHiiServicesLib\UefiHiiServicesLib\Makefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdePkg\Library\UefiLib\UefiLib\Makefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdeModulePkg\Library\UefiHiiLib\UefiHiiLib\Makefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdePkg\Library\UefiDriverEntryPoint\UefiDriverEntryPoint\Makefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdeModulePkg\Library\DxeNetLib\DxeNetLib\Makefile
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
$(DEBUG_DIR)\VlanConfigDxe.efi : $(DEBUG_DIR)\VlanConfigDxe.dll
	"$(GENFW)" -e $(MODULE_TYPE) -o c:\vector-edk-master\Build\OvmfX64\RELEASE_VS2010x86\X64\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfigDxe\DEBUG\VlanConfigDxe.efi c:\vector-edk-master\Build\OvmfX64\RELEASE_VS2010x86\X64\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfigDxe\DEBUG\VlanConfigDxe.dll $(GENFW_FLAGS)
	$(CP) c:\vector-edk-master\Build\OvmfX64\RELEASE_VS2010x86\X64\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfigDxe\DEBUG\VlanConfigDxe.efi $(OUTPUT_DIR)
	$(CP) c:\vector-edk-master\Build\OvmfX64\RELEASE_VS2010x86\X64\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfigDxe\DEBUG\VlanConfigDxe.efi $(BIN_DIR)
	-$(CP) $(DEBUG_DIR)\*.map $(OUTPUT_DIR)

$(OUTPUT_DIR)\VlanConfigDxe.lib : $(OBJECT_FILES)
	"$(SLINK)" $(SLINK_FLAGS) /OUT:c:\vector-edk-master\Build\OvmfX64\RELEASE_VS2010x86\X64\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfigDxe\OUTPUT\VlanConfigDxe.lib @$(OBJECT_FILES_LIST)

$(DEBUG_DIR)\VlanConfigDxe.dll : $(MAKE_FILE)
$(DEBUG_DIR)\VlanConfigDxe.dll : $(STATIC_LIBRARY_FILES)
	"$(DLINK)" /OUT:c:\vector-edk-master\Build\OvmfX64\RELEASE_VS2010x86\X64\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfigDxe\DEBUG\VlanConfigDxe.dll $(DLINK_FLAGS) $(DLINK_SPATH) @$(STATIC_LIBRARY_FILES_LIST)

$(OUTPUT_DIR)\VlanConfig.obj : $(MAKE_FILE)
$(OUTPUT_DIR)\VlanConfig.obj : $(DEBUG_DIR)\VlanConfig.c
	"$(CC)" /Foc:\vector-edk-master\Build\OvmfX64\RELEASE_VS2010x86\X64\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfigDxe\OUTPUT\.\VlanConfig.obj $(CC_FLAGS) $(INC) c:\vector-edk-master\Build\OvmfX64\RELEASE_VS2010x86\X64\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfigDxe\DEBUG\VlanConfig.c

$(OUTPUT_DIR)\AutoGen.obj : $(MAKE_FILE)
$(OUTPUT_DIR)\AutoGen.obj : $(WORKSPACE)\MdePkg\Include\Uefi\UefiSpec.h
$(OUTPUT_DIR)\AutoGen.obj : $(WORKSPACE)\MdePkg\Include\Library\UefiBootServicesTableLib.h
$(OUTPUT_DIR)\AutoGen.obj : $(WORKSPACE)\MdePkg\Include\Library\BaseLib.h
$(OUTPUT_DIR)\AutoGen.obj : $(WORKSPACE)\MdePkg\Include\Library\UefiDriverEntryPoint.h
$(OUTPUT_DIR)\AutoGen.obj : $(WORKSPACE)\MdePkg\Include\Protocol\DevicePath.h
$(OUTPUT_DIR)\AutoGen.obj : $(DEBUG_DIR)\AutoGen.h
$(OUTPUT_DIR)\AutoGen.obj : $(WORKSPACE)\MdePkg\Include\Guid\PcAnsi.h
$(OUTPUT_DIR)\AutoGen.obj : $(WORKSPACE)\MdePkg\Include\Library\DebugLib.h
$(OUTPUT_DIR)\AutoGen.obj : $(WORKSPACE)\MdePkg\Include\Guid\HiiFormMapMethodGuid.h
$(OUTPUT_DIR)\AutoGen.obj : $(WORKSPACE)\MdePkg\Include\Protocol\SimpleTextIn.h
$(OUTPUT_DIR)\AutoGen.obj : $(WORKSPACE)\MdePkg\Include\Uefi\UefiMultiPhase.h
$(OUTPUT_DIR)\AutoGen.obj : $(WORKSPACE)\MdePkg\Include\Protocol\SimpleTextInEx.h
$(OUTPUT_DIR)\AutoGen.obj : $(WORKSPACE)\MdePkg\Include\Uefi\UefiGpt.h
$(OUTPUT_DIR)\AutoGen.obj : $(WORKSPACE)\MdePkg\Include\Uefi\UefiInternalFormRepresentation.h
$(OUTPUT_DIR)\AutoGen.obj : $(WORKSPACE)\MdePkg\Include\Uefi.h
$(OUTPUT_DIR)\AutoGen.obj : $(WORKSPACE)\MdePkg\Include\Base.h
$(OUTPUT_DIR)\AutoGen.obj : $(WORKSPACE)\MdePkg\Include\Uefi\UefiBaseType.h
$(OUTPUT_DIR)\AutoGen.obj : $(WORKSPACE)\MdePkg\Include\Uefi\UefiPxe.h
$(OUTPUT_DIR)\AutoGen.obj : $(DEBUG_DIR)\VlanConfigDxeStrDefs.h
$(OUTPUT_DIR)\AutoGen.obj : $(WORKSPACE)\MdePkg\Include\Protocol\SimpleTextOut.h
$(OUTPUT_DIR)\AutoGen.obj : $(WORKSPACE)\MdePkg\Include\X64\ProcessorBind.h
$(OUTPUT_DIR)\AutoGen.obj : $(WORKSPACE)\MdePkg\Include\Guid\WinCertificate.h
$(OUTPUT_DIR)\AutoGen.obj : $(DEBUG_DIR)\AutoGen.c
	"$(CC)" /Foc:\vector-edk-master\Build\OvmfX64\RELEASE_VS2010x86\X64\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfigDxe\OUTPUT\.\AutoGen.obj $(CC_FLAGS) $(INC) c:\vector-edk-master\Build\OvmfX64\RELEASE_VS2010x86\X64\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfigDxe\DEBUG\AutoGen.c

$(OUTPUT_DIR)\VlanConfigImpl.obj : $(MAKE_FILE)
$(OUTPUT_DIR)\VlanConfigImpl.obj : $(COMMON_DEPS)
$(OUTPUT_DIR)\VlanConfigImpl.obj : $(WORKSPACE)\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfigImpl.c
	"$(CC)" /Foc:\vector-edk-master\Build\OvmfX64\RELEASE_VS2010x86\X64\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfigDxe\OUTPUT\.\VlanConfigImpl.obj $(CC_FLAGS) $(INC) c:\vector-edk-master\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfigImpl.c

$(OUTPUT_DIR)\ComponentName.obj : $(MAKE_FILE)
$(OUTPUT_DIR)\ComponentName.obj : $(COMMON_DEPS)
$(OUTPUT_DIR)\ComponentName.obj : $(WORKSPACE)\MdeModulePkg\Universal\Network\VlanConfigDxe\ComponentName.c
	"$(CC)" /Foc:\vector-edk-master\Build\OvmfX64\RELEASE_VS2010x86\X64\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfigDxe\OUTPUT\.\ComponentName.obj $(CC_FLAGS) $(INC) c:\vector-edk-master\MdeModulePkg\Universal\Network\VlanConfigDxe\ComponentName.c

$(OUTPUT_DIR)\VlanConfigDriver.obj : $(MAKE_FILE)
$(OUTPUT_DIR)\VlanConfigDriver.obj : $(COMMON_DEPS)
$(OUTPUT_DIR)\VlanConfigDriver.obj : $(WORKSPACE)\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfigDriver.c
	"$(CC)" /Foc:\vector-edk-master\Build\OvmfX64\RELEASE_VS2010x86\X64\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfigDxe\OUTPUT\.\VlanConfigDriver.obj $(CC_FLAGS) $(INC) c:\vector-edk-master\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfigDriver.c

$(DEBUG_DIR)\VlanConfig.c : $(MAKE_FILE)
$(DEBUG_DIR)\VlanConfig.c : $(WORKSPACE)\MdePkg\Include\Uefi\UefiSpec.h
$(DEBUG_DIR)\VlanConfig.c : $(WORKSPACE)\MdePkg\Include\Protocol\SimpleTextInEx.h
$(DEBUG_DIR)\VlanConfig.c : $(WORKSPACE)\MdePkg\Include\Uefi\UefiGpt.h
$(DEBUG_DIR)\VlanConfig.c : $(DEBUG_DIR)\VlanConfigDxeStrDefs.h
$(DEBUG_DIR)\VlanConfig.c : $(WORKSPACE)\MdePkg\Include\Guid\PcAnsi.h
$(DEBUG_DIR)\VlanConfig.c : $(WORKSPACE)\MdePkg\Include\Guid\HiiPlatformSetupFormset.h
$(DEBUG_DIR)\VlanConfig.c : $(WORKSPACE)\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfigNvData.h
$(DEBUG_DIR)\VlanConfig.c : $(WORKSPACE)\MdeModulePkg\Include\Guid\VlanConfigHii.h
$(DEBUG_DIR)\VlanConfig.c : $(WORKSPACE)\MdePkg\Include\Uefi\UefiPxe.h
$(DEBUG_DIR)\VlanConfig.c : $(WORKSPACE)\MdePkg\Include\Guid\HiiFormMapMethodGuid.h
$(DEBUG_DIR)\VlanConfig.c : $(WORKSPACE)\MdePkg\Include\Protocol\SimpleTextOut.h
$(DEBUG_DIR)\VlanConfig.c : $(DEBUG_DIR)\AutoGen.h
$(DEBUG_DIR)\VlanConfig.c : $(WORKSPACE)\MdePkg\Include\Protocol\SimpleTextIn.h
$(DEBUG_DIR)\VlanConfig.c : $(WORKSPACE)\MdePkg\Include\Protocol\DevicePath.h
$(DEBUG_DIR)\VlanConfig.c : $(WORKSPACE)\MdePkg\Include\Uefi.h
$(DEBUG_DIR)\VlanConfig.c : $(WORKSPACE)\MdePkg\Include\X64\ProcessorBind.h
$(DEBUG_DIR)\VlanConfig.c : $(WORKSPACE)\MdePkg\Include\Base.h
$(DEBUG_DIR)\VlanConfig.c : $(WORKSPACE)\MdePkg\Include\Uefi\UefiBaseType.h
$(DEBUG_DIR)\VlanConfig.c : $(WORKSPACE)\MdePkg\Include\Guid\WinCertificate.h
$(DEBUG_DIR)\VlanConfig.c : $(WORKSPACE)\MdePkg\Include\Uefi\UefiInternalFormRepresentation.h
$(DEBUG_DIR)\VlanConfig.c : $(WORKSPACE)\MdePkg\Include\Uefi\UefiMultiPhase.h
$(DEBUG_DIR)\VlanConfig.c : $(WORKSPACE)\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfig.vfr
	"$(VFRPP)" $(VFRPP_FLAGS) $(INC) c:\vector-edk-master\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfig.vfr > $(OUTPUT_DIR)\VlanConfig.i
	"$(VFR)" $(VFR_FLAGS) --string-db $(OUTPUT_DIR)\$(MODULE_NAME)StrDefs.hpk --output-directory c:\vector-edk-master\Build\OvmfX64\RELEASE_VS2010x86\X64\MdeModulePkg\Universal\Network\VlanConfigDxe\VlanConfigDxe\DEBUG\. $(OUTPUT_DIR)\VlanConfig.i



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
	-@if exist $(BIN_DIR)\MdePkg\Library\BasePcdLibNull\BasePcdLibNull\Makefile "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdePkg\Library\BasePcdLibNull\BasePcdLibNull\Makefile cleanall
	-@if exist $(BIN_DIR)\MdePkg\Library\BaseMemoryLibRepStr\BaseMemoryLibRepStr\Makefile "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdePkg\Library\BaseMemoryLibRepStr\BaseMemoryLibRepStr\Makefile cleanall
	-@if exist $(BIN_DIR)\MdePkg\Library\BaseLib\BaseLib\Makefile "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdePkg\Library\BaseLib\BaseLib\Makefile cleanall
	-@if exist $(BIN_DIR)\MdePkg\Library\BaseDebugPrintErrorLevelLib\BaseDebugPrintErrorLevelLib\Makefile "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdePkg\Library\BaseDebugPrintErrorLevelLib\BaseDebugPrintErrorLevelLib\Makefile cleanall
	-@if exist $(BIN_DIR)\MdePkg\Library\BaseIoLibIntrinsic\BaseIoLibIntrinsic\Makefile "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdePkg\Library\BaseIoLibIntrinsic\BaseIoLibIntrinsic\Makefile cleanall
	-@if exist $(BIN_DIR)\MdePkg\Library\BasePrintLib\BasePrintLib\Makefile "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdePkg\Library\BasePrintLib\BasePrintLib\Makefile cleanall
	-@if exist $(BIN_DIR)\OvmfPkg\Library\PlatformDebugLibIoPort\PlatformDebugLibIoPort\Makefile "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\OvmfPkg\Library\PlatformDebugLibIoPort\PlatformDebugLibIoPort\Makefile cleanall
	-@if exist $(BIN_DIR)\MdePkg\Library\UefiBootServicesTableLib\UefiBootServicesTableLib\Makefile "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdePkg\Library\UefiBootServicesTableLib\UefiBootServicesTableLib\Makefile cleanall
	-@if exist $(BIN_DIR)\MdePkg\Library\UefiMemoryAllocationLib\UefiMemoryAllocationLib\Makefile "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdePkg\Library\UefiMemoryAllocationLib\UefiMemoryAllocationLib\Makefile cleanall
	-@if exist $(BIN_DIR)\MdePkg\Library\UefiRuntimeServicesTableLib\UefiRuntimeServicesTableLib\Makefile "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdePkg\Library\UefiRuntimeServicesTableLib\UefiRuntimeServicesTableLib\Makefile cleanall
	-@if exist $(BIN_DIR)\MdePkg\Library\UefiDevicePathLibDevicePathProtocol\UefiDevicePathLibDevicePathProtocol\Makefile "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdePkg\Library\UefiDevicePathLibDevicePathProtocol\UefiDevicePathLibDevicePathProtocol\Makefile cleanall
	-@if exist $(BIN_DIR)\MdeModulePkg\Library\UefiHiiServicesLib\UefiHiiServicesLib\Makefile "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdeModulePkg\Library\UefiHiiServicesLib\UefiHiiServicesLib\Makefile cleanall
	-@if exist $(BIN_DIR)\MdePkg\Library\UefiLib\UefiLib\Makefile "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdePkg\Library\UefiLib\UefiLib\Makefile cleanall
	-@if exist $(BIN_DIR)\MdeModulePkg\Library\UefiHiiLib\UefiHiiLib\Makefile "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdeModulePkg\Library\UefiHiiLib\UefiHiiLib\Makefile cleanall
	-@if exist $(BIN_DIR)\MdePkg\Library\UefiDriverEntryPoint\UefiDriverEntryPoint\Makefile "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdePkg\Library\UefiDriverEntryPoint\UefiDriverEntryPoint\Makefile cleanall
	-@if exist $(BIN_DIR)\MdeModulePkg\Library\DxeNetLib\DxeNetLib\Makefile "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)\MdeModulePkg\Library\DxeNetLib\DxeNetLib\Makefile cleanall
	@cd $(MODULE_BUILD_DIR)

