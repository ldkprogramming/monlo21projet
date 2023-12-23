//
// Created by Leo on 04/12/2023.
//

#include "statsaver.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <ostream>
#include <string>

using json = nlohmann::json;

void StatSaver::saveGameStats(const Game &game) {
    std::ifstream f(path);
    json data = json::parse(f);

    if (!data["players"].contains(game.getPlayer1().getName())){
        std::cout << "nope\n";
        data["players"][game.getPlayer1().getName()] = {{"gamesWon", 0}, {"gamesLost", 0}};
    }
    if (!data["players"].contains(game.getPlayer2().getName())){
        std::cout << "nope\n";
        data["players"][game.getPlayer2().getName()] = {{"gamesWon", 0}, {"gamesLost", 0}};
    }


    // on est obblige d'utiliser une variable intermediaire, car l'operateur += est deja surcharge
    int temp1 = data["players"][game.getPlayer(game.getWinner()).getName()]["gamesWon"].template get<int>();
    temp1 += 1;
    data["players"][game.getPlayer(game.getWinner()).getName()]["gamesWon"] = temp1;

    int temp2 = data["players"][game.getPlayer(game.getLoser()).getName()]["gamesLost"].template get<int>();
    temp2 += 1;
    data["players"][game.getPlayer(game.getWinner()).getName()]["gamesLost"] = temp2;


    std::ofstream outputFile(path);
    outputFile << std::setw(4) << data <<std::endl;
    outputFile.close();
}

std::ostream& operator<<(std::ostream& f, const StatSaver& s)
{
    std::string path = s.getPath();
    std::ifstream i(path);
    json stats = json::parse(i);
    stats = stats["players"];

    for (auto it = stats.begin(); it != stats.end(); ++it)
    {
        f << "-------" << "\n";
        f << "Joueur: " << it.key() << '\n';
        for (auto jt = stats[it.key()].begin(); jt != stats[it.key()].end(); ++jt)
        {
            f << jt.key() << " : "<< jt.value() << std::endl;
        }
        f << "-------" << "\n\n";

    }
    return f;

}
