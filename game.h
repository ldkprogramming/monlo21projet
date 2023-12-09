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

PlayerEnum toPlayerEnum(std::string s);
PlayerEnum getOpponent(PlayerEnum p);


class Game {

    Coinbag coinBag = Coinbag();
    Coinboard coinBoard = Coinboard(coinBag);
    int privileges = 3;
    Player player1;
    Player player2;

    PlayerEnum winner = PlayerEnum::Empty;
    PlayerEnum loser = PlayerEnum::Empty;
    PlayerEnum turn = PlayerEnum::Player1;

    Pile pile1 = Pile(PileType::One);
    Pile pile2 = Pile(PileType::Two);
    Pile pile3 = Pile(PileType::Three);
    Pile royalPile = Pile(PileType::Royal);

    CardPyramid pyramid = CardPyramid(pile1, pile2, pile3, royalPile);

    WinConditions winConditions = WinConditions(20, 10, 10);


    bool playerUsePrivilege(std::pair<int, int> coordinates);

    Player& getActivePlayer() {
        // fonction privee de sorte a ce que slmt les fonctions
        // autorisees puissent modifier les joueurs
        if (turn == PlayerEnum::Player1){
            return player1;
        }
        return player2;
    }

    Player& getOpponentPlayer() {
        // fonction privee de sorte a ce que slmt les fonctions
        // autorisees puissent modifier les joueurs
        if (turn == PlayerEnum::Player1){
            return player2;
        }
        return player1;
    }

    bool playerTakeCoin(std::pair<int, int> coordinates);

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

    const Player& getPlayer(const PlayerEnum p) const{
        if (p == PlayerEnum::Player2){
            return player2;
        }
        return player1;
    }

    const Pile &getRoyalPile() const;
    const Pile &getPile1() const;
    const Pile &getPile2() const;
    const Pile &getPile3() const;

    const PlayerEnum getPlayerTurn() const {return turn;}
    const PlayerEnum getWinner() const {return winner;}
    const PlayerEnum getLoser() const {return loser;}

    bool playerUsePrivileges(int numberOfPrivileges, const std::vector<std::pair<int, int>>& coordinates);
    bool playerFillBoard();
    bool playerTakeCoins(std::vector<std::pair<int, int>> coordinates);

    void incrementPrivileges(){
        privileges += 1;
    }
    void decrementPrivileges(){
        if (privileges > 0){
            privileges -= 1;
        }
    }

};


#endif //MONLO21PROJET_GAME_H
