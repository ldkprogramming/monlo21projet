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
    cardButton(Card& c, int x, int l, QWidget *parent = nullptr);
    cardButton(int id, QWidget* parent=nullptr);
    ~cardButton();

    //à faire
    inline const int getX() const {return x_pos;}
    inline const int getLevel() const {return level;}
    inline Card* getCard() {return card;}
};





class cardPyramidView: public QWidget
{
    Q_OBJECT
private:
    // CardPyramid* cards;

    QHBoxLayout* layout;
    QVBoxLayout* royal;

    QVBoxLayout* rows;
    QHBoxLayout* level1;
    QHBoxLayout* level2;
    QHBoxLayout* level3;

    vector<Card> level1Cards;

    vector<QLabel*> labelsLevel1;
    vector<QLabel*> labelsLevel2;
    vector<QLabel*> labelsLevel3;

public:
    cardPyramidView(QWidget *parent = nullptr);
    void addCard(const int& cId);
};






#endif // CARDPYRAMIDVIEW_H
