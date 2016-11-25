#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QDebug>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void initElements();
    void setOnScreen();
    void setFunctional();
    QString stringNumber(const QString &, int, int);
    QString insertString(const QString &, const QString &, int, int);

    int findCharFirst(const QString &);
    int findCharSecond(const QString &);

public slots:
    void set0();
    void set1();
    void set2();
    void set3();
    void set4();
    void set5();
    void set6();
    void set7();
    void set8();
    void set9();
    void setMul();
    void setDiv();
    void setAdd();
    void setMin();
    void setEqu();    
    void setDel();
    void setC();

private:
    QVBoxLayout *mainLayout;
    QHBoxLayout *layoutForBlock0;
    QHBoxLayout *layoutForBlock1;
    QHBoxLayout *layoutForBlock2;
    QHBoxLayout *layoutForBlock3;
    QHBoxLayout *layoutForBlock4;
    QHBoxLayout *layoutForBlock5;
    QHBoxLayout *layoutForBlock6;

    QLabel *mainField;

    QPushButton *numC;
    QPushButton *numDel;
    QPushButton *num7;
    QPushButton *num8;
    QPushButton *num9;
    QPushButton *numDiv;
    QPushButton *num4;
    QPushButton *num5;
    QPushButton *num6;
    QPushButton *numMul;
    QPushButton *num1;
    QPushButton *num2;
    QPushButton *num3;
    QPushButton *numMin;
    QPushButton *num0;
    QPushButton *numEqu;
    QPushButton *numAdd;
};

#endif // WIDGET_H
