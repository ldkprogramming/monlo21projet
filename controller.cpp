//
// Created by Leo on 22/11/2023.
//

#include "controller.h"
#include "coin.h"
#include "algorithm"
#include <cstdlib>



Controller::Controller(GameMoveVerification& checker, const Game& GameControlled) : checker(checker), GameControlled(GameControlled){}

bool Controller::launch_save(GameSaver& save)
{
    save.saveGame(this->GameControlled);
   
}



bool Controller::reset_game(
)
{
    this->GameControlled.~Game();
    this->checker.~GameMoveVerification();
    
    return true;
}

std::vector<Coin> Controller::ask_player_for_tokens(Player& Player)
{
    std::vector<Coin> coins;
    int number_of_coins;
    std::cout << "Combien de jetons voulez vous prendre" << std::endl;
    std::cin >> number_of_coins;
    int x, y;
    for (int i = 0; number_of_coins; i++) {
        std::cout << "Entrez la coordonnées x du jeton à prendre " << std::endl;
        std::cin >> x;
        std::cout << "Entrez la coordonnées y du jeton à prendre " << std::endl;
        std::cin >> y;
        coins.push_back(this->GameControlled.coinBoard.getCoin(x,y));
    }
    return coins;
}

bool Controller::ask_player_for_optional_actions(Player& player)
{
    int state;
    std::cout << "Voulez-vous effectuer une action optionnelle ? \n 1 pour oui \n 0 pour non" << std::endl;
    std::cin >> state;
    if (state) { return true; }
    else { return false; }
}

Card& Controller::ask_player_for_card_to_buy(Player& player)
{
    int pile, position;
    std::cout << "Quelle carte voulez-vous acheter ?" << std::endl << "Entrez le numéro de pile \n 1 pour le niveau 1 \n 2 pour le niveau 2 \n 3 pour le niveau 3 \n 4 pour les cartes royales \n";
    std::cin >> pile;
    std::cout << "Entrez la position de la carte dans la pyramide" << std::endl;
    std::cin >> position;
    
    
    Card& card_to_buy = this->GameControlled.pyramid.checkCard(pile, position);
    return card_to_buy;
   
}

Card& Controller::ask_player_for_card_to_reserve(Player& player)
{
    int pile, position;
    std::cout << "Quelle carte voulez-vous réserver ?" << std::endl << "Entrez le numéro de pile \n 1 pour le niveau 1 \n 2 pour le niveau 2 \n 3 pour le niveau 3 \n 4 pour les cartes royales \n";
    std::cin >> pile;
    std::cout << "Entrez la position de la carte dans la pyramide" << std::endl;
    std::cin >> position;


    Card& card_to_reserve = this->GameControlled.pyramid.checkCard(pile, position);
    return card_to_reserve;

    
}

CoinColor Controller::ask_player_for_bonus_color(Player& player)
{
    int Color;
    std::cout << "A quelle couleur vous attacher ce bonus ?" << std::endl << "1 : Rouge \n  2 : Vert \n 3 : Bleu \n  4 : Blanc \n 5 : Noir" << std::endl ;
    std::cin >> Color;

    switch (Color)
    {
    case 1:
        return CoinColor::Red;

    case 2:
        return CoinColor::Green;

    case 3 :
        return CoinColor::Blue;

    case 4 :
        return CoinColor::White;

    case 5 : 
        return CoinColor::Black;
    default:
        return ask_player_for_bonus_color(player);
        break;
    }
    
}



void Controller::change_turn()
{
    if (GameControlled.getPlayerTurn() == PlayerEnum::Player1) {
        GameControlled.turn = GameControlled.getOpponentPlayer();
    }
}

bool Controller::verify_win(Player& player){
    int winTotalPoints = this->GameControlled.getWinConditions().getTotalPoints();
    int winTotalCrowns = this->GameControlled.getWinConditions().getTotalCrowns();
    int winPointsInOneColor = this->GameControlled.getWinConditions().getPointsInOneColor();

    return ((player.getMaxPointsPerColor() == winPointsInOneColor) || (player.getTotalPoints() == winTotalPoints) || (player.getTotalCrowns() == winTotalCrowns));
}
