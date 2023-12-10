//
// Created by Leo on 22/11/2023.
//

#ifndef MONLO21PROJET_WINCONDITIONS_H
#define MONLO21PROJET_WINCONDITIONS_H


class WinConditions {
private:
    int totalPoints;
    int totalCrowns;
    int pointsInOneColor;
public:
    WinConditions(int totalPoints, int totalCrowns, int pointsInOneColor) : totalPoints(totalPoints), totalCrowns(totalCrowns), pointsInOneColor(pointsInOneColor){}
    WinConditions() = default;
    int getTotalPoints() const {
        return totalPoints;
    }

    int getTotalCrowns() const {
        return totalCrowns;
    }

    int getPointsInOneColor() const {
        return pointsInOneColor;
    }
};


#endif //MONLO21PROJET_WINCONDITIONS_H
