cmake_minimum_required(VERSION 3.19)

project(HelloWorld
  VERSION 0.0.1
  LANGUAGES C CXX Fortran
  )

set(HelloWorld_INSTALL_BIN_DIR bin)
set(HelloWorld_INSTALL_LIB_DIR lib)

add_subdirectory(executable)
add_subdirectory(executable_with_sharedlib)

