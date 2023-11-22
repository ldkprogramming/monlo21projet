
#include <fstream>
#include "nlohmann/json.hpp"
#include <iostream>
#include "pile.h"
#include "game.h"
#include "controller.h"

using json = nlohmann::json;


int main() {
    Game game = Game("joueur1", "joueur2");
    Controller controller = Controller();

    return 0;
}
