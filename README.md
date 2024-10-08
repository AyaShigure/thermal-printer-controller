# Thermal printer controller for Raspberry Pis (VersionA1.0/VersionB1.0)
This software package is based on what is provided by [Xiamen MY Electronic Technology Co.,Ltd](http://en.xmmydzkj.com/dom/down_list.php?username=xiamenminyoux&channel_id=18042624) on their thermal printer modules.

### VersionA1.0:
This software package is a python API for controlling the thermal printer module. In the current versionA1.0 python API build, functionalities below are included. Each of below function is a binary executable which could be called indivadually. For example, one could make thermal prints simply from Jupyter Lab while testing the contents of which are being printed.
1.  PrintTextUTF8
2.  PrintRasterImage
3.  FeedAndFullCut
4.  FeedAndHalfCut
5.  FeedDot
6.  FeedLines
7.  PrintHorizontalLineSpecifyThickness
8.  PrintSelftest

### ~~VersionB1.0:~~
~~Aside from VersionA1.0, I have also made a VersionB1.0 which is a simple printer server written in C++. It is controlled via socket communication by a Pyhton script, which means the functionalities from VersionA1.0 are integrated together. Without the need of executing each binary with 'box64' everytime, VersionB1.0 should be a lot faster at run time than VersionA1.0(At least I think, still working on this part yet.)~~

## The basic principles of building and running the package on a Raspberry Pi
They have provided a varity of binary libraries for both arm and x86 architectures, but what worked for me on the Raspberry 4B with `aarch64` Ubuntu, is compiling the source file for `x86_64` then execute with ['box64'](https://github.com/ptitSeb/box64). 

## The python API for the thermal printer
Some functionalities provided by the closed source library `libautoreplyprint.a` is compiled to executables separately. With these executables, a python library named `printer_class` is created to handle calling each executable in command line with `os.system()`, which allows us to interfacing with the printer in python. 

## Problems with the VersionA approach
1.  Utilizing `os.system()` to call the executibles requires calling `box64` repeatedly, this will limit the performance to a degree. To completely solve this problem, it requires VersionB version of the API, in which the C++ side is constructed as a state machine waiting for instructions from Python side via socket communication. Doing so will create a constantly online printer server in the background.

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

# Notes for myself(2024/8/11):
1.  There are still more functions from the origional API, need to explore the setprinting speed and density settings for better printing quality.
2.  CP_Pos_SetPrintDensity(h, 30) gives pretty good printing quality.