//
// Created by Leo on 21/11/2023.
//

#ifndef MONLO21PROJET_COINBOARD_H
#define MONLO21PROJET_COINBOARD_H
#include <vector>

#include "coin.h"
#include "coinbag.h"

/*

*/
class Coinboard {

private:
    int numberOfCoins = 0;
    Coin board[5][5];

    friend std::ostream& operator<<(std::ostream& f, const Coinboard& coinboard);
    std::vector<std::pair<int, int>> orderOfFilling = {std::pair(2, 2), std::pair(3, 2),
                                                       std::pair(3, 1),std::pair(2, 1),
                                                       std::pair(1, 1),std::pair(1, 2),
                                                       std::pair(1, 3),std::pair(2, 3),
                                                       std::pair(3, 3),std::pair(4, 3),
                                                       std::pair(4, 2),std::pair(4, 1),
                                                       std::pair(4, 0),std::pair(3, 0),
                                                       std::pair(2, 0),std::pair(1, 0),
                                                       std::pair(0, 0),std::pair(0, 1),
                                                       std::pair(0, 2),std::pair(0, 3),
                                                       std::pair(0, 4),std::pair(1, 4),
                                                       std::pair(2, 4),std::pair(3, 4),
                                                       std::pair(4, 4)};


public:
    Coinboard(Coinbag& coinbag);
    void fill(Coinbag& coinbag);
    bool isEmpty() const;
    bool containsOnly(CoinColor color) const;
    bool containsAtLeastOne(CoinColor color) const;
    Coin getCoin(int x, int y) const {
        /*
         * ajouter les verifs de validite
         */
        return board[x][y];
    }
    void setCoin(int x, int y, CoinColor c){
        board[x][y] = Coin(c);
    }

};

std::ostream& operator<<(std::ostream& f, const Coinboard& coinboard);

#endif //MONLO21PROJET_COINBOARD_H
