//
// Created by Leo on 22/11/2023.
//

#ifndef MONLO21PROJET_CARDPYRAMID_H
#define MONLO21PROJET_CARDPYRAMID_H
#include "pile.h"
#include "card.h"

enum class CardLevel {
    One, Two, Three, Royal
};

class CardPyramid {

private:
    std::vector<Card> level1Cards;
    int maxNumberOfLevel1Cards = 3;

    std::vector<Card> level2Cards;
    int maxNumberOfLevel2Cards = 4;

    std::vector<Card> level3Cards;
    int maxNumberOfLevel3Cards = 5;

    std::vector<Card> royalCards;
    int maxNumberOfRoyalCards = 4;

    std::vector<Card>& getCards(CardLevel level);


public:
    CardPyramid(Pile& pile1, Pile& pile2, Pile& pile3, Pile& royalPile);
    CardPyramid(std::vector<Card> level1Cards, std::vector<Card> level2Cards, std::vector<Card> level3Cards, std::vector<Card> royalCards) : level1Cards(level1Cards), level2Cards(level2Cards), level3Cards(level3Cards), royalCards(royalCards)  {}
    CardPyramid() = default;

    const std::vector<Card> &getLevel1Cards() const;
    int getMaxNumberOfLevel1Cards() const;

    const std::vector<Card> &getLevel2Cards() const;
    int getMaxNumberOfLevel2Cards() const;

    const std::vector<Card> &getLevel3Cards() const;
    int getMaxNumberOfLevel3Cards() const;

    const std::vector<Card> &getRoyalCards() const;
    int getMaxNumberOfRoyalCards() const;

    Card& distributeCard(CardLevel level, int cardNumber);
    Card& checkCard(CardLevel level, int cardNumber);
    void refill(CardLevel level, Pile& pile);
    friend std::ostream& operator<<(std::ostream& f, const CardPyramid& cardPyramid);

    const int getMaxCards(CardLevel level) const;
    const int getNumberOfCards(CardLevel level) const;

};


#endif //MONLO21PROJET_CARDPYRAMID_H
