#include "gameView.h"



gameView::gameView(string player1Name, string player2Name, QWidget *parent)
    : QMainWindow(parent), currentPlayer(nullptr){

    setWindowTitle("Splendor Duel");

    mainWidget = new QWidget(this);
    gameVLayoutLeftUpper = new QVBoxLayout(this);
    gameVLayoutCenterUpper = new QVBoxLayout(this);
    gameVLayoutRightUpper = new QVBoxLayout(this);
    gameHLayoutLeftUpperButtons = new QHBoxLayout(this);
    //gameVLayoutLower = new QVBoxLayout(this);

    gameHLayoutUpper = new QHBoxLayout(this);
    gameHLayoutLower = new QHBoxLayout(this);
    gameMainLayout = new QVBoxLayout(this);

    //Sac à Jetons et plateau de Jetons
    Coinbag bag;
    bagView = new coinBagView(mainWidget);

    coinsBoard = new coinBoardView(mainWidget);
    coinsBoard->fillBoard(bag);
    coinSelectionButton = new coinSelectionButtonView(mainWidget);
    usePrivilegeButton = new usePrivilegeButtonView(mainWidget);
    cardReservationButtonCoinBoardPart = new cardReservationButtonCoinBoardPartView(mainWidget);

    connect(coinSelectionButton, SIGNAL(clicked(bool)), this, SLOT(checkCoinsSelection()));
    connect(bagView, SIGNAL(clicked(bool)), this, SLOT(fillCoinsBoard())); 
    connect(usePrivilegeButton, SIGNAL(clicked(bool)), this, SLOT(usePrivilege()));
    //ajouter connect pour cardReservationButtonCoinBoardPart

    gameHLayoutLeftUpperButtons->addWidget(coinSelectionButton);
    gameHLayoutLeftUpperButtons->addWidget(usePrivilegeButton);
    gameHLayoutLeftUpperButtons->addWidget(cardReservationButtonCoinBoardPart);
    cardReservationButtonCoinBoardPart->hide(); //on affichera uniquement le bouton quand nécessaire (automatique)
    gameVLayoutLeftUpper->addWidget(coinsBoard);
    gameVLayoutLeftUpper->addLayout(gameHLayoutLeftUpperButtons);
    gameVLayoutCenterUpper->addWidget(bagView);


    //Privilèges
    privilegeLabel = new privileges(mainWidget);
    privilegeLabel -> setStyleSheet("border: 3px solid black; border-radius: 10px;");
    gameVLayoutCenterUpper->addWidget(privilegeLabel);


    ///Zones cartes (à implémenter - Jules)




    ///

    //Joueurs
    //Player player1("Tareq"); //Simple test - remplacer les noms par ceux choisis - à passer en paramètre
    //Player player2("Jules"); // Le joueur 1 sera celui qui a été sélectionné pour démarrer
    player1 = new Player(player1Name);
    player2 = new Player(player2Name);

    currentPlayer = player1;
    //playerView tmpPlayerView1(&player1, mainWidget);
    player1View = new playerView(player1, mainWidget);
    player1View -> setStyleSheet("border: 3px solid black; border-radius: 10px;");
    //playerView tmpPlayerView2(&player2);
    player2View = new playerView(player2, mainWidget);
    player2View -> setStyleSheet("border: 3px solid black; border-radius: 10px;");

    gameHLayoutLower->addWidget(player1View);
    gameHLayoutLower->addWidget(player2View);

    //Mise en page
    gameHLayoutUpper->addLayout(gameVLayoutLeftUpper);
    gameHLayoutUpper->addLayout(gameVLayoutCenterUpper);
    gameHLayoutUpper->addLayout(gameVLayoutRightUpper);

    gameMainLayout -> addLayout(gameHLayoutUpper);
    gameMainLayout -> addLayout(gameHLayoutLower);

    mainWidget->setLayout(gameMainLayout);
    setCentralWidget(mainWidget);

    /*std::cout<<"\n";
    for (int i=0; i<25; i++){
        std::cout<<coinsBoard->getBoard()[i]->getCoin()->getColor();
    }*/
}

gameView::~gameView() {
    qDebug()<<"Destruction de l'interface jeu";
}



