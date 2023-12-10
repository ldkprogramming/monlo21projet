//
// Created by Leo on 21/11/2023.
//

#include "game.h"
#include <string>
#include "nlohmann/json.hpp"
#include "coinboard.h"
#include <fstream>

using json = nlohmann::json;

const CardPyramid &Game::getPyramid() const {
    return pyramid;
}

const Coinbag & Game::getCoinBag() const {
    return coinBag;
}

const Coinboard &Game::getCoinBoard() const {
    return coinBoard;
}

int Game::getPrivileges() const {
    return privileges;
}


const Pile &Game::getPile1() const {
    return pile1;
}

const Pile &Game::getPile2() const {
    return pile2;
}

const Pile &Game::getPile3() const {
    return pile3;
}

const Player &Game::getPlayer1() const{
    return player1;
}

const Player &Game::getPlayer2() const {
    return player2;
}

const Pile &Game::getRoyalPile() const {
    return royalPile;
}



std::string toString(PlayerEnum p){
    switch(p){
        case PlayerEnum::Player1:
            return "Player1";
            break;
        case PlayerEnum::Player2:
            return "Player2";
            break;
        default:
            return "Empty";
            break;
    }
}

PlayerEnum toPlayerEnum(std::string s){
    // faudra ajouter le traitement des erreurs
    if (s == "Player1"){
        return PlayerEnum::Player1;
    }
    if (s == "Player2"){
        return PlayerEnum::Player2;
    }
    return PlayerEnum::Empty;
}

bool Game::playerUsePrivilege(std::pair<int, int> coordinates) {
    // returns true if action has been done, false otherwise



    // faut verifier si les coordonnees sont correctes, valides
    // faudra ajouter un attribut largeur au coinboard, mais pour l'instant ca marche
    if ((coordinates.first > 4 ) or (coordinates.first < 0) or (coordinates.second > 4 ) or (coordinates.second < 0)){
        return false;
    }
    // faut verifier si ce n'est pas un jeton or
    if ((coinBoard.getCoin(coordinates.first, coordinates.second).getColor() == CoinColor::Gold) or (coinBoard.getCoin(coordinates.first, coordinates.second).getColor() == CoinColor::Empty)){
        return false;
    }
    // faut verifier que le joueur a qui c le tour possede au moins un privilege
    if (getPlayer(turn).getPrivileges() < 1){
        return false;
    }

    getActivePlayer().addCoin(coinBoard.getCoin(coordinates.first, coordinates.second));

    // on vide le jeton du plateau
    coinBoard.setCoin(coordinates.first, coordinates.second, CoinColor::Empty);
    return true;


}

PlayerEnum getOpponent(PlayerEnum p){
    switch (p){
        case (PlayerEnum::Player1) : {
            return PlayerEnum::Player2;
        }
        case (PlayerEnum::Player2) : {
            return PlayerEnum::Player1;
        }
        default : {
            return PlayerEnum::Empty;
        }
    }
}

bool Game::playerUsePrivileges(int numberOfPrivileges, const std::vector<std::pair<int, int>> &coordinates) {
    // Returns true if action has been done correctly
    // false otherwise

    // faut verifier si le nombre de privileges et de coordonnees correspond
    if (numberOfPrivileges != coordinates.size()){
        return false;
    }
    // faut verifier si le joueeur a assez de privileges
    if (getActivePlayer().getPrivileges() < numberOfPrivileges){
        return false;
    }
    // faut verifier si les coordonnees sont valides
    for (auto c : coordinates){
        if ((c.first > 4 ) or (c.first < 0) or (c.second > 4 ) or (c.second < 0)){
            return false;
        }
        // faut verifier si ce n'est pas un jeton or
        if ((coinBoard.getCoin(c.first, c.second).getColor() == CoinColor::Gold) or (coinBoard.getCoin(c.first, c.second).getColor() == CoinColor::Empty)){
            return false;
        }
    }
    for (auto c : coordinates){
        // faudra verifier si aucune coordonnee n'est pareil que l'autre
        playerUsePrivilege(c);
    }
    return true;
}

bool Game::playerFillBoard() {
    if (coinBag.isEmpty()){
        return false;
    }
    // Si le jeu contient des privileges, l'adversaire le prend
    // sinon , si le jeu n'en contient pas mais le joueur actif en a, l'adversaire le vole
    // sinon, il en prend pas (ca vetu dire qu'il a deja les 3 privileges).
    if (privileges > 0){
        decrementPrivileges();
        getOpponentPlayer().incrementPrivileges();
    } else if (getActivePlayer().getPrivileges() > 0){
        getActivePlayer().decrementPrivileges();
        getOpponentPlayer().incrementPrivileges();
    }
    coinBoard.fill(coinBag);
    return true;
}

