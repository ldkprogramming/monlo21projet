
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

    std::cout <<test.getPyramid();

    return 0;
}
