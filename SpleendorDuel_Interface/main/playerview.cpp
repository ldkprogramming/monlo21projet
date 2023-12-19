#include "playerview.h"

playerView::playerView(Player* player, QWidget *parent)
    : player(player), coinsPerColor(7,nullptr), bonusPerColor(7,nullptr), pointsPerColor(7,nullptr), QWidget(parent){
    setFixedSize(930,450);
    //mainWidgetPlayer = new QWidget(this);
    playerLayout = new QHBoxLayout(this);

    inventoryLayout = new QVBoxLayout(this);
    cardsLayout = new QVBoxLayout(this);

    coinsLayout = new QHBoxLayout(this);
    bonusLayout = new QHBoxLayout(this);
    pointsLayout = new QHBoxLayout(this);
    CrownsPrivilegesLayout = new QHBoxLayout(this);
    //CrownsPrivilegesData = new QHBoxLayout(this);



    // Label nom du joueur
    QString qstr = QString::fromStdString(player->getName());
    playerName = new QLabel(this);
    playerName -> setText(qstr);



    //Label Jetons du joueur
    coinsLabel = new QLabel(this);
    qstr = "Jetons par Couleur : ";
    coinsLabel -> setText(qstr);
    coinsLabel -> setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    //Data Jetons du Joueur
    for (int i = 0; i<7; i++){
        coinsPerColor[i] = new QLabel(this);
        CoinColor tmpColor = colors[i];
        int tmpNumber = 0;
        //int tmpNumber = player->getBonusesPerColor().find(tmpColor)->second
        string tmpNumberStr = to_string(tmpNumber);
        string tmpColorStr = toString(player->getCoinsPerColor().find(tmpColor)->first);
        string tmpStr = tmpColorStr + " x" + tmpNumberStr;
        qstr =  QString::fromStdString(tmpStr);
        coinsPerColor[i] -> setText(qstr);

        coinsLayout->addWidget(coinsPerColor[i]);
    }



    //Label Bonus du Joueur
    bonusLabel = new QLabel(this);
    qstr = "Bonus par Couleur : ";
    bonusLabel -> setText(qstr);
    bonusLabel -> setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    //Data Bonus du Joueur
    for (int i = 0; i<7; i++){
        bonusPerColor[i] = new QLabel(this);
        CoinColor tmpColor = colors[i];
        int tmpNumber = 0;
        //int tmpNumber = player->getBonusesPerColor().find(tmpColor)->second
        string tmpNumberStr = to_string(tmpNumber);
        string tmpColorStr = toString(player->getBonusesPerColor().find(tmpColor)->first);
        string tmpStr = tmpColorStr + " x" + tmpNumberStr;
        qstr =  QString::fromStdString(tmpStr);
        bonusPerColor[i] -> setText(qstr);

        bonusLayout->addWidget(bonusPerColor[i]);
    }



    //Label Points du Joueur
    pointsLabel = new QLabel(this);
    qstr = "Points par Couleur : ";
    pointsLabel -> setText(qstr);
    pointsLabel -> setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    //Data Bonus du Joueur
    for (int i = 0; i<7; i++){
        pointsPerColor[i] = new QLabel(this);
        CoinColor tmpColor = colors[i];
        int tmpNumber = 0;
        //int tmpNumber = player->getBonusesPerColor().find(tmpColor)->second
        string tmpNumberStr = to_string(tmpNumber);
        string tmpColorStr = toString(player->getPointsPerColor().find(tmpColor)->first);
        string tmpStr = tmpColorStr + " x" + tmpNumberStr;
        qstr =  QString::fromStdString(tmpStr);
        pointsPerColor[i] -> setText(qstr);

        pointsLayout->addWidget(pointsPerColor[i]);
    }



    //Label Couronnes du Joueur
    crownLabel = new QLabel(this);
    qstr = "Couronnes du Joueur : ";
    crownLabel -> setText(qstr);
    crownLabel -> setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    //Data Couronnes du Joueur
    numberOfCrowns = new QLabel(this);
    string tmpStr = "x" + to_string(player->getTotalCrowns());
    numberOfCrowns -> setText(QString::fromStdString(tmpStr));
    numberOfCrowns -> setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);



    //Label Privilèges du JoueurS
    privilegeLabel = new QLabel(this);
    qstr = "Privilèges du Joueur : ";
    privilegeLabel -> setText(qstr);
    privilegeLabel -> setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    //Data Privilèges du Joueur
    numberOfPrivileges = new QLabel(this);
    tmpStr = "x" + to_string(player->getPrivileges());
    //tmpStr = "x" + tmpStr;
    numberOfPrivileges -> setText(QString::fromStdString(tmpStr));
    numberOfPrivileges -> setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);



    //Label total de points
    totalNumberOfPointsLabel = new QLabel(this);
    qstr = "Points au total : ";
    totalNumberOfPointsLabel -> setText(qstr);
    totalNumberOfPointsLabel -> setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    //Data nombre total de points
    totalNumberOfPoints = new QLabel(this);
    tmpStr = "x" + to_string(player->getTotalPoints());
    totalNumberOfPoints -> setText(QString::fromStdString(tmpStr));
    totalNumberOfPoints -> setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);



    //Label Cartes du Joueur
    CardLabel = new QLabel(this);
    qstr = "Cartes Réservées du Joueur : ";
    CardLabel -> setText(qstr);
    CardLabel -> setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    //Partie inventaire
    inventoryLayout->addWidget(playerName);
    inventoryLayout->addWidget(coinsLabel);
    inventoryLayout->addLayout(coinsLayout);
    inventoryLayout->addWidget(bonusLabel);
    inventoryLayout->addLayout(bonusLayout);
    inventoryLayout->addWidget(pointsLabel);
    inventoryLayout->addLayout(pointsLayout);

    CrownsPrivilegesLayout->addWidget(crownLabel);
    CrownsPrivilegesLayout->addWidget(numberOfCrowns);
    CrownsPrivilegesLayout->addWidget(privilegeLabel);
    CrownsPrivilegesLayout->addWidget(numberOfPrivileges);
    CrownsPrivilegesLayout->addWidget(totalNumberOfPointsLabel);
    CrownsPrivilegesLayout->addWidget(totalNumberOfPoints);
    inventoryLayout->addLayout(CrownsPrivilegesLayout);

    //inventoryLayout->addLayout(CrownsPrivilegesLabels);

    //Partie Cartes Réservées
    cardsLayout->addWidget(CardLabel);

    //Ajout dans le Layout Principal
    playerLayout->addLayout(inventoryLayout);
    playerLayout->addLayout(cardsLayout);
    this->setLayout(playerLayout);


    //mainWidgetPlayer->setLayout(playerLayout);

    //setCentralWidget(mainWidgetPlayer);
}


