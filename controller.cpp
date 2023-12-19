//
// Created by Leo on 22/11/2023.
//

#include "controller.h"
#include "coin.h"
#include "algorithm"
#include <cstdlib>



Controller::Controller(GameMoveVerification& checker, Game& GameControlled) : checker (checker), GameControlled(GameControlled) {

}
bool Controller::launch_save(GameSaver& save)
{
    save.saveGame(this->GameControlled);
   
}



bool Controller::reset_game()
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

std::vector<std::pair<int, int>> Controller::ask_player_for_tokens_coordinates(Player& player)
{
    std::vector<std::pair<int, int>> coordinates;
    int number_of_coins;
    std::cout << "Combien de jetons voulez vous prendre" << std::endl;
    std::cin >> number_of_coins;
    int x, y;
    for (int i = 0; number_of_coins; i++) {
        std::cout << "Entrez la coordonnées x du jeton à prendre " << std::endl;
        std::cin >> x;
        std::cout << "Entrez la coordonnées y du jeton à prendre " << std::endl;
        std::cin >> y;
        if (x > 4 || x < 0 || y> 4 || y < 0) {
            throw std::runtime_error("Coordonnées erronnées !  ");
            return ask_player_for_tokens_coordinates(player);
        }
      coordinates.push_back(std::pair<int, int>(x, y));
    }
    
    if(coordinates.size()> 1){
        for (size_t i = 0; i < coordinates.size() - 1; i++) {
            if (coordinates.at(i) == coordinates.at(i + 1)) {
                throw std::runtime_error("Vecteur contenant des coordonnées identiques !");
                return ask_player_for_tokens_coordinates(player);
            }
        }
    }

    return coordinates;
}

std::pair<int, int> Controller::ask_for_player_solo_token_coordinates(Player& p)
{
    int x, y;
    std::cout << "Entrez la coordonnées x du jeton à prendre " << std::endl;
    std::cin >> x;
    std::cout << "Entrez la coordonnées y du jeton à prendre " << std::endl;
    std::cin >> y;
    std::pair<int,int> coordinates = std::pair<int, int>(x, y);
    return coordinates;
}
    


bool Controller::ask_player_for_optional_actions(Player& player)
{
    int state;
    std::cout << "Voulez-vous effectuer une action optionnelle ? \n 1 pour oui \n 0 pour non" << std::endl;
    std::cin >> state;
    if (state) { return true; }
    else { return false; }
}

 const Card& Controller::ask_player_for_card_to_buy(Player& player){
    int pile, id;
    std::cout << this->get_GameControlled().getPyramid();
    std::cout << "Quelle carte voulez-vous acheter ?" << std::endl << "Entrez le niveau de la carte \n 1 pour le niveau 1 \n 2 pour le niveau 2 \n 3 pour le niveau 3 \n";
    std::cin >> pile;
    std::cout << "Entrez la position de la carte dans la pyramide" << std::endl;
    std::cin >> id;
    CardLevel pileconverted = int_to_cardlevel(pile);
    if (pile == 1) {
        for (auto c : this->get_GameControlled().getPyramid().getLevel1Cards()) {
            if (c.getId() == id) {
                return c;
            }
        }
    }
    if (pile == 2) {
        for (auto d : this->get_GameControlled().getPyramid().getLevel2Cards()) {
            if (d.getId() == id) {
                return d;
            }
        }
    }
    if (pile == 3) {
        for (auto e : this->get_GameControlled().getPyramid().getLevel1Cards()) {
            if (e.getId() == id) {
                return e;
            }
        }
        }
    throw std::runtime_error("Mauvaise pile selectionnée");
    return ask_player_for_card_to_buy(player);



}

   


 std::pair<int, CardLevel> Controller::ask_player_for_card_to_reserve(Player& player)
 {
     int pile, id;
     std::cout << this->get_GameControlled().getPyramid();
     std::cout << "Quelle carte voulez-vous acheter ?" << std::endl << "Entrez le niveau de la carte \n 1 pour le niveau 1 \n 2 pour le niveau 2 \n 3 pour le niveau 3 \n";
     std::cin >> pile;
     std::cout << "Entrez la position de la carte dans la pyramide" << std::endl;
     std::cin >> id;
     CardLevel pileconverted = int_to_cardlevel(pile);
     int iterator_tracker;
     if (pile == 1) {
         iterator_tracker = 0;
         for (auto c : this->get_GameControlled().getPyramid().getLevel1Cards()) {

             if (c.getId() == id) {
                 return std::pair<int, CardLevel>(iterator_tracker, CardLevel::One);
             }
             iterator_tracker++;
         }
     }
     if (pile == 2) {
         iterator_tracker = 0;
         for (auto d : this->get_GameControlled().getPyramid().getLevel2Cards()) {
             if (d.getId() == id) {
                 return std::pair<int, CardLevel>(iterator_tracker, CardLevel::Two);
             }
             iterator_tracker++;
         }
     }
     if (pile == 3) {
         iterator_tracker = 0;
         for (auto e : this->get_GameControlled().getPyramid().getLevel3Cards())
             if (e.getId() == id) {
                 return std::pair<int, CardLevel>(iterator_tracker, CardLevel::Three);
             }
         iterator_tracker++;
     }

     std::cout << "Mauvaise pile selectionnée " << std::endl;
     return ask_player_for_card_to_reserve(player);
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
        throw std::runtime_error("Mauvais choix !");
        return ask_player_for_bonus_color(player);
        break;
    }
    
}

