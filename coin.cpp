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
            return "White";
            break;
        default :
            return "Empty";
    }
}
std::ostream& operator<<(std::ostream& f, Coin coin) {
    f <<  toString(coin.getColor()) << "Coin";
    return f;}