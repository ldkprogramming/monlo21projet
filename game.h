//
// Created by Leo on 21/11/2023.
//

#ifndef MONLO21PROJET_GAME_H
#define MONLO21PROJET_GAME_H
#include "cardpyramid.h"
#include "coinbag.h"
#include "coinboard.h"
#include "player.h"
#include <string>


class Game {
    CardPyramid pyramid = CardPyramid();
    Coinbag coinBag = Coinbag();
    Coinboard coinBoard = Coinboard(coinBag);
    int privileges = 3;
    Player player1;
    Player player2;


public:
    const CardPyramid &getPyramid() const;
    const Coinbag &getCoinBag() const;
    const Coinboard &getCoinBoard() const;
    int getPrivileges() const;
    void setPrivileges(int privileges);

    Game(std::string player1Name, std::string player2Name): player1(player1Name), player2(player2Name){}
};


#endif //MONLO21PROJET_GAME_H
