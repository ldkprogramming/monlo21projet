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
    f << c.crowns << " " << c.points;
    return f;
}