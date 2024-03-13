cmake_minimum_required(VERSION 3.10)
project(TextRPG)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(SourceLibrary SHARED Allies.cpp CivilPeople.cpp Locations.cpp MainCharacter.cpp
        Enemies.cpp Quests.cpp World.cpp Wrapper.cpp Control.cpp)
