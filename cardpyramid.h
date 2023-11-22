//
// Created by Leo on 22/11/2023.
//

#ifndef MONLO21PROJET_CARDPYRAMID_H
#define MONLO21PROJET_CARDPYRAMID_H
#include "pile.h"

class CardPyramid {

private:
    Pile pile1 = Pile(PileType::One);
    Pile pile2 = Pile(PileType::Two);
    Pile pile3 = Pile(PileType::Three);
    Pile royalPile = Pile(PileType::Royal);


public:
    const Pile &getPile1() const;

    const Pile &getPile2() const;

    const Pile &getPile3() const;

    const Pile &getRoyalPile() const;




};


#endif //MONLO21PROJET_CARDPYRAMID_H
