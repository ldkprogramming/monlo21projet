//
// Created by Leo on 22/11/2023.
//

#include "controller.h"
#include "coin.h"
#include "algorithm"

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
    for (auto card : game.getPyramid().getLevel1Cards()){
        if (player.canBuy(card)){
            result.push_back(CompulsoryActions::BuyCard);
            break;
        }
    }
    for (auto card : game.getPyramid().getLevel2Cards()){
        if (player.canBuy(card)){
            result.push_back(CompulsoryActions::BuyCard);
            break;
        }
    }
    for (auto card : game.getPyramid().getLevel3Cards()){
        if (player.canBuy(card)){
            result.push_back(CompulsoryActions::BuyCard);
            break;
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
        case Skill::PlayAgain:
            playAgain = true;
            break;
        case Skill::Bonus:
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