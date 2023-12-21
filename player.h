//
// Created by Leo on 21/11/2023.
//

#ifndef MONLO21PROJET_PLAYER_H
#define MONLO21PROJET_PLAYER_H
#include <string>
#include <vector>
#include "card.h"
#include "coin.h"

enum class PlayerType {
    AI, Human 
};

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
    std::map<CoinColor, int> pointsPerColor;

    PlayerType type;

    int actionsDone = 0;

public:
    Player(std::string name, PlayerType type);
    Player(std::string name, std::vector<Card> hand, std::vector<Card> reservedCards, std::vector<Coin> coins, int privileges, std::map<CoinColor, int> coinsPerColor,  std::map<CoinColor, int> bonusesPerColor,  std::map<CoinColor, int> pointsPerColor, PlayerType type) :
    name(name), hand(hand), reservedCards(reservedCards), coins(coins), privileges(privileges), type(type) {}
    int getTotalPoints();
    int getTotalCrowns();
    int getMaxPointsPerColor();
    const int getPrivileges() const {return privileges;}
    bool canBuy(const Card& card);
    PlayerType get_type() const { return type; }

    const std::map<CoinColor, int> &getCoinsPerColor() const;
    const std::map<CoinColor, int> &getBonusesPerColor() const;
    const std::map<CoinColor, int> &getPointsPerColor() const;

    void addCoin(const Coin& c);
    void reserveCard(const Card& c);

    const std::string &getName() const;
    friend std::ostream& operator<<(std::ostream &f, const Player& p);

    const std::vector<Card> getHand() const {return hand;}
    const std::vector<Card> getReservedCards() const {return reservedCards;}
    void incrementPrivileges() {privileges += 1;}
    void decrementPrivileges() {
        if (privileges > 0){
            privileges -= 1;
        }
    }
    void loseCoin(CoinColor c);
    void addCardToHand(const Card& card);
    const int getBonus(CoinColor color) const {
        for (auto c : bonusesPerColor){
            if (c.first == color){
                return c.second;        
            }
        }
    }

    
    bool AIcanBuy(const Card& c) const;
    void incrementActionsDone();
};



#endif //MONLO21PROJET_PLAYER_H
