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
};


#endif //MONLO21PROJET_CARDPYRAMID_H
