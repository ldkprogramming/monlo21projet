//
// Created by Leo on 21/11/2023.
//

#include "player.h"
Player::Player(std::string name) : name(name){
    coinsPerColor[CoinColor::White] = 0;
    coinsPerColor[CoinColor::Red] = 0;
    coinsPerColor[CoinColor::Green] = 0;
    coinsPerColor[CoinColor::Blue] = 0;
    coinsPerColor[CoinColor::Black] = 0;
    coinsPerColor[CoinColor::Pearl] = 0;
    coinsPerColor[CoinColor::Gold] = 0;

    bonusesPerColor[CoinColor::White] = 0;
    bonusesPerColor[CoinColor::Red] = 0;
    bonusesPerColor[CoinColor::Green] = 0;
    bonusesPerColor[CoinColor::Blue] = 0;
    bonusesPerColor[CoinColor::Black] = 0;
    bonusesPerColor[CoinColor::Pearl] = 0;
    bonusesPerColor[CoinColor::Gold] = 0;

    pointsPerColor[CoinColor::White] = 0;
    pointsPerColor[CoinColor::Red] = 0;
    pointsPerColor[CoinColor::Green] = 0;
    pointsPerColor[CoinColor::Blue] = 0;
    pointsPerColor[CoinColor::Black] = 0;
    pointsPerColor[CoinColor::Pearl] = 0;
    pointsPerColor[CoinColor::Gold] = 0;
}

int Player::getTotalCrowns() {
    int crowns = 0;
    for (auto card : hand){
        crowns += card.getCrowns();
    }
    return crowns;
}

int Player::getTotalPoints() {
    int points;
    for (auto card : hand){
        points += card.getPoints();
    }
}


int Player::getMaxPointsPerColor() {
    for (auto card : hand){
        CoinColor cardColor = card.getCardColor();
        if (cardColor != CoinColor::Empty){
            pointsPerColor[cardColor] += card.getPoints();
        }
    }

    int max = 0;
    for (auto pair : pointsPerColor){
        if (pair.second > max){
            max = pair.second;
        }
    }

    return max;
}

bool Player::canBuy(const Card &card) {
    for (auto cost : card.getCosts()){
        if ( bonusesPerColor[cost.first] + coinsPerColor[cost.first] < cost.second ){
            return false;
        }
    }
    return true;
}