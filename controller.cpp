//
// Created by Leo on 22/11/2023.
//

#include "controller.h"
#include "coin.h"
#include "algorithm"
#include <cstdlib>







std::vector<Coin> Controller::ask_player_for_tokens(const Player& Player)
{
    std::vector<Coin> coins;
    int number_of_coins;
    std::cout << "Combien de jetons voulez vous prendre" << std::endl;
    std::cin >> number_of_coins;
    int x, y;
    for (int i = 0; i<number_of_coins; i++) {
        std::cout << "Entrez la coordonn�es x du jeton � prendre " << std::endl;
        std::cin >> x;
        std::cout << "Entrez la coordonn�es y du jeton � prendre " << std::endl;
        std::cin >> y;
        coins.push_back(this->get_GameControlled().getCoinBoard().getCoin(x, y));
    }
    return coins;
}

std::vector<std::pair<int, int>> Controller::ask_player_for_tokens_coordinates(const Player& player)
{
    std::vector<std::pair<int, int>> coordinates;
    int number_of_coins;
    std::cout << "Combien de jetons voulez vous prendre" << std::endl;
    std::cin >> number_of_coins;
    while (number_of_coins > 3 || number_of_coins < 1) {
        std::cout << "Nombre invalide \n Réessayez ! " << std::endl;
        std::cin >> number_of_coins;
    }
    int x, y;
    for (int i = 0; i<number_of_coins; i++) {
        std::cout << "Entrez la coordonn�es x du jeton � prendre " << std::endl;
        std::cin >> x;
        std::cout << "Entrez la coordonn�es y du jeton � prendre " << std::endl;
        std::cin >> y;
        if (x > 4 || x < 0 || y> 4 || y < 0) {
            std::cout << "Erreur : Coordonnées invalides" << std::endl;
            return ask_player_for_tokens_coordinates(player);
        }
      coordinates.push_back(std::pair<int, int>(x, y));
    }
    
    if(coordinates.size()> 1){
        for (size_t i = 0; i < coordinates.size() - 1; i++) {
            if (coordinates.at(i) == coordinates.at(i + 1)) {
                std::cout << " Erreur de choix \n" << std::endl;
                return ask_player_for_tokens_coordinates(player);
            }
        }
    }

    return coordinates;
}

std::pair<int, int> Controller::ask_for_player_solo_token_coordinates(const Player& p)
{
    int x, y;
    std::cout << "Entrez la coordonn�es x du jeton � prendre " << std::endl;
    std::cin >> x;
    std::cout << "Entrez la coordonn�es y du jeton � prendre " << std::endl;
    std::cin >> y;
    std::pair<int,int> coordinates = std::pair<int, int>(x, y);
    return coordinates;
}
    


bool Controller::ask_player_for_optional_actions(const Player& player)
{
    int state;
    std::cout << "Voulez-vous effectuer une action optionnelle ? \n 1 pour oui \n 0 pour non" << std::endl;
    std::cin >> state;

    if (state) { return true; }
    else { return false; }
}

 const Card& Controller::ask_player_for_card_to_buy(const Player& player){
    int pile, id;
    std::cout << this->get_GameControlled().getPyramid();
    std::cout << "Quelle carte voulez-vous acheter ?" << std::endl << "Entrez le niveau de la carte \n 1 pour le niveau 1 \n 2 pour le niveau 2 \n 3 pour le niveau 3 \n";
    std::cin >> pile;
    std::cout << "Entrez l'ID de la carte dans la pyramide" << std::endl;
    std::cin >> id;
    CardLevel pileconverted = int_to_cardlevel(pile);
    if (pile == 1) {
        for (auto c : this->get_GameControlled().getPyramid().getLevel1Cards()) {
            if (c.getId() == id && player.canBuy(c)) {
                return c;
            }
        }
    }
    if (pile == 2) {
        for (auto d : this->get_GameControlled().getPyramid().getLevel2Cards()) {
            if (d.getId() == id && player.canBuy(d)) {
                return d;
            }
        }
    }
    if (pile == 3) {
        for (auto e : this->get_GameControlled().getPyramid().getLevel1Cards()) {
            if (e.getId() == id && player.canBuy(e)) {
                return e;
            }
        }
        }
    std::cout << "Impossible d'acheter cette carte" << std::endl;
    return ask_player_for_card_to_buy(player);



}

   


 std::pair<int, CardLevel> Controller::ask_player_for_card_to_reserve(const Player& player)
 {
     int pile, id;
     std::cout << this->get_GameControlled().getPyramid();
     std::cout << "Quelle carte voulez-vous réserver ?" << std::endl << "Entrez le niveau de la carte \n 1 pour le niveau 1 \n 2 pour le niveau 2 \n 3 pour le niveau 3 \n";
     std::cin >> pile;
     std::cout << "Entrez l'ID de la carte dans la pyramide" << std::endl;
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

     std::cout << "Mauvaise pile selectionn�e " << std::endl;
     return ask_player_for_card_to_reserve(player);
 }

    


