//
// Created by Leo on 04/12/2023.
//

#ifndef MONLO21PROJET_STATSAVER_H
#define MONLO21PROJET_STATSAVER_H

#include <string>
#include "game.h"

class StatSaver {
    // Cette classe a pour objectif de sauvegarder les statistiques
    // des differents joueurs dans un fichier json predefini
    // Ainsi, on sauvegardera le nombre de parties gagnees,
    // les informations de chaque partie, etc.

    std::string path;

public:
    StatSaver(std::string path = "../jsonFiles/stats.json") : path(path){}
    void saveGameStats(const Game& game);
    std::string getPath() const { return path; }
};

std::ostream& operator<<(std::ostream f, StatSaver s);


#endif //MONLO21PROT_STATSAVER_H
