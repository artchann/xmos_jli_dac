# The TARGET variable determines what target system the application is 
# compiled for. It either refers to an XN file in the source directories
# or a valid argument for the --target option when compiling.

TARGET   = custom_XUF216.xn
APP_NAME =

# The flags passed to xcc when building the application
BUILD_FLAGS  = -DFLASH_MAX_UPGRADE_SIZE=64*1024 -fcomment-asm -Xmapper --map -Xmapper MAPFILE -Wall -O3 -report -lquadflash -fsubword-select -save-temps -g 
BUILD_FLAGS +=  -DSDA_HIGH=2 -DSCL_HIGH=1 -DXUD_SERIES_SUPPORT=4 -march=xs2a -DUSB_TILE=tile[1] -DADAT_TX_USE_SHARED_BUFF=1 -DQUAD_SPI_FLASH=1
BUILD_FLAGS += -fxscope -DXSCOPE -DPRINTF #-DAUDIO_CLASS=2 -DSPDIF_TX =0 -DMIDI =0 -DNUM_USB_CHAN_IN=0

#-DPRINTF_USBREQ
# The USED_MODULES variable lists other module used by the application. These
# modules will extend the SOURCE_DIRS, INCLUDE_DIRS and LIB_DIRS variables. 
# Modules are expected to be in the directory above the BASE_DIR directory.
USED_MODULES  = module_usb_shared module_xud module_usb_audio  module_usb_device   
USED_MODULES += lib_logging lib_spi lib_xassert module_dfu module_i2c_simple module_locks module_queue 
# module_spdif_rx module_usb_midi module_adat_tx module_adat_rx
# module_i2c_single and module_i2c_shared 
# module_usb_audio module_usb_device module_usb_shared module_xud
# Build config naming scheme:

# Audio Class:  1 or 2
# Output 	enabled: o (channelcount)
# DSD out	enabled: d, disabled: x
# e.g. 2o2x: Audio class 2.0, 2 input channels, no DSD

TEST_DFU_1 ?= 0
ifeq ($(TEST_DFU_1),1)
BUILD_FLAGS += -DBCD_DEVICE=0x9901
endif
TEST_DFU_2 ?= 0
ifeq ($(TEST_DFU_2),1)
BUILD_FLAGS += -DBCD_DEVICE=0x9902
endif

MFI ?= 0

ifeq ($(MFI), 0)

# Test build configs (Note these make use of the defaults in customdefines.h)
#Audio class 2.0, 2 output channels, no DSD
XCC_FLAGS_2o2x = $(BUILD_FLAGS) -DI2S_CHANS_DAC=2 -DNUM_USB_CHAN_OUT=2 -DDSD_CHANS_DAC=0

#Audio class 2.0, 2 input channels, DSD
XCC_FLAGS_2o2d = $(BUILD_FLAGS) -DI2S_C2HANS_DAC=2 -DNUM_USB_CHAN_OUT=2 -DDSD_CHANS_DAC=2


ifeq ($(TEST_CONFIGS),1)
XCC_FLAGS_upgrade1 = $(BUILD_FLAGS) -DBCD_DEVICE_J=0x99 -DBCD_DEVICE_M=0x0 -DBCD_DEVICE_N=0x1
XCC_FLAGS_upgrade2 = $(BUILD_FLAGS) -DBCD_DEVICE_J=0x99 -DBCD_DEVICE_M=0x0 -DBCD_DEVICE_N=0x2
endif

else

# MFi test build configs - iAP support enabled
	
# # Audio Class 2, iAP enabled, Input, Output, No MIDI, SPDIF Tx
XCC_FLAGS_2i10o10xsxxxx_mfi = $(BUILD_FLAGS) -DIAP=1  
INCLUDE_ONLY_IN_2i10o10xsxxxx_mfi = 

# # Audio Class 2, iAP enabled, No Input, Output, No MIDI, SPDIF Tx, DSD
XCC_FLAGS_20i10oxsxxxxd_mfi = $(BUILD_FLAGS) -DIAP=1   -DDSD_CHANS_DAC=2
INCLUDE_ONLY_IN_20i10oxsxxxxd_mfi = 

#Audio Class 2, iAP enabled, EA Protocol (Native Transport), Input, Output, No MIDI, No SPDIF Tx. i
# Hid controls disabled (buttons used for EA)
# XCC_FLAGS_210i10oxxxxx_mfi_n = $(BUILD_FLAGS) -DIAP=1 -DIAP_EA_NATIVE_TRANS=1   -DHID_CONTROLS=0
# INCLUDE_ONLY_IN_210i10oxxxxx_mfi_n =

#Audio Class 2, iAP enabled, Input, Output, No,  No SPDIF Tx. Select USB A port. Ignore VBUS.
#Note, this is the config used for Apple role-switch
XCC_FLAGS_2ioxx_usba_mfi = $(BUILD_FLAGS) -DIAP=1   -DUSB_SEL_A=1 -DXUD_PWR_CFG=0
INCLUDE_ONLY_IN_2ioxx_usba_mfi = 

include mfi.mk

endif


MODULE_LIBRARIES = xud_x200
verbose = 1
#=============================================================================
# The following part of the Makefile includes the common build infrastructure
# for compiling XMOS applications. You should not need to edit below here.

XMOS_MAKE_PATH ?= ../..
include $(XMOS_MAKE_PATH)/xcommon/module_xcommon/build/Makefile.common