//Renvoie un vecteur contenant les jetons si sélection ok // renvoie un vecteur de nullptr sinon
//Rappel : on peut choisir 1, 2 ou 3 jetons et ces derniers doivent être adjacents et alignés
int gameView::checkCoinsSelection(){
    qDebug() << "bouton confirmation sélectionné";
    vector<coinButton*> selectedCoins(3, nullptr);
    int counter = 0;
    bool givePrivileges = false;

    for (int i=0; i<25; i++){
        if (coinsBoard->getBoard()[i]->isChecked()) counter++;
    }

    if (counter == 0){
        qDebug()<<"Aucun jeton sélectionné";
        return 0;
    }

    //modifier résultat test pour lever exception et afficher popup ? amélioration bonus
    if (counter > 3) {
        qDebug()<<"Trop de jetons ont été sélectionnés";
        for (int i=0; i<25; i++){
            coinsBoard->getBoard()[i]->setChecked(false);
        }
        return 0;
    }

    counter = 0;
    for (int i=0; i<25; i++){
        //if (coinsBoard->getBoard()[i]->isChecked()) selectedCoins.push_back(coinsBoard->getBoard()[i]);
        if (coinsBoard->getBoard()[i]->isChecked()) selectedCoins[counter++]=(coinsBoard->getBoard()[i]);
    }

    //vérification pas de jeton(s) or
    for (int i=0; i<counter; i++){
        if (selectedCoins[i]->getColor() == CoinColor::Gold){
            qDebug()<<"Au moins un jeton Or a été sélectionné";
            for (int j=0; j<25; j++){
                coinsBoard->getBoard()[j]->setChecked(false);
            }
            for (int j=0; j < counter; j++) selectedCoins[j] = nullptr;
            return 0;
        }
    }

    //on regarde si on peut récupérer les jetons en fonction de leurs coordonées
    if (counter > 1) {
        qDebug() << "on test alignés \n";
        bool alignedRow = true;
        bool alignedColumn = true;
        bool alignedDiag1 = true;
        bool alignedDiag2 = true;

        // Jetons alignés sur une même ligne ?
        for (int i = 0; i < counter - 1; i++) {
            if (selectedCoins[i]->getY() != selectedCoins[i+1]->getY()) {
                alignedRow = false;
            }
        }
        if(alignedRow){
            for (int i = 0; i < counter - 1; i++) {
                if (abs(selectedCoins[i]->getX() - selectedCoins[i+1]->getX()) != 1)
                    alignedRow = false;
            }
        }

        // Jetons alignés sur une même colonne ?
        for (int i = 0; i < counter - 1; i++) {
            if (selectedCoins[i]->getX() != selectedCoins[i+1]->getX()) {
                alignedColumn = false;
            }
        }
        if(alignedColumn){
            for (int i = 0; i < counter - 1; i++) {
                if (abs(selectedCoins[i]->getY() - selectedCoins[i+1]->getY()) != 1)
                    alignedColumn = false;
            }
        }

        // Jetons alignés en diagonale ?
        // Diagonale de gauche à droite et du haut vers le bas
        for (int i = 0; i < counter - 1; i++) {
            if (((selectedCoins[i]->getX() - selectedCoins[i+1]->getX()) != -1) || (selectedCoins[i]->getY() - selectedCoins[i+1]->getY()) != -1) {
                alignedDiag1 = false;
            }
        }
        // Diagonale de droite à gauche et du haut vers le bas
        for (int i = 0; i < counter - 1; i++) {
            if (((selectedCoins[i]->getX() - selectedCoins[i+1]->getX()) != 1) || (selectedCoins[i]->getY() - selectedCoins[i+1]->getY()) != -1) {
                alignedDiag2 = false;
            }
        }

        if (!alignedRow && !alignedColumn && !alignedDiag1 && !alignedDiag2) {
            qDebug() << "Les jetons ne sont pas alignés et/ou adjacents \n";
            for (int i=0; i<25; i++){
                coinsBoard->getBoard()[i]->setChecked(false);
            }
            for (int i=0; i < counter; i++) selectedCoins[i] = nullptr;
            return 0;
        }

        //VERIFICATION DEUX JETONS PERLES OU BIEN 3 JETONS MEME COULEUR
        if (counter==3){
            if ((selectedCoins[0]->getColor() == selectedCoins[1]->getColor())
                && (selectedCoins[2]->getColor() == selectedCoins[1]->getColor())){
                givePrivileges = true;
            }
        }

        if (not givePrivileges){
            int counterPearlCoins = 0;
            for (int i = 0; i<counter; i++){
                if (selectedCoins[i]->getColor() == CoinColor::Pearl) counterPearlCoins ++;
            }
            if (counterPearlCoins >= 2) givePrivileges = true;
        }

    }


    //on récupère les jetons choisis et on les remplace par des "jetons" vides
    qDebug() << "Les jetons sont renvoyés \n";
    for(int i=0; i<counter; i++){
        currentPlayer->addCoin(*(selectedCoins[i]->getCoin()));
        Coin c(CoinColor::Empty);
        selectedCoins[i]->changeColor(&c);
        coinsBoard->substractCoins(counter);
    }

    //Si le choix impose le don d'un privilège à l'adversaire, on le fait
    Player* receiverPlayer = nullptr;
    if (currentPlayer == player1) receiverPlayer = player2;
    else receiverPlayer = player1;

    if (givePrivileges){
        if (privilegeLabel->getCounter()>0){
            //Le joueur adverse prend un privilège du plateau
            receiverPlayer->incrementPrivileges();
            privilegeLabel->decrementCounter();
        }
        else if((privilegeLabel->getCounter()==0) && (currentPlayer->getPrivileges()>0)){
            currentPlayer->decrementPrivileges();
            receiverPlayer->incrementPrivileges();
        }
    }

    qDebug() << "Actualisation des données des joueurs \n";
    player1View -> updateView();
    player2View -> updateView();
    cout<<player2->getPrivileges();
    privilegeLabel ->updateCounter();

    return 1;
}


