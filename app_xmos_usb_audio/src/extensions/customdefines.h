/**
 * @file       customdefines.h
 * @brief      Defines relating to device configuration and customisation.
 *             For xCORE-200 Audio MC Board
 * @author     Ross Owen, XMOS Limited
 */
#ifndef _CUSTOMDEFINES_H_
#define _CUSTOMDEFINES_H_
//MAX_FREQ
#include "user_main.h"

/*
 * Device configuration option defines to override default defines found devicedefines.h
 *
 * Build can be customised but changing and adding defines here
 *
 * Note, we check if they are already defined in Makefile
 */

#define custom_xuf 1

#if defined(PRINTF) && defined(XSCOPE)
#include <stdio.h>
#define xprintf(...) printf(__VA_ARGS__)
#else
#define xprintf(...)
#endif

/* Default to board version version 2.0 */
#ifndef XCORE_200_MC_AUDIO_HW_VERSION
#define XCORE_200_MC_AUDIO_HW_VERSION 2
#endif

/* Tile defines */
#define AUDIO_IO_TILE      0
#define XUD_TILE           1

/* SPDIF Tx i/o moved tile between board versions 1.0 -> 2.0 */
#ifndef custom_xuf
#if XCORE_200_MC_AUDIO_HW_VERSION < 2
#define SPDIF_TX_TILE      1
#endif
#endif

#define MIDI_TILE          1

/* Mixer core enabled by default */
#ifndef MIXER
#define MIXER              0
#endif

/* Mixing disabled by default */
#ifndef MAX_MIX_COUNT
#define MAX_MIX_COUNT      0
#endif

/* Board is self-powered i.e. not USB bus-powered */
#define SELF_POWERED       1

/* Enable/Disable MIDI - Default is MIDI off */
#ifndef MIDI
#define MIDI 		       0
#endif

/* Enable/Disable SPDIF output - Default is S/PDIF on */
#ifndef SPDIF_TX
#define SPDIF_TX	       0
#endif

/* Defines relating to channel count and channel arrangement (Set to 0 for disable) */
//:audio_defs
/* Number of USB streaming channels - Default is 4 in 4 out */
#ifndef NUM_USB_CHAN_IN
#define NUM_USB_CHAN_IN    (0)         /* Device to Host */
#endif
#ifndef NUM_USB_CHAN_OUT
#define NUM_USB_CHAN_OUT   (2)         /* Host to Device */
#endif

/* Number of I2S chans from ADC */
#ifndef I2S_CHANS_ADC
#define I2S_CHANS_ADC      (0)
#endif

/* Number of IS2 chans to DAC..*/
#ifndef I2S_CHANS_DAC
#define I2S_CHANS_DAC      (2)
#endif

#ifndef DSD_CHANS_DAC
#define DSD_CHANS_DAC      (2)
#endif

/* Master clock defines (in Hz) */
#define MCLK_441           (1024*44100)   /* 44.1, 88.2 etc */
#define MCLK_48            (1024*48000)   /* 48, 96 etc */

/* Maximum frequency device runs at */
#ifndef MAX_FREQ
#define MAX_FREQ           (768000)
#endif

#ifndef DEFAULT_FREQ
#define DEFAULT_FREQ           (768000)
#endif

/* Audio class version to run in - Default is 2.0 */
#define AUDIO_CLASS (2)

/* Enable/disable fall back to Audio Class 1.0 when connected to FS hub. */
#ifndef AUDIO_CLASS_FALLBACK
#define AUDIO_CLASS_FALLBACK 0
#endif

/* Run the CODEC as slave, Xcore as master
 * Changing this define will cause CODECs to setup appropriately and XCore to be I2S slave
 */
#define CODEC_MASTER      0

/* Enable DFU interface, Note, requires a driver for Windows */
#define DFU             1

/* Channel index of SPDIF Tx channels (duplicated DAC channels 1/2 when index is 0) */
#define SPDIF_TX_INDEX     (0)

/* Channel index of SPDIF Rx channels */
#define SPDIF_RX_INDEX     (0)

/* Channel index of ADAT Tx channels */
#if defined(SPDIF_TX) && (SPDIF_TX==1)
#define ADAT_TX_INDEX      (SPDIF_TX_INDEX + 2)
#else
#define ADAT_TX_INDEX      (I2S_CHANS_DAC)
#endif

/* Channel index of ADAT Rx channels */
#if defined(SPDIF_RX) && (SPDIF_RX==1)
#define ADAT_RX_INDEX      (SPDIF_RX_INDEX + 2)
#else
#define ADAT_RX_INDEX      (I2S_CHANS_ADC)
#endif

#define MIN_VOLUME 0x9D00 //-99dB

//:
/***** Defines relating to USB descriptors etc *****/
//:usb_defs
#define VENDOR_ID          (0x20B1) /* XMOS VID */
#define PID_AUDIO_2        (0x0008) /* SKC_SU1 USB Audio Reference Design PID */
#define PID_AUDIO_1        (0x0009) /* SKC_SU1 Audio Reference Design PID */
//:

/* Enable/Disable example HID code */
#ifndef HID_CONTROLS
#define HID_CONTROLS       1
#endif


/* Enable DFU interface, Note, requires a driver for Windows */
#define DFU 1

#endif
