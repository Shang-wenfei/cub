FILE(GLOB_RECURSE all_files
*.cpp
*.cc
*.c++
*.c
*.C)

add_library(cub STATIC ${all_files} ../include/cub/network/ByteOrder.h ../test/TestByteOrder.cpp)

install(TARGETS cub ARCHIVE DESTINATION lib)

