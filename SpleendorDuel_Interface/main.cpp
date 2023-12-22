#include "gameView.h"
#include "menuView.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MenuWindow W;
    W.showMaximized();

    // std::string player1 = "Tareq";
    // std::string player2 = "Jules";
    // gameView w(player1, player2);
    // w.showMaximized();

    return a.exec();
}
