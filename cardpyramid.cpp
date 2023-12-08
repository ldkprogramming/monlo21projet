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

const Card& CardPyramid::distributeCard(int pileNumber, int cardNumber){
    /*
     * ajouter les verifs!
     */
    switch (pileNumber){
        case 1:{
            Card result = level1Cards[cardNumber];
            level1Cards.erase(level1Cards.begin()+cardNumber-1);
            return result;
        }
        case 2:{
            Card result = level2Cards[cardNumber];
            level2Cards.erase(level2Cards.begin()+cardNumber-1);
            return result;
        }
        case 3:{
            Card result = level3Cards[cardNumber];
            level3Cards.erase(level3Cards.begin()+cardNumber-1);
            return result;
        }
        case 4:{
            Card result = royalCards[cardNumber];
            royalCards.erase(royalCards.begin()+cardNumber-1);
            return result;
        }
    }
}

std::ostream& operator<<(std::ostream& f, const CardPyramid& cardPyramid){
    f << "----- Pile1 ------\n";
    for (auto card : cardPyramid.level1Cards){
        f << card << '\n';
    }
    f << "----------\n";

    f << "----- Pile2 ------\n";
    for (auto card : cardPyramid.level2Cards){
        f << card << '\n';
    }
    f << "----------\n";

    f << "----- Pile3 ------\n";
    for (auto card : cardPyramid.level3Cards){
        f << card << '\n';
    }
    f << "----------\n";

    f << "----- RoyalPile ------\n";
    for (auto card : cardPyramid.royalCards){
        f << card << '\n';
    }
    f << "----------\n";
    return f;
}

void CardPyramid::refill(int pileNumber, Pile &pile) {
    // c'est tres moche mais ca marche, on pourra modifier apres
    int maxNumberOfCards;
    switch (pileNumber){
        case 1:
            maxNumberOfCards = getMaxNumberOfLevel1Cards();
            while ((level1Cards.size() < maxNumberOfCards) and (!pile.isEmpty())){
                level1Cards.push_back(pile.distributeCard());
            }
            break;
        case 2:
            maxNumberOfCards = getMaxNumberOfLevel2Cards();
            while ((level2Cards.size() < maxNumberOfCards) and (!pile.isEmpty())){
                level2Cards.push_back(pile.distributeCard());
            }
            break;
        case 3:
            maxNumberOfCards = getMaxNumberOfLevel3Cards();
            while ((level3Cards.size() < maxNumberOfCards) and (!pile.isEmpty())){
                level3Cards.push_back(pile.distributeCard());
            }
            break;
        case 4:
            maxNumberOfCards = getMaxNumberOfRoyalCards();
            while ((royalCards.size() < maxNumberOfCards) and (!pile.isEmpty())){
                royalCards.push_back(pile.distributeCard());
            }
            break;
    }

}