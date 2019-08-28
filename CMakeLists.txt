cmake_minimum_required(VERSION 3.7)

project(XibaOfDevs)

include_directories(include)
include_directories(engine/include)

set ( ENGINE_LIBS libXibaEngine.so )

set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)

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

# Engine Linking
link_directories( ${BUILD_DIR}/libs/ )

# Sources
file(GLOB SOURCE_FILES "src/*.cpp")


# Binaries
add_executable(XibaOfDevs ${SOURCE_FILES})

# Likage
target_link_libraries(XibaOfDevs ${ENGINE_LIBS})
set_target_properties(XibaOfDevs PROPERTIES LINK_FLAGS "-Wl,-rpath,./libs")

# Installing
install(TARGETS XibaOfDevs RUNTIME DESTINATION ${BUILD_DIR})
