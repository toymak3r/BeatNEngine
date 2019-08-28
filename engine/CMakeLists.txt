cmake_minimum_required(VERSION 3.7)

project(XibaEngine)

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include_directories(include)

set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../build)


if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
	if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
	endif()
endif()

# SDL
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

# Engine Build
file(GLOB ENGINE_SOURCE_FILES "src/*.cpp")
add_library(XibaEngine SHARED ${ENGINE_SOURCE_FILES})

# Sources
file(GLOB SOURCE_FILES "src/*.cpp")

# Binaries
set ( ENGINE_LIBS XibaEngine.so )

# Likage
target_link_libraries(XibaEngine ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} )

# Installing
install(TARGETS XibaEngine LIBRARY DESTINATION ${BUILD_DIR}/libs)
