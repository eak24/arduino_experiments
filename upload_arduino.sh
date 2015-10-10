#!/bin/bash

clear

#UNO:
PORTPATH=/dev//cu.usbmodem14
BAUDRATE=115200

#NANO:
#PORTPATH=/dev//cu.usbserial-AI03RL8S
#BAUDRATE=57600

read -e -p "Enter the path to the hex file: " FILEPATH
echo "ports available:"
find /dev/ -name *.usb*

/Users/ethankeller/Downloads/Arduino.app/Contents/Java/hardware/tools/avr/bin/avrdude -C/Users/ethankeller/Downloads/Arduino.app/Contents/Java/hardware/tools/avr/etc/avrdude.conf -v -patmega328p -carduino -P${PORTPATH} -b${BAUDRATE} -D -Uflash:w:${FILEPATH}:i