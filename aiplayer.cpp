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



