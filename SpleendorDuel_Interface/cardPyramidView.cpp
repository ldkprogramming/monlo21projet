#include "cardPyramidView.h"






cardButton::cardButton(Card& c, int x, int l, QWidget*parent)
    :QPushButton(parent), x_pos(x), level(l), card(new Card(c)) {
    int id = card->getId();
    QString string = QString::number(id);
    this->setText(string);
}

cardButton::cardButton(int cId, QWidget* parent): QPushButton(parent){

    Card* c = new Card(cId);

        // Texte de la carte
    // Indice
    QString text = "Carte n°";
    text.append(QString::number(cId));

    // Prix
    map<CoinColor, int> price = c->getCosts();
    bool hasPrice = false;
    for (auto c : price){
        if (c.second > 0){
            if (!hasPrice) {
                text.append("\n\nCost:\n");
                hasPrice = true;
            }
            QString colorPrice = QString::fromStdString(toString(c.first));
            colorPrice.append(": ");
            colorPrice.append(QString::number(c.second));
            text.append("|");
            text.append(colorPrice);
            text.append("| ");
        }
    }

    // Bonus
    map<CoinColor, int> bonuses = c->getBonuses();
    bool hasBonus = false;
    for (auto b : bonuses){
        if (b.second > 0){
            if (!hasBonus) {
                text.append("\nBonus:\n");
                hasPrice = true;
            }
            QString colorBonus = QString::fromStdString(toString(b.first));
            colorBonus.append(": ");
            colorBonus.append(QString::number(b.second));
            text.append("|");
            text.append(colorBonus);
            text.append("| ");
        }
    }

    // Points
    int points = c->getPoints();
    if (points != 0){
        text.append("\nPoints: ");
        text.append(QString::number(points));
    }
    //Points couronnes
    int crowns = c->getCrowns();
    if (crowns != 0) {
        text.append("\nCrown Points: ");
        text.append(QString::number(crowns));
    }
    // Skill1
    Skill skill1 = c->getSkill1();
    if (skill1 != Skill::Empty){
        text.append("\nSkills:\n");
        text.append(toString(skill1));
    }

    // Skill2
    Skill skill2 = c->getSkill2();
    if (skill2 != Skill::Empty){
        text.append(" | ");
        text.append(toString(skill2));
    }

    delete c;
    this->setText(text);

        //Taille
    // resize(50,50);
    // setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    const QSize BUTTON_SIZE = QSize(125, 150);
    setMinimumSize(BUTTON_SIZE);
    setMaximumSize(BUTTON_SIZE);
}

cardButton::~cardButton(){}




void cardPyramidView::addCard(const int& cId)
{
    Card* c = new Card(cId);
    PileType level = c->getPileTypeOfCard(cId);
    delete c;
    switch (level) {
    case PileType::One:
        level1->insertWidget(-1, new cardButton(cId, this));
        break;
    case PileType::Two:
        level2->insertWidget(-1, new cardButton(cId, this));
        break;
    case PileType::Three:
        level3->insertWidget(-1, new cardButton(cId, this));
        break;
    case PileType::Royal:
        royal->insertWidget(-1, new cardButton(cId, this));
        break;
    default:
        break;
    }
}


cardPyramidView::cardPyramidView(QWidget* parent) : QWidget(parent)
{
    // QWidget* widget = new QWidget(this);

    layout = new QHBoxLayout(this);
    royal = new QVBoxLayout(this);

    rows = new QVBoxLayout(this);
    level1 = new QHBoxLayout(this);
    level2 = new QHBoxLayout(this);
    level3 = new QHBoxLayout(this);

    layout->addLayout(royal);
    layout->addLayout(rows);

    rows->addLayout(level3);
    rows->addLayout(level2);
    rows->addLayout(level1);

    // royal->setSizeConstraint(royal->SetMinimumSize);


    // cards = new CardPyramid;

    // labelsLevel1.push_back(new QLabel("CARTE", this)); // Toujours penser a mettre this en parent!
    // level1->addWidget(labelsLevel1.back());

    // level1Cards = cards->getLevel1Cards();

    // for (auto& card : level1Cards)
    // {
    //     int id = card.getId();
    //     QString string;
    //     string.append("Carte ");
    //     // string.append(QString::number(id));
    //     QLabel* label = new QLabel(string, this);
    //     level1->addWidget(label);
    // }

    // Card c(10);
    // level1->addWidget(new cardButton(c,0,0,this));

    // addCard(1);


    // level1->addWidget(new cardButton(1, this));
    // level1->addWidget(new cardButton(9, this));
    // level1->addWidget(new cardButton(10, this));
    // level1->addWidget(new cardButton(3, this));
    // level1->addWidget(new cardButton(15, this));

    // level2->addWidget(new cardButton(29, this));
    // level2->addWidget(new cardButton(31, this));
    // level2->addWidget(new cardButton(42, this));
    // level2->addWidget(new cardButton(35, this));

    // level3->addWidget(new cardButton(60, this));
    // level3->addWidget(new cardButton(59, this));
    // level3->addWidget(new cardButton(63, this));

    // level1->addWidget(new QPushButton("1Carte1", this));
    // level1->addWidget(new QPushButton("1Carte2", this));
    // level1->addWidget(new QPushButton("1Carte3", this));
    // level1->addWidget(new QPushButton("1Carte4", this));
    // level1->addWidget(new QPushButton("1Carte5", this));

    // level2->addWidget(new QPushButton("2Carte1", this));
    // level2->addWidget(new QPushButton("2Carte2", this));
    // level2->addWidget(new QPushButton("2Carte3", this));
    // level2->addWidget(new QPushButton("2Carte4", this));

    // level3->addWidget(new QPushButton("3Carte1", this));
    // level3->addWidget(new QPushButton("3Carte2", this));
    // level3->addWidget(new QPushButton("3Carte3", this));

    // widget->setLayout(level1);

    this->setLayout(layout);

    // level1->addItem(labelsLevel1);
}




















