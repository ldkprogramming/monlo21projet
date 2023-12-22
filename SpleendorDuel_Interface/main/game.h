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
    friend class Controller;
    friend class GameMoveVerification;

    Coinbag coinBag;
    Coinboard coinBoard;
    int privileges;
    Player player1;
    Player player2;

    PlayerEnum winner;
    PlayerEnum loser;
    PlayerEnum turn;

    Pile pile1;
    Pile pile2;
    Pile pile3;
    Pile royalPile;

    CardPyramid pyramid;

    WinConditions winConditions;



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

    bool applyCardSkill(Card& card, Skill skill, CoinColor bonusColor = CoinColor::Empty,
                        CoinColor stolenColor = CoinColor::Empty , std::pair<int, int> coordinates = {0, 0});

public:
    const CardPyramid &getPyramid() const;
    const Coinbag& getCoinBag() const;
    const Coinboard &getCoinBoard() const;
    int getPrivileges() const;
    const Card& get_Card_from_ID(int cID) const;
    const std::pair<CardLevel, int> cardinfosfromCard(const Card& card) const;

    Game(std::string player1Name, std::string player2Name,PlayerType player2Type ): player1(player1Name, PlayerType::Human), player2(player2Name, player2Type),pile1(PileType::One), pile2(PileType::Two), pile3(PileType::Three), royalPile(PileType::Royal),pyramid(pile1, pile2, pile3, royalPile), winConditions(20, 10, 10){
        winner = PlayerEnum::Empty;
        loser = PlayerEnum::Empty;
        turn = PlayerEnum::Player1;
        coinBag = Coinbag();
        coinBoard = Coinboard(coinBag);
        privileges = 3;
    }
    explicit Game(const std::string&  path);

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
    bool playerReserveCard(CardLevel level, int cardNumber);
    bool playerBuyCard(CardLevel level, int cardNumber, CoinColor bonusColor, CoinColor stolenColor,
                       std::pair<int, int> coordinates);


    void incrementPrivileges(){
        privileges += 1;
    }
    void decrementPrivileges(){
        if (privileges > 0){
            privileges -= 1;
        }
    }
    PlayerType toPlayerType(std::string json);
};


#endif //MONLO21PROJET_GAME_H