CoinColor Controller::ask_for_color_to_steal(Player& p)

{
    int Color;
    std::cout << " Quelle couleur de jetons voulez-vous parler ? " << std::endl << "1 : Rouge \n  2 : Vert \n 3 : Bleu \n  4 : Blanc \n 5 : Noir \n 6 : Perle" << std::endl;
    std::cin >> Color;

    switch (Color)
    {
    case 1:
        return CoinColor::Red;

    case 2:
        return CoinColor::Green;

    case 3:
        return CoinColor::Blue;

    case 4:
        return CoinColor::White;

    case 5:
        return CoinColor::Black;
    case 6:
        return CoinColor::Pearl;

    default:
        throw std::runtime_error("Mauvaise couleur ! ");
        return ask_for_color_to_steal(p);
        break;
    }


}

PlayerType Controller::ask_for_opponenent_type(Player& )
{
    int choice;
    std::cout << "Voulez vous jouer contre une IA ? " << std::endl << "0 pour non et 1 pour oui" << std::endl;
    std::cin >> choice;
    if (choice) {
        return PlayerType::AI;
    }
    return PlayerType::AI;
}

OptionalActions Controller::ask_for_optional_action_type(Player& player)
{
    int choice;
    std::cout << "Quelle action voulez-vous effectuer ? \n 1 pour  prendre un jeton avec un privilège \n 2 pour remplir le plateau";
    std::cin >> choice;
    switch (choice) {
    case 1 :
        return OptionalActions::UsePrivileges;
    case 2:
        return OptionalActions::FillBoard;

    default:
        throw std::runtime_error("Mauvais choix !");
        return ask_for_optional_action_type(player);


    }
    

}






void Controller::change_turn()
{
    if (GameControlled.getPlayerTurn() == PlayerEnum::Player1) {
        GameControlled.turn = getOpponent(GameControlled.turn);
    }
}

bool Controller::verify_win(Player& player){
    int winTotalPoints = this->GameControlled.getWinConditions().getTotalPoints();
    int winTotalCrowns = this->GameControlled.getWinConditions().getTotalCrowns();
    int winPointsInOneColor = this->GameControlled.getWinConditions().getPointsInOneColor();

    return ((player.getMaxPointsPerColor() == winPointsInOneColor) || (player.getTotalPoints() == winTotalPoints) || (player.getTotalCrowns() == winTotalCrowns));
}

int Controller::ask_for_number_of_privileges_to_use(Player &p) {
    int number;
    std::cout << "Combien de privilèges voulez-vous utiliser ?"<< std::endl;
    std::cin >> number;
    return number;
}

CompulsoryActions Controller::ask_for_compulsory_action_type(Player& p)
{
    int choice;
    std::cout << "Quelle type d'action obligatoire voulez-vous effectuer ? \n 1 : Acheter une carte \n 2 : Réserver une carte \n 3 : Prendre des jetons"  << std::endl;
    std::cin >> choice;
    switch (choice)
    {
    case 1 :
        return CompulsoryActions::BuyCard;
    case 2 :
        return CompulsoryActions::ReserveCard;
    case 3 :
        return CompulsoryActions::TakeCoins;
    default:
        std::cout << "Erreur de choix" << std::endl;
        return ask_for_compulsory_action_type(p);

        break;
    }
}

