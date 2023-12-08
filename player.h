//
// Created by Leo on 21/11/2023.
//

#ifndef MONLO21PROJET_PLAYER_H
#define MONLO21PROJET_PLAYER_H
#include <string>
#include <vector>
#include "card.h"
#include "coin.h"

enum class OptionalActions{
    UsePrivileges, FillBoard, Empty
};

enum class CompulsoryActions{
    TakeCoins, ReserveCard, BuyCard
};


class Player {
private:
    std::string name;
    std::vector<Card> hand;
    std::vector<Card> reservedCards;
    std::vector<Coin> coins;
    int privileges = 0;

    std::map<CoinColor, int> coinsPerColor;
    std::map<CoinColor, int> bonusesPerColor;
    std::map<CoinColor,int> pointsPerColor;


public:
    Player(std::string name);
    int getTotalPoints();
    int getTotalCrowns();
    int getMaxPointsPerColor();
    const int getPrivileges() const {return privileges;}
    bool canBuy(const Card& card);

    const std::map<CoinColor, int> &getCoinsPerColor() const;
    const std::map<CoinColor, int> &getBonusesPerColor() const;
    const std::map<CoinColor, int> &getPointsPerColor() const;

    void addCoin(const Coin& c);
    void reserveCard(const Card& c);

    const std::string &getName() const;
    friend std::ostream& operator<<(std::ostream &f, const Player& p);

    const std::vector<Card> getHand() const {return hand;}
    const std::vector<Card> getReservedCards() const {return reservedCards;}
};



#endif //MONLO21PROJET_PLAYER_H
