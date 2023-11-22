//
// Created by Leo on 22/11/2023.
//

#ifndef MONLO21PROJET_CONTROLLER_H
#define MONLO21PROJET_CONTROLLER_H
#include "game.h"
#include "player.h"

class Controller {
public:
    // Retourne les actions optionnelles possibles
    std::vector<OptionalActions> getValidOptionalActions(const Game& game);

    // Retourne les actions obbligatoires possibles
    std::vector<CompulsoryActions> getValidCompulsoryActions (const Game& game);

    // appliquer une action optionnelle
    void applyOptionalAction(Game& game, OptionalActions action);

    // appliquer une action obbligatoire
    void applyCompulsoryAction(Game& game, CompulsoryActions action);

    // appliquer la capacite d'une carte
    void applyCardSkill(Game& game, Player& cardOwner, Card& card);

    // Jouer un jeu splendor duel
    void play(Game& game);

    // Jouer le tour d'un joueur
    void playTurn(Game& game, Player& player);

    // Verifier si un Joueur gagne
    bool checkIfPlayerWins(Game& game, Player& player);

};


#endif //MONLO21PROJET_CONTROLLER_H
