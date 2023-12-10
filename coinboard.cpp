//
// Created by Leo on 21/11/2023.
//

#include "coinboard.h"
Coinboard::Coinboard(Coinbag &coinbag) {

    for (auto coordinates : orderOfFilling){
        board[coordinates.first][coordinates.second] = coinbag.distributeCoin();
    }
}

std::ostream& operator<<(std::ostream& f, const Coinboard& coinboard){
    for (int i = 0; i<5; i++){
        for (int j = 0; j<5; j++){
            f << coinboard.board[i][j] << " ";
        }
        f << '\n';
    }
    return f;
}

bool Coinboard::isEmpty() const {
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (board[i][j].getColor() != CoinColor::Empty){
                return false;
            }
        }
    }
    return true;
}

bool Coinboard::containsOnly(CoinColor color) const {
    // verifie si le plateau ne contient que des jetons Gold ou Empty
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if ((board[i][j].getColor() != CoinColor::Empty) && (board[i][j].getColor() != color)){
                return false;
            }
        }
    }
    return true;
}

bool Coinboard::containsAtLeastOne(CoinColor color) const {
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (board[i][j].getColor() == color){
                return true;
            }
        }
    }
    return false;
}

void Coinboard::fill(Coinbag &coinbag) {
    for (auto pair : orderOfFilling){
        if (!coinbag.isEmpty()){
            if (getCoin(pair.first, pair.second).getColor() == CoinColor::Empty){
                setCoin(pair.first, pair.second, coinbag.distributeCoin());
            }
        }
    }
}