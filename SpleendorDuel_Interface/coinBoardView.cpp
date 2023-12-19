#include "coinBoardView.h"
#include <QPainter>
#include <QString>
#include <QStaticText>

using namespace std;



//Jeton
coinButton::coinButton(CoinColor color, int x, int y, QWidget *parent)
    : QPushButton(parent),  x_pos(x), y_pos(y), coin(nullptr), color(color){

    qDebug()<<"création jetons";
    //setText("Jeton");
    //à adapter
    //setFixedSize(70,70);
    //setBackgroundRole(QPalette::Base);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    setCheckable(false); //bouton pas appuyable au début - pas de couleur
}

coinButton::~coinButton(){
    qDebug()<< "Destruction Jeton\n";
}


//en modifier en PaintEvent ??? pour qu'il se comporte seul comme un grand ?
Coin* coinButton::changeColor(Coin* new_coin){
    qDebug() << "ok \n";
    Coin* old_coin = new Coin;
    //old_coin = coin;
    CoinColor new_color = new_coin->getColor();
    coin = new_coin;

    switch(new_color){
    case CoinColor::White:
        //fillColor = QColor("white");
        this->setStyleSheet("background-color: white;");
        break;
    case CoinColor::Blue:
        //fillColor = QColor("blue");
        this->setStyleSheet("background-color: blue;");
        break;
    case CoinColor::Black:
        //fillColor = QColor("black");
        this->setStyleSheet("background-color: black;");
        break;
    case CoinColor::Gold:
        //fillColor = QColor("yellow");
        this->setStyleSheet("background-color: yellow;");
        break;
    case CoinColor::Pearl:
        //fillColor = QColor("beige");
        this->setStyleSheet("background-color: beige;");
        break;
    case CoinColor::Red:
        //fillColor = QColor("red");
        this->setStyleSheet("background-color: red;");
        break;
    case CoinColor::Green:
        //fillColor = QColor("green");
        this->setStyleSheet("background-color: green;");
        break;
    case CoinColor::Empty:
        //fillColor = QColor("purple");
        this->hide();
        break;

    }
    color = new_color;
    if(color != CoinColor::Empty){
        setCheckable(true);
        this->show();
    }
    else {
        setCheckable(false);
        //numberOfCoins--; à mettre dans la fonction qui appelle pour prendre un jeton
    }

    //QPainter painter(this);
    //brush.setStyle(Qt::SolidPattern);
    //painter.setBrush(brush);

    return old_coin;

}






//Plateau de Jetons
coinBoardView::coinBoardView(QWidget *parent)
    : QWidget(parent), coins(25,nullptr), indexSequence(new int[25]),numberOfCoins(0), boardSize(25){

    int indexSeq[25] = {12, 11, 6, 7, 8, 13, 18, 17,
                             16, 15, 10, 5, 0, 1, 2, 3, 4,
                             9, 14, 19, 24, 23, 22, 21, 20};
    for (int ind=0; ind<25; ind++) indexSequence[ind] = indexSeq[ind];
    setFixedSize(350,350);
    board = new QGridLayout;
    for (int i=0; i<25; i++){
        coins[i] = new coinButton(CoinColor::Empty, i%5, i/5, this);//i/5, i%5
        board->addWidget(coins[i], i/5, i%5);
    }
    setLayout(board);
}

coinBoardView::~coinBoardView(){
    qDebug()<< "Destruction Plateau de Jetons\n";
}

// Remplit le plateau de jeton
void coinBoardView::fillBoard(Coinbag& coinbag){
    qDebug()<< "Remplissage du plateau de jetons\n";
    //int numberOfMissingCoins = boardSize - numberOfCoins;
    for(int i=0; i<25; i++){
        // si jetons est couleur empty alors ajouter nouveau jeton et changer couleur
        int indice = indexSequence[i];
        if (coins[indice]->getColor()==CoinColor::Empty){
            //Coin new_coin = coinbag.distributeCoin();
            //coins[indice]->changeColor(&new_coin);
            //coins[indice]->changeColor(coinbag.distributeCoin());

            coins[indice]->changeColor(coinbag.distributeCoinPointer());
        }
        coins[indice]->setChecked(false);
    }
    numberOfCoins = 25;
}

bool coinBoardView::containsAtLeastOne(CoinColor color) const{
    for(int i=0; i<25; i++){
        if (coins[i]->getColor()==color) return true;
    }
    return false;
}








//Bouton de confirmation de la sélection de jetons
coinSelectionButtonView::coinSelectionButtonView(QWidget *parent){
    setText("Confirmer Sélection de Jetons");
    setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
}


//Bouton de confirmation de la sélection de jeton pour la réservation de carte
cardReservationButtonCoinBoardPartView::cardReservationButtonCoinBoardPartView(QWidget *parent){
    setText("Confirmer Réservation");
    setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
}











