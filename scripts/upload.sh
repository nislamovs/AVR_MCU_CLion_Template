#!/usr/bin/env bash

avrdude -c usbasp -P com1 -p m328p -b 115200 -U flash:w:../bin/avr-mcu-clion-template.hex
