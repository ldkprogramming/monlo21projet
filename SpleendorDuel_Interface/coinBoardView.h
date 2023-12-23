#ifndef COINBOARDVIEW_H
#define COINBOARDVIEW_H

#include <QObject>
#include <QVBoxLayout>
#include <QPushButton>
#include <QPen>
#include <QBrush>
#include "main/coin.h"
#include "main/coinbag.h"


using namespace std;


class coinButton : public QPushButton
{
    Q_OBJECT
private:
    CoinColor color;
    int x_pos;
    int y_pos;
    Coin* coin;

    //QColor fillColor;
    //QBrush brush;
protected:
    //void paintEvent(QPaintEvent *event) override;
public:
    coinButton(CoinColor color, int x, int y, QWidget *parent = nullptr);
    ~coinButton();

    //à faire
    Coin* changeColor(Coin* coin); //QPaintEvent ???
    inline const int getX() const {return x_pos;}
    inline const int getY() const {return y_pos;}
    inline const CoinColor getColor() const {return color;}
    inline Coin* getCoin() {return coin;}
};


class coinBoardView : public QWidget
{
    Q_OBJECT
private:
    QGridLayout* board;
    vector<coinButton*> coins;
    int boardSize;
    int* indexSequence;
    int numberOfCoins;
public:
    coinBoardView(QWidget *parent = nullptr);
    ~coinBoardView();

    //à faire
    //Getters
    //bool containsOnly(CoinColor color) const;

    bool containsAtLeastOne(CoinColor color) const;
    void fillBoard(Coinbag& coinbag);
    bool isEmpty(){return numberOfCoins==0;}
    bool isFull(){return numberOfCoins==25;}
    void substractCoins(int n){numberOfCoins -= n;}

    vector<coinButton*> getBoard(){return coins;}
    int getBoardSize(){return boardSize;}
    //  /!!!\ décrémenter numberOfCoins quand on retirera un jeton
};


class coinSelectionButtonView : public QPushButton
{
    Q_OBJECT
public:
    coinSelectionButtonView(QWidget *parent = nullptr);
    ~coinSelectionButtonView(){qDebug()<<"Destruction Bouton";}

    void isUsable(){this->setCheckable(true);}
    void isUnusable(){this->setCheckable(false);}
};


class cardReservationButtonCoinBoardPartView : public QPushButton
{
    Q_OBJECT
public:
    cardReservationButtonCoinBoardPartView(QWidget *parent = nullptr);
    ~cardReservationButtonCoinBoardPartView(){qDebug()<<"Destruction Bouton";}

    void isUsable(){this->setCheckable(true);}
    void isUnusable(){this->setCheckable(false);}
};


class takeCoinCapacityButtonView : public QPushButton
{
    Q_OBJECT
public:
    takeCoinCapacityButtonView(QWidget *parent = nullptr);
    ~takeCoinCapacityButtonView(){qDebug()<<"Destruction Bouton";}

    void isUsable(){this->setCheckable(true);}
    void isUnusable(){this->setCheckable(false);}
};



// Faire tout ce qui a un rapport avec la sélection des jetons
#endif // COINBOARDVIEW_H
