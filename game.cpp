//
// Created by Leo on 21/11/2023.
//

#include "game.h"

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

std::string toString(PlayerTurn p){
    switch(p){
        case PlayerTurn::Player1:
            return "Player1";
            break;
        case PlayerTurn::Player2:
            return "Player2";
            break;
    }
}

PlayerTurn toPlayerTurn(std::string s){
    // faudra ajouter le traitement des erreurs
    if (s == "Player1"){
        return PlayerTurn::Player1;
    }
    if (s == "Player2"){
        return PlayerTurn::Player2;
    }
}

