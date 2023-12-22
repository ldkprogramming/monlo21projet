//
// Created by Leo on 21/11/2023.
//

#include <fstream>
#include "pile.h"
#include "nlohmann/json.hpp"
#include "coin.h"
#include "card.h"
#include <random>
using json = nlohmann::json;

Pile::Pile(PileType type){
    std::ifstream f;
    switch (type){
        case PileType::One:
            f = std::ifstream ("../../../jsonFiles/pile1.json");
            break;
        case PileType::Two:
            f = std::ifstream ("../../../jsonFiles/pile2.json");
            break;
        case PileType::Three:
            f = std::ifstream ("../../../jsonFiles/pile3.json");
            break;
        case PileType::Royal:
            f = std::ifstream ("../../../jsonFiles/royalpile.json");
            break;

    }
    json data = json::parse(f);
    for (json::iterator it = data["cards"].begin(); it != data["cards"].end(); ++it){
        auto card = data["cards"][it.key()];
        int id = card["card_id"].template get<int>();
        int points = card["points"].template get<int>();
        int crowns = card["crowns"].template get<int>();

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

        cards.emplace_back(id, points, crowns, costs, bonuses, skill1, skill2);

    }
    // penser a rajouter le cas des cartes royales ?

    // On melange la pioche
    shuffle();
}

std::ostream& operator<<(std::ostream& f, const Pile& p){
    for (auto card : p.cards){
        f << card << " => ";
    }
    return f;
}

Card Pile::distributeCard(){
    if (isEmpty()){
        throw std::runtime_error("Empty pile, can't distribute card !");
    }
    Card card = cards.back();
    cards.pop_back();
    return card;
}

void Pile::shuffle() {
    unsigned seed = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    std::shuffle (cards.begin(), cards.end(), std::default_random_engine(seed));
}