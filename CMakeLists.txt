cmake_minimum_required(VERSION 3.14.0) # 3.5 for SDL2, should be enough
project(YACppTetr VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

# includes
include_directories(include)

# find SDL (see SDL cmake example in their repo)
option(MYGAME_VENDORED "Use vendored libraries" OFF)
if(MYGAME_VENDORED)
    add_subdirectory(vendored/sdl EXCLUDE_FROM_ALL)
else()
    find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
    find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)
endif()

# executables
add_executable(YACppTetr src/main.cpp)

# linkable libs
if(TARGET SDL2::SDL2main)
    target_link_libraries(YACppTetr PRIVATE SDL2::SDL2main)
endif()
target_link_libraries(YACppTetr PRIVATE SDL2::SDL2)

# subdirectories (search for makefiles in them)
add_subdirectory(tests)
add_subdirectory(src/engine)

#linkable local libs
target_link_libraries(YACppTetr PRIVATE TetrEngine)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
