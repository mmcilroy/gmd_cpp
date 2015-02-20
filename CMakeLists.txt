cmake_minimum_required( VERSION 2.8 )
project( gmd_cpp )
set( VERSION_NUMBER "1.0.0" )

if( "${CMAKE_BUILD_TYPE}" STREQUAL "Release" )
    set( VERSION "${VERSION_NUMBER}-release" )
else()
    set( VERSION "${VERSION_NUMBER}-debug" )
endif()

set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11 -Wl,--no-as-needed -g" )

find_package( Boost REQUIRED COMPONENTS system )

include_directories( include include/gmd /home/sm87110/pulsar_cpp/include ${Boost_INCLUDE_DIRS} )

add_subdirectory( src )
add_subdirectory( test )
