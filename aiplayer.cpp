#include "aiplayer.h"

std::vector<std::pair<int, int>> AIPlayer::AI_take_coins_by_coordinates(Controller& controller)
{


	for (int i = 0; i < 3; i++) {
		std::vector<std::pair<int, int>> coordinates_3;

		for (int j = i; j < i + 3; j++) {

			coordinates_3.push_back(std::pair<int, int>(j, i));

		}
		if (controller.get_checker().verify_coin_alignment(coordinates_3) && controller.get_checker().verify_coin_colors(controller.coordinates_to_coin(coordinates_3)))
		{
			return coordinates_3; //Si la combinaison est valide on prend

		}
		else {
			coordinates_3.erase(coordinates_3.begin(), coordinates_3.end()); //Sinon on efface les coordonnées du vecteur
		}

	}
	//On cherche maintenant en colonne

	for (int i = 0; i < 3; i++) {
		std::vector<std::pair<int, int>> coordinates_3;

		for (int j = i; j < i + 3; j++) {

			coordinates_3.push_back(std::pair<int, int>(j, i));

		}
		if (controller.get_checker().verify_coin_alignment(coordinates_3) && controller.get_checker().verify_coin_colors(controller.coordinates_to_coin(coordinates_3)))
		{
			return coordinates_3; //Si la combinaison est valide on prend

		}
		else {
			coordinates_3.erase(coordinates_3.begin(), coordinates_3.end()); //Sinon on efface les coordonnées du vecteur
		}
	}
	for (int i = 0; i < 3; i++) {
		std::vector<std::pair<int, int>> coordinates_3;

		for (int j = 0; j < 3; j++) {
			coordinates_3.push_back(std::pair<int, int>(i + j, j));

			if (controller.get_checker().verify_coin_alignment(coordinates_3) && controller.get_checker().verify_coin_colors(controller.coordinates_to_coin(coordinates_3))) {
				return coordinates_3; // Si la combinaison est valide on prend
			}
			else {
				coordinates_3.erase(coordinates_3.begin(), coordinates_3.end()); // Sinon on efface les coordonnées du vecteur
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		std::vector<std::pair<int, int>> coordinates_3;

		for (int j = 0; j < 3; j++) {
			coordinates_3.push_back(std::pair<int, int>(i + j, j));

			if (controller.get_checker().verify_coin_alignment(coordinates_3) && controller.get_checker().verify_coin_colors(controller.coordinates_to_coin(coordinates_3))) {
				return coordinates_3; // Si la combinaison est valide on prend
			}
			else {
				coordinates_3.erase(coordinates_3.begin(), coordinates_3.end()); // Sinon on efface les coordonnées du vecteur
			}
		}
	}

	// sous - diagonale
	for (int i = 2; i < 5; i++) {
		std::vector<std::pair<int, int>> coordinates_3;

		for (int j = 0; j < 3; j++) {
			coordinates_3.push_back(std::pair<int, int>(i - j, j));

			if (controller.get_checker().verify_coin_alignment(coordinates_3) && controller.get_checker().verify_coin_colors(controller.coordinates_to_coin(coordinates_3))) {
				return coordinates_3; // Si la combinaison est valide on prend
			}
			else {
				coordinates_3.erase(coordinates_3.begin(), coordinates_3.end()); // Sinon on efface les coordonnées du vecteur
			}
		}
	}

	// sur-diagonale
	for (int i = 0; i < 3; i++) {
		std::vector<std::pair<int, int>> coordinates_3;

		for (int j = 0; j < 3; j++) {
			coordinates_3.push_back(std::pair<int, int>(j, i + j));

			if (controller.get_checker().verify_coin_alignment(coordinates_3) && controller.get_checker().verify_coin_colors(controller.coordinates_to_coin(coordinates_3))) {
				return coordinates_3; // Si la combinaison est valide on prend
			}
			else {
				coordinates_3.erase(coordinates_3.begin(), coordinates_3.end()); // Sinon on efface les coordonnées du vecteur
			}
		}
	}

	// anti-diagonale
	for (int i = 0; i < 3; i++) {
		std::vector<std::pair<int, int>> coordinates_3;

		for (int j = 0; j < 3; j++) {
			coordinates_3.push_back(std::pair<int, int>(i + j, 4 - j));

			if (controller.get_checker().verify_coin_alignment(coordinates_3) && controller.get_checker().verify_coin_colors(controller.coordinates_to_coin(coordinates_3))) {
				return coordinates_3; // Si la combinaison est valide on prend
			}
			else {
				coordinates_3.erase(coordinates_3.begin(), coordinates_3.end()); // Sinon on efface les coordonnées du vecteur
			}
		}
	}

	//  sous-anti-diagonale
	for (int i = 2; i < 5; i++) {
		std::vector<std::pair<int, int>> coordinates_3;

		for (int j = 0; j < 3; j++) {
			coordinates_3.push_back(std::pair<int, int>(i - j, 4 - j));

			if (controller.get_checker().verify_coin_alignment(coordinates_3) && controller.get_checker().verify_coin_colors(controller.coordinates_to_coin(coordinates_3))) {
				return coordinates_3; // Si la combinaison est valide on prend
			}
			else {
				coordinates_3.erase(coordinates_3.begin(), coordinates_3.end()); // Sinon on efface les coordonnées du vecteur
			}
		}
	}

	//  sur-anti-diagonale
	for (int i = 0; i < 3; i++) {
		std::vector<std::pair<int, int>> coordinates_3;

		for (int j = 0; j < 3; j++) {
			coordinates_3.push_back(std::pair<int, int>(j, 4 - (i + j)));

			if (controller.get_checker().verify_coin_alignment(coordinates_3) && controller.get_checker().verify_coin_colors(controller.coordinates_to_coin(coordinates_3))) {
				return coordinates_3; // Si la combinaison est valide on prend
			}
			else {
				coordinates_3.erase(coordinates_3.begin(), coordinates_3.end()); // Sinon on efface les coordonnées du vecteur
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		std::vector<std::pair<int, int>> coordinates_2;

		for (int j = i; j < i + 2; j++) {

			coordinates_2.push_back(std::pair<int, int>(i, j));

		}
		if (controller.get_checker().verify_coin_alignment(coordinates_2) && controller.get_checker().verify_coin_colors(controller.coordinates_to_coin(coordinates_2)))
		{
			return coordinates_2; //Si la combinaison est valide on prend

		}
		else {
			coordinates_2.erase(coordinates_2.begin(), coordinates_2.end()); //Sinon on efface les coordonnées du vecteur
		}

	}
	//On cherche maintenant en colonne

	for (int i = 0; i < 4; i++) {
		std::vector<std::pair<int, int>> coordinates_2;

		for (int j = i; j < i + 2; j++) {

			coordinates_2.push_back(std::pair<int, int>(j, i));

		}
		if (controller.get_checker().verify_coin_alignment(coordinates_2) && controller.get_checker().verify_coin_colors(controller.coordinates_to_coin(coordinates_2)))
		{
			return coordinates_2; //Si la combinaison est valide on prend

		}
		else {
			coordinates_2.erase(coordinates_2.begin(), coordinates_2.end()); //Sinon on efface les coordonnées du vecteur
		}

	}

	for (int i = 0; i < 4; i++) {
		std::vector<std::pair<int, int>> coordinates_2;

		for (int j = 0; j < 2; j++) {
			coordinates_2.push_back(std::pair<int, int>(i + j, j));

			if (controller.get_checker().verify_coin_alignment(coordinates_2) && controller.get_checker().verify_coin_colors(controller.coordinates_to_coin(coordinates_2))) {
				return coordinates_2; // Si la combinaison est valide on prend
			}
			else {
				coordinates_2.erase(coordinates_2.begin(), coordinates_2.end()); // Sinon on efface les coordonnées du vecteur
			}
		}
	}
	// Sous-diagonale
	for (int i = 1; i < 5; i++) {
		std::vector<std::pair<int, int>> coordinates_2;

		for (int j = 0; j < 2; j++) {
			coordinates_2.push_back(std::pair<int, int>(i - j, j));

			if (controller.get_checker().verify_coin_alignment(coordinates_2) && controller.get_checker().verify_coin_colors(controller.coordinates_to_coin(coordinates_2))) {
				return coordinates_2; // Si la combinaison est valide on prend
			}
			else {
				coordinates_2.erase(coordinates_2.begin(), coordinates_2.end()); // Sinon on efface les coordonnées du vecteur
			}
		}
	}

	//Sur - diagonale
	for (int i = 0; i < 4; i++) {
		std::vector<std::pair<int, int>> coordinates_2;

		for (int j = 0; j < 2; j++) {
			coordinates_2.push_back(std::pair<int, int>(j, i + j));

			if (controller.get_checker().verify_coin_alignment(coordinates_2) && controller.get_checker().verify_coin_colors(controller.coordinates_to_coin(coordinates_2))) {
				return coordinates_2; // Si la combinaison est valide on prend
			}
			else {
				coordinates_2.erase(coordinates_2.begin(), coordinates_2.end()); // Sinon on efface les coordonnées du vecteur
			}
		}
	}

	// anti-diagonale
	for (int i = 0; i < 4; i++) {
		std::vector<std::pair<int, int>> coordinates_2;

		for (int j = 0; j < 2; j++) {
			coordinates_2.push_back(std::pair<int, int>(i + j, 4 - j));

			if (controller.get_checker().verify_coin_alignment(coordinates_2) && controller.get_checker().verify_coin_colors(controller.coordinates_to_coin(coordinates_2))) {
				return coordinates_2; // Si la combinaison est valide on prend
			}
			else {
				coordinates_2.erase(coordinates_2.begin(), coordinates_2.end()); // Sinon on efface les coordonnées du vecteur
			}
		}
	}

	// sous-anti-diagonales
	for (int i = 1; i < 5; i++) {
		std::vector<std::pair<int, int>> coordinates_2;

		for (int j = 0; j < 2; j++) {
			coordinates_2.push_back(std::pair<int, int>(i - j, 4 - j));

			if (controller.get_checker().verify_coin_alignment(coordinates_2) && controller.get_checker().verify_coin_colors(controller.coordinates_to_coin(coordinates_2))) {
				return coordinates_2; // Si la combinaison est valide on prend
			}
			else {
				coordinates_2.erase(coordinates_2.begin(), coordinates_2.end()); // Sinon on efface les coordonnées du vecteur
			}
		}
	}

	// sur-anti-diagonale
	for (int i = 0; i < 4; i++) {
		std::vector<std::pair<int, int>> coordinates_2;

		for (int j = 0; j < 2; j++) {
			coordinates_2.push_back(std::pair<int, int>(j, 4 - (i + j)));

			if (controller.get_checker().verify_coin_alignment(coordinates_2) && controller.get_checker().verify_coin_colors(controller.coordinates_to_coin(coordinates_2))) {
				return coordinates_2; // Si la combinaison est valide on prend
			}
			else {
				coordinates_2.erase(coordinates_2.begin(), coordinates_2.end()); // Sinon on efface les coordonnées du vecteur
			}
		}
	}
	std::vector<std::pair<int, int>> coordinates_void = { {0,0} }; //On a trouvé aucune combinaison plurielle
	return coordinates_void;
}

const Card& AIPlayer::AI_reserve_card(Controller& controller)
{
	int choice = rand() % 2;
	if (choice) {
		std::vector<Card> reserve;
		for (auto c : controller.get_GameControlled().getPyramid().getLevel3Cards()) {
			reserve.push_back(c);
		}

		for (auto c : controller.get_GameControlled().getPyramid().getLevel2Cards()) {
			reserve.push_back(c);
		}

		for (auto c : controller.get_GameControlled().getPyramid().getLevel1Cards()) {
			reserve.push_back(c);
		}
		return reserve.at(rand() % reserve.size());
	}
	
	else {
		int choicepile = rand() % 3 + 1;
		switch (choicepile)
		{
		case 1:
			return controller.get_GameControlled().getPile1().getCards().at(0);
		case 2:
			return controller.get_GameControlled().getPile2().getCards().at(0);

		default:
			return controller.get_GameControlled().getPile3().getCards().at(0);

			break;
		}
	}

	
}

const Card& AIPlayer::AI_buy_card(Controller& controller)
{
	for (auto c : getReservedCards()) {
		if (canBuy(c));
		return c;
	}
	for (auto c : controller.get_GameControlled().getPyramid().getLevel3Cards()) {
		if (canBuy(c));
		return c;
	}

	for (auto c : controller.get_GameControlled().getPyramid().getLevel2Cards()) {
		if (canBuy(c));
		return c;
	}

	for (auto c : controller.get_GameControlled().getPyramid().getLevel1Cards()) {
		if (canBuy(c));
		return c;
	}
}

std::pair<int, int> AIPlayer::AI_take_one_coin_by_coordinates(Controller& controller)
{
	
	int x = rand()%5, y = rand() % 5;
	while (controller.get_GameControlled().getCoinBoard().getCoin(x, y).getColor() == CoinColor::Empty || controller.get_GameControlled().getCoinBoard().getCoin(x, y).getColor() == CoinColor::Gold) {
		x = rand() % 5; y = rand() % 5;
	}
	
	return std::pair<int, int>(x,y);
}





	

	
OptionalActions AIPlayer::AI_choose_optional_action(Controller& Controller)
{
	int choice = rand() % 2;
	
	if (choice) { return OptionalActions::UsePrivileges; }
	else { return OptionalActions::FillBoard; }
	
}

bool AIPlayer::AI_optional_or_not(Controller& controller)
{
	int choice = rand() % 2;

	if (choice) { return true;}
	else { return false; }
}

void AIPlayer::AI_increment_actions_done()
{
	actionsdone += 1;
}

std::vector<std::pair<int, int>> AIPlayer::AI_use_privileges(Controller& controller, int privileges)
{
	std::vector<std::pair<int, int>> coincoordinates;
	for (int i = 0; i < privileges; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				if (controller.get_GameControlled().getCoinBoard().getCoin(j, k).getColor() != CoinColor::Empty && coincoordinates.size() < privileges) {
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

CoinColor AIPlayer::AI_choose_bonus(Controller& controller)
{
	std::vector<CoinColor> bonus;
	for (auto c : getCoinsPerColor()) {
		if (c.second > 0) {
			bonus.push_back(c.first);
		} 
	}

	return bonus.at(rand() % bonus.size());

}

CoinColor AIPlayer::AI_choose_color_to_steal(Controller& controller)
{
	std::vector<CoinColor> steal;
	for (auto c : controller.get_GameControlled().getPlayer(getOpponent(controller.get_GameControlled().getPlayerTurn())).getCoinsPerColor()) {
		if (c.second > 0) {
			steal.push_back(c.first);
		}
	}
	return steal.at(rand() % steal.size());
}

int AIPlayer::AI_number_of_privileges_to_use(Controller& controller)
{
		return rand() % getPrivileges()+1; // On retourne une valeur aléatoire de privilège
}

CompulsoryActions AIPlayer::AI_choose_compulsory_action(Controller& Controller)
{
	
	for (auto c : getReservedCards()) {
		if (canBuy(c));
		return CompulsoryActions::BuyCard;
	}
	for(auto c : Controller.get_GameControlled().getPyramid().getLevel3Cards()){
		if (canBuy(c));
		return CompulsoryActions::BuyCard;
	}

	for (auto c : Controller.get_GameControlled().getPyramid().getLevel2Cards()) {
		if (canBuy(c));
		return CompulsoryActions::BuyCard;
	}

	for (auto c : Controller.get_GameControlled().getPyramid().getLevel1Cards()) {
		if (canBuy(c));
		return CompulsoryActions::BuyCard;
	}

	for (auto c : getCoinsPerColor()) {
		if (c.second > 1 && c.first == CoinColor::Gold) {
			return CompulsoryActions::ReserveCard;
		}
	}
	

	return CompulsoryActions::TakeCoins;
}




