cmake_minimum_required(VERSION 2.6)
project(game)

#set (
#   SOURCES
#   somefile.cpp
#   otherfile.cpp
#   main.cpp
#)

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

# REQUIRED does not work in CMake <=2.4.6 for SDL
Find_Package ( SDL REQUIRED )
Find_Package ( SDL_image REQUIRED ) # if using SDL_image
Find_Package( SDL_ttf REQUIRED)

# Workaround for the non-working REQUIRED flag
if ( NOT SDL_FOUND )
   message ( FATAL_ERROR "SDL not found!" )
endif ( NOT SDL_FOUND )

link_libraries (
   ${SDL_LIBRARY}
   ${SDLIMAGE_LIBRARY} # if using SDL_image, obviously
   ${SDLTTF_LIBRARY}
   SDLmain # Sadly not included in SDL_LIBRARY variable
)

add_executable(game test.cpp character.cpp timer.cpp object.cpp
 global.cpp things.cpp living_things.cpp non_living_things.cpp bandit.cpp
targetable.cpp)
