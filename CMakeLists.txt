cmake_minimum_required(VERSION 3.27)
project(Snake)

set(CMAKE_CXX_STANDARD 17)

add_executable(Snake main.cpp
               Engine/Window.cpp
               Engine/Window.hpp
               Engine/Game.cpp
               Engine/Game.hpp
               Entity/SnakeStructure.hpp
               Entity/Snake.cpp
               Entity/Snake.hpp
               World/World.cpp
               World/World.hpp
               Entity/TextBox.cpp
               Entity/TextBox.hpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR libraries/SFML-2.6.1/lib/cmake/SFML)
find_package(SFML REQUIRED COMPONENTS system window graphics audio network)

include_directories(libraries/SFML-2.6.1/include ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Snake sfml-system sfml-window sfml-graphics sfml-audio sfml-network)