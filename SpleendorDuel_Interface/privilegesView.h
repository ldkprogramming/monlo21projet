#ifndef PRIVILEGESVIEW_H
#define PRIVILEGESVIEW_H

#include <QObject>
#include <QLabel>

class privileges : public QLabel
{
    Q_OBJECT
private:
    int counter;
public:
    privileges(QWidget *parent = nullptr);
    ~privileges();
    int getCounter(){return counter;}
    void setCounter(int new_value_counter);
    void updateCounter();
    void incrementCounter(){counter++;}
    void decrementCounter(){counter--;}
};

#endif // PRIVILEGESVIEW_H
