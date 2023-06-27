#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>

namespace Ui {
class LoginPage;
}

class LoginPage : public QWidget
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

private slots:
    void on_pushButton_clicked();

private:
    static const QString pinCode;

private:
    bool checkPinCode(const QString& enteredPin) const;

private:
    Ui::LoginPage *ui;
};
// Поле для хранения пин-кода

#endif // LOGINPAGE_H
