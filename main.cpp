
#include <fstream>
#include "nlohmann/json.hpp"
#include <iostream>
#include "pile.h"
#include "game.h"
#include "controller.h"


using json = nlohmann::json;


int main() {

    Game test = Game("haha", "hehe");
    Controller co = Controller();

    std::cout << test.getCoinBoard();
    co.applyCompulsoryAction(test, test.getPlayer1(), CompulsoryActions::TakeCoins);
    std::cout << test.getCoinBoard();
    std::cout << test.getPlayer1();

    return 0;
}
