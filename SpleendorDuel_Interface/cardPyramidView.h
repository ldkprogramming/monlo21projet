#ifndef CARDPYRAMIDVIEW_H
#define CARDPYRAMIDVIEW_H

#include "main/cardpyramid.h"

#include <QLayout>
#include <QLabel>
#include <QWidget>
#include <QObject>
#include <QPushButton>

using namespace std;



class cardButton : public QPushButton
{
    Q_OBJECT
private:
    int x_pos;
    int level;
    int id;
    Card* card;
public:
    // cardButton(Card& c, int x, int l, QWidget *parent = nullptr);
    cardButton(int id, QWidget* parent=nullptr, bool onPile=false);
    ~cardButton();

    Card* getCard() const {return card;}
};




class cardPyramidView: public QWidget
{
    Q_OBJECT
private:
    // CardPyramid* cards;

    QHBoxLayout* layout;
    QVBoxLayout* royal;
    QVBoxLayout* piles;
    QHBoxLayout* pile1;
    QHBoxLayout* pile2;
    QHBoxLayout* pile3;

    QVBoxLayout* rows;
    QHBoxLayout* level1;
    QHBoxLayout* level2;
    QHBoxLayout* level3;

    vector<cardButton*> cardButtons;
    cardButton* selectedCard;

public:
    cardPyramidView(QWidget *parent = nullptr);
    void addCard(const int& cId, bool onPile=false);
    void removeCard(const int& cId);

    cardButton* getSelectedCard() const {return selectedCard;}


private slots:
    void cardClicked(cardButton* c);
};




class buyCardButtonView : public QPushButton
{
    Q_OBJECT
public:
    buyCardButtonView(QWidget *parent = nullptr);
    ~buyCardButtonView(){qDebug()<<"Destruction Bouton";}

    void isUsable(){this->setCheckable(true);}
    void isUnusable(){this->setCheckable(false);}
};


class reserveCardButtonView : public QPushButton
{
    Q_OBJECT
public:
    reserveCardButtonView(QWidget *parent = nullptr);
    ~reserveCardButtonView(){qDebug()<<"Destruction Bouton";}

    void isUsable(){this->setCheckable(true);}
    void isUnusable(){this->setCheckable(false);}
};





#endif // CARDPYRAMIDVIEW_H
