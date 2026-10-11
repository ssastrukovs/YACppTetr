# engine lib

# main lib
set(SOURCE_FILES
    backbone.cpp)

add_library(TetrEngine STATIC ${SOURCE_FILES})
target_include_directories(TetrEngine PUBLIC ../../include)

# link sdl
if(TARGET SDL3::SDL3main)
    target_link_libraries(TetrEngine PRIVATE SDL3::SDL3main)
endif()
target_link_libraries(TetrEngine PRIVATE SDL3::SDL3)
