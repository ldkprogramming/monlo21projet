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