int Controller::ask_for_royal_card(Player& p)
{
    int id;
    std::cout << p.getName() << "Vous avez " << p.getTotalCrowns() << std::endl << "Vous pouvez choisir une carte royale !";
    std::cout << "Entrez l'ID dans la pyramide" << std::endl;
    for (auto c : get_GameControlled().getPyramid().getRoyalCards()) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    std::cin >> id;
    return id;
}

std::vector<Coin> Controller::coordinates_to_coin(std::vector<std::pair<int, int>>& coordinates)
{
    std::vector<Coin> coinvector;
    for (auto c : coordinates) {
        coinvector.push_back(this->GameControlled.getCoinBoard().getCoin(c.first, c.second));
   
    }
    return coinvector;
}

CardLevel Controller::int_to_cardlevel(int level)
{
    switch (level)
    {
    case 1:
        return CardLevel::One;
        break;
    case 2:
        return CardLevel::Two;
        break;
    case 3:
        return CardLevel::Three;
        break;
    default:
        break;
    }
}

CardLevel Controller::piletype_to_cardlevel(PileType type)
{
    if (type == PileType::One) { return CardLevel::One; }
    if (type == PileType::Two) { return CardLevel::Two; }
    if (type == PileType::Three) { return CardLevel::Three; }
    if (type == PileType::Royal) { return CardLevel::Royal; }
}




void Controller::printGameState()
{
    std::cout << "Tour de " << get_GameControlled().getPlayer(get_GameControlled().getPlayerTurn()).getName() << std::endl;
    std::cout << "Plateau de jeu" << std::endl;
    std::cout << get_GameControlled().getCoinBoard() << std::endl;
    std::cout << "Pyramide de cartes" << std::endl;
    std::cout << get_GameControlled().getPyramid() << std::endl;
    std::cout << get_GameControlled().getPlayer1();
    std::cout << get_GameControlled().getPlayer2();
}

void Controller::play_game()
{
    
    int coin = rand() % 2;
    if (coin) {this->GameControlled.turn = PlayerEnum::Player2; }
    else { this->GameControlled.turn = PlayerEnum::Player1; }

    while (!verify_win(this->GameControlled.getActivePlayer()))
        if (this->GameControlled.getActivePlayer().get_type() == PlayerType::Human) { play_turn_human(); }
        else(play_turn_AI());


}

