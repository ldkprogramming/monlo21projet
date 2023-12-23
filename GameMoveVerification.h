//bannedtwice

#pragma once

#include "pile.h"
#include "card.h"
#include "game.h"
#include "cardpyramid.h"
#include "coin.h"
#include "coinbag.h"
#include "coinboard.h"
#include "player.h"
#include "winconditions.h"
#include "gamesaver.h"
#include "card.h"

class GameMoveVerification {
    friend class Game;
    friend class Controller;
    Game& GameChecked;


public:

    GameMoveVerification(Game& game) : GameChecked(game) {} // Controller en argument potentiellement je sais pas
    GameMoveVerification(const GameMoveVerification&) = delete;
    inline Game& get_game_checked() const { return GameChecked; };
  


    bool verify_coin_alignment(std::vector<std::pair<int, int>> coinchoices);
    bool verify_coin_colors(std::vector<Coin> coinstaken);
    bool verify_optional_actions(const Player& player);
    bool verify_card_type_reservation(const Card& reservedCard);
    bool verify_no_bonus_card(const Card& boughtCard, Player& player);

    bool compulsory_action_can_be_done(Player& p);

    bool can_royal_card_pick(Player& p);
    bool verify_royal_card_pick(const Player& p, const Card& pickedCard);
    bool canBuyCard(const Player& p) const;
    bool overTen(const Player& p) const;
}; 