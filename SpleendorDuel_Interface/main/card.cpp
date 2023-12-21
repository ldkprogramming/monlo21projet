//
// Created by Leo on 21/11/2023.
//

#include "nlohmann/json.hpp"
#include <ostream>
#include <fstream>

#include <QDebug>

using json = nlohmann::json;

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

Card::Card(int cId) {
    PileType type = getPileTypeOfCard(cId);
    std::ifstream f;
    switch (type) {
        case PileType::One:
            f = std::ifstream("../SpleendorDuel_Interface/main/jsonFiles/pile1.json");
            break;
        case PileType::Two:
            f = std::ifstream("../SpleendorDuel_Interface/main/jsonFiles/pile2.json");
            break;
        case PileType::Three:
            f = std::ifstream("../SpleendorDuel_Interface/main/jsonFiles/pile3.json");
            break;
        case PileType::Royal:
            f = std::ifstream("../SpleendorDuel_Interface/main/jsonFiles/royalpile.json");
            break;
    }

    json data = json::parse(f);
    // f.close();

    qDebug() << "ON EST LA LES REUFS!";

    std::cout<<"OUE ON EST LA!! LA DATA EST:\n";
    std::cout<<data << std::endl;

    qDebug() << "ON EST LA1 LES REUFS!";

    std::cout<< "VOICI LES CARTES:\n";
    std::cout << data["cards"][std::to_string(cId)] << std::endl;

    auto card = data["cards"][std::to_string(cId)];
    qDebug() << "ON EST LA2 LES REUFS!";
    int id = card["card_id"].template get<int>();
    qDebug() << "ON EST LA3 LES REUFS!";
    int points = card["points"].template get<int>();
    qDebug() << "ON EST LA4 LES REUFS!";
    int crowns = card["crowns"].template get<int>();

    qDebug() << "ON EST ICI LES REUFS!";

    std::map<CoinColor, int> costs;
    costs[CoinColor::Green] = card["costs"]["Green"].template get<int>();
    costs[CoinColor::White] = card["costs"]["White"].template get<int>();
    costs[CoinColor::Black] = card["costs"]["Black"].template get<int>();
    costs[CoinColor::Pearl] = card["costs"]["Pearl"].template get<int>();
    costs[CoinColor::Gold] = card["costs"]["Gold"].template get<int>();
    costs[CoinColor::Red] = card["costs"]["Red"].template get<int>();
    costs[CoinColor::Blue] = card["costs"]["Blue"].template get<int>();

    std::map<CoinColor, int> bonuses;
    bonuses[CoinColor::Green] = card["bonuses"]["Green"].template get<int>();
    bonuses[CoinColor::White] = card["bonuses"]["White"].template get<int>();
    bonuses[CoinColor::Black] = card["bonuses"]["Black"].template get<int>();
    bonuses[CoinColor::Pearl] = card["bonuses"]["Pearl"].template get<int>();
    bonuses[CoinColor::Gold] = card["bonuses"]["Gold"].template get<int>();
    bonuses[CoinColor::Red] = card["bonuses"]["Red"].template get<int>();
    bonuses[CoinColor::Blue] = card["bonuses"]["Blue"].template get<int>();

    Skill skill1 = toSkill(card["skill1"].template get<std::string>());
    Skill skill2 = toSkill(card["skill2"].template get<std::string>());

    this->crowns = crowns;
    this->points = points;
    this->cardId = id;
    this->bonuses = bonuses;
    this->costs = costs;
    this->skill1 = skill1;
    this->skill2 = skill2;
}
