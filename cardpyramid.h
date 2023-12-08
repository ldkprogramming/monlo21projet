//
// Created by Leo on 22/11/2023.
//

#ifndef MONLO21PROJET_CARDPYRAMID_H
#define MONLO21PROJET_CARDPYRAMID_H
#include "pile.h"

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


public:
    CardPyramid(Pile& pile1, Pile& pile2, Pile& pile3, Pile& royalPile);

    const std::vector<Card> &getLevel1Cards() const;

    int getMaxNumberOfLevel1Cards() const;

    const std::vector<Card> &getLevel2Cards() const;

    int getMaxNumberOfLevel2Cards() const;

    const std::vector<Card> &getLevel3Cards() const;

    int getMaxNumberOfLevel3Cards() const;

    const std::vector<Card> &getRoyalCards() const;

    int getMaxNumberOfRoyalCards() const;

    const Card& distributeCard(int pileNumber, int cardNumber);

    void refill(int pileNumber, Pile& pile);

    friend std::ostream& operator<<(std::ostream& f, const CardPyramid& cardPyramid);
};


#endif //MONLO21PROJET_CARDPYRAMID_H
