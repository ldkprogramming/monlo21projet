#include "cardPyramidView.h"

#include <QSignalMapper>




cardButton::cardButton(Card& c, int x, int l, QWidget*parent)
    :QPushButton(parent), x_pos(x), level(l), card(new Card(c)) {
    int id = card->getId();
    QString string = QString::number(id);
    this->setText(string);
}

cardButton::cardButton(int cId, QWidget* parent, bool onPile): QPushButton(parent) {
    qDebug()<<"création carte";

    Card* c = new Card(cId);
    cardButton(*c, 0, 0, parent);

    QString text;

    if (!onPile) {
            // Texte de la carte
        // Indice
        text = "Carte n°";
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
                    hasBonus = true;
                }
                QString colorBonus = QString::fromStdString(toString(b.first));
                colorBonus.append(": ");
                colorBonus.append(QString::number(b.second));

                // Test couleur
                // QString redPart = QString("<span style=\" color:#ff0000;\">%1</span>").arg(QString::number(b.second));
                // colorBonus.append(redPart);

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
    }
    else {
        text="Pile";
        PileType pile = c->getPileTypeOfCard(cId);
        switch(pile){
        case PileType::One:
            text.append(" 1");
            break;
        case PileType::Two:
            text.append(" 2");
            break;
        case PileType::Three:
            text.append(" 3");
            break;
        default:
            break;
        }
    }

    delete c;

    this->setText(text);

        //Taille
    // resize(50,50);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    // const QSize BUTTON_SIZE = QSize(125, 100);
    // setMinimumSize(BUTTON_SIZE);
    // setMaximumSize(BUTTON_SIZE);

    setCheckable(true);
}

cardButton::~cardButton(){}



void cardPyramidView::cardClicked(cardButton* c){
    qDebug() << "Carte cliquée";

    for (auto card : cardButtons){
        qDebug() << "Yahoo";
        if (card != c){
            // card->clearFocus();
            card->setChecked(false);
        }
    }
}



void cardPyramidView::addCard(const int& cId, bool onPile)
{
    Card* c = new Card(cId);
    PileType level = c->getPileTypeOfCard(cId);
    delete c;

    QSignalMapper* signalMapper = new QSignalMapper (this) ;

    if (!onPile){
        cardButton* cB = new cardButton(cId, this);
        switch (level) {
        case PileType::One:
            level1->insertWidget(-1, cB);
            break;
        case PileType::Two:
            level2->insertWidget(-1, cB);
            break;
        case PileType::Three:
            level3->insertWidget(-1, cB);
            break;
        case PileType::Royal:
            royal->insertWidget(-1, cB);
            break;
        default:
            break;
        }

        connect(cB, &QPushButton::clicked, [this, cB] { cardClicked(cB); });
        cardButtons.push_back(cB);
    }
    else {
        cardButton* cB = new cardButton(cId, this, true);
        switch (level) {
        case PileType::One:
            pile1->insertWidget(-1, cB);
            break;
        case PileType::Two:
            pile2->insertWidget(-1, cB);
            break;
        case PileType::Three:
            pile3->insertWidget(-1, cB);
            break;
        default:
            break;
        }

        connect(cB, &QPushButton::clicked, [this, cB] { cardClicked(cB); });
        cardButtons.push_back(cB);
    }

}


cardPyramidView::cardPyramidView(QWidget* parent) : QWidget(parent)
{
    layout = new QHBoxLayout(this);
    royal = new QVBoxLayout(this);
    piles = new QVBoxLayout(this);
    pile1 = new QHBoxLayout(this);
    pile2 = new QHBoxLayout(this);
    pile3 = new QHBoxLayout(this);

    rows = new QVBoxLayout(this);
    level1 = new QHBoxLayout(this);
    level2 = new QHBoxLayout(this);
    level3 = new QHBoxLayout(this);

    // Ordre du layout
    layout->addLayout(royal);
    layout->addLayout(rows);
    layout->addLayout(piles);

    rows->addLayout(level3);
    rows->addLayout(level2);
    rows->addLayout(level1);

    piles->addLayout(pile1);
    piles->addLayout(pile2);
    piles->addLayout(pile3);

    this->setLayout(layout);
}




buyCardButtonView::buyCardButtonView(QWidget* parent): QPushButton(parent){
    setText("Acheter la carte sélectionnée");
    setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
}

reserveCardButtonView::reserveCardButtonView(QWidget* parent): QPushButton(parent){
    setText("Réserver la carte sélectionnée");
    setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
}
















