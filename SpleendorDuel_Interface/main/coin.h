#ifndef COIN_H
#define COIN_H

#include <iostream>
#include <string>

enum class CoinColor {
    White, Blue, Black, Gold, Pearl, Red, Green, Empty
};

std::string toString(CoinColor c);
CoinColor toCoinColor(std::string s);

class Coin {
private:
    CoinColor color;
public:
    Coin(CoinColor color) : color(color) {}
    Coin() : color(CoinColor::Empty) {} //par defaut
    inline CoinColor getColor() const { return color;}
};

std::ostream& operator<<(std::ostream& f, Coin coin);

#endif
