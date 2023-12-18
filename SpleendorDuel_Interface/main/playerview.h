#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include "player.h"

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QLCDNumber>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMessageBox>
#include <QWidget>
#include <QPushButton>
#include <QObject>

using namespace std;

class playerView : public QWidget
{
    Q_OBJECT
private:
    Player* player;

    //QWidget* mainWidgetPlayer;
    QHBoxLayout* playerLayout; //setLayout(playerLayout)

    QVBoxLayout* inventoryLayout;
    QVBoxLayout* cardsLayout;

    QHBoxLayout* coinsLayout;
    QHBoxLayout* bonusLayout;
    QHBoxLayout* pointsLayout;
    QHBoxLayout* CrownsPrivilegesLayout;

    QLabel* playerName;
    QLabel* coinsLabel;
    QLabel* bonusLabel;
    QLabel* pointsLabel;
    QLabel* crownLabel;
    QLabel* privilegeLabel;
    QLabel* CardLabel;
    QLabel* totalNumberOfPointsLabel;

    //Données
    vector<QLabel*> coinsPerColor;
    vector<QLabel*> bonusPerColor;
    vector<QLabel*> pointsPerColor;
    QLabel* numberOfCrowns;
    QLabel* numberOfPrivileges;
    QLabel* totalNumberOfPoints;

    CoinColor colors[7] = {CoinColor::White, CoinColor::Red, CoinColor::Green, CoinColor::Blue,
                           CoinColor::Black, CoinColor::Pearl, CoinColor::Gold};

    //Pour Jules : Zones pour cartes à ajouter dans le QVBoxLayout cardsLayout

public:
    playerView(Player* player, QWidget *parent = nullptr);
    ~playerView(){
        qDebug()<<"Destruction d'une zone joueur";
    }
    playerView(const playerView&) = delete;
    void updateView();
};



#endif // PLAYERVIEW_H
