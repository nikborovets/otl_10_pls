#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QFileDialog"
#include "MyPlot.h"
#include <QDir>
#include <iostream>


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      shish(new QSettings)
{
    shish->setValue("Path", "\0");
    ui->setupUi(this);
    //QObject::connect(ui->pushButton, SIGNAL(clicked(Settings*)), this, SLOT(on_pushButton_clicked(Settings*)));

    db = new DataBase();
    db->connectToDataBase();

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

void MainWindow::on_add_pattern_2_clicked()
{
    MoveItem* item = new MoveItem();
    item->setPos(random_between(100, 200), random_between(100, 200));
    scene->addItem(item);
}


void MainWindow::on_push_button_clicked()
{
    QSettings settings("Path", "\0");
    QString filePath = settings.value("Path").toString();
    if (filePath.size() > 0)
    {
        qDebug() << filePath;
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
        char* path = new char [file_name.size()];
        strcpy(path, file_name.toUtf8().constData());

        shish->setValue("Path", QString::fromUtf8(path));
    }
    system(shish->value("Path").toString().toUtf8().data());

    GraphWidget* plot = new GraphWidget(this);
    plot->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
    plot->setWindowTitle("График");
    plot->show();
}


/*void MainWindow::on_set_button_clicked()
{
    MoveItem* item = new MoveItem();
    item->setPos(random_between(100, 200), random_between(100, 200));
    scene->addItem(item);
}*/


void MainWindow::on_set_button_clicked()
{ 
    enum Color {
        RED,
        GREEN,
        BLUE,
        YELLOW
    };
    QColor color_list[] = { QColor("#FF0000"), QColor("#00FF00"), QColor("#0000FF"), QColor("#FFFF00") };


    //MoveItem* item = new MoveItem();
    //item->setPos(random_between(100, 200), random_between(100, 200));
    //scene->addItem(item);
    QTreeWidgetItem* current_item = ui->filters_information->currentItem();
    if (!current_item)
        return;
    int color_number = ui->filters_information->currentIndex().row();
    QColor my_color = color_list[color_number];
    MoveItem* color_item = new MoveItem();
    color_item->setColor(my_color);
    scene->addItem(color_item);

    //connect(ui->filters_information, &QTreeWidget::itemSelectionChanged, this, &MainWindow::on_filters_information_currentItemChanged);
    //connect(ui->set_button, &QPushButton::clicked, this, &MainWindow::on_set_button_clicked);
}

