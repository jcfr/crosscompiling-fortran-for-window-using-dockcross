
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include(FortranCInterface)

add_library(${PROJECT_NAME}Lib SHARED
  helloworld.f90
  )

FortranCInterface_HEADER(HelloWorld.h
  MACRO_NAMESPACE "FC_"
  SYMBOL_NAMESPACE "F_"
  SYMBOLS helloworld:display
)

add_executable(${PROJECT_NAME}WithSharedLib
  main.cxx
  )

target_link_libraries(${PROJECT_NAME}WithSharedLib PRIVATE ${PROJECT_NAME}Lib)

install(TARGETS
    ${PROJECT_NAME}Lib
    ${PROJECT_NAME}WithSharedLib
  RUNTIME DESTINATION ${HelloWorld_INSTALL_BIN_DIR} COMPONENT RuntimeLibraries
  LIBRARY DESTINATION ${HelloWorld_INSTALL_LIB_DIR} COMPONENT RuntimeLibraries
  ARCHIVE DESTINATION ${HelloWorld_INSTALL_LIB_DIR} COMPONENT Development
  )
