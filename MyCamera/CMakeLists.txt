CMAKE_MINIMUM_REQUIRED(VERSION 2.8.11)
#PROJECT(MyCamera)

FIND_PACKAGE(TI3DToF 0.5.2 REQUIRED)

### Do not export any symbol by default
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
include(GenerateExportHeader)

set(CMAKE_INCLUDE_CURRENT_DIR 1)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  SET(LINUX 1)
  add_definitions(-msse2 -pthread -std=c++11 -fPIC -ffast-math)
  ADD_DEFINITIONS(-DLINUX)  

  if(ARCH STREQUAL "x86_64")
    set(ARCH amd64)
  endif()
  
  file(WRITE "${CMAKE_BINARY_DIR}/make_deb.sh" "for i in CPackConfig-*.cmake; do cpack -G DEB --config $i; done\n")
  
  SET(COMMON_LIB_FILES)
endif()

add_library(mycamera SHARED
  MyCameraCamera.cpp
  MyCameraCameraFactory.cpp
  ${COMMON_LIB_FILES}
)

generate_export_header(mycamera
  EXPORT_FILE_NAME "SymbolExports.h"
  EXPORT_MACRO_NAME SYMBOL_EXPORT
)

target_include_directories(mycamera PUBLIC ${VOXEL_INCLUDE_DIRS} ${TI3DToF_INCLUDE_DIRS})

TARGET_LINK_LIBRARIES(mycamera ${VOXEL_LIBRARIES} ${TI3DToF_LIBRARIES})

install(TARGETS mycamera
  LIBRARY DESTINATION lib/voxel COMPONENT mycamera
  ARCHIVE DESTINATION lib/voxel COMPONENT mycamera
  RUNTIME DESTINATION lib/voxel COMPONENT mycamera
)

list(APPEND CONF_FILES
  MyCameraCamera.conf
  MyCameraCameraTest.conf
  #MyCameraCameraPhaseOffset.bin
)

list(APPEND UDEV_FILES
  #72-MyCamera.rules
)
                      
### Copy configuration and firmware files to build directory
foreach(f ${CONF_FILES} ${FW_FILES})
  get_filename_component(filename ${f} NAME)
  list(APPEND filesToCopy
    ${CMAKE_CURRENT_BINARY_DIR}/${filename}
  )
  add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${filename}
                   COMMAND ${CMAKE_COMMAND} -E copy
                   ${CMAKE_CURRENT_SOURCE_DIR}/${f} ${CMAKE_CURRENT_BINARY_DIR}/
                   MAIN_DEPENDENCY ${CMAKE_CURRENT_SOURCE_DIR}/${f})
endforeach()

# add_custom_target(filesToCopyTarget ALL DEPENDS ${filesToCopy})
                   
IF(LINUX)
install(FILES 
  ${CONF_FILES}
  DESTINATION /etc/voxel/
  COMPONENT mycamera
)

install(FILES 
  ${FW_FILES}
  DESTINATION /lib/firmware/voxel
  COMPONENT mycamera
)

install(FILES
  ${UDEV_FILES}
  DESTINATION /etc/udev/rules.d/
  COMPONENT mycamera
)
ENDIF()