//retourne 1 s'il y a eu un remplissage / 0 si le plateau était déjà plein ou que la pioche était vide
int gameView::fillCoinsBoard(){
    if (coinsBoard->isFull() || bag.isEmpty()){
        qDebug() << "Action Impossible : Sac vide ou Plateau rempli \n";
        return 0;
    }
    coinsBoard->fillBoard(bag);
    qDebug() << "Remplissage du Plateau \n";
    return 1;
}


//prend un jeton NON or si présent sur le plateau et donne un privilège (si conditions le permettent)
int gameView::usePrivilege(){
    if (currentPlayer->getPrivileges() == 0){
        qDebug()<<"Le Joueur ne possède pas de privilèges !";
        for (int i=0; i<25; i++){
            coinsBoard->getBoard()[i]->setChecked(false);
        }
        return 0;
    }

    /*
    if (!(coinsBoard->containsAtLeastOne(CoinColor::Gold))){
        qDebug()<<"Aucun jeton OR sur le plateau !";
        return 0;
    }*/

    int counter = 0;
    coinButton* selectedCoin = nullptr;
    for (int i=0; i<coinsBoard->getBoardSize(); i++){
        if (coinsBoard->getBoard()[i]->isChecked()) {
            counter++;
            selectedCoin = coinsBoard->getBoard()[i];
        }
    }

    if (counter > 1 || counter==0){
        for (int i=0; i<25; i++){
            coinsBoard->getBoard()[i]->setChecked(false);
        }
        qDebug()<<"Vous devez choisir UN seul jeton !";
        return 0;
    }

    if (selectedCoin->getColor() == CoinColor::Gold){
        for (int i=0; i<25; i++){
            coinsBoard->getBoard()[i]->setChecked(false);
        }
        qDebug()<<"Vous ne pouvez pas choisir un jeton OR !";
        return 0;
    }

    currentPlayer->addCoin(*(selectedCoin->getCoin()));
    Coin c(CoinColor::Empty);
    selectedCoin->changeColor(&c);
    coinsBoard->substractCoins(counter);

    currentPlayer->decrementPrivileges();
    privilegeLabel->incrementCounter();
    privilegeLabel->updateCounter();
    player1View->updateView();
    player2View->updateView();

    return 1;
}


int gameView::cardReservationCoinBoardPart(){
    if (!(coinsBoard->containsAtLeastOne(CoinColor::Gold))){
        qDebug()<<"Réservation impossible : aucun jeton OR sur le plateau !";
        return 0;
    }

    cardReservationButtonCoinBoardPart->show();

    int counter = 0;
    coinButton* selectedCoin = nullptr;
    for (int i=0; i<coinsBoard->getBoardSize(); i++){
        if (coinsBoard->getBoard()[i]->isChecked()) {
            counter++;
            selectedCoin = coinsBoard->getBoard()[i];
        }
    }

    if (counter > 1 || counter==0){
        for (int i=0; i<25; i++){
            coinsBoard->getBoard()[i]->setChecked(false);
        }
        qDebug()<<"Vous devez choisir UN seul jeton !";
        cardReservationButtonCoinBoardPart->hide();
        return 0;
    }

    if (selectedCoin->getColor() != CoinColor::Gold){
        for (int i=0; i<25; i++){
            coinsBoard->getBoard()[i]->setChecked(false);
        }
        qDebug()<<"Vous devez choisir UN jeton OR !";
        cardReservationButtonCoinBoardPart->hide();
        return 0;
    }

    currentPlayer->addCoin(*(selectedCoin->getCoin()));
    Coin c(CoinColor::Empty);
    selectedCoin->changeColor(&c);
    coinsBoard->substractCoins(counter);
    player1View->updateView();
    player2View->updateView();


    cardReservationButtonCoinBoardPart->hide();
    return 1;
}




