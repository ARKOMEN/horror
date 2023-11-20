cmake_minimum_required(VERSION 3.14)

project(horror CXX)

set(CMAKE_CXX_STANDARD 17)

set(exe_name ${PROJECT_NAME})

if(WIN32 OR MSVC)
    include(FetchContent)
    FetchContent_Declare(
            PDcurses
            GIT_REPOSITORY https://github.com/dsavenko/PDCurses.git
            GIT_TAG        dfbac0fe5ef90a40a67d6b13cc7d9c69bf40a5f5
    )
    FetchContent_MakeAvailable(PDcurses)
endif()

add_executable(${exe_name} main.cpp
        test_level.cpp
        test_level.h
        header.h
        source.cpp
)

if(WIN32 OR MSVC)
    target_link_libraries(${exe_name} PDcurses)
else()
    target_link_libraries(${exe_name} curses)
    find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
    include_directories( ${SFML_INCLUDE_DIRS} )
    target_link_libraries(${exe_name}  sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
endif()