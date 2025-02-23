#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);


   number1 = "";
    number2 = "";
    state = 1;
    operand = -1;

    connect(ui->num1, &QLineEdit::textChanged, this, &MainWindow::num1_napaimisto);
    connect(ui->num2, &QLineEdit::textChanged, this, &MainWindow::num2_napaimisto);
    connect(ui->N0, &QPushButton::clicked, this, &MainWindow::numberNappi);
    connect(ui->N1, &QPushButton::clicked, this, &MainWindow::numberNappi);
    connect(ui->N2, &QPushButton::clicked, this, &MainWindow::numberNappi);
    connect(ui->N3, &QPushButton::clicked, this, &MainWindow::numberNappi);
    connect(ui->N4, &QPushButton::clicked, this, &MainWindow::numberNappi);
    connect(ui->N5, &QPushButton::clicked, this, &MainWindow::numberNappi);
    connect(ui->N6, &QPushButton::clicked, this, &MainWindow::numberNappi);
    connect(ui->N7, &QPushButton::clicked, this, &MainWindow::numberNappi);
    connect(ui->N8, &QPushButton::clicked, this, &MainWindow::numberNappi);
    connect(ui->N9, &QPushButton::clicked, this, &MainWindow::numberNappi);




    connect(ui->sum, &QPushButton::clicked, this, &MainWindow::operaNappi);
    connect(ui->mi, &QPushButton::clicked, this, &MainWindow::operaNappi);
    connect(ui->ke, &QPushButton::clicked, this, &MainWindow::operaNappi);
    connect(ui->ja, &QPushButton::clicked, this, &MainWindow::operaNappi);


    connect(ui->clear, &QPushButton::clicked, this, &MainWindow::clearNappi);
    connect(ui->enter, &QPushButton::clicked, this, &MainWindow::enterNappi);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberNappi()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    QString number = button->text();
    if (state == 1) {
        number1 += number;
        ui->num1->setText(number1);
    } else if (state == 2) {
        number2 += number;
        ui->num2->setText(number2);
    }

   // qDebug() << "Number1:" << number1;
    //qDebug() << "Number2:" << number2;
}

void MainWindow::num1_napaimisto()
{
    number1 = ui->num1->text();
    qDebug() << "kentä 1 numero otettu: " << number1;
}

void MainWindow::num2_napaimisto()
{
    number2 = ui->num2->text();
    qDebug() << "kentä 2 numero otettu: " << number2;
}

void MainWindow::operaNappi()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;


    if (button == ui->sum) {
          operand = 0;
    ui->result->setText("+");
    } else if (button == ui->mi) {
        operand = 1;
          ui->result->setText("-");
    } else if (button == ui->ke) {
        operand = 2;
           ui->result->setText("*");
    } else if (button == ui->ja) {
        operand = 3;
           ui->result->setText("/");
    }

    if (!number1.isEmpty()) {
        state = 2;
    }
    qDebug() << "valittu laskutapa:  " << ui->result->text();
}

void MainWindow::clearNappi()
{
    asettaUudelleen();
}

void MainWindow::enterNappi()
{
    if (state == 1 && !number1.isEmpty()) {

        state = 2;
        qDebug() << "Siirrytään toisen numeron syöttöön.";
    } else if (state == 2 && !number1.isEmpty() && !number2.isEmpty() && operand != -1) {

        float num1 = number1.toFloat();
        float num2 = number2.toFloat();
        float result = 0.0;


        switch (operand) {
        case 0:
            result = num1 + num2;

            break;
        case 1:
            result = num1 - num2;
            break;
        case 2:
            result = num1 * num2;
            break;
        case 3:
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                ui->result->setText("ei voi ;(");
                return;
            }

            break;
         }

        ui->result->setText(QString::number(result));
    }
}

void MainWindow::asettaUudelleen()
{
    number1 = "";
    number2 = "";
    operand = -1;
    state = 1;


    ui->num1->clear();
    ui->num2->clear();
    ui->result->clear();
}
