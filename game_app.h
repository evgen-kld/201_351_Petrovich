#ifndef GAME_APP_H
#define GAME_APP_H
#include <QDialog>
#include <QTableWidgetItem>
#include <QLineEdit>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <windows.h>
#include <QCryptographicHash>

//using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class game_app; }
QT_END_NAMESPACE


class game_app : public QDialog
{
    Q_OBJECT

public:
    game_app(QWidget *parent = nullptr);
    ~game_app();
    void createUI();
    std::array<int, 10000> array;
    int s;
    int k;
    void createTable();

private:
    Ui::game_app *ui;
    QLineEdit *lineEdit;
    bool eventFilter(QObject* watched, QEvent* event);


signals:
    void ShowMW();
};

#endif // GAME_APP_H

