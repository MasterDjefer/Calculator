#include "widget.h"

Widget::~Widget(){}

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    initElements();
    setOnScreen();
    setFunctional();
}

void Widget::initElements()
{
    this->setFixedSize(200,180);
    mainLayout = new QVBoxLayout(this);
    layoutForBlock0 = new QHBoxLayout;
    layoutForBlock1 = new QHBoxLayout;
    layoutForBlock2 = new QHBoxLayout;
    layoutForBlock3 = new QHBoxLayout;
    layoutForBlock4 = new QHBoxLayout;
    layoutForBlock5 = new QHBoxLayout;
    layoutForBlock6 = new QHBoxLayout;

    mainField = new QLabel;

    numDel = new QPushButton("Delete");
    numC = new QPushButton("C");

    num7 = new QPushButton("7");
    num8 = new QPushButton("8");
    num9 = new QPushButton("9");
    numDiv = new QPushButton("/");

    num4 = new QPushButton("4");
    num5 = new QPushButton("5");
    num6 = new QPushButton("6");
    numMul = new QPushButton("*");

    num1 = new QPushButton("1");
    num2 = new QPushButton("2");
    num3 = new QPushButton("3");
    numMin = new QPushButton("-");

    num0 = new QPushButton("0");
    numEqu = new QPushButton("=");
    numAdd = new QPushButton("+");
}

void Widget::setOnScreen()
{
    mainLayout->addWidget(mainField);

    layoutForBlock0->addWidget(numDel);
    layoutForBlock0->addWidget(numC);

    layoutForBlock1->addWidget(num7);
    layoutForBlock1->addWidget(num8);
    layoutForBlock1->addWidget(num9);
    layoutForBlock1->addWidget(numDiv);

    layoutForBlock2->addWidget(num4);
    layoutForBlock2->addWidget(num5);
    layoutForBlock2->addWidget(num6);
    layoutForBlock2->addWidget(numMul);

    layoutForBlock3->addWidget(num1);
    layoutForBlock3->addWidget(num2);
    layoutForBlock3->addWidget(num3);
    layoutForBlock3->addWidget(numMin);


    layoutForBlock5->addWidget(num0);
    layoutForBlock6->addWidget(numEqu);
    layoutForBlock6->addWidget(numAdd);

    layoutForBlock4->addLayout(layoutForBlock5);
    layoutForBlock4->addLayout(layoutForBlock6);

    mainLayout->addLayout(layoutForBlock0);
    mainLayout->addLayout(layoutForBlock1);
    mainLayout->addLayout(layoutForBlock2);
    mainLayout->addLayout(layoutForBlock3);
    mainLayout->addLayout(layoutForBlock4);


    this->setLayout(mainLayout);
}

void Widget::setFunctional()
{
    QObject::connect(num0, &QPushButton::clicked, this, &set0);
    QObject::connect(num1, &QPushButton::clicked, this, &set1);
    QObject::connect(num2, &QPushButton::clicked, this, &set2);
    QObject::connect(num3, &QPushButton::clicked, this, &set3);
    QObject::connect(num4, &QPushButton::clicked, this, &set4);
    QObject::connect(num5, &QPushButton::clicked, this, &set5);
    QObject::connect(num6, &QPushButton::clicked, this, &set6);
    QObject::connect(num7, &QPushButton::clicked, this, &set7);
    QObject::connect(num8, &QPushButton::clicked, this, &set8);
    QObject::connect(num9, &QPushButton::clicked, this, &set9);
    QObject::connect(numDiv, &QPushButton::clicked, this, &setDiv);
    QObject::connect(numMul, &QPushButton::clicked, this, &setMul);
    QObject::connect(numAdd, &QPushButton::clicked, this, &setAdd);
    QObject::connect(numMin, &QPushButton::clicked, this, &setMin);
    QObject::connect(numDel, &QPushButton::clicked, this, &setDel);
    QObject::connect(numC, &QPushButton::clicked, this, &setC);
    QObject::connect(numEqu, &QPushButton::clicked, this, &setEqu);       
}

void Widget::set0()
{
    mainField->setText(mainField->text() + "0");
}
void Widget::set1()
{
    mainField->setText(mainField->text() + "1");
}
void Widget::set2()
{
    mainField->setText(mainField->text() + "2");
}
void Widget::set3()
{
    mainField->setText(mainField->text() + "3");
}
void Widget::set4()
{
    mainField->setText(mainField->text() + "4");
}
void Widget::set5()
{
    mainField->setText(mainField->text() + "5");
}
void Widget::set6()
{
    mainField->setText(mainField->text() + "6");
}
void Widget::set7()
{
    mainField->setText(mainField->text() + "7");
}
void Widget::set8()
{
    mainField->setText(mainField->text() + "8");
}
void Widget::set9()
{
    mainField->setText(mainField->text() + "9");
}

void Widget::setDel()
{
    mainField->setText("");
}

void Widget::setC()
{
    if (!mainField->text().isEmpty())
    {
        QString temp = mainField->text().remove(mainField->text().size() - 1, 1);
        mainField->setText(temp);

    }
}

