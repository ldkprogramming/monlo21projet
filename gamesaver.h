//
// Created by Leo on 02/12/2023.
//

#ifndef MONLO21PROJET_GAMESAVER_H
#define MONLO21PROJET_GAMESAVER_H

#include <string>
#include "game.h"

class GameSaver {
private:
    // On pourra modifier en std::filesystem::path si on a le temps
    std::string path;
public:
    std::string getSavePath(){ return path; }
    GameSaver(std::string path = "../jsonFiles/ongoingGame.json") : path(path) {}
    bool saveGame(const Game& game) const;
};


#endif //MONLO21PROJET_GAMESAVER_H
