//
// Created by Leo on 22/11/2023.
//

#include "cardpyramid.h"
#include "pile.h"

CardPyramid::CardPyramid(Pile &pile1, Pile &pile2, Pile &pile3, Pile &royalPile) {
    for (int i = 0; i < maxNumberOfLevel1Cards; i++){
        if (not (pile1.isEmpty())) {
            level1Cards.push_back(pile1.distributeCard());
        }
    }
    for (int i = 0; i < maxNumberOfLevel2Cards; i++){
        if (not (pile2.isEmpty())) {
            level2Cards.push_back(pile2.distributeCard());
        }
    }
    for (int i = 0; i < maxNumberOfLevel3Cards; i++){
        if (not (pile3.isEmpty())) {
            level3Cards.push_back(pile3.distributeCard());
        }
    }
    for (int i = 0; i < maxNumberOfRoyalCards; i++){
        if (not (royalPile.isEmpty())) {
            royalCards.push_back(royalPile.distributeCard());
        }
    }
}

const std::vector<Card> &CardPyramid::getLevel1Cards() const {
    return level1Cards;
}

int CardPyramid::getMaxNumberOfLevel1Cards() const {
    return maxNumberOfLevel1Cards;
}

const std::vector<Card> &CardPyramid::getLevel2Cards() const {
    return level2Cards;
}

int CardPyramid::getMaxNumberOfLevel2Cards() const {
    return maxNumberOfLevel2Cards;
}

const std::vector<Card> &CardPyramid::getLevel3Cards() const {
    return level3Cards;
}

int CardPyramid::getMaxNumberOfLevel3Cards() const {
    return maxNumberOfLevel3Cards;
}

const std::vector<Card> &CardPyramid::getRoyalCards() const {
    return royalCards;
}

int CardPyramid::getMaxNumberOfRoyalCards() const {
    return maxNumberOfRoyalCards;
}
