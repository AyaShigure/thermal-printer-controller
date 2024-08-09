#!/bin/sh

export CC=/opt/poky/1.4.3/sysroots/i686-pokysdk-linux/usr/bin/armv7a-vfp-neon-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc
export CXX=/opt/poky/1.4.3/sysroots/i686-pokysdk-linux/usr/bin/armv7a-vfp-neon-poky-linux-gnueabi/arm-poky-linux-gnueabi-g++
export AR=/opt/poky/1.4.3/sysroots/i686-pokysdk-linux/usr/bin/armv7a-vfp-neon-poky-linux-gnueabi/arm-poky-linux-gnueabi-ar

export AUTOREPLYPRINT_ARCH=arm-poky-linux-gnueabi

make

