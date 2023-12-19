#ifndef USEPRIVILEGEBUTTONVIEW_H
#define USEPRIVILEGEBUTTONVIEW_H

#include <QObject>
#include <QPushButton>

class usePrivilegeButtonView : public QPushButton
{
    Q_OBJECT
public:
    usePrivilegeButtonView(QWidget *parent=nullptr);
    ~usePrivilegeButtonView(){qDebug()<<"Destruction boutton usePrivilege";}
    void isUsable(){this->setCheckable(true);}
    void isUnusable(){this->setCheckable(false);}
};

#endif // USEPRIVILEGEBUTTONVIEW_H
