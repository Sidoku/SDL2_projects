cmake_minimum_required(VERSION 3.5.0)
project(SDL2_Tutorial VERSION 0.1.0 LANGUAGES C CXX)

#Find SDL2
find_package(SDL2 REQUIRED)

#Find SDL2_image
find_package(SDL2_image REQUIRED)

#Find SDL2_ttf
find_package(SDL2_ttf REQUIRED)

#Find SDL2_mixer
find_package(SDL2_mixer REQUIRED)

#Executable file
add_executable(SDL2_Tutorial SDL2_tutorial.cpp)

target_link_libraries(SDL2_Tutorial SDL2 SDL2_image SDL2_ttf SDL2_mixer)

#include(CTest)
#enable_testing()

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)