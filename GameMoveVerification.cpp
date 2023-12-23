#include "GameMoveVerification.h"


bool GameMoveVerification::verify_coin_alignment(std::vector<std::pair<int, int>> coinchoices)
{
	if (coinchoices.size() == 1) { return true; }
	if (coinchoices.size() == 2) {
		int x1 = coinchoices.at(0).first, x2 = coinchoices.at(1).first;
		int y1 = coinchoices.at(0).second, y2 = coinchoices.at(1).second;

		if (x1 == x2) {
			if ((y1 == y2 + 1) || (y1 == y2 - 1)) {
				return true;
			}
		}

		if (y1 == y2) {
			if ((x1 == y2 + 1) || (x1 == x2 - 1)) {
				return true;
			}
		}
		// Diagonales 

		if ((x1 == x2 + 1 || x1 == x2 - 1) && (y1 == y2 + 1 || y1 == y2 - 1)) {
			return true;
		}

		return false;
	}

	if (coinchoices.size() == 3) {
		int x1 = coinchoices.at(0).first, x2 = coinchoices.at(1).first, x3 = coinchoices.at(2).first;;
		int y1 = coinchoices.at(0).second, y2 = coinchoices.at(1).second, y3 = coinchoices.at(2).second;
		if (x1 == x2 == x3) {
				

			if ((y1 + 1 == y2) && (y3 == y2 + 1) || (y1 - 1 == y2) && (y3 == y2 - 1)) {
				return true;
			}
		}

		if (y1 == y2 == y3) {
			if ((x1 + 1 == x2) && (x3 == x2 + 1) || (x1 - 1 == x2) && (x3 == x2 - 1)) {
				return true;
			}
		}

		if (x2 == x1 + 1 && x3 == x2 + 1) { //Diagonales
			if (y3 == y2 + 1 && y2 == y1 + 1) {
				return true;
			}
			if (y3 == y2 - 1 && y2 == y1 - 1) {
				return true;
			}
		}

		if (x2 == x1 - 1 && x3 == x2 - 1) { //Antiiagonales
			if (y3 == y2 + 1 && y2 == y1 + 1) {
				return true;
			}
			if (y3 == y2 - 1 && y2 == y1 - 1) {
				return true;
			}
		}
	
	}

}

bool GameMoveVerification::verify_coin_colors(std::vector<Coin> coinstaken)
{ 
	for (auto c : coinstaken) {
		if (c.getColor() == CoinColor::Gold || c.getColor() == CoinColor::Empty) {
			return false;
		}
	}

	return true;
}

bool GameMoveVerification::verify_optional_actions(const Player& player) //Vérifie si le joueur peut effectuer une action optionnelle
{
	if (player.getPrivileges() == 0) {
		return false;
	}
	return true;

}

bool GameMoveVerification::verify_card_type_reservation(const Card& reservedCard) //On vérifie que la carte n'est pas une carte royale
{
	if (reservedCard.getPileTypeOfCard(reservedCard.getId()) == PileType::Royal)
	{
		return false;
	}
	for (int j = 0; j < 4; j++) {
		for (int k = 0; k < 4; k++) {
			if (get_game_checked().getCoinBoard().getCoin(j, k).getColor() == CoinColor::Gold) {
				return true;
			}
		}
		
	}
	return false;
}
bool GameMoveVerification::verify_no_bonus_card(const Card& boughtCard, Player& player)
{
	if ((boughtCard.getSkill1() == Skill::Bonus || boughtCard.getSkill2() == Skill::Bonus) && player.getBonusesPerColor().size() == 0) {
		return false;
	}
	return true;
}

bool GameMoveVerification::compulsory_action_can_be_done(Player& p)
{

		for (auto c : p.getReservedCards()) {
			if (p.canBuy(c)) {
				return true;
			}
		}
		for (auto c : get_game_checked().getPyramid().getLevel3Cards()) {
			if (p.canBuy(c)) {
				return true;
			}
		}

		for (auto c : get_game_checked().getPyramid().getLevel2Cards()) {
			if (p.canBuy(c)) {
				return true;
			}
		}

		for (auto c : get_game_checked().getPyramid().getLevel1Cards()) {
			if (p.canBuy(c)) {
				return true;
			}
		}
		//Réserver une carte
		for (int x = 0; x < 5; x++) {
			for (int y = 0; y < 5; y++) {
				if (get_game_checked().getCoinBoard().getCoin(x, y).getColor() == CoinColor::Gold)
					return true; 
			}
		}
		if (!get_game_checked().getCoinBoard().isEmpty()) { return true; }

		return false;
	}

bool GameMoveVerification::can_royal_card_pick(Player& p)
{
	if (p.getTotalCrowns() < 3) { return false; }
	if (p.getTotalCrowns() >= 3 && p.getTotalCrowns() < 6) {
		for (auto hand : p.getHand()) {
			if (hand.getPileTypeOfCard(hand.getId()) == PileType::Royal) {
				return false;
			}
		}
	}

	int counter = 0;
	if  (p.getTotalCrowns() > 6) {
		for (auto hand : p.getHand()) {
			if (hand.getPileTypeOfCard(hand.getId()) == PileType::Royal) {
				counter += 1;
			}
		}
		if (counter == 2) {
			return false;
		}
	}
	return true;
}

bool GameMoveVerification::verify_royal_card_pick(const Player& p, const Card& pickedCard)
{
	if (pickedCard.getPileTypeOfCard(pickedCard.getId()) == PileType::Royal) {
		return true;
	}
	return false;
}

bool GameMoveVerification::canBuyCard(const Player& p) const {
	for (auto c : p.getReservedCards() ) {
		if (p.canBuy(c)) {
			return true;
		}
	}
	for (auto c : get_game_checked().getPyramid().getLevel3Cards()) {
		if (p.canBuy(c)) {
			return true;
		}
	}

	for (auto c : get_game_checked().getPyramid().getLevel2Cards()) {
		if (p.canBuy(c)) {
			return true;
		}
	}

	for (auto c : get_game_checked().getPyramid().getLevel1Cards()) {
		if (p.canBuy(c)) {
			return true;
		}
	}

return false;
}