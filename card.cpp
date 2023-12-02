//
// Created by Leo on 21/11/2023.
//

#include "card.h"
std::string toString(Skill s){
    switch (s){
        case Skill::PlayAgain:
            return "PlayAgain";
        case Skill::Bonus:
            return "Bonus";
        case Skill::TakeCoin:
            return "TakeCoin";
        case Skill::TakePrivilege:
            return "TakePrivilege";
        case Skill::RobCoin:
            return "RobCoin";
        default:
            return "Empty";

    }
}
Skill toSkill(std::string s){
    if (s == "PlayAgain") {
        return Skill::PlayAgain;
    }
    if (s == "Bonus") {
        return Skill::Bonus;
    }
    if (s == "TakeCoin") {
        return Skill::TakeCoin;
    }
    if (s == "TakePrivilege") {
        return Skill::TakePrivilege;
    }
    if (s == "RobCoin") {
        return Skill::RobCoin;
    }
    return Skill::Empty;
}

std::ostream& operator<<(std::ostream& f, const Card& c){
    f << "card : " << c.cardId <<
    '\n';
    f << "skill1 : " << toString(c.skill1) << '\n';
    f << "skill2 : " << toString(c.skill2) << '\n';
    return f;
}

CoinColor Card::getCardColor() {
    CoinColor coinColor = CoinColor::Empty;
    for (auto pair : bonuses){
        if (pair.second > 0){
            coinColor = pair.first;
        }
    }
    return coinColor;
}

const std::map<CoinColor, int> &Card::getCosts() const {
    return costs;
}

Skill Card::getSkill1() const {
    return skill1;
}

Skill Card::getSkill2() const {
    return skill2;
}

void Card::incrementBonus(CoinColor c, int amount){
    // ajouter la verification de la validite du coincolor

    if (amount <= 0){
        return;
    }
    if (c == CoinColor::Empty){
        return;
    }
    bonuses[c] += amount;
}
