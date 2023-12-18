#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "coinBagView.h"
#include "privilegesView.h"
#include "coinBoardView.h"
#include "main/playerView.h"
#include "main/player.h"
#include "useprivilegebuttonView.h"

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

    //Joueurs
    playerView* player1View;
    playerView* player2View;
    Player* player1;
    Player* player2;
    Player* currentPlayer;

    //Boutons
    coinSelectionButtonView* coinSelectionButton;
    usePrivilegeButtonView* usePrivilegeButton;
    cardReservationButtonCoinBoardPartView* cardReservationButtonCoinBoardPart;

private slots:
    int checkCoinsSelection();
    int fillCoinsBoard();
    int usePrivilege();

    //Méthode ci-dessous à connecter avec Travail de Jules pour réservation de carte
    int cardReservationCoinBoardPart();

public:
    gameView(string player1Name, string player2Name, QWidget *parent = nullptr);
    ~gameView();

};
#endif // GAMEVIEW_H
