#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QFileDialog"
#include <QDir>
#include <iostream>

char* Settings::get_path() const
{
    return this->path;
}

void Settings::set_path(char* path)
{
    this->path = path;
}



MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      shish(new Settings)
{
    shish->set_path("\0");
    ui->setupUi(this);
    //QObject::connect(ui->pushButton, SIGNAL(clicked(Settings*)), this, SLOT(on_pushButton_clicked(Settings*)));

    scene = new QGraphicsScene(this);   // Инициализируем графическую сцену
    ui->graphics_view->setScene(scene); //  Устанавливаем графическую сцену в graphics_view
    scene->setItemIndexMethod(QGraphicsScene::NoIndex); // настраиваем индексацию элементов
    scene->setSceneRect(0,0,500,500); // Устанавливаем размер сцены
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_open_triggered()
{
    QString str = QFileDialog::getExistingDirectory(0, "Choose file", "");
}

void MainWindow::on_action_remove_triggered()
{

}

static int random_between(int low, int high)
{
    return (rand() % ((high + 1) - low) + low);
}

void MainWindow::on_add_pattern_clicked()
{
    MoveItem* item = new MoveItem();
    item->setPos(random_between(100, 200), random_between(100, 200));
    scene->addItem(item);
}

void MainWindow::on_pushButton_clicked()
{
    if (strlen(shish->get_path()) > 0)
    {
        qDebug() << shish->get_path();
    }
    else
    {
        QFileDialog dialog;
        QString file_name;
        dialog.setNameFilter("Executable (*.o)");
        if (dialog.exec() == QDialog::Accepted)
        {
                file_name = dialog.selectedFiles().first();
                qDebug() << "Выбранный файл: " << file_name;
        }

        //QString str = QFileDialog::getExistingDirectory(0, "Choose file", "");
        //str += "/untitled8";
        //const int buffer_size = str.size() + 1;
        //char *path = shish->get_path();
        char* path = new char [file_name.size()];
        strcpy(path, file_name.toUtf8().constData());
        shish->set_path(path);
    }
    system(shish->get_path());
}
