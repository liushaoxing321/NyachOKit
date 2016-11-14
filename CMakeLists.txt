cmake_minimum_required (VERSION 2.8)
project (NyachO)
enable_testing()
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

if(UNIX)
	#Microsoft managed to think different again. Congratulations! /s
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")
endif()
include_directories(src/)
file(GLOB NyachOSource
    "src/*.h"
    "src/*.cpp"
    "src/*.hpp"
    "src/*.c"
)
file(GLOB NyachOHeaders
    "src/*.h"
    "src/*.hpp"
)
file(GLOB NyachOTestSource
    "src/*.h"
    "src/*.cpp"
    "src/*.hpp"
    "src/*.c"
    "UnitTest/*.cpp"
)
add_library(NyachO STATIC ${NyachOSource})
add_executable(TestCase ${NyachOTestSource})
add_test(NAME NyachOTest COMMAND TestCase)

SET(BuildDirectoryHeaderPath ${CMAKE_CURRENT_BINARY_DIR}/include)

file(MAKE_DIRECTORY ${BuildDirectoryHeaderPath})
foreach(templateFile ${NyachOHeaders})
	file(COPY ${templateFile} DESTINATION ${BuildDirectoryHeaderPath})
endforeach(templateFile)
