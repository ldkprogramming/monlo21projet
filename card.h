//
// Created by Leo on 21/11/2023.
//

#ifndef MONLO21PROJET_CARD_H
#define MONLO21PROJET_CARD_H
#include <map>
#include <string>
#include "coin.h"

enum class Skill{
    PlayAgain, Bonus, TakeCoin, TakePrivilege, RobCoin, Empty
};

enum class PileType{
    One, Two, Three, Royal
};

std::string toString(Skill s);
Skill toSkill(std::string s);

class Card {
private:
    int points = 0;
    int crowns = 0;
    std::map<CoinColor, int> costs;
    std::map<CoinColor, int> bonuses;
    Skill skill1 = Skill::Empty;
    Skill skill2 = Skill::Empty;
    friend std::ostream& operator<<(std::ostream& f, const Card& c);

public:

    Card(int p, int c, std::map<CoinColor, int> co, std::map<CoinColor, int> b, Skill s1, Skill s2){
        points = p;
        crowns = c;
        costs = co;
        bonuses = b;
        skill1 = s1;
        skill2 = s2;
    }
    int getCrowns(){return crowns;}
    int getPoints(){return points;}

};




#endif //MONLO21PROJET_CARD_H
