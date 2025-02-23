#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , laskuri(0)
{
    ui->setupUi(this);


    ui->lineEdit->setText(QString::number(laskuri));

    connect(ui->laskuri, &QPushButton::clicked, this, &MainWindow::LaskuriNappi);
    connect(ui->nollaus, &QPushButton::clicked, this, &MainWindow::NollausNappi);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LaskuriNappi()
{
    laskuri++;
    ui->lineEdit->setText(QString::number(laskuri));
}

void MainWindow::NollausNappi()
{
    laskuri = 0;
    ui->lineEdit->setText(QString::number(laskuri));
}

