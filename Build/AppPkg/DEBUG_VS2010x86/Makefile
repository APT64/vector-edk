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

#
# Build Configuration Macro Definition
#
TOOLCHAIN = VS2010x86
TOOLCHAIN_TAG = VS2010x86
TARGET = DEBUG

#
# Build Directory Macro Definition
#
BUILD_DIR = c:\vector-edk-master\Build\AppPkg\DEBUG_VS2010x86
FV_DIR = c:\vector-edk-master\Build\AppPkg\DEBUG_VS2010x86\FV

#
# Shell Command Macro
#
RD = rmdir /s /q
RM = del /f /q
MD = mkdir
CP = copy /y
MV = move /y


MAKE = C:\Program Files (x86)\Microsoft Visual Studio 10.0\Vc\bin\nmake.exe
MAKE_FILE = $(BUILD_DIR)\Makefile

#
# Default target
#
all: modules fds

#
# Initialization target: print build information and create necessary directories
#
init:
	-@
	-@if not exist $(BUILD_DIR)\X64 $(MD) $(BUILD_DIR)\X64
	-@if not exist $(FV_DIR) $(MD) $(FV_DIR)
	
#
# library build target
#
libraries: init
	@cd $(BUILD_DIR)\X64 && "$(MAKE)" $(MAKE_FLAGS) libraries
	@cd $(BUILD_DIR)

#
# module build target
#
modules: init
	@cd $(BUILD_DIR)\X64 && "$(MAKE)" $(MAKE_FLAGS) modules
	@cd $(BUILD_DIR)

#
# Flash Device Image Target
#
fds: init
	-@cd $(FV_DIR)


#
# run command for emulator platform only
#
run:
	cd $(BUILD_DIR)\IA32 && ".\SecMain"
	cd $(BUILD_DIR)

#
# Clean intermediate files
#
clean:
	-@if exist $(BUILD_DIR)\X64\Makefile "$(MAKE)" $(MAKE_FLAGS) -f $(BUILD_DIR)\X64\Makefile clean
	@cd $(BUILD_DIR)

#
# Clean all generated files except to makefile
#
cleanall:
	if exist $(BUILD_DIR)\X64 $(RD) $(BUILD_DIR)\X64
	if exist $(FV_DIR) $(RD) $(FV_DIR)


#
# Clean all library files
#
cleanlib:
	-@if exist $(BUILD_DIR)\X64\Makefile "$(MAKE)" $(MAKE_FLAGS) -f $(BUILD_DIR)\X64\Makefile cleanlib
	@cd $(BUILD_DIR)