CoinColor Controller::ask_player_for_bonus_color(const Player& player)
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
        std::cout << " Erreur de choix \n" << std::endl;
        return ask_player_for_bonus_color(player);
        break;
    }
    
}

CoinColor Controller::ask_for_color_to_steal(const Player& p)

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

PlayerType Controller::ask_for_opponenent_type(const Player& p )
{
    int choice;
    std::cout << "Voulez vous jouer contre une IA ? " << std::endl << "0 pour non et 1 pour oui" << std::endl;
    std::cin >> choice;
    if (choice) {
        return PlayerType::AI;
    }
    return PlayerType::AI;
}

OptionalActions Controller::ask_for_optional_action_type(const Player& player)
{
    int choice;
    std::cout << "Quelle action voulez-vous effectuer ? \n 1 pour  prendre un jeton avec un privil�ge \n 2 pour remplir le plateau";
    std::cin >> choice;
    switch (choice) {
    case 1 :
        return OptionalActions::UsePrivileges;
    case 2:
        return OptionalActions::FillBoard;

    default:
        std::cout << " Erreur de choix \n" << std::endl;
        return ask_for_optional_action_type(player);


    }
    

}






void Controller::change_turn()
{
    {
        GameControlled.turn = getOpponent(GameControlled.turn);
    }
}

bool Controller::verify_win(Player& player){
    int winTotalPoints = this->get_GameControlled().getWinConditions().getTotalPoints();
    int winTotalCrowns = this->get_GameControlled().getWinConditions().getTotalCrowns();
    int winPointsInOneColor = this->get_GameControlled().getWinConditions().getPointsInOneColor();

    return ((player.getMaxPointsPerColor() == winPointsInOneColor) || (player.getTotalPoints() == winTotalPoints) || (player.getTotalCrowns() == winTotalCrowns));
}

int Controller::ask_for_number_of_privileges_to_use(const Player &p) {
    int number;
    std::cout << "Combien de privil�ges voulez-vous utiliser ?"<< std::endl;
    std::cin >> number;
    return number;
}

CompulsoryActions Controller::ask_for_compulsory_action_type(const Player& p)
{
    int choice;
    std::cout << "Quelle type d'action obligatoire voulez-vous effectuer ? \n 1 : Acheter une carte \n 2 : R�server une carte \n 3 : Prendre des jetons"  << std::endl;
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

int Controller::ask_for_royal_card(const Player& p)
{
    int id;
    std::cout << p.getName() << "Vous avez " << p.getTotalCrowns() << std::endl << "Vous pouvez choisir une carte royale !";
    std::cout << "Entrez l'ID dans la pyramide" << std::endl;
    for (auto c : get_GameControlled().getPyramid().getRoyalCards()) {
        std::cout << c << " ";
    }
    std::cout << "Entrez l'ID de la carte" << std::endl;
    std::cin >> id;
    return id;
}

bool Controller::askPlayerForCoinsToLose()
{
    CoinColor colortolose;
    int choice;
   
    std::cout << " Quelle couleur de jetons voulez-vous parler ? " << std::endl << "1 : Rouge \n  2 : Vert \n 3 : Bleu \n  4 : Blanc \n 5 : Noir \n 6 : Perle" << std::endl;
    
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        colortolose = CoinColor::Red;

    case 2:
        colortolose = CoinColor::Green;

    case 3:
        colortolose = CoinColor::Blue;

    case 4:
        colortolose = CoinColor::White;

    case 5:
        colortolose = CoinColor::Black;
    case 6:
        colortolose = CoinColor::Pearl;
    default:
        std::cout << "Mauvaise couleur ! " << std::endl;
        return false;

    }
    for (auto c : get_GameControlled().getPlayer(get_GameControlled().getPlayerTurn()).getBonusesPerColor()) {
        if (c.first == colortolose && c.second == 0) {
            return false;
        }
    }
    this->GameControlled.getActivePlayer().loseCoin(colortolose);
    return true;
    
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
    GameMoveVerification checker(this->get_GameControlled());
    GameSaver saver;
    int coin = rand() % 2;
    if (coin) { this->GameControlled.turn = PlayerEnum::Player2; }
    else { this->GameControlled.turn = PlayerEnum::Player1; }
    get_GameControlled().getOpponentPlayer().incrementPrivileges();

    while (!verify_win(this->GameControlled.getActivePlayer())) {
        if (this->GameControlled.getActivePlayer().get_type() == PlayerType::Human)
            {
                this->play_turn_human(checker);
            }
        else {
            play_turn_AI(checker);
        }
        saver.saveGame(this->get_GameControlled());
    }
    StatSaver saverstats;
    saverstats.saveGameStats(get_GameControlled());


}

