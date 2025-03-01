#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player1Time = 0;
    player2Time = 0;
    currentPlayer = 1;
    gameTime = 0;


    pQTimer = new QTimer(this);
    connect(pQTimer, &QTimer::timeout, this, &MainWindow::timeout);

    connect(ui->STARTGAME, &QPushButton::clicked, this, &MainWindow::startGame);
    connect(ui->STOPGAME, &QPushButton::clicked, this, &MainWindow::stopGame);
    connect(ui->S1, &QPushButton::clicked, this, &MainWindow::midoPlayer);
    connect(ui->S2, &QPushButton::clicked, this, &MainWindow::AliPlayer);
    connect(ui->min5, &QPushButton::clicked, this, &MainWindow::Min5);
    connect(ui->sen120, &QPushButton::clicked, this, &MainWindow::Sen120);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeout()
{
    if (currentPlayer == 1) {
        if (player1Time > 0) {
            player1Time--;
            updateProgressBar();
        } else {
            stopGame();
            QMessageBox::information(this, "Peli loppu", "mido voitti ja se on bro :)");
        }
    } else {
        if (player2Time > 0) {
            player2Time--;
            updateProgressBar();
        } else {
            stopGame();
            QMessageBox::information(this, "Peli loppu", "Ali voitti ja se on bro :)");
        }
    }
}

void MainWindow::updateProgressBar()
{
    if (gameTime > 0) {
        ui->progressBar_1->setValue((player1Time * 100) / gameTime);
        ui->progressBar_2->setValue((player2Time * 100) / gameTime);
    }
}

void MainWindow::setGameInfoText(QString text)
{
    ui->label->setText(text);
}

void MainWindow::startGame()
{
    if (gameTime == 0) {
        setGameInfoText("no siis valitse ensin aika kiitos sit pystyt pela ;) ");
        return;
    }

    player1Time = gameTime;
    player2Time = gameTime;


    ui->progressBar_1->setValue(100);
    ui->progressBar_2->setValue(100);

    currentPlayer = 1;
    pQTimer->start(1000);
    updateProgressBar();
    setGameInfoText("Peli alkanut mido vuoro ;)");
}

void MainWindow::stopGame()
{
    pQTimer->stop();
    player1Time = 0;
    player2Time = 0;
    updateProgressBar();
    setGameInfoText("Peli pysäyty");
}

void MainWindow::midoPlayer()
{
    if (pQTimer->isActive()) {
        if (currentPlayer == 1) {
            pQTimer->stop();
            currentPlayer = 2;
            pQTimer->start(1000);
            setGameInfoText("Ali vuoro.");
        }
    }
}

void MainWindow::AliPlayer()
{
    if (pQTimer->isActive()) {
        if (currentPlayer == 2) {
            pQTimer->stop();
            currentPlayer = 1;
            pQTimer->start(1000);
            setGameInfoText("mido vuoro.");
        }
    }
}

void MainWindow::Min5()
{
    gameTime = 300;
    setGameInfoText("Peliaika on 5 minuttia.");
}

void MainWindow::Sen120()
{
    gameTime = 120;
    setGameInfoText("Peliaika on 120 sekuntia.");
}
