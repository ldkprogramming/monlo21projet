//
// Created by Leo on 21/11/2023.
//

#ifndef MONLO21PROJET_COINBAG_H
#define MONLO21PROJET_COINBAG_H
#include "coin.h"
#include <vector>
#include <algorithm>
#include <random>




class Coinbag {
private:
    int maxLength = 25;
    std::vector<Coin> coins;
    friend std::ostream& operator<<(std::ostream& f, const Coinbag& coinbag);

public:
    Coinbag();
    void shuffle();
    int getNumberOfCoins();
    void addCoin(const Coin& coin);
    Coin distributeCoin();

};

std::ostream& operator<<(std::ostream& f, const Coinbag& coinbag);


#endif //MONLO21PROJET_COINBAG_H
