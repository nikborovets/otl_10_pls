#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QFileDialog"


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    return (qrand() % ((high + 1) - low) + low);
}

void MainWindow::on_add_pattern_clicked()
{
    MoveItem* item = new MoveItem();
    item->setPos(random_between(100, 200), random_between(100, 200));
    scene->addItem(item);
}
