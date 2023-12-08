
#include <fstream>
#include "nlohmann/json.hpp"
#include <iostream>
#include "pile.h"
#include "game.h"
#include "controller.h"
#include "gamesaver.h"


using json = nlohmann::json;


int main() {
    Game test("ha","hoe");
    GameSaver gs;
    gs.saveGame(test);
    std::cout << test.getPyramid();
    return 0;
}
