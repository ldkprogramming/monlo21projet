//
// Created by Leo on 21/11/2023.
//

#include "game.h"
#include <string>
#include "nlohmann/json.hpp"
#include <fstream>

using json = nlohmann::json;

const CardPyramid &Game::getPyramid() const {
    return pyramid;
}

const Coinbag & Game::getCoinBag() const {
    return coinBag;
}

const Coinboard &Game::getCoinBoard() const {
    return coinBoard;
}

int Game::getPrivileges() const {
    return privileges;
}

void Game::setPrivileges(int privileges) {
    Game::privileges = privileges;
}

const Pile &Game::getPile1() const {
    return pile1;
}

const Pile &Game::getPile2() const {
    return pile2;
}

const Pile &Game::getPile3() const {
    return pile3;
}

const Player &Game::getPlayer1() const{
    return player1;
}

const Player &Game::getPlayer2() const {
    return player2;
}

const Pile &Game::getRoyalPile() const {
    return royalPile;
}



std::string toString(PlayerEnum p){
    switch(p){
        case PlayerEnum::Player1:
            return "Player1";
            break;
        case PlayerEnum::Player2:
            return "Player2";
            break;
        default:
            return "Empty";
            break;
    }
}

PlayerEnum toPlayerEnum(std::string s){
    // faudra ajouter le traitement des erreurs
    if (s == "Player1"){
        return PlayerEnum::Player1;
    }
    if (s == "Player2"){
        return PlayerEnum::Player2;
    }
    return PlayerEnum::Empty;
}