void Controller::play_turn_human(GameMoveVerification& checker)
{
    printGameState();
    OptionalActions optionalaction;
    while (checker.verify_optional_actions(get_GameControlled().getPlayer(get_GameControlled().getPlayerTurn()))) {
        if (ask_player_for_optional_actions(get_GameControlled().getPlayer(get_GameControlled().getPlayerTurn()))) {
            optionalaction = ask_for_optional_action_type(get_GameControlled().getPlayer(get_GameControlled().getPlayerTurn()));
            if (optionalaction == OptionalActions::UsePrivileges) {
                int number_of_privileges = ask_for_number_of_privileges_to_use(get_GameControlled().getPlayer(get_GameControlled().getPlayerTurn()));
                std::vector<std::pair<int, int>> coordinates = ask_player_for_tokens_coordinates(get_GameControlled().getPlayer(get_GameControlled().getPlayerTurn()));
                while (!GameControlled.playerUsePrivileges(number_of_privileges, coordinates)) {
            
                    int number_of_privileges = ask_for_number_of_privileges_to_use(get_GameControlled().getPlayer(get_GameControlled().getPlayerTurn()));
                    std::vector<std::pair<int, int>> coordinates = ask_player_for_tokens_coordinates(get_GameControlled().getPlayer(get_GameControlled().getPlayerTurn()));
                }
                
                 
            }
            if (optionalaction == OptionalActions::FillBoard) {
                GameControlled.playerFillBoard();
            }

            
        }
        else {
            break;
        }
        printGameState();
    }
    if (!checker.compulsory_action_can_be_done(GameControlled.getActivePlayer())) {
        GameControlled.playerFillBoard();
        GameControlled.getOpponentPlayer().decrementPrivileges();

    }
    
        CompulsoryActions Compulsory_Action = ask_for_compulsory_action_type(GameControlled.getActivePlayer());
        if (Compulsory_Action == CompulsoryActions::BuyCard) {
            
            while (Compulsory_Action==CompulsoryActions::BuyCard && checker.canBuyCard(get_GameControlled().getPlayer(get_GameControlled().getPlayerTurn()))==false)
            {
                std::cout << "Vous ne pouvez pas acheter de cartes " << std::endl;
                Compulsory_Action = ask_for_compulsory_action_type(GameControlled.getActivePlayer());

            }
        }

        if (Compulsory_Action == CompulsoryActions::TakeCoins) {
            
            std::vector<std::pair<int, int>> coordinates = ask_player_for_tokens_coordinates(GameControlled.getActivePlayer());
            while  (!checker.verify_coin_alignment(coordinates) || !checker.verify_coin_colors(coordinates_to_coin(coordinates) )) {
                std::cout <<" Erreur de choix \n" <<std::endl;
                std::cout << "Lol" << std::endl;
                coordinates = ask_player_for_tokens_coordinates(GameControlled.getActivePlayer());
            }
            GameControlled.playerTakeCoins(coordinates);

            if (checker.can_royal_card_pick(GameControlled.getActivePlayer())) {
                int id = ask_for_royal_card(GameControlled.getActivePlayer());

                if (!checker.verify_royal_card_pick(get_GameControlled().getPlayer(GameControlled.getPlayerTurn()), this->get_GameControlled().get_Card_from_ID(id))) {

                    std::cout << " Erreur de choix \n" << std::endl;
                    id = ask_for_royal_card(GameControlled.getActivePlayer());
                    
                }
                GameControlled.getActivePlayer().addCardToHand(get_GameControlled().get_Card_from_ID(id));
            }
            if (checker.overTen(get_GameControlled().getPlayer(GameControlled.getPlayerTurn()))) {
                while (checker.overTen(get_GameControlled().getPlayer(GameControlled.getPlayerTurn()))) {
                    std::cout << "Vous avez trop de jetons ! (plus de 10) \n";
                    if (askPlayerForCoinsToLose() == false) {
                        std::cout << "Mauvaise couleur !" << std::endl;
                    };
                }
            }



            change_turn();
        }
        if (Compulsory_Action == CompulsoryActions::ReserveCard) {
            std::pair<int, CardLevel> cardinfos = ask_player_for_card_to_reserve(GameControlled.getActivePlayer());
            if (!checker.verify_card_type_reservation(GameControlled.pyramid.checkCard(cardinfos.second, cardinfos.first))) {
                std::cout << " Erreur de choix \n" << std::endl;
                cardinfos = ask_player_for_card_to_reserve(GameControlled.getActivePlayer());
       
            }



            GameControlled.playerReserveCard(cardinfos.second, GameControlled.pyramid.checkCard(cardinfos.second, cardinfos.first).getId());
            if (checker.can_royal_card_pick(GameControlled.getActivePlayer())) {
                int id = ask_for_royal_card(GameControlled.getActivePlayer());

                if (!checker.verify_royal_card_pick(get_GameControlled().getPlayer(GameControlled.getPlayerTurn()), this->get_GameControlled().get_Card_from_ID(id))) {

                    std::cout << " Erreur de choix \n" << std::endl;
                    id = ask_for_royal_card(GameControlled.getActivePlayer());

                }
                GameControlled.getActivePlayer().addCardToHand(get_GameControlled().get_Card_from_ID(id));
            }
            
            if (checker.overTen(get_GameControlled().getPlayer(GameControlled.getPlayerTurn()))) {
                while (checker.overTen(get_GameControlled().getPlayer(GameControlled.getPlayerTurn()))) {
                    std::cout << "Vous avez trop de jetons ! (plus de 10) \n";
                    if (askPlayerForCoinsToLose() == false) {
                        std::cout << "Mauvaise couleur !" << std::endl;
                    };
                }
            }

            change_turn();
        }

        if (Compulsory_Action == CompulsoryActions::BuyCard) {
           
          
            const Card& card_to_buy = ask_player_for_card_to_buy(GameControlled.getActivePlayer());
            Skill cardskill1 = card_to_buy.getSkill1();
            Skill cardskill2 = card_to_buy.getSkill2();
            
            if (cardskill1 == Skill::TakeCoin && cardskill2 == Skill::RobCoin || cardskill1 == Skill::RobCoin && cardskill2 == Skill::TakeCoin) {
                GameControlled.playerBuyCard(piletype_to_cardlevel(card_to_buy.getPileTypeOfCard(card_to_buy.getId())), idtoPosition(card_to_buy.getId()), card_to_buy.getCardColor(), ask_for_color_to_steal(GameControlled.getActivePlayer()), ask_for_player_solo_token_coordinates(GameControlled.getActivePlayer()));
            }

            if (cardskill1 == Skill::TakeCoin || cardskill2 == Skill::TakeCoin) {
                GameControlled.playerBuyCard(piletype_to_cardlevel(card_to_buy.getPileTypeOfCard(card_to_buy.getId())), idtoPosition(card_to_buy.getId()), card_to_buy.getCardColor(), CoinColor::Empty, ask_for_player_solo_token_coordinates(GameControlled.getActivePlayer()));
            }
            if (cardskill1 == Skill::RobCoin || cardskill2 == Skill::RobCoin) {
                GameControlled.playerBuyCard(piletype_to_cardlevel(card_to_buy.getPileTypeOfCard(card_to_buy.getId())), idtoPosition(card_to_buy.getId()), card_to_buy.getCardColor(), ask_for_color_to_steal(GameControlled.getActivePlayer()), { 0, 0 });
                  
                
            }
           
            if (checker.can_royal_card_pick(GameControlled.getActivePlayer())) {
                int id = ask_for_royal_card(GameControlled.getActivePlayer());

                if (!checker.verify_royal_card_pick(get_GameControlled().getPlayer(GameControlled.getPlayerTurn()), this->get_GameControlled().get_Card_from_ID(id))) {

                    std::cout << " Erreur de choix \n" << std::endl;

                    id = ask_for_royal_card(GameControlled.getActivePlayer());
                 }
                GameControlled.getActivePlayer().addCardToHand(get_GameControlled().get_Card_from_ID(id));
            }
            if (checker.overTen(get_GameControlled().getPlayer(GameControlled.getPlayerTurn()))) {
                while (checker.overTen(get_GameControlled().getPlayer(GameControlled.getPlayerTurn()))) {
                    std::cout << "Vous avez trop de jetons ! (plus de 10) \n";
                    if (askPlayerForCoinsToLose() == false) {
                        std::cout << "Mauvaise couleur !" << std::endl;
                    };
               }
            }


            change_turn();
            
        }
        
       


    }