void playerView::updateView(){
    //update jetons par couleur
    for (int i = 0; i<7; i++){
        QLabel* currentLabel = coinsPerColor[i];
        CoinColor tmpColor = colors[i];
        int tmpNumber = player->getCoinsPerColor().find(tmpColor)->second;

        string tmpNumberStr = to_string(tmpNumber);
        //string tmpColorStr = toString(player->getCoinsPerColor().find(tmpColor)->first);
        string tmpColorStr = toString(tmpColor);
        string tmpStr = tmpColorStr + " x" + tmpNumberStr;
        QString qstr =  QString::fromStdString(tmpStr);
        currentLabel -> setText(qstr);
    }

    //update bonus par couleur
    for (int i = 0; i<7; i++){
        QLabel* currentLabel = bonusPerColor[i];
        CoinColor tmpColor = colors[i];
        int tmpNumber = player->getBonusesPerColor().find(tmpColor)->second;

        string tmpNumberStr = to_string(tmpNumber);
        string tmpColorStr = toString(tmpColor);
        string tmpStr = tmpColorStr + " x" + tmpNumberStr;
        QString qstr =  QString::fromStdString(tmpStr);
        currentLabel -> setText(qstr);
    }

    //update points par couleur
    for (int i = 0; i<7; i++){
        QLabel* currentLabel = pointsPerColor[i];
        CoinColor tmpColor = colors[i];
        int tmpNumber = player->getPointsPerColor().find(tmpColor)->second;

        string tmpNumberStr = to_string(tmpNumber);
        string tmpColorStr = toString(tmpColor);
        string tmpStr = tmpColorStr + " x" + tmpNumberStr;
        QString qstr =  QString::fromStdString(tmpStr);
        currentLabel -> setText(qstr);
    }

    //update couronnes
    string tmpStr = "x" + to_string(player->getTotalCrowns());
    numberOfCrowns -> setText(QString::fromStdString(tmpStr));

    //update privilèges
    tmpStr = "x" + to_string(player->getPrivileges());
    numberOfPrivileges -> setText(QString::fromStdString(tmpStr));
}

