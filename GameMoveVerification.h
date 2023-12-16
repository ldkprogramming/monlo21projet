//bannedtwice

#pragma once

#include "pile.h"
#include "card.h"
#include "game.h"
#include "cardpyramid.h"
#include "coin.h"
#include "coinbag.h"
#include "coinboard.h"
#include "controller.h"
#include "player.h"
#include "winconditions.h"
#include "gamesaver.h"
#include "card.h"

class GameMoveVerification{
    friend class Game;
    friend class Controller;
    Game& GameChecked;
    bool verificator_state = true;

    
public:

    GameMoveVerification(Game& game); // Controller en argument potentiellement je sais pas
    GameMoveVerification(const GameMoveVerification&) = delete; 
    inline Game& get_game_checked() const {return GameChecked;};
    inline int get_verificator_state() const {return verificator_state;};

    void change_verificator_state();
    bool verify_coin_alignment(std::vector<std::pair<int,int>> coinchoices);
    bool verify_coin_colors(std::vector<Coin> coinstaken);
    bool verify_optional_actions(Player& player);
    bool verify_card_type_reservation(const Card& reservedCard);
    bool verify_no_bonus_card(const Card& boughtCard, Player& player);



};

