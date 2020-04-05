cmake_minimum_required(VERSION 3.10.2)

SET(PROJ_NAME "Counter")
PROJECT(${PROJ_NAME})

include_directories(include)
file(GLOB SOURCES "src/*.cpp" "include/*.h")

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

if(WIN32)
  # WIN32 := subsystem is windows instead of console?
  add_executable(${PROJ_NAME} WIN32 ${SOURCES})
else(WIN32)
  add_executable(${PROJ_NAME} ${SOURCES})
endif()


#add_executable (${PROJ_NAME} ${SOURCES} )


target_link_libraries(${PROJ_NAME} LINK_PUBLIC neulib ${wxWidgets_LIBRARIES})