void Widget::setDiv()
{
    if (mainField->text().size() > 1 ||
       (mainField->text().size() == 1 && mainField->text().at(0) != '-'))
    {
        QString temp = mainField->text();

        if (temp.at(temp.size() - 1) >= 48 && temp.at(temp.size() - 1) <= 57)
        {
            mainField->setText(temp + "/");
        }
        else
        {
            temp.remove(temp.size() - 1, 1);
            temp += '/';
            mainField->setText(temp);
        }
    }
}
void Widget::setMul()
{
    if (mainField->text().size() > 1 ||
       (mainField->text().size() == 1 && mainField->text().at(0) != '-'))
    {
        QString temp = mainField->text();

        if (temp.at(temp.size() - 1) >= 48 && temp.at(temp.size() - 1) <= 57)
        {
            mainField->setText(temp + "*");
        }
        else
        {
            temp.remove(temp.size() - 1, 1);
            temp += '*';
            mainField->setText(temp);
        }
    }
}
void Widget::setAdd()
{
    if (mainField->text().size() > 1 ||
       (mainField->text().size() == 1 && mainField->text().at(0) != '-'))
    {
        QString temp = mainField->text();

        if (temp.at(temp.size() - 1) >= 48 && temp.at(temp.size() - 1) <= 57)
        {
            mainField->setText(temp + "+");
        }
        else
        {
            temp.remove(temp.size() - 1, 1);
            temp += '+';
            mainField->setText(temp);
        }
    }
}
void Widget::setMin()
{
    if (mainField->text().size() > 1 ||
       (mainField->text().size() == 1 && mainField->text().at(0) != '-'))
    {
        QString temp = mainField->text();

        if (temp.at(temp.size() - 1) >= 48 && temp.at(temp.size() - 1) <= 57)
        {
            mainField->setText(temp + "-");
        }
        else
        {
            temp.remove(temp.size() - 1, 1);
            temp += '-';
            mainField->setText(temp);
        }
    }
    else
    {
        mainField->setText("-");
    }
}

void Widget::setEqu()
{
    QString temp = mainField->text();
    if (temp.isEmpty())
    {
        return;
    }
    if (temp.at(temp.size() - 1) < 48 || temp.at(temp.size() - 1) > 57)
    {
        return;
    }




    while (findCharFirst(temp) != -1)
    {
        int mul = findCharFirst(temp);

        int begin = mul - 1;
        int end = mul + 1;

        while (temp.at(begin) >= 48 && temp.at(begin) <= 57)
        {
            if (begin == 0)
            {
                break;
            }
            begin--;
        }
        if (begin != 0)
        {
            begin++;
        }

        while (temp.at(end) >= 48 && temp.at(end) <= 57)
        {
            if (end == temp.size() - 1)
            {
                break;
            }
            end++;
        }
        if (end != temp.size() - 1)
        {
            end--;
        }

        QString val1 = stringNumber(temp, begin, mul);
        QString val2 = stringNumber(temp, mul + 1, end + 1);

        QString final = "";
        if (temp.at(mul) == '*')
            final = QString::number(val1.toInt() * val2.toInt());
        else
            final = QString::number(val1.toInt() / val2.toInt());


        QString normal = insertString(temp, final, begin, end);
        temp = normal;
        mainField->setText(normal);
    }


    while (findCharSecond(temp) != -1)
    {        
        if (findCharSecond(temp) == 0)
        {
            QString temp = mainField->text().remove(0, 1);
            if (findCharSecond(temp) == -1)
            {
                return;
            }
        }
        if (findCharSecond(temp) != 0)
        {
            int mul = findCharSecond(temp);

            int begin = mul - 1;
            int end = mul + 1;

            while (temp.at(begin) >= 48 && temp.at(begin) <= 57)
            {
                if (begin == 0)
                {
                    break;
                }
                begin--;
            }
            if (begin != 0)
            {
                begin++;
            }

            while (temp.at(end) >= 48 && temp.at(end) <= 57)
            {
                if (end == temp.size() - 1)
                {
                    break;
                }
                end++;
            }
            if (end != temp.size() - 1)
            {
                end--;
            }

            QString val1 = stringNumber(temp, begin, mul);
            QString val2 = stringNumber(temp, mul + 1, end + 1);

            QString final = "";
            if (temp.at(mul) == '+')
                final = QString::number(val1.toInt() + val2.toInt());
            else
                final = QString::number(val1.toInt() - val2.toInt());


            QString normal = insertString(temp, final, begin, end);
            temp = normal;
            mainField->setText(normal);
        }
        else
        {
            int mul = 2;

            while (temp.at(mul) >= 48 && temp.at(mul) <= 57)
            {
                mul++;
            }

            int begin = 1;
            int end = mul + 1;

            while (temp.at(end) >= 48 && temp.at(end) <= 57)
            {
                if (end == temp.size() - 1)
                {
                    break;
                }
                end++;
            }
            if (end != temp.size() - 1)
            {
                end--;
            }



            QString val1 = stringNumber(temp, begin, mul);
            QString val2 = stringNumber(temp, mul + 1, end + 1);

            QString final = "";
            if (temp.at(mul) == '+')
                final = QString::number(val2.toInt() - val1.toInt());
            else
                final = QString::number(-(val1.toInt() + val2.toInt()));


            QString normal = insertString(temp, final, 0, end);
            temp = normal;
            mainField->setText(normal);
        }
    }
}

QString Widget::insertString(const QString &temp, const QString &final, int begin, int end)
{
    QString normal = "";

    for (int i = 0; i < begin; ++i)
    {
        normal += temp.at(i);
    }

    normal += final;


    for (int i = end + 1; i < temp.size(); ++i)
    {
        normal += temp.at(i);
    }

    return normal;
}

QString Widget::stringNumber(const QString &temp, int begin, int end)
{
    QString s = "";
    for (int i = begin; i < end; ++i)
    {
        s += temp.at(i);
    }
    return s;
}

int Widget::findCharFirst(const QString &temp)
{
    for (int i = 0; i < temp.size(); ++i)
    {
        if (temp.at(i) == '*' || temp.at(i) == '/')
            return i;
    }
    return -1;
}

int Widget::findCharSecond(const QString &temp)
{
    for (int i = 0; i < temp.size(); ++i)
    {
        if (temp.at(i) == '+' || temp.at(i) == '-')
            return i;
    }
    return -1;
}
