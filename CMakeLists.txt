cmake_minimum_required(VERSION 3.26)
project(monlo21projet)

set(CMAKE_CXX_STANDARD 17)

add_executable(monlo21projet main.cpp
        game.cpp
        game.h
        player.cpp
        player.h
        coinboard.cpp
        coinboard.h
        coin.cpp
        coin.h
        coinbag.cpp
        coinbag.h
        card.cpp
        card.h
        pile.cpp
        pile.h)

