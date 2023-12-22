#include "menuView.h"
#include "gameView.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include <QString>
#include <QJsonDocument>
#include <QLabel>
#include <QDir>
#include <QPushButton>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHBoxLayout>
#include <QImage>
#include <QApplication>

QList<QStringList> readScoresJson(QString& path)
{
    QString val;
    // QDir::setCurrent(qApp->applicationDirPath());

    qDebug() << QDir::currentPath();

    QFile file(path);
    // file.setFileName(path);
    file.open(QIODevice::ReadOnly  | QIODevice::Text);
    val = file.readAll();
    file.close();
    qWarning() << val;
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject sett2 = d.object();
    QJsonValue value = sett2.value(QString("players"));
    qWarning() << value;

    QJsonObject players = value.toObject(); // Contenu de "players": Dictionnaire
    qWarning() << "Contenu de \"players\": " << players;

    QList<QStringList> scoresList; // [ ["player1", gamesWon(int), gamesLost(int)], ["player2", gamesWon(int), gamesLost(int)], ... ]

    size_t nb_players = players.length();
    QStringList keys = players.keys(); // Listes des clés (String) de players
    for (size_t i=0; i<nb_players; i++){
        QString player_name = keys[i]; // String
        QJsonValue player_infos = players[player_name]; // Dictionnaire
        QString gamesWon = QString::number(player_infos["gamesWon"].toInt()); // int stocke sous forme de QString
        QString gamesLost = QString::number(player_infos["gamesLost"].toInt()); // int stocke sous forme de QString
        qWarning() << " Player name:" << player_name << " | Games Won: " << gamesWon << " | Games Lost: " << gamesLost;

        QStringList player_i;
        player_i.append(player_name);
        player_i.append(gamesWon);
        player_i.append(gamesLost);
        scoresList.append(player_i); // On ajoute ["playeri", gamesWon(int), gamesLost(int)]
    }

    return scoresList;
}



MenuWindow::MenuWindow(QWidget *parent): QMainWindow(parent) {
    // this->centralWidget()->setStyleSheet("background-image:url(../SpleendorDuel_Interface/images/background.png); background-position: center;" );

    // Layouts
    mainWidget = new QWidget(this);

    layoutGlobal = new QHBoxLayout(this);
    layoutButtons = new QVBoxLayout(this);
    layoutScores = new QHBoxLayout(this);

    layoutGlobal->addLayout(layoutButtons);
    layoutGlobal->addLayout(layoutScores);

    mainWidget->setLayout(layoutGlobal);
    setCentralWidget(mainWidget);

    // Boutons
    buttonContinue = new QPushButton("Continuer", this);
    buttonNewGame = new QPushButton("Nouvelle Partie", this);
    buttonQuit = new QPushButton("Quitter", this);

    layoutButtons->addWidget(buttonContinue);
    layoutButtons->addWidget(buttonNewGame);
    layoutButtons->addWidget(buttonQuit);

    connect(buttonQuit, SIGNAL(clicked(bool)), this, SLOT(on_pushButtonQuitter_clicked()));
    connect(buttonContinue, SIGNAL(clicked(bool)), this, SLOT(on_pushButtonContinuer_clicked()));
    connect(buttonNewGame, SIGNAL(clicked(bool)), this, SLOT(on_pushButtonNouvellePartie_clicked()));

    const QSize BUTTON_SIZE = QSize(150,50);
    buttonQuit->setMinimumSize(BUTTON_SIZE);
    buttonQuit->setMaximumSize(BUTTON_SIZE);
    buttonContinue->setMinimumSize(BUTTON_SIZE);
    buttonContinue->setMaximumSize(BUTTON_SIZE);
    buttonNewGame->setMinimumSize(BUTTON_SIZE);
    buttonNewGame->setMaximumSize(BUTTON_SIZE);



    // Tableau des scores
    tableScores = new QTableWidget(0,3,this); // 1 ligne, 3 colonnes, parent=this
    layoutScores->addWidget(tableScores);

    const QSize TABLE_SCORES_SIZE = QSize(350,590);
    tableScores->setMinimumSize(TABLE_SCORES_SIZE);
    tableScores->setMaximumSize(TABLE_SCORES_SIZE);

    // QRect rect(352,399,350,590); // CHANGER LA TAILLE ET LA POSITION DU RECT!!!!!
    // layoutScores->setGeometry(rect);

    QString path = "../SpleendorDuel_Interface/main/jsonFiles/stats.json";
    QList<QStringList> list = readScoresJson(path);

    size_t nb_players = list.length();

    tableScores->setRowCount(nb_players);

    for (size_t i=0; i<nb_players; i++){
        size_t nb_columns = list[0].length();
        for (size_t j=0; j<nb_columns; j++){
            QLabel* text_ij = new QLabel(list[i][j]);
            tableScores->setCellWidget(i,j,text_ij);
        }
    }

    tableScores->show();

    // PROBLEME AU NIVEAU DES PATHS!!!!!
    // QLabel label("<img src='../SpleendorDuel_Interface/images/title.png' />", this);
    // label.show();


}

MenuWindow::~MenuWindow() {
    qDebug() << "Destruction de MenuWindow";
}



// ----Connections aux boutons----

//Continuer
void MenuWindow::on_pushButtonContinuer_clicked() {
    std::string player1 = "Tareq";
    std::string player2 = "Jules";
    gameView* w = new gameView(player1, player2);
    w->showMaximized();

    delete this;
}

//Nouvelle Partie
void MenuWindow::on_pushButtonNouvellePartie_clicked() {
    std::string player1 = "Tareq";
    std::string player2 = "Jules";
    gameView* w = new gameView(player1, player2);
    w->showMaximized();

    delete this;
}




//Quitter
void MenuWindow::on_pushButtonQuitter_clicked() {
    QApplication::exit();
}