void Controller::play_turn_AI(GameMoveVerification& checker)
{
    printGameState();
    if (checker.verify_optional_actions(get_GameControlled().getPlayer(get_GameControlled().getPlayerTurn()))) {
        if (AI_optional_or_not(get_GameControlled().getPlayer(get_GameControlled().getPlayerTurn()))) {
            OptionalActions optionalactionAI = AI_choose_optional_action(get_GameControlled().getPlayer(get_GameControlled().getPlayerTurn()));
            if (optionalactionAI == OptionalActions::UsePrivileges) {
                int privileges = AI_number_of_privileges_to_use(get_GameControlled().getPlayer(get_GameControlled().getPlayerTurn()));
                std::vector<std::pair<int, int>> coordinates = AI_use_privileges(get_GameControlled().getPlayer(get_GameControlled().getPlayerTurn()), privileges);
                while (!GameControlled.playerUsePrivileges(privileges, coordinates)) {
                    int privileges = AI_number_of_privileges_to_use(get_GameControlled().getPlayer(get_GameControlled().getPlayerTurn()));
                    std::vector<std::pair<int, int>> coordinates = AI_use_privileges(get_GameControlled().getPlayer(get_GameControlled().getPlayerTurn()), privileges);
                }
                if (optionalactionAI == OptionalActions::FillBoard) {
                    GameControlled.playerFillBoard();
                }



            }
            
        }
        printGameState();
    }
    if (!checker.compulsory_action_can_be_done(GameControlled.getActivePlayer())) {
        GameControlled.playerFillBoard();
   
    }

    CompulsoryActions compulsoryActionAI = AI_choose_compulsory_action(get_GameControlled().getPlayer(get_GameControlled().getPlayerTurn()));
    if (compulsoryActionAI == CompulsoryActions::TakeCoins) {
        std::vector<std::pair<int, int>> coordinates = AI_take_coins_by_coordinates(get_GameControlled().getPlayer(get_GameControlled().getPlayerTurn()), checker);
        GameControlled.playerTakeCoins(coordinates);
    }
    if (compulsoryActionAI == CompulsoryActions::ReserveCard) {
        const Card& reservedCardAI = AI_reserve_card(get_GameControlled().getPlayer(get_GameControlled().getPlayerTurn()));
        GameControlled.playerReserveCard(get_GameControlled().cardinfosfromCard(reservedCardAI).first, get_GameControlled().cardinfosfromCard(reservedCardAI).second);
    }

    if (compulsoryActionAI == CompulsoryActions::BuyCard) {
        const Card& boughtCardAI = AI_buy_card(get_GameControlled().getPlayer(get_GameControlled().getPlayerTurn()));
        Skill cardskill1 = boughtCardAI.getSkill1();
        Skill cardskill2 = boughtCardAI.getSkill2();

        if (cardskill1 == Skill::TakeCoin && cardskill2 == Skill::RobCoin || cardskill1 == Skill::RobCoin && cardskill2 == Skill::TakeCoin) {
            GameControlled.playerBuyCard(piletype_to_cardlevel(boughtCardAI.getPileTypeOfCard(boughtCardAI.getId())), idtoPosition( boughtCardAI.getId()), boughtCardAI.getCardColor(), AI_choose_color_to_steal(get_GameControlled().getPlayer(get_GameControlled().getPlayerTurn())), AI_take_one_coin_by_coordinates(get_GameControlled().getPlayer(get_GameControlled().getPlayerTurn())));
        }

        if (cardskill1 == Skill::TakeCoin || cardskill2 == Skill::TakeCoin) {
            GameControlled.playerBuyCard(piletype_to_cardlevel(boughtCardAI.getPileTypeOfCard(boughtCardAI.getId())), idtoPosition(boughtCardAI.getId()), boughtCardAI.getCardColor(), CoinColor::Empty, AI_take_one_coin_by_coordinates(get_GameControlled().getPlayer(get_GameControlled().getPlayerTurn())));
        }
        if (cardskill1 == Skill::RobCoin || cardskill2 == Skill::RobCoin) {
            GameControlled.playerBuyCard(piletype_to_cardlevel(boughtCardAI.getPileTypeOfCard(boughtCardAI.getId())), idtoPosition(boughtCardAI.getId()), boughtCardAI.getCardColor(), AI_choose_color_to_steal(get_GameControlled().getPlayer(get_GameControlled().getPlayerTurn())), { 0, 0 });
        }

        
    }
    printGameState();
    if (checker.can_royal_card_pick(GameControlled.getActivePlayer())) {
        const Card& royalpick = AI_royal_pick(get_GameControlled().getPlayer(get_GameControlled().getPlayerTurn()));
        GameControlled.getActivePlayer().addCardToHand(royalpick);
        printGameState();
    }
    if (checker.overTen(get_GameControlled().getPlayer(get_GameControlled().getPlayerTurn()))) {
        while (checker.overTen(get_GameControlled().getPlayer(get_GameControlled().getPlayerTurn()))) {
            AI_lose_coin();
        }
    }
    
    change_turn();
}

    


