#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Start->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Check_clicked()
{
    QString enterList;
    enterList.append(ui->enterCArray->text());
    for (int i = 0; i < enterList.length(); i ++){
        if(enterList.at(i) == 'c' || enterList.at(i) == 'C' || enterList.at(i) == 'D' || enterList.at(i) == 'd' || enterList.at(i) == '+' || enterList.at(i) >= '0' || enterList.at(i) <= '9' || enterList.at(i) == ' '){
            ui->status->setText("Status: OK");
            ui->Start->setEnabled(true);
        }else{
           ui->status->setText("Status: ERROR. Try another array");
        }
    }

}


void MainWindow::on_Start_clicked()
{

    QString enterList;
    this->score.setScore(enterList.append(ui->enterCArray->text()));
    ui->yourArray->setText("Your array: " + enterList);
    this->score.sumScore();

    ui->yourRes->setText("Your result: " + QString::number(this->score.getResult()));
    ui->Start->setEnabled(false);
}

