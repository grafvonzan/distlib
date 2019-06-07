#######################
#	File: 
#		CMakeLists.txt
#	Description: 
#		Contains the configuration information necessary to build the 
#		distlib library
#	Author: 
#		(Original) 	Dave McPherson et al (VT ECE Department)		
#		(Modifed) 	Zander S. Ackerman
#	Date:
#		June 05 2019
#######################

cmake_minimum_required(VERSION 3.5)
project(DISTLIB CXX)

# EDIT
# add any files you create related to library
# excluding unit tests
set(distlib_src
	distlib.cpp
	distlib.h
  )

# EDIT
# add any files you create related to unit testing here
set(test_src
  catch.hpp
  unittests_main.cpp
  unittests_calc.cpp  
  unittests_gen.cpp
)


# ------------------------------------------------
# You should not need to edit any files below here
# ------------------------------------------------

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
find_package( Threads )

# create the cqbench executable
add_library(distlib STATIC ${distlib_src})
target_link_libraries(distlib ${CMAKE_THREAD_LIBS_INIT})
set_property(TARGET distlib PROPERTY CXX_STANDARD 11)

include_directories(${CMAKE_BINARY_DIR})

add_executable(unittests ${distlib_src} ${test_src})
target_link_libraries(unittests ${CMAKE_THREAD_LIBS_INIT} )
set_property(TARGET unittests PROPERTY CXX_STANDARD 11)

enable_testing()
add_test(unittests unittests)

# On Linux, using GCC, to enable coverage on tests -DMEMORY=TRUE
if(UNIX AND NOT APPLE AND CMAKE_COMPILER_IS_GNUCXX AND MEMORY)
  add_custom_target(memtest
    COMMAND valgrind ${CMAKE_BINARY_DIR}/unittests)
endif()
