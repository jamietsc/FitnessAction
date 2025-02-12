cmake_minimum_required(VERSION 3.30)
project(FitnessAction)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FETCHCONTENT_MAKEAVAILABLE(SFML)

add_executable(FitnessAction main.cpp
        game/Game.cpp
        game/Game.h
        game/Fighter.cpp
        game/Fighter.h
        game/Weapon.cpp
        game/Weapon.h
        game/AI.cpp
        game/AI.h
        game/Gravity.cpp
        game/Gravity.h
        GUI/PlayerGUI.cpp
        GUI/PlayerGUI.h
        GUI/MainMenu.cpp
        GUI/MainMenu.h)

#SFML mit dem Projekt linken
target_link_libraries(FitnessAction PRIVATE sfml-graphics)
target_compile_features(FitnessAction PRIVATE cxx_std_23)
