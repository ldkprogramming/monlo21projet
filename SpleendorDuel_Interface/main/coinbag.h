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
    Coinbag(std::vector<Coin> coins) : coins(coins){}
    void shuffle();
    int getNumberOfCoins();
    void addCoin(const Coin& coin);
    Coin distributeCoin();
    Coin* distributeCoinPointer();
    bool isEmpty() const {return coins.empty();}
    const std::vector<Coin>& getCoins() const {return coins;}
    //penser a ajouter un iterateur ?
};

std::ostream& operator<<(std::ostream& f, const Coinbag& coinbag);


#endif //MONLO21PROJET_COINBAG_H
