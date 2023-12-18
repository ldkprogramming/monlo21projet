#include "privilegesView.h"
using namespace std;

privileges::privileges(QWidget *parent) : QLabel(parent){
    //Pour modifier le nombre de privilèges restants, on agira sur le compteur
    counter = 3;
    updateCounter();

    //à adapter
    setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
}

privileges::~privileges(){
    qDebug()<< "Destruction Privileges\n";
}

void privileges::updateCounter(){
    string txt = "Privilèges : ";
    string displayedTxt = txt + to_string(counter);
    QString qstr = QString::fromStdString(displayedTxt);
    setText(qstr);
}

void privileges::setCounter(int new_value_counter){
    if(new_value_counter<=3 && new_value_counter>=0) counter = new_value_counter;
}
