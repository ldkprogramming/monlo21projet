#include "GameMoveVerification.h"

GameMoveVerification::GameMoveVerification(Game& game) : GameChecked(game)
{
	verificator_state = true;
}

void GameMoveVerification::change_verificator_state()
{
	if (this->verificator_state) {
		this->verificator_state = false;
	}
	else {
		this->verificator_state = true;
	}
}

bool GameMoveVerification::verify_coin_alignment(std::vector<std::pair<int, int>> coinchoices)
{
	int x1 = coinchoices.at(0).first, x2 = coinchoices.at(1).first, x3 = coinchoices.at(2).first;
	int y1 = coinchoices.at(0).second, y2 = coinchoices.at(1).second, y3 = coinchoices.at(2).second;
	switch (coinchoices.size()) {
	case 2: //Jetons perles
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

		if ((x1 == x2 + 1|| x1 == x2-1) && (y1 == y2 + 1 || y1 == y2 - 1)) {
			return true;
		}

		return false;

	case 3 :
		if (x1 == x2 == x3) {
			if ((y1 + 1 == y2 ) && (y3 == y2 + 1) || (y1 - 1 == y2) && (y3 == y2 - 1)) {
				return true;
			}
		}

		if (y1 == y2 == y3) {
			if ((x1 + 1 == x2) && (x3 == x2 + 1) || (x1 - 1 == x2) && (x3 == x2 - 1)) {
				return true;
			}
		}

		if (x2== x1 + 1 && x3 == x2 + 1) { //Diagonales
			if (y3 == y2 + 1 && y2  == y1 + 1) {
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
		if (c.getColor() == CoinColor::Gold) {
			return false;
		}
		if (c.getColor() == CoinColor::Pearl && coinstaken.size() == 3) {
			return false;
		}
		if (c.getColor() != CoinColor::Pearl && coinstaken.size() == 2)
		{
			return false;
		}
	}

	return true;
}

bool GameMoveVerification::verify_optional_actions(Player& player) //Vérifie si le joueur peut effectuer une action optionnelle
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
	return true;
}

bool GameMoveVerification::verify_no_bonus_card(const Card& boughtCard, Player& player)
{
	if ((boughtCard.getSkill1() == Skill::Bonus || boughtCard.getSkill2() == Skill::Bonus) && player.getBonusesPerColor().size() == 0) {
		return false;
	}
	return true;
}
