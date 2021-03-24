# Cross-compiling Fortran code for Windows from Linux

## Overview

This CMake project configures the following executables:

| Executable Name | Description | Source Directory |
|---|---|---|
| `HelloWorld` | Standalone executable associated with `helloworld.f90` program | [executable](./executable)|
| `HelloWorldWithSharedLib` | C++ executable linking against a shared library associated with `helloworld.f90` module | [executable_with_sharedlib](./executable_with_sharedlib) |


## Cross-compilation using dockcross

dockcross is a collection of Docker images providing cross compiling toolchains. See available images [here](https://github.com/dockcross/dockcross#cross-compilers).

Using image `dockcross/windows-shared-x64-posix`, we can compile the example project from linux and execute
the binaries on windows.

Step by step:

```
# Download docker image
docker pull dockcross/windows-shared-x64-posix

# Generate dockcross script
cd /tmp
docker run --rm dockcross/windows-shared-x64-posix > dockcross-windows-shared-x64-posix
chmod u+x dockcross-windows-shared-x64-posix

# Download source
git clone git://github.com/jcfr/crosscompiling-fortran-for-window-using-dockcross

# Configure
./dockcross-windows-shared-x64-posix cmake \
  -S crosscompiling-fortran-for-window-using-dockcross \
  -B crosscompiling-fortran-for-window-using-dockcross-build \
  -DCMAKE_BUILD_TYPE:STRING=Release \
  -DCMAKE_INSTALL_PREFIX:PATH=/work/crosscompiling-fortran-for-window-using-dockcross-install

# Build
./dockcross-windows-shared-x64-posix cmake --build crosscompiling-fortran-for-window-using-dockcross-build

# Install
./dockcross-windows-shared-x64-posix cmake --build crosscompiling-fortran-for-window-using-dockcross-build --target install
```

