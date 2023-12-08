//
// Created by Leo on 21/11/2023.
//

#ifndef MONLO21PROJET_GAME_H
#define MONLO21PROJET_GAME_H
#include "cardpyramid.h"
#include "coinbag.h"
#include "coinboard.h"
#include "player.h"
#include <string>
#include "winconditions.h"

enum class PlayerEnum{
    Player1, Player2, Empty
};

std::string toString(PlayerEnum p);

PlayerEnum toPlayerTurn(std::string s);

class Game {

    Coinbag coinBag = Coinbag();
    Coinboard coinBoard = Coinboard(coinBag);
    int privileges = 3;
    Player player1;
    Player player2;

    PlayerEnum winner = PlayerEnum::Empty;
    PlayerEnum turn = PlayerEnum::Player1;

    Pile pile1 = Pile(PileType::One);
    Pile pile2 = Pile(PileType::Two);
    Pile pile3 = Pile(PileType::Three);
    Pile royalPile = Pile(PileType::Royal);

    CardPyramid pyramid = CardPyramid(pile1, pile2, pile3, royalPile);

    WinConditions winConditions = WinConditions(20, 10, 10);



public:
    const CardPyramid &getPyramid() const;
    const Coinbag& getCoinBag() const;
    const Coinboard &getCoinBoard() const;
    int getPrivileges() const;
    void setPrivileges(int privileges);
    friend class Controller;

    Game(std::string player1Name, std::string player2Name): player1(player1Name), player2(player2Name){}

    WinConditions getWinConditions() const{ return winConditions; }

    const Player &getPlayer1() const ;

    const Player &getPlayer2() const ;

    const Pile &getRoyalPile() const;
    const Pile &getPile1() const;
    const Pile &getPile2() const;
    const Pile &getPile3() const;

    const PlayerEnum getPlayerTurn() const {return turn;}

};


#endif //MONLO21PROJET_GAME_H
