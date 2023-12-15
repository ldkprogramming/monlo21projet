//
// Created by Leo on 22/11/2023.
//

#ifndef MONLO21PROJET_CONTROLLER_H
#define MONLO21PROJET_CONTROLLER_H
#include "game.h"
#include "player.h"
#include "gamesaver.h"
#include "GameMoveVerification.h"

class Controller {
private: 
	friend class Game;
	friend class GameMoveVerification;
	GameMoveVerification& checker;
	const Game& GameControlled;


public:
	Controller(GameMoveVerification& checker, const Game& GameControlled);
	Controller(const Controller&) = delete;
	Controller& operator=(const Controller&) = delete;

	inline GameMoveVerification& get_checker() const { return checker; }
	inline const Game&  get_GameControlled() const { return GameControlled; }

	bool launch_save(GameSaver& save);
	bool reset_game();

	void play_game();
	void change_turn();
	bool verify_win(Player& player);


};


#endif //MONLO21PROJET_CONTROLLER_H