void Controller::play_turn_human()
{
    printGameState();
    OptionalActions optionalaction;
    while (checker.verify_optional_actions(this->GameControlled.getActivePlayer())) {
        if (ask_player_for_optional_actions(this->GameControlled.getActivePlayer())) {
            optionalaction = ask_for_optional_action_type(this->GameControlled.getActivePlayer());
            if (optionalaction == OptionalActions::UsePrivileges) {
                int number_of_privileges = ask_for_number_of_privileges_to_use(this->GameControlled.getActivePlayer());
                std::vector<std::pair<int, int>> coordinates = ask_player_for_tokens_coordinates(GameControlled.getActivePlayer());
                while (!GameControlled.playerUsePrivileges(number_of_privileges, coordinates)) {
            
                    int number_of_privileges = ask_for_number_of_privileges_to_use(this->GameControlled.getActivePlayer());
                    std::vector<std::pair<int, int>> coordinates = ask_player_for_tokens_coordinates(GameControlled.getActivePlayer());
                }
                
                 
            }
            if (optionalaction == OptionalActions::FillBoard) {
                GameControlled.playerFillBoard();
            }

        }
        }
    printGameState();
        CompulsoryActions Compulsory_Action = ask_for_compulsory_action_type(GameControlled.getActivePlayer());
        if (Compulsory_Action == CompulsoryActions::TakeCoins) {
            
            std::vector<std::pair<int, int>> coordinates = ask_player_for_tokens_coordinates(GameControlled.getActivePlayer());
            while  (!checker.verify_coin_alignment(coordinates) || !checker.verify_coin_colors(coordinates_to_coin(coordinates) )) {
                throw std::runtime_error (" Erreur de choix \n");
                coordinates = ask_player_for_tokens_coordinates(GameControlled.getActivePlayer());
            }
            GameControlled.playerTakeCoins(coordinates);

            if (get_checker().can_royal_card_pick(GameControlled.getActivePlayer())) {
                int id = ask_for_royal_card(GameControlled.getActivePlayer());

                if (!checker.verify_royal_card_pick(get_GameControlled().getPlayer(GameControlled.getPlayerTurn()), this->get_GameControlled().get_Card_from_ID(id))) {

                    throw std::runtime_error("Erreur de choix \n");
                    id = ask_for_royal_card(GameControlled.getActivePlayer());
                    
                }
            }


            change_turn();
        }
        if (Compulsory_Action == CompulsoryActions::ReserveCard) {
            std::pair<int, CardLevel> cardinfos = ask_player_for_card_to_reserve(GameControlled.getActivePlayer());
            if (!checker.verify_card_type_reservation(GameControlled.pyramid.checkCard(cardinfos.second, cardinfos.first))) {
                throw std::runtime_error("Erreur de choix \n");
                cardinfos = ask_player_for_card_to_reserve(GameControlled.getActivePlayer());
       
            }



            GameControlled.playerReserveCard(cardinfos.second, GameControlled.pyramid.checkCard(cardinfos.second, cardinfos.first).getId());
            if (get_checker().can_royal_card_pick(GameControlled.getActivePlayer())) {
                int id = ask_for_royal_card(GameControlled.getActivePlayer());
                
                if (!checker.verify_royal_card_pick(get_GameControlled().getPlayer(GameControlled.getPlayerTurn()), this->get_GameControlled().get_Card_from_ID(id))) {
                    
                    throw std::runtime_error("Erreur de choix ! \n");
                    id = ask_for_royal_card(GameControlled.getActivePlayer());
                    
                }
            }
            

            change_turn();
        }

        if (Compulsory_Action == CompulsoryActions::BuyCard) {
            const Card& card_to_buy = ask_player_for_card_to_buy(GameControlled.getActivePlayer());
            Skill cardskill1 = card_to_buy.getSkill1();
            Skill cardskill2 = card_to_buy.getSkill2();
            
            if (cardskill1 == Skill::TakeCoin && cardskill2 == Skill::RobCoin || cardskill1 == Skill::RobCoin && cardskill2 == Skill::TakeCoin) {
                GameControlled.playerBuyCard(piletype_to_cardlevel(card_to_buy.getPileTypeOfCard(card_to_buy.getId())), card_to_buy.getId(), card_to_buy.getCardColor(), ask_for_color_to_steal(GameControlled.getActivePlayer()), ask_for_player_solo_token_coordinates(GameControlled.getActivePlayer()));
            }

            if (cardskill1 == Skill::TakeCoin || cardskill2 == Skill::TakeCoin) {
                GameControlled.playerBuyCard(piletype_to_cardlevel(card_to_buy.getPileTypeOfCard(card_to_buy.getId())), card_to_buy.getId(), card_to_buy.getCardColor(), CoinColor::Empty, ask_for_player_solo_token_coordinates(GameControlled.getActivePlayer()));
            }
            if (cardskill1 == Skill::RobCoin || cardskill2 == Skill::RobCoin) {
                GameControlled.playerBuyCard(piletype_to_cardlevel(card_to_buy.getPileTypeOfCard(card_to_buy.getId())), card_to_buy.getId(), card_to_buy.getCardColor(), ask_for_color_to_steal(GameControlled.getActivePlayer()), { 0, 0 });
            }
           
            if (get_checker().can_royal_card_pick(GameControlled.getActivePlayer())) {
                int id = ask_for_royal_card(GameControlled.getActivePlayer());

                if (!checker.verify_royal_card_pick(get_GameControlled().getPlayer(GameControlled.getPlayerTurn()), this->get_GameControlled().get_Card_from_ID(id))) {

                    throw std::runtime_error("Erreur de choix  \n");

                    id = ask_for_royal_card(GameControlled.getActivePlayer());
                 }
            }


            change_turn();
            
        }
        
       


    }

void Controller::play_turn_AI()
{

}

    


