/*#pragma once
#include "card.h"
#include "cardpyramid.h"
#include "coin.h"
#include "coinbag.h"
#include "coinboard.h"
#include "game.h"
#include "GameMoveVerification.h"
#include "pile.h"
#include "player.h"
#include <cstdio>
#include <cstdlib>

class AIPlayer : public Player{
	int actionsdone = 0; 
public:

	AIPlayer(std::string name, PlayerType type = PlayerType::AI) : Player(name){}

	
	
	std::vector<std::pair<int, int>> AI_take_coins_by_coordinates(Controller& controller) ;
	const Card& AI_reserve_card(Controller& controller);
	const Card& AI_buy_card(Controller& controller) ;
	std::pair<int, int> AI_take_one_coin_by_coordinates(Controller& controller) ;
	std::vector<std::pair<int, int>> AI_use_privileges(Controller& controller, int privileges) ;
	CoinColor AI_choose_bonus(Controller& controller);
	CoinColor AI_choose_color_to_steal(Controller& controller);
	int AI_number_of_privileges_to_use(Controller& controller);
	CompulsoryActions AI_choose_compulsory_action(Controller& Controller);
	OptionalActions AI_choose_optional_action(Controller& Controller) ;
	bool AI_optional_or_not(Controller& controller) ;
	void AI_increment_actions_done() ;

};
*/
