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
#include"statsaver.h"

class Controller {
private: 
	friend class Game;
	friend class GameMoveVerification;
	//GameMoveVerification& checker;
	Game& GameControlled;


public:
	Controller(Game& GameControlled) :  GameControlled(GameControlled) {}
	Controller(const Controller&) = delete;
	Controller& operator=(const Controller&) = delete;

	//inline GameMoveVerification& get_checker() const { return checker; }
	inline Game&  get_GameControlled() const { return GameControlled; }


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
	void play_turn_human(GameMoveVerification& checker);
	void play_turn_AI(GameMoveVerification& checker);
	void change_turn();
	bool verify_win(Player& player);

	std::vector<std::pair<int, int>> AI_take_coins_by_coordinates(const Player& AI,  GameMoveVerification& checker);
	const Card& AI_reserve_card(const Player& AI);
	const Card& AI_buy_card(const Player& AI);
	std::pair<int, int> AI_take_one_coin_by_coordinates(const Player& AI);
	std::vector<std::pair<int, int>> AI_use_privileges(const Player& AI, int privileges);
	CoinColor AI_choose_bonus(const Player& AI);
	CoinColor AI_choose_color_to_steal(const Player& AI);
	int AI_number_of_privileges_to_use(const Player& AI);
	CompulsoryActions AI_choose_compulsory_action(const Player& AI);
	OptionalActions AI_choose_optional_action(const Player& AI);
	bool AI_optional_or_not(const Player& AI);
	const Card& AI_royal_pick(const Player& AI);
	
	
	


};


#endif //MONLO21PROJET_CONTROLLER_H
