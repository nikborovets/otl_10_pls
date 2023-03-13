#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QFileDialog"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString str = QFileDialog::getExistingDirectory(0, "Choose file", "");
}

void MainWindow::on_AddForm_clicked()
{

}

void MainWindow::on_RemoveForm_clicked()
{

}

void MainWindow::on_MoveUp_clicked()
{

}

void MainWindow::on_pushButton_4_clicked()
{

}
