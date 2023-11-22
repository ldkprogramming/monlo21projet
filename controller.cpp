//
// Created by Leo on 22/11/2023.
//

#include "controller.h"
bool Controller::checkIfPlayerWins(Game &game, Player &player) {
    int winTotalPoints = game.getWinConditions().getTotalPoints();
    int winTotalCrowns = game.getWinConditions().getTotalCrowns();
    int winPointsInOneColor = game.getWinConditions().getPointsInOneColor();

    return ((player.getMaxPointsPerColor() == winPointsInOneColor) || (player.getTotalPoints() == winTotalPoints) ||
            (player.getTotalCrowns() == winTotalCrowns)) ;
}