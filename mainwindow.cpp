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

    MoveItem* static_settings_item = new MoveItem(); // начало
    item_list.push_back(static_settings_item);
    item_list_in_order.push_back(static_settings_item);
    static_settings_item->setColor(Qt::gray);
    static_settings_item->setData(Qt::UserRole, "settings");
    static_settings_item->set_name("settings");

    MoveItem* static_end_item = new MoveItem();
    item_list.push_back(static_end_item);
    item_list_in_order.push_back(static_end_item);
    static_end_item->setColor(Qt::gray);
    static_end_item->setData(Qt::UserRole, "конец");
    static_end_item->set_name("конец");

    db = new DataBase();
    db->connectToDataBase();

    scene = new QGraphicsScene(this);   // Инициализируем графическую сцену
    ui->graphics_view->setScene(scene); //  Устанавливаем графическую сцену в graphics_view
    scene->setItemIndexMethod(QGraphicsScene::NoIndex); // настраиваем индексацию элементов
    scene->setSceneRect(0, 0, 300, 300); // Устанавливаем размер сцены

    socket = new QTcpSocket(this);
    connect(socket,&QTcpSocket::readyRead,this,&MainWindow::slotReadyRead);
    connect(socket,&QTcpSocket::disconnected,socket,&QTcpSocket::deleteLater);
    nextBlockSize  = 0;


    scene->addItem(static_settings_item);
    scene->addItem(static_end_item);

    connect(static_settings_item, &MoveItem::selectionChanged, this, &MainWindow::define_order);
    connect(static_end_item, &MoveItem::selectionChanged, this, &MainWindow::define_order);
    connect(static_settings_item, &MoveItem::itemMoved, this, &MainWindow::ReDrawLines);
    connect(static_end_item, &MoveItem::itemMoved, this, &MainWindow::ReDrawLines);
    connect(static_settings_item, &MoveItem::itemSelected, this, &MainWindow::set_selected_item);
    connect(static_end_item, &MoveItem::itemSelected, this, &MainWindow::set_selected_item);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_open_triggered()
{
    QString str = QFileDialog::getExistingDirectory(0, "Choose file", "");
    read_pattern(str);
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


void MainWindow::on_save_filters_clicked(QString s1,QString s2)
{ 
    m_moderation_item->set_value(s1, s2);
    qDebug()<<s1<<" "<<s2;
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

    QString filter_name[] = { "Ограничение амплитуды", "стянуть к оси", "фильтр 1", "фильтр 2"};


    QTreeWidgetItem* current_item = ui->filters_information->currentItem();
    if (!current_item)
        return;
    int order_number = ui->filters_information->currentIndex().row();

    MoveItem* filter_item = new MoveItem();
    item_list.push_back(filter_item);
    //qDebug() << item_list.size() << "\n";

    filter_item->set_name(filter_name[order_number]);
    filter_item->setData(Qt::UserRole, filter_name[order_number]);
    filter_item->setToolTip(filter_name[order_number]);

    scene->addItem(filter_item);
    //connect(filter_item, &MoveItem::selectionChanged, this, &MainWindow::paint_filters);


    connect(filter_item, &MoveItem::itemMoved, this, &MainWindow::ReDrawLines);
    //ReDrawLines();

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


void MainWindow::define_order(MoveItem* item)
{
    for (int i = 0; i < item_list_in_order.size(); ++i)
    {
        if (item == item_list_in_order[i])
        {
                if (m_first_selected == nullptr && i < item_list_in_order.size() - 1)
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
        if (first > second)
        {
            m_second_selected = nullptr;
            return;
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
    ReDrawLines();
}


void MainWindow::calculate_pattern()
{
    //qDebug() << socket-> isValid();
    socket->connectToHost("127.0.0.1", 3230);

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
    //QSettings settings("MyCompany", "MyApp");

    // Сохранить itemText в качестве значения параметра
    //settings.setValue("MyParameter", itemText);

    qDebug() << "Value entered: " << itemText;
}


void MainWindow::set_selected_item(MoveItem *item)
{
    this->m_selected_item = item;
}


void MainWindow::delete_item()
{
    if (m_selected_item && m_selected_item != item_list_in_order[0] && m_selected_item != item_list_in_order[item_list_in_order.size() - 1])
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


QString MainWindow::open_dialog()
{
    // Создаем диалоговое окно
    QDialog *inputDialog = new QDialog(this);
    // Задаем название окна
    inputDialog->setWindowTitle("Название шаблона");
    // Создаем поле для ввода текста
    QLineEdit *lineEdit = new QLineEdit(inputDialog);
    // Задаем начальное значение поля
    lineEdit->setText("0");
    // Создаем кнопки "OK" и "Cancel"
    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, inputDialog);
    // Подключаем сигналы от кнопок к слотам обработки событий
    connect(buttonBox, &QDialogButtonBox::accepted, inputDialog, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, inputDialog, &QDialog::reject);
    // Создаем вертикальный layout и добавляем на форму
    QVBoxLayout *layout = new QVBoxLayout(inputDialog);
    layout->addWidget(lineEdit);
    layout->addWidget(buttonBox);
    // Устанавливаем вертикальный layout
    inputDialog->setLayout(layout);
    // Отображаем диалоговое окно и ожидаем его закрытия
    QString value;
    if(inputDialog->exec() == QDialog::Accepted) {
       value = lineEdit->text();
    }
    delete inputDialog;
    return value;
}


void MainWindow::open_settings()
{

    if (m_selected_item && ui->filters->count() == 0)
    {
        m_moderation_item = m_selected_item;
        QWidget *widget = new QWidget();
        QHBoxLayout *layout = new QHBoxLayout(widget);  // создаем горизонтальный QHBoxLayout
        QLabel *label = new QLabel(m_moderation_item->get_name());
        //qDebug() << m_moderation_item->get_name();
        QLineEdit *lineEdit = new QLineEdit();
        layout->addWidget(label);
        layout->addWidget(lineEdit);


        QListWidgetItem *newItem = new QListWidgetItem();
        newItem->setSizeHint(widget->sizeHint());
        newItem->setFlags(newItem->flags() | Qt::ItemIsEditable);
        ui->filters->addItem(newItem);
        ui->filters->setItemWidget(newItem, widget);
        //qDebug() << "Ура";

        //connect(ui->filters, &QListWidget::itemChanged, this, &MainWindow::on_filters_itemChanged);
        QPair<QLabel*, QLineEdit*> values = {label, lineEdit};
        ui->filters->item(0)->setText(lineEdit->text());
        lineEdit->setText(m_moderation_item->get_values(m_moderation_item->get_name()));

        connect(lineEdit, &QLineEdit::editingFinished, this, [=]() {
            on_save_filters_clicked(label->text(), lineEdit->text());
        });

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


void MainWindow::on_copy_button_clicked()
{
    insert_copy();
}


void MainWindow::insert_copy()
{

}


#define SETTINGS "settings"
#define PULL_TO_AXIS "стянуть к оси"
#define LIMIT_AMPLITUDE "Ограничение амплитуды"
#define FILTER_1 "фильтр 1"
#define FILTER_2 "фильтр 2"
#define END "конец"


void MainWindow::write_pattern(QString path)
{
    path += ".txt";
    QFile file(path);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        for (int i = 0; i < item_list_in_order.size(); ++i)
        {
            QString label = item_list_in_order[i]->get_name();
            if (label == SETTINGS)
                out << "settings" << " " << item_list_in_order[i]->get_values(label) << "\n";
            else if (label == PULL_TO_AXIS)
                out << "multiply" << " " << item_list_in_order[i]->get_values(label) << "\n";
            else if (label == LIMIT_AMPLITUDE)
                out << "amplitude" << " " << item_list_in_order[i]->get_values(label) << "\n";
            else if (label == FILTER_1)
                out << "filter_1" << " " << item_list_in_order[i]->get_values(label) << "\n";
            else if (label == FILTER_2)
                out << "filter_2" << " " << item_list_in_order[i]->get_values(label) << "\n";
            else if (label == END)
                out << "end" << " " << item_list_in_order[i]->get_values(label) << "\n";
        }
    }
    else {
        qDebug() << "Файл не открыт\n";
    }
}

void MainWindow::read_pattern(QString path)
{
    QFile file(path);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file); // Создание потока для чтения данных
        QString line = in.readLine(); // Чтение первой строки из файла
        // Обработка данных
        file.close(); // Закрытие файла
    }
}


void MainWindow::on_save_pattern_clicked()
{
    write_pattern(open_dialog());
}


