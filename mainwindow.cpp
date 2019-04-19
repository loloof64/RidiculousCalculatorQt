#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonValidate_pressed()
{
    auto operand1Txt = this->ui->fieldOperand1->text();
    auto operand2Txt = this->ui->fieldOperand2->text();
    auto operatorTxt = this->ui->fieldOperator->currentText();

    auto result = 0;
    if (operatorTxt == '+') result = operand1Txt.toInt() + operand2Txt.toInt();
    if (operatorTxt == '-') result = operand1Txt.toInt() - operand2Txt.toInt();
    if (operatorTxt == '*') result = operand1Txt.toInt() * operand2Txt.toInt();

    auto message = QString(operand1Txt +  " " + operatorTxt + " " + operand2Txt + " = " + QString::number(result));
    auto title = QString("Result");
    QMessageBox::information(this, title, message);
}
