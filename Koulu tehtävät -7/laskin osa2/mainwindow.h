#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;

    QString number1;
    QString number2;
    int state;
    int operand;

    void numberNappi();
    void operaNappi();
    void clearNappi();
    void enterNappi();
    void num1_napaimisto();
    void num2_napaimisto();


    void asettaUudelleen();
};

#endif // MAINWINDOW_H