std::vector<std::pair<int, int>> Controller:: AI_take_coins_by_coordinates(const Player& AI,  GameMoveVerification& checker)
{
    

    for (int i = 0; i < 3; i++) {
        std::vector<std::pair<int, int>> coordinates_3;

        for (int j = i; j < i + 3; j++) {

            coordinates_3.push_back(std::pair<int, int>(j, i));

        }
        if (checker.verify_coin_alignment(coordinates_3) && checker.verify_coin_colors(coordinates_to_coin(coordinates_3)))
        {
            return coordinates_3; //Si la combinaison est valide on prend

        }
        else {
            coordinates_3.erase(coordinates_3.begin(), coordinates_3.end()); //Sinon on efface les coordonn�es du vecteur
        }

    }
    //On cherche maintenant en colonne

    for (int i = 0; i < 3; i++) {
        std::vector<std::pair<int, int>> coordinates_3;

        for (int j = i; j < i + 3; j++) {

            coordinates_3.push_back(std::pair<int, int>(j, i));

        }
        if (checker.verify_coin_alignment(coordinates_3) && checker.verify_coin_colors(coordinates_to_coin(coordinates_3)))
        {
            return coordinates_3; //Si la combinaison est valide on prend

        }
        else {
            coordinates_3.erase(coordinates_3.begin(), coordinates_3.end()); //Sinon on efface les coordonn�es du vecteur
        }
    }
    for (int i = 0; i < 3; i++) {
        std::vector<std::pair<int, int>> coordinates_3;

        for (int j = 0; j < 3; j++) {
            coordinates_3.push_back(std::pair<int, int>(i + j, j));

            if (checker.verify_coin_alignment(coordinates_3) && checker.verify_coin_colors(coordinates_to_coin(coordinates_3))) {
                return coordinates_3; // Si la combinaison est valide on prend
            }
            else {
                coordinates_3.erase(coordinates_3.begin(), coordinates_3.end()); // Sinon on efface les coordonn�es du vecteur
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        std::vector<std::pair<int, int>> coordinates_3;

        for (int j = 0; j < 3; j++) {
            coordinates_3.push_back(std::pair<int, int>(i + j, j));

            if (checker.verify_coin_alignment(coordinates_3) && checker.verify_coin_colors(coordinates_to_coin(coordinates_3))) {
                return coordinates_3; // Si la combinaison est valide on prend
            }
            else {
                coordinates_3.erase(coordinates_3.begin(), coordinates_3.end()); // Sinon on efface les coordonn�es du vecteur
            }
        }
    }

    // sous - diagonale
    for (int i = 2; i < 5; i++) {
        std::vector<std::pair<int, int>> coordinates_3;

        for (int j = 0; j < 3; j++) {
            coordinates_3.push_back(std::pair<int, int>(i - j, j));

            if (checker.verify_coin_alignment(coordinates_3) && checker.verify_coin_colors(coordinates_to_coin(coordinates_3))) {
                return coordinates_3; // Si la combinaison est valide on prend
            }
            else {
                coordinates_3.erase(coordinates_3.begin(), coordinates_3.end()); // Sinon on efface les coordonn�es du vecteur
            }
        }
    }

    // sur-diagonale
    for (int i = 0; i < 3; i++) {
        std::vector<std::pair<int, int>> coordinates_3;

        for (int j = 0; j < 3; j++) {
            coordinates_3.push_back(std::pair<int, int>(j, i + j));

            if (checker.verify_coin_alignment(coordinates_3) && checker.verify_coin_colors(coordinates_to_coin(coordinates_3))) {
                return coordinates_3; // Si la combinaison est valide on prend
            }
            else {
                coordinates_3.erase(coordinates_3.begin(), coordinates_3.end()); // Sinon on efface les coordonn�es du vecteur
            }
        }
    }

    // anti-diagonale
    for (int i = 0; i < 3; i++) {
        std::vector<std::pair<int, int>> coordinates_3;

        for (int j = 0; j < 3; j++) {
            coordinates_3.push_back(std::pair<int, int>(i + j, 4 - j));

            if (checker.verify_coin_alignment(coordinates_3) && checker.verify_coin_colors(coordinates_to_coin(coordinates_3))) {
                return coordinates_3; // Si la combinaison est valide on prend
            }
            else {
                coordinates_3.erase(coordinates_3.begin(), coordinates_3.end()); // Sinon on efface les coordonn�es du vecteur
            }
        }
    }

    //  sous-anti-diagonale
    for (int i = 2; i < 5; i++) {
        std::vector<std::pair<int, int>> coordinates_3;

        for (int j = 0; j < 3; j++) {
            coordinates_3.push_back(std::pair<int, int>(i - j, 4 - j));

            if (checker.verify_coin_alignment(coordinates_3) && checker.verify_coin_colors(coordinates_to_coin(coordinates_3))) {
                return coordinates_3; // Si la combinaison est valide on prend
            }
            else {
                coordinates_3.erase(coordinates_3.begin(), coordinates_3.end()); // Sinon on efface les coordonn�es du vecteur
            }
        }
    }

    //  sur-anti-diagonale
    for (int i = 0; i < 3; i++) {
        std::vector<std::pair<int, int>> coordinates_3;

        for (int j = 0; j < 3; j++) {
            coordinates_3.push_back(std::pair<int, int>(j, 4 - (i + j)));

            if (checker.verify_coin_alignment(coordinates_3) && checker.verify_coin_colors(coordinates_to_coin(coordinates_3))) {
                return coordinates_3; // Si la combinaison est valide on prend
            }
            else {
                coordinates_3.erase(coordinates_3.begin(), coordinates_3.end()); // Sinon on efface les coordonn�es du vecteur
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        std::vector<std::pair<int, int>> coordinates_2;

        for (int j = i; j < i + 2; j++) {

            coordinates_2.push_back(std::pair<int, int>(i, j));

        }
        if (checker.verify_coin_alignment(coordinates_2) && checker.verify_coin_colors(coordinates_to_coin(coordinates_2)))
        {
            return coordinates_2; //Si la combinaison est valide on prend

        }
        else {
            coordinates_2.erase(coordinates_2.begin(), coordinates_2.end()); //Sinon on efface les coordonn�es du vecteur
        }

    }
    //On cherche maintenant en colonne

    for (int i = 0; i < 4; i++) {
        std::vector<std::pair<int, int>> coordinates_2;

        for (int j = i; j < i + 2; j++) {

            coordinates_2.push_back(std::pair<int, int>(j, i));

        }
        if (checker.verify_coin_alignment(coordinates_2) && checker.verify_coin_colors(coordinates_to_coin(coordinates_2)))
        {
            return coordinates_2; //Si la combinaison est valide on prend

        }
        else {
            coordinates_2.erase(coordinates_2.begin(), coordinates_2.end()); //Sinon on efface les coordonn�es du vecteur
        }

    }

    for (int i = 0; i < 4; i++) {
        std::vector<std::pair<int, int>> coordinates_2;

        for (int j = 0; j < 2; j++) {
            coordinates_2.push_back(std::pair<int, int>(i + j, j));

            if (checker.verify_coin_alignment(coordinates_2) && checker.verify_coin_colors(coordinates_to_coin(coordinates_2))) {
                return coordinates_2; // Si la combinaison est valide on prend
            }
            else {
                coordinates_2.erase(coordinates_2.begin(), coordinates_2.end()); // Sinon on efface les coordonn�es du vecteur
            }
        }
    }
    // Sous-diagonale
    for (int i = 1; i < 5; i++) {
        std::vector<std::pair<int, int>> coordinates_2;

        for (int j = 0; j < 2; j++) {
            coordinates_2.push_back(std::pair<int, int>(i - j, j));

            if (checker.verify_coin_alignment(coordinates_2) && checker.verify_coin_colors(coordinates_to_coin(coordinates_2))) {
                return coordinates_2; // Si la combinaison est valide on prend
            }
            else {
                coordinates_2.erase(coordinates_2.begin(), coordinates_2.end()); // Sinon on efface les coordonn�es du vecteur
            }
        }
    }

    //Sur - diagonale
    for (int i = 0; i < 4; i++) {
        std::vector<std::pair<int, int>> coordinates_2;

        for (int j = 0; j < 2; j++) {
            coordinates_2.push_back(std::pair<int, int>(j, i + j));

            if (checker.verify_coin_alignment(coordinates_2) && checker.verify_coin_colors(coordinates_to_coin(coordinates_2))) {
                return coordinates_2; // Si la combinaison est valide on prend
            }
            else {
                coordinates_2.erase(coordinates_2.begin(), coordinates_2.end()); // Sinon on efface les coordonn�es du vecteur
            }
        }
    }

    // anti-diagonale
    for (int i = 0; i < 4; i++) {
        std::vector<std::pair<int, int>> coordinates_2;

        for (int j = 0; j < 2; j++) {
            coordinates_2.push_back(std::pair<int, int>(i + j, 4 - j));

            if (checker.verify_coin_alignment(coordinates_2) && checker.verify_coin_colors(coordinates_to_coin(coordinates_2))) {
                return coordinates_2; // Si la combinaison est valide on prend
            }
            else {
                coordinates_2.erase(coordinates_2.begin(), coordinates_2.end()); // Sinon on efface les coordonn�es du vecteur
            }
        }
    }

    // sous-anti-diagonales
    for (int i = 1; i < 5; i++) {
        std::vector<std::pair<int, int>> coordinates_2;

        for (int j = 0; j < 2; j++) {
            coordinates_2.push_back(std::pair<int, int>(i - j, 4 - j));

            if (checker.verify_coin_alignment(coordinates_2) && checker.verify_coin_colors(coordinates_to_coin(coordinates_2))) {
                return coordinates_2; // Si la combinaison est valide on prend
            }
            else {
                coordinates_2.erase(coordinates_2.begin(), coordinates_2.end()); // Sinon on efface les coordonn�es du vecteur
            }
        }
    }

    // sur-anti-diagonale
    for (int i = 0; i < 4; i++) {
        std::vector<std::pair<int, int>> coordinates_2;

        for (int j = 0; j < 2; j++) {
            coordinates_2.push_back(std::pair<int, int>(j, 4 - (i + j)));

            if (checker.verify_coin_alignment(coordinates_2) && checker.verify_coin_colors(coordinates_to_coin(coordinates_2))) {
                return coordinates_2; // Si la combinaison est valide on prend
            }
            else {
                coordinates_2.erase(coordinates_2.begin(), coordinates_2.end()); // Sinon on efface les coordonn�es du vecteur
            }
        }
    }
    std::vector<std::pair<int, int>> coordinates_void = { {0,0} }; //On a trouv� aucune combinaison plurielle
    return coordinates_void;
}
const Card& Controller::AI_reserve_card(const Player& AI)
{
    int choice = rand() % 2;
    if (choice) {
        std::vector<Card> reserve;
        for (auto c : get_GameControlled().getPyramid().getLevel3Cards()) {
            reserve.push_back(c);
        }

        for (auto c : get_GameControlled().getPyramid().getLevel2Cards()) {
            reserve.push_back(c);
        }

        for (auto c : get_GameControlled().getPyramid().getLevel1Cards()) {
            reserve.push_back(c);
        }
        int total = reserve.size();
        return reserve.at(rand() % total + 1 );
    }

    else {
        int choicepile = rand() % 3 + 1;
        switch (choicepile)
        {
        case 1:
            return get_GameControlled().getPile1().getCards().at(0);
        case 2:
            return get_GameControlled().getPile2().getCards().at(0);

        default:
            return get_GameControlled().getPile3().getCards().at(0);

            break;
        }
    }


}

const Card& Controller::AI_buy_card(const Player& AI)
{
    for (auto c : AI.getReservedCards()) {
        if (AI.AIcanBuy(c)) {
            return c;
        }
    }
    for (auto c : get_GameControlled().getPyramid().getLevel3Cards()) {
        if (AI.AIcanBuy(c)){
        return c;
    }
    }

    for (auto c : get_GameControlled().getPyramid().getLevel2Cards()) {
        if (AI.AIcanBuy(c)) {
            return c;
        }
    }

    for (auto c : get_GameControlled().getPyramid().getLevel1Cards()) {
        if (AI.AIcanBuy(c)) {
            return c;
        }
    }
}

std::pair<int, int> Controller::AI_take_one_coin_by_coordinates(const Player& AI)
{

    int x = rand() % 5, y = rand() % 5;
    while (get_GameControlled().getCoinBoard().getCoin(x, y).getColor() == CoinColor::Empty || get_GameControlled().getCoinBoard().getCoin(x, y).getColor() == CoinColor::Gold) {
        x = rand() % 5; y = rand() % 5;
    }

    return std::pair<int, int>(x, y);
}








OptionalActions Controller::AI_choose_optional_action(const Player& AI)
{
    int choice = rand() % 2;

    if (choice) { return OptionalActions::UsePrivileges; }
    else { return OptionalActions::FillBoard; }

}

bool Controller::AI_optional_or_not(const Player& AI)
{
    int choice = rand() % 2;

    if (choice) { return true; }
    else { return false; }
}

const Card& Controller::AI_royal_pick(const Player& AI)
{
    int royalchoice = rand() % get_GameControlled().getPyramid().getRoyalCards().size() + 1;
    return get_GameControlled().getPyramid().getRoyalCards().at(royalchoice);
}

bool Controller::AI_lose_coin()
{
    std::vector<CoinColor> lose;
    for (auto c : get_GameControlled().getPlayer(getOpponent(get_GameControlled().getPlayerTurn())).getCoinsPerColor()) {
        if (c.second > 0) {
            lose.push_back(c.first);
        }
    }
    this->GameControlled.getActivePlayer().loseCoin(lose .at(rand() % lose.size()));
}


int Controller::idtoPosition(int cID)
{
    int iterator_tracker;
        iterator_tracker = 0;
        for (auto c : this->get_GameControlled().getPyramid().getLevel1Cards()) {

            if (c.getId() == cID) {
                return iterator_tracker;
            }
            iterator_tracker++;
        }
  
        iterator_tracker = 0;
        for (auto d : this->get_GameControlled().getPyramid().getLevel2Cards()) {
            if (d.getId() == cID) {
                return iterator_tracker;
            }
            iterator_tracker++;
        }
   
        iterator_tracker = 0;
        for (auto e : this->get_GameControlled().getPyramid().getLevel3Cards())
            if (e.getId() == cID) {
                return iterator_tracker;
            }
        iterator_tracker++;
    
    
    return 0;
}


std::vector<std::pair<int, int>>  Controller:: AI_use_privileges(const Player& AI, int privileges)
{
    std::vector<std::pair<int, int>> coincoordinates;
    for (int i = 0; i < privileges; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (get_GameControlled().getCoinBoard().getCoin(j, k).getColor() != CoinColor::Empty && coincoordinates.size() < privileges) {
                    coincoordinates.push_back(std::pair<int, int>(j, k));
                }
                else {
                    if (coincoordinates.size() >= privileges) { return coincoordinates; }
                }
            }
        }
    }
    return coincoordinates;
}

CoinColor Controller:: AI_choose_bonus(const Player& AI)
{
    std::vector<CoinColor> bonus;
    for (auto c : AI.getCoinsPerColor()) {
        if (c.second > 0) {
            bonus.push_back(c.first);
        }
    }

    return bonus.at(rand() % bonus.size());

}

CoinColor Controller::AI_choose_color_to_steal(const Player& AI)
{
    std::vector<CoinColor> steal;
    for (auto c : get_GameControlled().getPlayer(getOpponent(get_GameControlled().getPlayerTurn())).getCoinsPerColor()) {
        if (c.second > 0) {
            steal.push_back(c.first);
        }
    }
    return steal.at(rand() % steal.size());
}

int Controller::AI_number_of_privileges_to_use(const Player& AI)
{
    return rand() % AI.getPrivileges() + 1; // On retourne une valeur al�atoire de privil�ge
}

CompulsoryActions Controller::AI_choose_compulsory_action(const Player& AI)
{

    for (auto c : AI.getReservedCards()) {
        if (AI.AIcanBuy(c)) {
            return CompulsoryActions::BuyCard;
        }
    }
    for (auto c : get_GameControlled().getPyramid().getLevel3Cards()) {
        if (AI.AIcanBuy(c)) {
            return CompulsoryActions::BuyCard;
        }
    }

    for (auto c : get_GameControlled().getPyramid().getLevel2Cards()) {
        if (AI.AIcanBuy(c)) {
            return CompulsoryActions::BuyCard;
        }
    }

    for (auto c : get_GameControlled().getPyramid().getLevel1Cards()) {
        if (AI.AIcanBuy(c)) {
            return CompulsoryActions::BuyCard;
        }
    }

    for (auto c : AI.getCoinsPerColor()) {
        if (c.second > 1 && c.first == CoinColor::Gold) {
            return CompulsoryActions::ReserveCard;
        }
    }


    return CompulsoryActions::TakeCoins;
}
