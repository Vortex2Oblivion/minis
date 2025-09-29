cmake_minimum_required(VERSION 3.13)
project(minis)
add_subdirectory(external/raylib)
link_libraries(raylib)
add_executable(minis src/main.c)
include_directories(src)
if(WIN32)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}  /ENTRY:\"mainCRTStartup\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")
endif(WIN32)
add_dependencies(${PROJECT_NAME} copy_assets)
if(MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
add_custom_target(copy_assets ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/minis
    ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_BUILD_TYPE}/minis
    COMMENT "COPYING ASSETS"
)

else()
add_custom_target(copy_assets ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/minis
    ${CMAKE_CURRENT_BINARY_DIR}/minis
    COMMENT "COPYING ASSETS"
)
endif(MSVC)