#include "loginpage.h"
#include "ui_loginpage.h"

LoginPage::LoginPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::on_pushButton_clicked()
{
    QString enteredPin = ui->lineEditPinCode->text(); // Получение введенного пин-кода

    if (checkPinCode(enteredPin)) {
        // Переход на страницу "Игра"
        GamePage* gamePage = new GamePage(this);
        gamePage->show();
        this->hide();
    } else {
        // Неверный пин-код - выполните здесь необходимые действия (например, показать сообщение об ошибке)
    }
}

bool LoginPage::checkPinCode(const QString& enteredPin) const
{
    // Здесь вы должны сравнить введенный пин-код (enteredPin) с ожидаемым пин-кодом
    // Если они совпадают, верните true, иначе - false

    // Например:
    return enteredPin == pinCode;
}

