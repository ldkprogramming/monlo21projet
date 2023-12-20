#include "cardPyramidView.h"


cardPyramidView::cardPyramidView(QWidget* parent) : QWidget(parent)
{
    // QWidget* widget = new QWidget(this);

    rows = new QVBoxLayout(this);
    level1 = new QHBoxLayout(this);
    level2 = new QHBoxLayout(this);
    level3 = new QHBoxLayout(this);

    rows->addLayout(level3);
    rows->addLayout(level2);
    rows->addLayout(level1);

    cards = new CardPyramid;

    // labelsLevel1.push_back(new QLabel("CARTE", this)); // Toujours penser a mettre this en parent!
    // level1->addWidget(labelsLevel1.back());

    level1Cards = cards->getLevel1Cards();

    // for (auto& card : level1Cards)
    // {
    //     int id = card.getId();
    //     QString string;
    //     string.append("Carte ");
    //     // string.append(QString::number(id));
    //     QLabel* label = new QLabel(string, this);
    //     level1->addWidget(label);
    // }

    level1->addWidget(new QPushButton("1Carte1", this));
    level1->addWidget(new QPushButton("1Carte2", this));
    level1->addWidget(new QPushButton("1Carte3", this));
    level1->addWidget(new QPushButton("1Carte4", this));
    level1->addWidget(new QPushButton("1Carte5", this));

    level2->addWidget(new QPushButton("2Carte1", this));
    level2->addWidget(new QPushButton("2Carte2", this));
    level2->addWidget(new QPushButton("2Carte3", this));
    level2->addWidget(new QPushButton("2Carte4", this));

    level3->addWidget(new QPushButton("3Carte1", this));
    level3->addWidget(new QPushButton("3Carte2", this));
    level3->addWidget(new QPushButton("3Carte3", this));

    // widget->setLayout(level1);

    this->setLayout(rows);

    // level1->addItem(labelsLevel1);
}
