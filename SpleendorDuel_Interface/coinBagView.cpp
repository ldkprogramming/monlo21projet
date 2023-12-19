#include "coinBagView.h"
#include <QPushButton>
#include <QDebug>

coinBagView::coinBagView(QWidget *parent) : QPushButton(parent){
    setText("Sac de Jetons");

    //à adapter
    setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
}

coinBagView::~coinBagView(){
    qDebug()<< "Destruction sac\n";
}