bool Game::playerTakeCoin(std::pair<int, int> coordinates) {
    // on doit verifier si les coordonnees sont valides
    if ((coordinates.first > 4 ) or (coordinates.first < 0) or (coordinates.second > 4 ) or (coordinates.second < 0)){
        return false;
    }
    // on doit verifier si c'est un jeton vide ou or
    if ((coinBoard.getCoin(coordinates.first, coordinates.second).getColor() == CoinColor::Empty) or (coinBoard.getCoin(coordinates.first, coordinates.second).getColor() == CoinColor::Gold)){
        return false;
    }

    getActivePlayer().addCoin(coinBoard.getCoin(coordinates.first, coordinates.second));
    // on vide le jeton du plateau
    coinBoard.setCoin(coordinates.first, coordinates.second, CoinColor::Empty);
    return true;
}

bool Game::playerTakeCoins(std::vector<std::pair<int, int>> coordinates) {
    // faudra verifier la validite des coordonnees
    int numberOfPearlCoins = 0;
    bool allSameColor = true;

    if (coordinates.size() > 3){
        return false;
    }

    for (auto c : coordinates){
        //verifications
        continue;
    }
    const Coin& firstCoin = coinBoard.getCoin(coordinates[0].first, coordinates[0].second);
    for (auto c : coordinates){

        if (firstCoin.getColor() != coinBoard.getCoin(c.first, c.second).getColor()){
            allSameColor = false;
        }
        if (coinBoard.getCoin(c.first, c.second).getColor() == CoinColor::Pearl){
            numberOfPearlCoins += 1;
        }
        playerTakeCoin(c);
    }

    if (allSameColor or (numberOfPearlCoins == 2)){
        if (privileges > 0){
            decrementPrivileges();
            getOpponentPlayer().incrementPrivileges();
        } else if (getActivePlayer().getPrivileges() > 0){
            getActivePlayer().decrementPrivileges();
            getOpponentPlayer().incrementPrivileges();
        }
    }
    // On passe au tour suivant !
    turn = getOpponent(turn);


}
Game::Game(const std::string& path) : player1("ha"), player2("ho"){
    std::ifstream f(path);
    json data = json::parse(f);

    // On initialise le sac a jetons
    std::vector<Coin> coinsInCoinBag;
    for (auto c : data["coinBag"]){
        coinsInCoinBag.push_back(Coin(toCoinColor(c)));
    }
    coinBag = Coinbag(coinsInCoinBag);

    // On initialise le plateau de jetons
    for (int i =0 ; i<5;i++){
        for (int j=0; j<5; j++){
            coinBoard.setCoin(i, j, toCoinColor(data["coinBoard"][i][j]));
        }
    }

    // On initialise les pioches
    std::vector<Card> pile1Cards;
    for (auto c : data["pile1"]){
        pile1Cards.push_back(Card(c));
    }
    pile1 = Pile(PileType::One, pile1Cards);
    std::vector<Card> pile2Cards;
    for (auto c : data["pile2"]){
        pile2Cards.push_back(Card(c));
    }
    pile2 = Pile(PileType::Two, pile2Cards);
    std::vector<Card> pile3Cards;
    for (auto c : data["pile3"]){
        pile3Cards.push_back(Card(c));
    }
    pile3 = Pile(PileType::Three, pile3Cards);
    std::vector<Card> royalPileCards;
    for (auto c : data["royalPile"]){
        royalPileCards.push_back(Card(c));
    }
    royalPile = Pile(PileType::Royal, royalPileCards);

    // On initialise les joueurs

    // On initialise les privileges
    privileges = data["privileges"];

    //On initialise la pyramide
    std::vector<Card> level1Cards;
    for (auto c: data["pyramid"]["level1Cards"]){
        level1Cards.push_back(Card(c));
    }
    std::vector<Card> level2Cards;
    for (auto c: data["pyramid"]["level2Cards"]){
        level2Cards.push_back(Card(c));
    }
    std::vector<Card> level3Cards;
    for (auto c: data["pyramid"]["level3Cards"]){
        level3Cards.push_back(Card(c));
    }
    std::vector<Card> royalCards;
    for (auto c: data["pyramid"]["royalCards"]){
        royalCards.push_back(Card(c));
    }

    pyramid = CardPyramid(level1Cards, level2Cards, level3Cards, royalCards);
    winConditions = WinConditions(data["winConditions"]["totalPoints"],data["winConditions"]["totalCrowns"], data["winConditions"]["pointsInOneColor"]);
    turn = toPlayerEnum(data["turn"]);
    winner = PlayerEnum::Empty;
    loser = PlayerEnum::Empty;
}

bool Game::playerReserveCard(CardLevel level, int cardNumber) {
    // ajouter les verifications
    // par exemple, on peut pas reserver de carte royale
    if (level == CardLevel::Royal){
        return false;
    }
    // ou bien, on peut pas reserver une carte inexistante
    if ((cardNumber < 0) or (cardNumber > pyramid.getNumberOfCards(level))){
        return false;
    }

    getActivePlayer().reserveCard(pyramid.distributeCard(level, cardNumber));
    switch (level){
        case CardLevel::One : {
            pyramid.refill(level, pile1);
        }
        case CardLevel::Two : {
            pyramid.refill(level, pile2);
        }
        case CardLevel::Three : {
            pyramid.refill(level, pile3);
        }
    }

    // On passe au tour suivant !
    turn = getOpponent(turn);

    return true;
}