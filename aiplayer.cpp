#include "aiplayer.h"

std::vector<std::pair<int, int>> AIPlayer::AI_take_coins_by_coordinates(Controller& controller)
{
	//On commence par les jetons perles pour leur valeur supérieure en jeu 
	//On cherche les jetons perles en ligne 
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

	// Diagonale à faire 

	//Autres couleurs (par 3)

	for (int i = 0; i < 3; i++) {
		std::vector<std::pair<int, int>> coordinates_3;

		for (int j = i; j < i + 3; j++) {

			coordinates_3.push_back(std::pair<int, int>(j,i));

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
	//Diagonale à faire
}
	

	

