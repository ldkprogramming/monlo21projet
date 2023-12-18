#ifndef COINBAGVIEW_H
#define COINBAGVIEW_H

#include <QObject>
#include <QPushButton>

class coinBagView : public QPushButton
{

    Q_OBJECT
public:
    coinBagView(QWidget *parent = nullptr);
    ~coinBagView();

    void isUsable(){this->setCheckable(true);}
    void isUnusable(){this->setCheckable(false);}
};

#endif // COINBAGVIEW_H
