#!/bin/sh

export CC=~/opt/gcc-linaro-4.9.4-2017.01-i686_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc
export CXX=~/opt/gcc-linaro-4.9.4-2017.01-i686_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-g++
export AR=~/opt/gcc-linaro-4.9.4-2017.01-i686_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-ar

export AUTOREPLYPRINT_ARCH=arm-linux-gnueabihf

make

