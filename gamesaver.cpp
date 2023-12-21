//
// Created by Leo on 02/12/2023.
//

#include "gamesaver.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <ostream>

using json = nlohmann::json;


bool GameSaver::saveGame(const Game &game) const {


    // On cree la structure qui va nous permettre de sauvegarder le jeu
    json j;

    // On sauvegarde le sac de jetons
    // en sauvegardant la couleur des jetons
    j["coinBag"] = {};
    for (auto coin : game.getCoinBag().getCoins()) {
        j["coinBag"].push_back(toString((coin.getColor())));
    }



    // On sauvegarde le plateau de jetons
    // en sauvegardant la couleur des jetons
    //faudra forcement a un moment gerer la constante 5
    // peut-etre ajouter un attribut a la classe CoinBoard?
    std::vector<std::vector<std::string>> coinBoardSave;
    for (int i = 0; i< 5; i++){
        std::vector<std::string> line;
        for (int j = 0; j <5; j++){
            line.push_back(toString(game.getCoinBoard().getCoin(i, j).getColor()));
        }
        coinBoardSave.push_back(line);
    }
    j["coinBoard"] = coinBoardSave;

    // On sauvegarde les privileges sur le plateau
    j["privileges"] = game.getPrivileges();

    // faudra ajouter la sauvegarde des joueurs


    // On sauvegarde le tour
    j["turn"] = toString(game.getPlayerTurn());

    // On sauvegarde l'etat des differentes pioches
    // Pour cela, on sauvegardera uniquement l'id des cartes
    j["pile1"] = {};
    for (auto c : game.getPile1().getCards()){
        j["pile1"].push_back(c.getId());
    }

    j["pile2"] = {};
    for (auto c : game.getPile2().getCards()){
        j["pile2"].push_back(c.getId());
    }

    j["pile3"] = {};
    for (auto c : game.getPile3().getCards()){
        j["pile3"].push_back(c.getId());
    }

    // C'est normal qu'elle est vide : il n'y a que 4 cartes
    // royales, qui seront directement mises dans la pyramide
    // Mais c'est utile au cas ou on rajoute d'autres cartes
    // royales dans le jeu
    j["royalPile"] = {};
    for (auto c : game.getRoyalPile().getCards()){
        j["royalPile"].push_back(c.getId());
    }


    // On sauvegarde l'etat de la pyramide
    // Pour cela, on sauvegardera uniquement l'id des cartes
    j["pyramid"]["level1Cards"] = {};
    for (auto c : game.getPyramid().getLevel1Cards()){
        j["pyramid"]["level1Cards"].push_back(c.getId());
    }
    j["pyramid"]["level2Cards"] = {};
    for (auto c : game.getPyramid().getLevel2Cards()){
        j["pyramid"]["level2Cards"].push_back(c.getId());
    }
    j["pyramid"]["level3Cards"] = {};
    for (auto c : game.getPyramid().getLevel3Cards()){
        j["pyramid"]["level3Cards"].push_back(c.getId());
    }
    j["pyramid"]["royalCards"] = {};
    for (auto c : game.getPyramid().getRoyalCards()){
        j["pyramid"]["royalCards"].push_back(c.getId());
    }



    // On sauvegarde les conditions de victoire a l'interieur d'un objet
    j["winConditions"]["totalPoints"] = game.getWinConditions().getTotalPoints();
    j["winConditions"]["totalCrowns"] = game.getWinConditions().getTotalCrowns();
    j["winConditions"]["pointsInOneColor"] = game.getWinConditions().getPointsInOneColor();


    // On sauvegarde l'etat de chaque joueur
    // Je ne sais pas trop si c'est utile de sauvegarder
    // les objets Coin en tant que tels...
    j["player1"]["name"] = game.getPlayer1().getName();
    j["player1"]["hand"] = {};
    for (auto c : game.getPlayer1().getHand()){
        j["player1"]["hand"].push_back(c.getId());
    }
    j["player1"]["reservedCards"] = {};
    for (auto c : game.getPlayer1().getReservedCards()){
        j["player1"]["reservedCards"].push_back(c.getId());
    }
    j["player1"]["privileges"] = game.getPlayer1().getPrivileges();
    j["player1"]["coinsPerColor"] = {};
    for (auto couple : game.getPlayer1().getCoinsPerColor()){
        j["player1"]["coinsPerColor"][toString(couple.first)] = couple.second;
    }
    j["player1"]["bonusesPerColor"] = {};
    for (auto couple : game.getPlayer1().getBonusesPerColor()){
        j["player1"]["bonusesPerColor"][toString(couple.first)] = couple.second;
    }
    j["player1"]["pointsPerColor"] = {};
    for (auto couple : game.getPlayer1().getPointsPerColor()){
        j["player1"]["pointsPerColor"][toString(couple.first)] = couple.second;
    }


    j["player2"]["name"] = game.getPlayer2().getName();
    j["player2"]["hand"] = {};
    for (auto c : game.getPlayer2().getHand()){
        j["player2"]["hand"].push_back(c.getId());
    }
    j["player2"]["reservedCards"] = {};
    for (auto c : game.getPlayer2().getReservedCards()){
        j["player2"]["reservedCards"].push_back(c.getId());
    }
    j["player2"]["privileges"] = game.getPlayer2().getPrivileges();
    j["player2"]["coinsPerColor"] = {};
    for (auto couple : game.getPlayer2().getCoinsPerColor()){
        j["player2"]["coinsPerColor"][toString(couple.first)] = couple.second;
    }
    j["player2"]["bonusesPerColor"] = {};
    for (auto couple : game.getPlayer2().getBonusesPerColor()){
        j["player2"]["bonusesPerColor"][toString(couple.first)] = couple.second;
    }
    j["player2"]["pointsPerColor"] = {};
    for (auto couple : game.getPlayer2().getPointsPerColor()){
        j["player2"]["pointsPerColor"][toString(couple.first)] = couple.second;
    }



    // On ecrit le tout sur un fichier externe
    std::ofstream outputFile(path);
    outputFile << std::setw(4) << j <<std::endl;
    return true;
}