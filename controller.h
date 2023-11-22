//
// Created by Leo on 22/11/2023.
//

#ifndef MONLO21PROJET_CONTROLLER_H
#define MONLO21PROJET_CONTROLLER_H
#include "game.h"
#include "player.h"

class Controller {
public:
    // Retourne les actions optionnelles possibles pour un joueur
    std::vector<OptionalActions> getValidOptionalActions(const Game& game, Player& player) const;

    // Retourne les actions obbligatoires possibles pour un joueur
    std::vector<CompulsoryActions> getValidCompulsoryActions (const Game& game, Player& player) const;

    // appliquer une action optionnelle
    void applyOptionalAction(Game& game, Player& player,  OptionalActions action);

    // appliquer une action obbligatoire
    void applyCompulsoryAction(Game& game, Player& player,  CompulsoryActions action);

    // appliquer les capacites d'une carte
    bool applyCardSkills(Game& game, Player& cardOwner, Player& opponent, Card& card);

    // Jouer un jeu splendor duel
    void play(Game& game);

    // Jouer le tour d'un joueur
    void playTurn(Game& game, Player& player);

    // Verifier si un Joueur gagne
    bool checkIfPlayerWins(Game& game, Player& player);


};


#endif //MONLO21PROJET_CONTROLLER_H
