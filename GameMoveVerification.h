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
    Game& GameChecked;
    bool verificator_state = true;

    
public:

    GameMoveVerification(Game&); // Controller en argument potentiellement je sais pas
    GameMoveVerification(const GameMoveVerification&) = delete;
    GameMoveVerification& operator=(const GameMoveVerification&) = delete;
    ~GameMoveVerification(); //Potentiellement inutile étant donné qu'il y a uniquement un booléen et une référence
    
    inline Game& get_game_checked() const {return GameChecked;};
    inline int get_verificator_state() const {return verificator_state;};

    void change_verificator_state(GameMoveVerification&);
    void verify_coin_alignment(std::vector<std::pair<int,int>> coinchoices);


};
