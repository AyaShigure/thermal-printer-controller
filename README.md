# Thermal-printer-controller

(This is mainly a note repo for myself.)

This software package is based on what is provided by [Xiamen MY Electronic Technology Co.,Ltd](http://en.xmmydzkj.com/dom/down_list.php?username=xiamenminyoux&channel_id=18042624) on their printers.

They have provided a varity of binary libraries for both arm and x86 architectures, but what worked for me on the Raspberry 4B with `aarch64` Ubuntu, is compiling the source file for `x86_64` then execute with ['box64'](https://github.com/ptitSeb/box64). This README explains that process.

## System setup
- **Raspberry Pi 4B** running `aarch64` Ubuntu.
- **Cross-compilation toolchain** for `x86_64`:
  - `gcc-x86-64-linux-gnu`
  - `g++-x86-64-linux-gnu`
- **CMake** and **Make** for build automation.
- **Box64** to run `x86_64` binaries on ARM.
