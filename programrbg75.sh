#!/bin/bash

make rgb75:elafonizi; echo "Hit combo to enter keyboard into program mode.."; sleep 10; lsusb; dfu-programmer atmega32u4 erase --debug 10000; dfu-programmer atmega32u4 flash rgb75_elafonizi.hex --debug 10000; dfu-programmer atmega32u4 start --debug 10000

