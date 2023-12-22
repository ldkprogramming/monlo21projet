//
// Created by Leo on 21/11/2023.
//

#include "player.h"
Player::Player(std::string name, PlayerType type) : name(name), type(type) {
    coinsPerColor[CoinColor::White] = 0;
    coinsPerColor[CoinColor::Red] = 0;
    coinsPerColor[CoinColor::Green] = 0;
    coinsPerColor[CoinColor::Blue] = 0;
    coinsPerColor[CoinColor::Black] = 0;
    coinsPerColor[CoinColor::Pearl] = 0;
    coinsPerColor[CoinColor::Gold] = 0;

    bonusesPerColor[CoinColor::White] = 0;
    bonusesPerColor[CoinColor::Red] = 0;
    bonusesPerColor[CoinColor::Green] = 0;
    bonusesPerColor[CoinColor::Blue] = 0;
    bonusesPerColor[CoinColor::Black] = 0;
    bonusesPerColor[CoinColor::Pearl] = 0;
    bonusesPerColor[CoinColor::Gold] = 0;

    pointsPerColor[CoinColor::White] = 0;
    pointsPerColor[CoinColor::Red] = 0;
    pointsPerColor[CoinColor::Green] = 0;
    pointsPerColor[CoinColor::Blue] = 0;
    pointsPerColor[CoinColor::Black] = 0;
    pointsPerColor[CoinColor::Pearl] = 0;
    pointsPerColor[CoinColor::Gold] = 0;

}

int Player::getTotalCrowns() {
    int crowns = 0;
    for (auto card : hand){
        crowns += card.getCrowns();
    }
    return crowns;
}

int Player::getTotalPoints() {
    int points{0};
    for (auto card : hand){
        points += card.getPoints();
    }
    return points;


    
}


int Player::getMaxPointsPerColor() {
    for (auto card : hand) {
        CoinColor cardColor = card.getCardColor();
        if (cardColor != CoinColor::Empty) {
            pointsPerColor[cardColor] += card.getPoints();
        }

        int max = 0;
        for (auto pair : pointsPerColor) {
            if (pair.second > max) {
                max = pair.second;
            }
        }

        return max;
    }
}

bool Player::canBuy(const Card &card) {
    // ATTENTION faut ajouter la verification sur une carte contenant la capacite bonus
    if ((card.getSkill1() == Skill::Bonus) || (card.getSkill2() == Skill::Bonus)){
        for (auto c : bonusesPerColor){
            if (c.second > 0){
                break;
            }
        }
        return false;
    }


    for (auto cost : card.getCosts()){
        if ( bonusesPerColor[cost.first] + coinsPerColor[cost.first] < cost.second ){
            return false;
        }
    }
    return true;
}

const std::map<CoinColor, int> &Player::getCoinsPerColor() const {
    return coinsPerColor;
}

const std::map<CoinColor, int> &Player::getBonusesPerColor() const {
    return bonusesPerColor;
}

const std::map<CoinColor, int> &Player::getPointsPerColor() const {
    return pointsPerColor;
}

void Player::addCoin(const Coin &c) {
    coins.push_back(c);
    coinsPerColor[c.getColor()] += 1;
}

void Player::reserveCard(const Card &c) {
    reservedCards.push_back(c);
}

const std::string &Player::getName() const {
    return name;
}

std::ostream& operator<<(std::ostream &f, const Player& p){
    f << "Player \n";
    f << "name : " << p.getName() << "\n";
    f << "---- hand ----- \n";
    for (auto card : p.hand){
        f << card;
    }
    f << "--------\n";
    f << "---- reserved ----- \n";
    for (auto card : p.reservedCards){
        f << card;
    }
    f << "--------\n";
    f << "---- coins ----- \n";
    for (auto coin : p.coins){
        f << coin << " ";
    }

    f << "\n--------\n";
    return f;
}

void Player::loseCoin(CoinColor c) {
    if (c == CoinColor::Gold){
        throw std::runtime_error("Invalid color");
    }
    if (coinsPerColor[c] <= 0){
        throw std::runtime_error("Invalid color");
    }
    coinsPerColor[c] -= 1;
    auto it = coins.begin();
    while (it != coins.end()){
        if (it->getColor() == c){
            it = coins.erase(it);
            break;
        } else {
            it++;
        }
    }
}

void Player::addCardToHand(const Card &card) {
    hand.push_back(card);
}
 
bool Player::AIcanBuy(const Card& c) const
{
    if ((c.getSkill1() == Skill::Bonus) || (c.getSkill2() == Skill::Bonus)) {
        for (auto c : bonusesPerColor) {
            if (c.second > 0) {
                break;
            }
        }
        return false;
    }
}

void Player::incrementActionsDone() 
{
    actionsDone = +1;
}
