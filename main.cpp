
#include <fstream>
#include "nlohmann/json.hpp"
#include <iostream>
#include "pile.h"
#include "game.h"
#include "controller.h"
#include "gamesaver.h"
#include "statsaver.h"


using json = nlohmann::json;


int main() {
    Game test("ha","hoe");

    std::cout << test.getCoinBoard();
    std::vector<std::pair<int, int>> c = {{1, 2}, {2,3}, {3, 3}};

    test.playerUsePrivileges(3, c);
    std::cout << test.getCoinBoard();

    return 0;
}
