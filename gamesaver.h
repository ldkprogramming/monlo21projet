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
    // ou bien
    /*
     * There are also third party libraries that can be used to get this information, such as whereami as mentioned in prideout's answer, or if you are using Qt, QCoreApplication::applicationFilePath() as mentioned in the comments.
     *
     */
    std::string path;
public:
    std::string getSavePath(){ return path; }
    GameSaver(std::string path = "../jsonFiles/ongoingGame.json") : path(path) {}
    bool saveGame(const Game& game) const;

    // peut-etre ajouter une verification de la validite d'une sauvegarde ?
};


#endif //MONLO21PROJET_GAMESAVER_H
