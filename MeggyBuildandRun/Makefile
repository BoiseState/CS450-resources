#######################
# Makefile
#
# This makefile will generate a .hex file from a 
# file.cpp or file.s
# and upload it to the MeggyJr with the commands 
#   make file.hex
# and
#   make file.install
# are run on a typical Mac with the Arduino tools installed.
# This Makefile was tested with Arduino version 1.6.9 on a Mac.
#
# Edit the AVRDUDE -P option to reflect the usb serial port
# you see in your Arduino Tools menu.
#
# 12/15/10, Michelle Strout
# 1/9/15, checked and edited port
# 8/13/16, modified AVRDIR
#######################

## paths to the necessary tools, on Mac using Arduino tools
AVRDIR = /Applications/Arduino.app/Contents/Java/hardware/tools/avr/bin

AVRGCC =        $(AVRDIR)/avr-gcc
AVRGXX =        $(AVRDIR)/avr-g++
AVROBJCOPY =    $(AVRDIR)/avr-objcopy
AVRDUDE =       $(AVRDIR)/avrdude

## AVRDUDE_OPTIONS
AVRDUDE_OPTIONS = -patmega328p -carduino -P/dev/cu.usbserial-FTF0Q9FG -b57600 -C/Applications/Arduino.app/Contents/Java/hardware/tools/avr/etc/avrdude.conf

## avr chip
MCU =           atmega328p

## Options common to compile, link and assembly rules
COMMON =        -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS =        $(COMMON)
CFLAGS +=       -Wall -Os -fsigned-char
CFLAGS +=       -MD -MP -MT $(*F).o -MF dep/$(@F).d 
CFLAGS +=       -DF_CPU=16000000UL
# The one below is for __builtin_avr_delay_cycles only taking constants.
CFLAGS +=       -D__DELAY_BACKWARD_COMPATIBLE__

## Assembly specific flags
ASMFLAGS =      $(COMMON)
ASMFLAGS +=     -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS =       $(COMMON)
LDFLAGS += 

## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom
HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0

## Compile and Build

%.s: %.cpp
	$(AVRGXX) $(INCLUDES) $(CFLAGS) -I. -S  $<

%.hex: %.s MeggyJr.o MeggyJrSimple.o
	$(AVRGXX) $(INCLUDES) $(CFLAGS) -I. -c  $*.s
	$(AVRGXX) $(LDFLAGS) $*.o MeggyJr.o MeggyJrSimple.o $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $*.elf
	$(AVROBJCOPY) -O ihex $(HEX_FLASH_FLAGS)  $*.elf $@

MeggyJr.o: MeggyJr.cpp
	$(AVRGCC) $(INCLUDES) $(CFLAGS) -c  $<

MeggyJrSimple.o: MeggyJrSimple.cpp
	$(AVRGXX) $(INCLUDES) $(CFLAGS) -I. -c  $<


## Install on the device
%.install: %.hex
	$(AVRDUDE) -b57600 -v $(AVRDUDE_OPTIONS) -D -Uflash:w:$<:i
	

## Clean target
.PHONY: clean
clean:
	-rm -rf dep/* dep .DS_Store *.o *.hex *.elf

## Other dependencies
-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)

