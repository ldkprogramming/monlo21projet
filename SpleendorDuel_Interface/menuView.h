#ifndef MENUVIEW_H
#define MENUVIEW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QBoxLayout>
#include <QPushButton>
#include "gameView.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MenuWindow;
}
QT_END_NAMESPACE

class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();

private slots:
    void on_pushButtonContinuer_clicked();
    void on_pushButtonQuitter_clicked();
    void on_pushButtonNouvellePartie_clicked();

private:
    QWidget* mainWidget;

    QTableWidget* tableScores;

    QHBoxLayout* layoutGlobal;
    QVBoxLayout* layoutButtons;
    QHBoxLayout* layoutScores;

    QPushButton* buttonQuit;
    QPushButton* buttonNewGame;
    QPushButton* buttonContinue;
};

#endif // MENUVIEW_H
