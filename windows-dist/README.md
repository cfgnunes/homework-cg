# Homework - Computer Graphics

## Windows packaging

This section assumes Windows 10, but the procedure is similar for other Windows versions. The prerequisites to build the source is to install the following applications:

### Install prerequisites

* [MinGW-W64 GCC-8.1.0](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/8.1.0/threads-posix/sjlj/i686-8.1.0-release-posix-sjlj-rt_v6-rev0.7z) - i686-posix-sjlj
* [CMake](https://cmake.org/download/)

### Build the project

Compile the sources and install with following commands in the terminal:

```sh
mkdir build
cd build
cmake -G "MinGW Makefiles" -DCMAKE_INSTALL_PREFIX:PATH=dist ..
cmake -G "MinGW Makefiles" -DCMAKE_INSTALL_PREFIX:PATH=dist ..
cmake --build . --target install --config Release
```
