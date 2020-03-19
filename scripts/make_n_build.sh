#!/usr/bin/env bash


cd ../bin
rm -rf ./avr-mcu-clion-template*

cd ..
cmake .
make