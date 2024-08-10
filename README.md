# Thermal printer controller for Raspberry Pis (Version1.0)

### 2024.8.10 notes:
This software package is a python API for controlling the thermal printer module.(Still under constructions)
In the current version1.0 python API build, functionalities below are included.
1.  Printing text
2.  Printing raster image
3.  Feed and cut paper

This software package is based on what is provided by [Xiamen MY Electronic Technology Co.,Ltd](http://en.xmmydzkj.com/dom/down_list.php?username=xiamenminyoux&channel_id=18042624) on their thermal printer modules.

## The basic principles of building and running the package on a Raspberry Pi
They have provided a varity of binary libraries for both arm and x86 architectures, but what worked for me on the Raspberry 4B with `aarch64` Ubuntu, is compiling the source file for `x86_64` then execute with ['box64'](https://github.com/ptitSeb/box64). 

## The python API
Each functionality provided in C++ is compiled separately and included in a python script as a Printer class. Allowing us to directly call each compiled (C++) functions for controlling the printer with python and pass argv to called binary in python. Therfore enabling us to control the low-level hardware directly and interactively using python.

## System setup
- **Raspberry Pi 4B** running `aarch64` Ubuntu 20.04.
- **Cross-compilation toolchain** for `x86_64`:
  - `gcc-x86-64-linux-gnu`
  - `g++-x86-64-linux-gnu`
- **CMake** and **Make** for build automation.
- **Box64** to run `x86_64` binaries on ARM.


# Notes for myself(2024/8/10):
1.  Strings that are sent to the printer must end with a '\n'.
2.  Printing text and printing image should be more than enough in most cases.
3.  More of the original functionalities (like printing QR codes and barcodes) are absent in version 1.0 since they are not needed in my projects for the iiiExhibition2024 at the University of Tokyo.