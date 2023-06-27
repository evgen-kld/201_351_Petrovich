#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QJsonDocument>
#include <windows.h>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    game = new game_app;
    ui->label->setVisible(false);
    connect(game, &game_app::ShowMW,this,&MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if (ui->lineEdit->text() == "1234")
    {
        game->show();
        game->createTable();
    }

    else
    {
        ui->label->setVisible(true);
    }
}

