/* 
	Editor: http://www.visualmicro.com
	        visual micro and the arduino ide ignore this code during compilation. this code is automatically maintained by visualmicro, manual changes to this file will be overwritten
	        the contents of the Visual Micro sketch sub folder can be deleted prior to publishing a project
	        all non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
	        note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Teensy 3.2 / 3.1, Platform=teensy3, Package=teensy
*/

#ifndef _VSARDUINO_H_
#define _VSARDUINO_H_
#define __MK20DX256__
#define TEENSYDUINO 125
#define ARDUINO 165
#define F_CPU 96000000
#define ARDUINO_ARCH_AVR
#define USB_SERIAL
#define LAYOUT_US_ENGLISH
#define __cplusplus
#define __arm__
#define __ARM__
#define __extension__
#define  __attribute__(x)
typedef void *__builtin_va_list;
#define __extension__
#define __ATTR_PURE__
#define __ATTR_CONST__
#define __inline__
#define __asm__ 
#define __volatile__

#define NEW_H

#include <arduino.h>
#undef F
#define F(string_literal) ((const PROGMEM char *)(string_literal))
#undef PSTR
#define PSTR(string_literal) ((const PROGMEM char *)(string_literal))
#undef cli
#define cli()
#define pgm_read_byte(address_short)
#define pgm_read_word(address_short)
#define pgm_read_word2(address_short)
#define digitalPinToPort(P)
#define digitalPinToBitMask(P) 
#define digitalPinToTimer(P)
#define analogInPinToBit(P)
#define portOutputRegister(P)
#define portInputRegister(P)
#define portModeRegister(P)
#include <..\PS_Lamp_V1\PS_Lamp_V1.ino>
#include <..\PS_Lamp_V1\PS_Animator.h>
#include <..\PS_Lamp_V1\PS_Bulb.h>
#include <..\PS_Lamp_V1\PS_Data.h>
#include <..\PS_Lamp_V1\PS_Settings.h>
#include <..\PS_Lamp_V1\PS_WifiController.h>
#include <..\PS_Lamp_V1\PS_Winch.h>
#endif
