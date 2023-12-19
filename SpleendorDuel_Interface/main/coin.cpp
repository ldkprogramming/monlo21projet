//
// Created by Leo on 21/11/2023.
//

#include "coin.h"

//White, Blue, Black, Gold, Pearl, Red, Green

std::string toString(CoinColor c){
    switch (c){
        case CoinColor::White:
            return "White";
            break;

        case CoinColor::Blue:
            return "Blue";
            break;

        case CoinColor::Black:
            return "Black";
            break;

        case CoinColor::Gold :
            return "Gold";
            break;

        case CoinColor::Pearl :
            return "Pearl";
            break;

        case CoinColor::Red :
            return "Red";
            break;

        case CoinColor::Green:
            return "Green";
            break;
        default :
            return "Empty";
    }
}

CoinColor toCoinColor(std::string s){
    if (s == "White"){
        return CoinColor::White;
    }
    if (s == "Blue"){
        return CoinColor::Blue;
    }
    if (s == "Red"){
        return CoinColor::Red;
    }
    if (s == "Black"){
        return CoinColor::Black;
    }
    if (s == "Green"){
        return CoinColor::Green;
    }
    if (s == "Pearl"){
        return CoinColor::Pearl;
    }
    if (s == "Gold"){
        return CoinColor::Gold;
    }
    return CoinColor::Empty;
}
std::ostream& operator<<(std::ostream& f, Coin coin) {
    f <<  toString(coin.getColor()) << "Coin";
    return f;}