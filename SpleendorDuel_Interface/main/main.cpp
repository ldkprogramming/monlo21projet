
#include <fstream>
#include "nlohmann/json.hpp"
#include <iostream>
#include "pile.h"
#include "game.h"
#include "controller.h"
#include "gamesaver.h"
#include "statsaver.h"
#include "coinboard.h"


using json = nlohmann::json;


int main() {

    GameSaver gs;
    Game test(gs.getPath());
    std::cout << test.getCoinBag();
    std::cout << test.getCoinBoard();
    std::cout << test.getPile1();
    std::cout << test.getPyramid();
    return 0;
}
