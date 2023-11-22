
#include <fstream>
#include "nlohmann/json.hpp"
#include <iostream>
#include "pile.h"
using json = nlohmann::json;


int main() {
    Pile test = Pile(PileType::One);
    std::cout << test;

    return 0;
}
