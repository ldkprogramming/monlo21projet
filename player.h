//
// Created by Leo on 21/11/2023.
//

#ifndef MONLO21PROJET_PLAYER_H
#define MONLO21PROJET_PLAYER_H
#include <string>
#include <vector>
#include "card.h"
#include "coin.h"


class Player {
private:
    std::string name;
    std::vector<Card> hand;
    std::vector<Card> reservedCards;
    std::vector<Coin> coins;
    int privileges = 0;

public:
    Player(std::string name){name = name;}
};


#endif //MONLO21PROJET_PLAYER_H
