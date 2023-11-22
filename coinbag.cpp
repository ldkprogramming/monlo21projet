//
// Created by Leo on 21/11/2023.
//

#include "coinbag.h"

Coinbag::Coinbag() {
    for (int i = 0; i < 4; i++){
        addCoin(Coin(CoinColor::Black));
    }
    for (int i = 0; i < 4; i++){
        addCoin(Coin(CoinColor::Blue));
    }
    for (int i = 0; i < 4; i++){
        addCoin(Coin(CoinColor::Red));
    }
    for (int i = 0; i < 4; i++){
        addCoin(Coin(CoinColor::Green));
    }
    for (int i = 0; i < 4; i++){
        addCoin(Coin(CoinColor::White));
    }
    for (int i = 0; i < 2; i++){
        addCoin(Coin(CoinColor::Pearl));
    }
    for (int i = 0; i < 3; i++){
        addCoin(Coin(CoinColor::Gold));
    }
    this->shuffle();
}

void Coinbag::addCoin(const Coin &coin) {
    if (coins.size() < maxLength){
        coins.push_back(coin);
    } else {
        throw MATH_ERREXCEPT;
    }
}

void Coinbag::shuffle() {
    unsigned seed = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    std::shuffle (coins.begin(), coins.end(), std::default_random_engine(seed));
}

std::ostream& operator<<(std::ostream& f, const Coinbag& coinbag){
    for (auto coin : coinbag.coins){
        f << coin << " ";
    }
    return f;
}

Coin Coinbag::distributeCoin(){
    // Si le sac est vide, on donne un "jeton" Empty
    if (coins.empty()){
        return Coin(CoinColor::Empty);
    }
    Coin coin = coins.back();
    coins.pop_back();
    return coin;
}

int Coinbag::getNumberOfCoins() {
    return coins.size();
}