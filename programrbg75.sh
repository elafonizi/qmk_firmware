#!/bin/bash

echo "Running makefile...";sleep 2
make rgb75:elafonizi
echo "Hit combo to enter keyboard into program mode.."
sleep 5
lsusb
echo "Running erase next..."
sleep 5
dfu-programmer atmega32u4 erase #--debug 10000;
echo "Flashing next..."
dfu-programmer atmega32u4 flash rgb75_elafonizi.hex #--debug 10000;
echo "Starting new image..."
dfu-programmer atmega32u4 start #--debug 10000
echo " "
echo "......Done!"
