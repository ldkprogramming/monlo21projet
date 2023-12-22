#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "coinBagView.h"
#include "privilegesView.h"
#include "coinBoardView.h"
#include "main/playerView.h"
#include "main/player.h"
#include "useprivilegebuttonView.h"
#include "cardPyramidView.h"

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



class gameView : public QMainWindow
{

    Q_OBJECT

private:
    //Layout
    QVBoxLayout* gameVLayoutLeftUpper;
    QVBoxLayout* gameVLayoutCenterUpper;
    QVBoxLayout* gameVLayoutRightUpper;

    QHBoxLayout* gameHLayoutLeftUpperButtons;
    QHBoxLayout* gameHLayoutRightUpperButtons;
    //QVBoxLayout* gameVLayoutLower;

    QHBoxLayout* gameHLayoutUpper;
    QHBoxLayout* gameHLayoutLower;

    QVBoxLayout* gameMainLayout;
    QWidget* mainWidget;

    //Objets
    Coinbag bag;
    coinBagView* bagView;
    privileges* privilegeLabel;
    coinBoardView* coinsBoard;
    cardPyramidView* cardPyramid;

    //Joueurs
    playerView* player1View;
    playerView* player2View;
    Player* player1;
    Player* player2;
    Player* currentPlayer;

    //Boutons Jetons
    coinSelectionButtonView* coinSelectionButton;
    usePrivilegeButtonView* usePrivilegeButton;
    cardReservationButtonCoinBoardPartView* cardReservationButtonCoinBoardPart;

    //Boutons Pyramide
    buyCardButtonView* buyCardButton;
    reserveCardButtonView* reserveCardButton;

private slots:
    int checkCoinsSelection();
    int fillCoinsBoard();
    int usePrivilege();

    int checkBuyCard();

    //Méthode ci-dessous à connecter avec Travail de Jules pour réservation de carte
    int cardReservationCoinBoardPart();

public:
    gameView(string player1Name, string player2Name, QWidget *parent = nullptr);
    ~gameView();

};
#endif // GAMEVIEW_H
