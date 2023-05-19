#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QFileDialog"
#include "MyPlot.h"
#include <QDir>
#include <iostream>

#include <QTcpSocket>
#include <QVariant>
#include <QGraphicsLineItem>
#include <QLineF>


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      shish(new QSettings)
{
    shish->setValue("Path", "\0");
    ui->setupUi(this);

    MoveItem* static_settings_item = new MoveItem();
    item_list.push_back(static_settings_item);
    item_list_in_order.push_back(static_settings_item);
    static_settings_item->setColor(Qt::gray);
    static_settings_item->setData(Qt::UserRole, "settings");
    static_settings_item->set_name("settings");

    //connect(static_settings_item, &MoveItem::selectionChanged, this, &MainWindow::settings_filter);

    //connect(my_item, &MoveItem::selectionChanged, this, &MainWindow::paint_filters);
    //QObject::connect(ui->pushButton, SIGNAL(clicked(Settings*)), this, SLOT(on_pushButton_clicked(Settings*)));

    db = new DataBase();
    db->connectToDataBase();

    scene = new QGraphicsScene(this);   // Инициализируем графическую сцену
    ui->graphics_view->setScene(scene); //  Устанавливаем графическую сцену в graphics_view
    scene->setItemIndexMethod(QGraphicsScene::NoIndex); // настраиваем индексацию элементов
    scene->setSceneRect(0,0,500,500); // Устанавливаем размер сцены

    socket = new QTcpSocket(this);
    connect(socket,&QTcpSocket::readyRead,this,&MainWindow::slotReadyRead);
    connect(socket,&QTcpSocket::disconnected,socket,&QTcpSocket::deleteLater);
    nextBlockSize  = 0;


    scene->addItem(static_settings_item);
    connect(static_settings_item, &MoveItem::selectionChanged, this, &MainWindow::define_order);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_open_triggered()
{
    QString str = QFileDialog::getExistingDirectory(0, "Choose file", "");
}


void MainWindow::on_open_filters_clicked()
{
    open_settings();
}


void MainWindow::on_close_filters_clicked()
{
    close_filter();
}


void MainWindow::on_calculate_clicked()
{
    calculate_pattern();
}


void MainWindow::on_set_button_clicked()
{
    add_pattern_on_scene();
}


void MainWindow::on_delete_button_clicked()
{
    delete_item();
}


void MainWindow::settings_filter()
{

}


void MainWindow::on_save_filters_clicked()
{
    QSettings settings("MyCompany", "MyApp");
    for (int i = 0; i < ui->filters->count(); i++)
    {
        QString myValue = settings.value("MyParameter", "").toString();
        qDebug() << myValue;
       // out << ui->filters->item(i)->text() << "\n";
    }
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


void MainWindow::add_pattern_on_scene()
{
    enum Color {
        RED,
        GREEN,
        BLUE,
        YELLOW
    };
    //Ограничение амплитуды, стянуть к оси,  фильтр 1, фильтр 2
    QColor color_list[] = { QColor("#FF0000"), QColor("#00FF00"), QColor("#0000FF"), QColor("#FFFF00"), QColor("#FFFFFF") };
    QString filter_name[] = { "Ограничение амплитуды", "стянуть к оси", "фильтр 1", "фильтр 2", "Конец"};


    QTreeWidgetItem* current_item = ui->filters_information->currentItem();
    if (!current_item)
        return;
    int color_number = ui->filters_information->currentIndex().row();
    QColor my_color = color_list[color_number];

    MoveItem* filter_item = new MoveItem();
    item_list.push_back(filter_item);
    //qDebug() << item_list.size() << "\n";

    filter_item->setColor(my_color);
    filter_item->set_name(filter_name[color_number]);
    filter_item->setData(Qt::UserRole, filter_name[color_number]);

    scene->addItem(filter_item);
    //connect(filter_item, &MoveItem::selectionChanged, this, &MainWindow::paint_filters);


    connect(filter_item, &MoveItem::itemMoved, this, &MainWindow::ReDrawLines);
    //ReDrawLines2();

    connect(filter_item, &MoveItem::itemSelected, this, &MainWindow::set_selected_item); // связь с кнопкой удалить
    connect(filter_item, &MoveItem::selectionChanged, this, &MainWindow::define_order); // связь с порядком связи шаблонов
}


void MainWindow::ReDrawLines()
{
    for (int i = 0; i < line_list.size(); i++)
    {
        scene->removeItem(line_list[i]);
    }
    line_list.clear();
    for (int i = 0; i < item_list_in_order.size() - 1; i++)
    {
        QPointF center_1 = item_list_in_order[i]->pos() + QPointF(item_list_in_order[i]->childrenBoundingRect().width() / 2.0, item_list_in_order[i]->childrenBoundingRect().height() / 2.0);
        QPointF center_2 = item_list_in_order[i + 1]->pos() + QPointF(item_list_in_order[i + 1]->childrenBoundingRect().width() / 2.0, item_list_in_order[i + 1]->childrenBoundingRect().height() / 2.0);
        QGraphicsLineItem* connect_line = new QGraphicsLineItem(0, 0, 50, 50);
        scene->addItem(connect_line);
        connect_line->setZValue(-1);
        connect_line->setLine(QLineF(center_1, center_2));
        line_list.push_back(connect_line);
    }
}

void MainWindow::ReDrawLines2()
{
    for (int i = 0; i < line_list.size(); i++)
    {
        scene->removeItem(line_list[i]);
    }
    line_list.clear();
    for (int i = 0; i < item_list.size() - 1; i++)
    {
        QPointF center_1 = item_list[i]->pos() + QPointF(item_list[i]->childrenBoundingRect().width() / 2.0, item_list[i]->childrenBoundingRect().height() / 2.0);
        QPointF center_2 = item_list[i + 1]->pos() + QPointF(item_list[i + 1]->childrenBoundingRect().width() / 2.0, item_list[i + 1]->childrenBoundingRect().height() / 2.0);
        QGraphicsLineItem* connect_line = new QGraphicsLineItem(0, 0, 50, 50);
        scene->addItem(connect_line);
        connect_line->setZValue(-1);
        connect_line->setLine(QLineF(center_1, center_2));
        line_list.push_back(connect_line);
    }
}

void MainWindow::define_order(MoveItem* item)
{
    qDebug() << "Сука";
    for (int i = 0; i < item_list_in_order.size(); ++i)
    {
        if (item == item_list_in_order[i])
        {
                if (m_first_selected == nullptr)
                {
                    m_first_selected = item;
                    return;
                }
                else if (m_first_selected == item)
                {
                    m_first_selected = nullptr;
                    return;
                }
                else if (m_first_selected && m_second_selected == nullptr)
                {
                    m_second_selected = item;
                    m_second_inside_orader = true;
                    break;
                }
        }
    }
    if (m_first_selected && m_second_selected == nullptr)
    {
        m_second_selected = item;
        m_second_inside_orader = false;
    }
    if (m_second_inside_orader)
    {
        int first = 0, second = 0;
        for (int i = 0; i < item_list_in_order.size(); ++i)
        {
                if (m_first_selected == item_list_in_order[i])
                    first = i;
                if (m_second_selected == item_list_in_order[i])
                    second = i;
        }
        item_list_in_order.remove(second);
        if (first < item_list_in_order.size() - 1)
                item_list_in_order.insert(first + 1, m_second_selected);
        else
                item_list_in_order.append(m_second_selected);
    }
    else
    {
        for (int i = 0; i < item_list_in_order.size(); ++i)
        {
                if (m_first_selected == item_list_in_order[i])
                {
                    if (i < item_list_in_order.size() - 1)
                        item_list_in_order.insert(i + 1, m_second_selected);
                    else
                        item_list_in_order.append(m_second_selected);
                }

        }
    }
    m_first_selected = nullptr;
    m_second_selected = nullptr;
    qDebug() << item_list_in_order.size();
    ReDrawLines();
}


void MainWindow::calculate_pattern()
{
    //qDebug() << socket-> isValid();
    socket->connectToHost("127.0.0.1",3230);

    QString path_file = "C:\\c++\\AKIP0002.csv";
    QString pattern_path = "C:\\c++\\AKIP0001.csv";
    QString result_path = "C:\\c++\\AKIP0001.csv";

    path_file += "$";
    path_file += pattern_path;
    path_file += "$";
    path_file += result_path;
    SendToServer(path_file);
}


void MainWindow::SendToServer(QString str)
{
    Data.clear();
    QDataStream out(&Data,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out<< quint16(0)<<str;
    out.device()->seek(0);
    out<<quint16(Data.size()-sizeof(quint16));
    socket->write(Data);
}


void MainWindow::slotReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    if(in.status() == QDataStream::Ok )
    {
        for(;;)
        {
            if(nextBlockSize == 0)
            {
                if(socket->bytesAvailable() < nextBlockSize)
                    break;

                in >> nextBlockSize;
            }
            if (socket->bytesAvailable() < nextBlockSize)
            {
                break;
            }
            QString str;
            in >>str;
            nextBlockSize = 0;
            if (str == "complete")
            {
                GraphWidget* plot = new GraphWidget(this);
                plot->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
                plot->setWindowTitle("График");
                plot->show();
            }
            qDebug() << str;
            break;
        }

    }
    else
    {
       qDebug() << "read error";
    }
}


void MainWindow::on_filters_itemChanged(QListWidgetItem *item)
{
    QString itemText = item->text();

    // Создать QSettings объект
    QSettings settings("MyCompany", "MyApp");

    // Сохранить itemText в качестве значения параметра
    settings.setValue("MyParameter", itemText);

    qDebug() << "Value entered: " << itemText;
}


void MainWindow::set_selected_item(MoveItem *item)
{
    this->m_selected_item = item;
}


void MainWindow::delete_item()
{
    if (m_selected_item)
    {
       for (int i = 0; i < item_list.size(); ++i)
       {
            if (m_selected_item == item_list[i])
            {
                item_list.remove(i);
                break;
            }
       }
       for (int i = 0; i < item_list_in_order.size(); ++i)
       {
            if (m_selected_item == item_list_in_order[i])
            {
                item_list_in_order.remove(i);
                break;
            }
       }
       m_selected_item->deleteLater();
       m_selected_item = nullptr;
    }
    ReDrawLines();
}


void MainWindow::open_settings()
{
    if (m_selected_item && ui->filters->count() == 0)
    {
        QWidget *widget = new QWidget();
        QHBoxLayout *layout = new QHBoxLayout(widget);  // создаем горизонтальный QHBoxLayout
        QLabel *label = new QLabel(m_selected_item->get_name());
        qDebug() << m_selected_item->get_name();
        QLineEdit *lineEdit = new QLineEdit;
        layout->addWidget(label);
        layout->addWidget(lineEdit);


        QListWidgetItem *newItem = new QListWidgetItem();
        newItem->setSizeHint(widget->sizeHint());
        //newItem->setFlags(newItem->flags() | Qt::ItemIsEditable);
        ui->filters->addItem(newItem);
        ui->filters->setItemWidget(newItem, widget);
        qDebug() << "Ура";

        connect(ui->filters, &QListWidget::itemChanged, this, &MainWindow::on_filters_itemChanged);
    }
}


void MainWindow::close_filter()
{
    // Получаем количество элементов в QListWidget
    int count = ui->filters->count();

    // Удаляем элементы из QListWidget в цикле
    for(int i = 0; i < count; ++i) {
        QListWidgetItem* item = ui->filters->takeItem(0); // Удаляем элемент с индексом 0
        delete item; // Удаляем объект QListWidgetItem из памяти
    }
}

