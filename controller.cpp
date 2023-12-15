//
// Created by Leo on 22/11/2023.
//

#include "controller.h"
#include "coin.h"
#include "algorithm"
#include <cstdlib>


// // faut completement refaire
/*
bool Controller::checkIfPlayerWins(Game &game, Player &player) {
    int winTotalPoints = game.getWinConditions().getTotalPoints();
    int winTotalCrowns = game.getWinConditions().getTotalCrowns();
    int winPointsInOneColor = game.getWinConditions().getPointsInOneColor();

    return ((player.getMaxPointsPerColor() == winPointsInOneColor) || (player.getTotalPoints() == winTotalPoints) ||
            (player.getTotalCrowns() == winTotalCrowns)) ;
}

std::vector<OptionalActions> Controller::getValidOptionalActions(const Game &game, Player &player) const {
    std::vector<OptionalActions> result;
    result.push_back(OptionalActions::Empty);
    if (player.getPrivileges() > 0){
        result.push_back(OptionalActions::UsePrivileges);
    }
    if (not (game.getCoinBag().isEmpty())){
        result.push_back(OptionalActions::FillBoard);
    }
    return result;
}

std::vector<CompulsoryActions> Controller::getValidCompulsoryActions(const Game &game, Player &player) const{
    std::vector<CompulsoryActions> result;
    // On verifie si y a des jetons et que ce n'est pas que des jetons Gold
    if ((not (game.getCoinBoard().isEmpty())) and (not game.getCoinBoard().containsOnly(CoinColor::Gold))){
        result.push_back(CompulsoryActions::TakeCoins);
    }

    // On verifie si on peut reserver : on verifie si on a au moins un jeton or et que les paquets ne sont pas vides
    if (game.getCoinBoard().containsAtLeastOne(CoinColor::Gold)){
        if ((not (game.getPile1().isEmpty())) || (not (game.getPile2().isEmpty())) || (not (game.getPile3().isEmpty()))){
            result.push_back(CompulsoryActions::ReserveCard);
        }
    }

    // On verifie si le joueur peut acheter au moins une carte
    bool hasBeenAdded = false;
    for (auto card : game.getPyramid().getLevel1Cards()){
        if (player.canBuy(card)){
            result.push_back(CompulsoryActions::BuyCard);
            hasBeenAdded = true;
            break;
        }
    }
    if (not hasBeenAdded){
        for (auto card : game.getPyramid().getLevel2Cards()){
            if (player.canBuy(card)){
                result.push_back(CompulsoryActions::BuyCard);
                hasBeenAdded = true;
                break;
            }
        }
    }

    if (not hasBeenAdded) {
        for (auto card: game.getPyramid().getLevel3Cards()) {
            if (player.canBuy(card)) {
                result.push_back(CompulsoryActions::BuyCard);

                break;
            }
        }
    }
    return result;
}

bool Controller::applyCardSkills(Game &game, Player &cardOwner, Player& opponent, Card &card) {
    //Renvoie true si le joueur doit jouer un autre tour
    bool playAgain = false;

    Skill skill1 = card.getSkill1();
    Skill skill2 = card.getSkill2();

    // PlayAgain, Bonus, TakeCoin, TakePrivilege, RobCoin, Empty
    switch (skill1){
        case Skill::PlayAgain: {
            return true;
        }


        case Skill::Bonus: {
            // obtenir les choix valides de couleur
            std::vector<CoinColor> validColorChoices;
            for (auto pair : cardOwner.getBonusesPerColor()){
                if (pair.second > 0){
                    validColorChoices.push_back(pair.first);
                }
            }

            bool isChoiceValid = false;
            std::string choice;
            while (not isChoiceValid){
                std::cout << "Quelle couleur pour le bonus ? ";
                std::cin >> choice;
                isChoiceValid = std::find(validColorChoices.begin(), validColorChoices.end(), toCoinColor(choice)) != validColorChoices.end();

            }
            card.incrementBonus(toCoinColor(choice), 1);
            break;
        }
    }
}

void Controller::applyCompulsoryAction(Game &game, Player &player, CompulsoryActions action) {
    // renvoie true si le joueur doit jouer un autre tour
    switch(action){
        case CompulsoryActions::TakeCoins:{
            int coinNumber = 0;
            std::vector<std::pair<int, int>> coinChoices;
            while (true) {
                std::cout << "Combien de Jetons ?";
                std::cin >> coinNumber;



                for (int i = 0; i< coinNumber; i++) {
                    int x,y;
                    std::cout << "X ?";
                    std::cin >> x;
                    std::cout << "Y ?";
                    std::cin >> y;
                    coinChoices.push_back(std::pair<int, int>(x, y));
                }



                for (auto coordinates : coinChoices) {
                    player.addCoin(game.getCoinBoard().getCoin(coordinates.first, coordinates.second));
                    game.coinBoard.setCoin(coordinates.first, coordinates.second, CoinColor::Empty);
                }

                break;
            }
            break;

        }
        case CompulsoryActions::ReserveCard:{
            int pileNumber = 0;
            std::cout << "Quelle pioche ?";
            std::cin >> pileNumber;

            int cardNumber = 0;
            std::cout << "Quelle carte ?";
            std::cin >> cardNumber;

            player.reserveCard(game.pyramid.distributeCard(pileNumber, cardNumber));
        }
        case CompulsoryActions::BuyCard:{
            // faire vrm attention pour le fait de rejouer un tour
        }
    }
}
*/

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
