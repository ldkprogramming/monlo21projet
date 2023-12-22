//
// Created by Leo on 22/11/2023.
//

#include "cardpyramid.h"
#include "pile.h"

CardPyramid::CardPyramid(Pile &pile1, Pile &pile2, Pile &pile3, Pile &royalPile) {
    for (int i = 0; i < maxNumberOfLevel1Cards; i++){
        if (!(pile1.isEmpty())) {
            level1Cards.push_back(pile1.distributeCard());
        }
    }
    for (int i = 0; i < maxNumberOfLevel2Cards; i++){
        if (! (pile2.isEmpty())) {
            level2Cards.push_back(pile2.distributeCard());
        }
    }
    for (int i = 0; i < maxNumberOfLevel3Cards; i++){
        if (! (pile3.isEmpty())) {
            level3Cards.push_back(pile3.distributeCard());
        }
    }
    for (int i = 0; i < maxNumberOfRoyalCards; i++){
        if (! (royalPile.isEmpty())) {
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

Card& CardPyramid::distributeCard(CardLevel level, int cardNumber){
    /*
     * ajouter les verifs!
     */
    Card result = getCards(level)[cardNumber];
    getCards(level).erase(getCards(level).begin()+ cardNumber -1);

    return result;

    // ne pas oublier de refill

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

void CardPyramid::refill(CardLevel level, Pile &pile) {
    int maxCards = getMaxCards(level);
    while ((getCards(level).size() < maxCards) && (!pile.isEmpty())){
        getCards(level).push_back(pile.distributeCard());
    }
}

const int CardPyramid::getMaxCards(CardLevel level) const{
    switch (level){
        case CardLevel::One : {
            return getMaxNumberOfLevel1Cards();
            break;
        }
        case CardLevel::Two : {
            return getMaxNumberOfLevel2Cards();
            break;
        }
        case CardLevel::Three: {
            return getMaxNumberOfLevel3Cards();
            break;
        }
        default : {
            return getMaxNumberOfRoyalCards();
            break;
        }
    }
}

std::vector<Card> &CardPyramid::getCards(CardLevel level) {
    switch (level){
        case CardLevel::One : {
            return level1Cards;
            break;
        }
        case CardLevel::Two : {
            return level2Cards;
            break;
        }
        case CardLevel::Three: {
            return level3Cards;
            break;
        }
        default : {
            return royalCards;
            break;
        }
    }
}

const int CardPyramid::getNumberOfCards(CardLevel level) const {
    switch (level){
        case CardLevel::One : {
            return level1Cards.size();
            break;
        }
        case CardLevel::Two : {
            return level2Cards.size();
            break;
        }
        case CardLevel::Three: {
            return level3Cards.size();
            break;
        }
        default : {
            return royalCards.size();
            break;
        }
    }
}

const Card &CardPyramid::checkCard(CardLevel level, int cardNumber) {
    // faudra ajouter les verifs
    return getCards(level)[cardNumber];
}
