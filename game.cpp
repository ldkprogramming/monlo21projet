//
// Created by Leo on 21/11/2023.
//

#include "game.h"

const CardPyramid &Game::getPyramid() const {
    return pyramid;
}

const Coinbag &Game::getCoinBag() const {
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
