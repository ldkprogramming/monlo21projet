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
        pile.h
        cardpyramid.cpp
        cardpyramid.h
        controller.cpp
        controller.h
        winconditions.cpp
        winconditions.h
        GameMoveVerification.h
        GameMoveVerification.cpp
        gamesaver.cpp
        gamesaver.h
        statsaver.cpp
        statsaver.h
        aiplayer.cpp
        

)

