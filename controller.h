//
// Created by Leo on 22/11/2023.
//

#ifndef MONLO21PROJET_CONTROLLER_H
#define MONLO21PROJET_CONTROLLER_H
#include "game.h"
#include "player.h"
#include "gamesaver.h"
#include "GameMoveVerification.h"
#include "aiplayer.h"

class Controller {
private: 
	friend class Game;
	friend class GameMoveVerification;
	GameMoveVerification& checker;
	Game& GameControlled;


public:
	Controller(GameMoveVerification& checker, Game& GameControlled);
	Controller(const Controller&) = delete;
	Controller& operator=(const Controller&) = delete;

	inline GameMoveVerification& get_checker() const { return checker; }
	inline const Game&  get_GameControlled() const { return GameControlled; }

	bool launch_save(GameSaver& save);
	bool reset_game();

	std::vector<Coin> ask_player_for_tokens(Player& Player);
	std::vector<std::pair<int, int>> ask_player_for_tokens_coordinates(Player& player);
	std::pair<int, int> ask_for_player_solo_token_coordinates(Player& p);
	bool ask_player_for_optional_actions(Player& player);
	const Card& ask_player_for_card_to_buy(Player& player);
	std::pair<int,CardLevel> ask_player_for_card_to_reserve(Player& player);
	CoinColor ask_player_for_bonus_color(Player& player);
	CoinColor ask_for_color_to_steal(Player& p);
	PlayerType ask_for_opponenent_type(Player& opponent);
	OptionalActions ask_for_optional_action_type(Player& player);
	int ask_for_number_of_privileges_to_use(Player& p);
	CompulsoryActions ask_for_compulsory_action_type(Player& p);
	int ask_for_royal_card(Player& p);

	
	std::vector<Coin> coordinates_to_coin(std::vector<std::pair<int, int>>& coordinates);
	CardLevel int_to_cardlevel(int level);
	CardLevel piletype_to_cardlevel(PileType type);

	
	void printGameState();
	void play_game();
	void play_turn_human();
	void play_turn_AI();
	void change_turn();
	bool verify_win(Player& player);
	


};


#endif //MONLO21PROJET_CONTROLLER_H
