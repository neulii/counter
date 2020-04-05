include_directories(include)
file(GLOB SOURCES "src/*.cpp" "include/*.h")

add_library (neulib ${SOURCES})


target_include_directories(neulib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})