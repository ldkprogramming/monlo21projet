
#include <fstream>
#include "nlohmann/json.hpp"
#include <iostream>
#include "pile.h"
#include "game.h"
#include "controller.h"
#include "gamesaver.h"
#include "statsaver.h"
#include "coinboard.h"
#include <string>


using json = nlohmann::json;


/*int main() {

    GameSaver gs;
    Game test(gs.getPath());
    std::cout << test.getCoinBag();
    std::cout << test.getCoinBoard();
    std::cout << test.getPile1();
    std::cout << test.getPyramid();
    return 0;
}*/

int main() {
    int menuChoice;
    std::cout << "Menu principal" << std::endl;
    std::cout << "1 :  Lancer une nouvelle partie " << std::endl << "2 : Charger la partie déjà existante" << std::endl << "3 : Afficher les scores sauvegardés" << std::endl << "4 : Quitter ";
    std::cin >> menuChoice;
    
    std::string  Player1Name;
    std::string  Player2Name;

    int winConditions_TotalPoints;
    int winConditions_TotalCrowns;
    int winConditions_TotalPointsinOneColor;
    PlayerType Player2Type;
    int AIchoice;

    StatSaver& statsaver = StatSaver();


   
   


    if (menuChoice == 1) {



        std::cout << "Entrez le nom du Joueur 1" << std::endl;
        std::cin >> Player1Name;
        std::cout << "Entrez le nom du Joueur 2" << std::endl;
        std::cin >> Player2Name;
        std::cout << "Souhaitez-vous jouer contre l'IA ?" << std::endl << "0 pour non " << std::endl << "1 pour oui" << std::endl;
        std::cin >> AIchoice;
        if (AIchoice) { Player2Type = PlayerType::AI; }
        else { Player2Type = PlayerType::Human; }

        std::cout << "Choix des conditions de victoire " << std::endl;
        std::cout << "Entrez le nombre de points totaux à avoir " << std::endl;
        std::cin >> winConditions_TotalPoints;
        std::cout << "Entrez le nombre de couronnes à avoir " << std::endl;
        std::cin >> winConditions_TotalCrowns;
        std::cout << "Entrez le nombre de points d'une seule couleur à avoir  " << std::endl;
        std::cin >> winConditions_TotalPointsinOneColor;

        WinConditions& winSet = WinConditions::WinConditions(winConditions_TotalPoints, winConditions_TotalCrowns, winConditions_TotalPointsinOneColor);
        Game& PlayedGame = Game::Game(Player1Name, Player2Name, Player2Type);
        GameMoveVerification& Checker = GameMoveVerification::GameMoveVerification(PlayedGame);
        Controller& CurrentController = Controller::Controller(Checker, PlayedGame);

        
        std::cout << "Lancement du jeu " << std::endl;
        CurrentController.play_game();

        std::cout << "Fin du jeu" << std::endl;
    }
    
    if (menuChoice == 2) {
        Game& savedGame = Game("../jsonFiles/ongoingGame.json");
        GameMoveVerification& savedChecker = GameMoveVerification(savedGame);
        Controller savedController = Controller(savedChecker, savedGame);


        std::cout << "Lancement de la partie sauvegardée !" << std::endl;

        savedController.play_game();

        std::cout << "Fin du jeu" << std::endl;
        
    }

    if (menuChoice == 3) {

        std::cout << "Affichage des données sauvegardées " << std::endl;

        std::cout << statsaver;
    }
    
 
    }





