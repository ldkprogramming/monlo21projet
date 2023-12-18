//
// Created by Leo on 21/11/2023.
//

#ifndef MONLO21PROJET_PILE_H
#define MONLO21PROJET_PILE_H

#include "card.h"
#include <vector>

class Pile {
private:

    PileType type;
    std::vector<Card> cards;
    friend std::ostream& operator<<(std::ostream& f, const Pile& p);

public:
    Pile(const Pile& p) = delete;
    Pile(PileType type);
    int getRemainingCards(){return cards.size();}
    bool isEmpty() const {return cards.empty();}
    Card distributeCard();
    void shuffle();
    const std::vector<Card>& getCards() const {return cards;}
    Pile() = default;
    Pile(PileType type, std::vector<Card> cards) : type(type), cards(cards){}
    void setPileType(PileType p){type = p;}
};


#endif //MONLO21PROJET_PILE_H
