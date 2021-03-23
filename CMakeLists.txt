cmake_minimum_required(VERSION 3.17)
project(ConnectFour)

set(CMAKE_CXX_STANDARD 14)

add_executable(ConnectFour main.cpp Player.cpp Player.h Game.cpp Game.h Board.cpp Board.h AIPlayer.cpp AIPlayer.h HumanPlayer.cpp HumanPlayer.h)