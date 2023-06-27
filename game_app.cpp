#include "game_app.h"
#include "ui_game_app.h"
#include <QDialog>
#include <QDebug>
#include <QFile>
#include <QCoreApplication>
#include <QItemDelegate>
#include <iostream>
#include <QEvent>
#include <random>
#include <vector>
#include <algorithm>
#include <iterator>
#include <QClipboard>
#include <QString>
#include <ctime>
#include <QMessageBox>


game_app::game_app(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::game_app)
{
    ui->setupUi(this);
}


//функция события qlineedit
bool game_app::eventFilter(QObject* watched, QEvent* event)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        if (QLineEdit* lineEdit = qobject_cast<QLineEdit*>(watched))
        {
            Q_FOREACH(const QLineEdit* i, findChildren<QLineEdit*>())
                i->disconnect();

            int row = lineEdit->property("row").toInt();

            if (k != 4) {
                for (int i = 0; i < 12; i++)
                {
                    if (i != row){
                        QString number = QString::number(array[i]);
                        number = number.leftJustified(4, '0');
                        lineEdit = new QLineEdit(number);
                        lineEdit->setEchoMode(QLineEdit::Password);
                        lineEdit->setProperty("row", i);
                        lineEdit->setReadOnly(true);
                        lineEdit->installEventFilter(this);
                        ui->table->setCellWidget(i, 0, lineEdit);
                    }
                    else {
                        QString number = QString::number(array[i]);
                        number = number.leftJustified(4, '0');
                        lineEdit = new QLineEdit(number);
                        lineEdit->setEchoMode(QLineEdit::Normal);
                        lineEdit->setReadOnly(true);
                        ui->table->setCellWidget(i, 0, lineEdit);
                        k += 1;
                        s += array[i];
                        ui->label->setText(QString::number(s));

                        if (k == 4) {
                            QMessageBox msgBox;
                            QString text = QString::number(s);
                            msgBox.setText(text);
                            msgBox.exec();
                            createTable(); //происходит сброс игры
                            ui->label->setText("");
                        }
                    }
                }
            }
        }
    }
    return QObject::eventFilter(watched, event);
}



void game_app::createTable() {
    ui->table->setRowCount(0);
    k = 0;
    s = 0;

    for (int i = 0; i < 10000; ++i) {
        array[i] = i;
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(array.begin(), array.end(), g);


    for (int i = 0; i < 12; i++)
    {
        ui->table->insertRow(i);
        QString number = QString::number(array[i]);
        number = number.leftJustified(4, '0');
        lineEdit = new QLineEdit(number);
        lineEdit->setEchoMode(QLineEdit::Password);
        lineEdit->setProperty("row", i);
        lineEdit->setReadOnly(true);
        lineEdit->installEventFilter(this);
        ui->table->setCellWidget(i, 0, lineEdit);
    }
}

game_app::~game_app()
{
    delete ui;
}





