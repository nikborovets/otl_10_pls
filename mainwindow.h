#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QSettings>
#include <QString>

#include <QSqlTableModel>
#include <DataBase.h>

#include <QTcpSocket>

#include "move_item.h"
#include "MyPlot.h"

#define SETTINGS "settings"
#define PULL_TO_AXIS "стянуть к оси"
#define LIMIT_AMPLITUDE "Ограничение амплитуды"
#define FILTER_1 "фильтр 1"
#define FILTER_2 "фильтр 2"
#define END "конец"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{

    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_open_triggered();
    void on_save_filters_clicked(QString s1,QString s2);
    void on_push_button_clicked();
    void on_set_button_clicked();
    void on_close_filters_clicked();
    void on_calculate_clicked();
    void on_delete_button_clicked();
    void on_open_filters_clicked();
    void on_copy_button_clicked();

    void on_filters_itemChanged(QListWidgetItem *item);

    void slotReadyRead();

    void settings_filter();
    void delete_item();
    void open_settings();
    void set_selected_item(MoveItem *item);
    void define_order(MoveItem* item);
    void add_pattern_on_scene();
    void calculate_pattern();
    void close_filter();
    void ReDrawLines();
    void insert_copy();

    void write_pattern();
    void read_pattern(QString path);

    void on_save_pattern_clicked();

private:
    Ui::MainWindow* ui;
    QGraphicsScene* scene;

    QSettings* shish;
    GraphWidget* plot;

    DataBase* db;
    QSqlTableModel* modelDevice;

    QVector<MoveItem*> item_list; // вектор объектов
    QVector<QGraphicsLineItem*> line_list;
    QVector<MoveItem*> item_list_in_order; //В каком порядке идут объекты

    MoveItem* m_selected_item = nullptr;
    MoveItem* m_first_selected = nullptr; // первый выбранный филтр для соединения
    MoveItem* m_second_selected = nullptr; // второй выбранный филтр для соединения

    MoveItem* m_moderation_item = nullptr;
    bool m_second_inside_orader = false;

//  client code

    QTcpSocket *socket;
    QByteArray Data;
    void SendToServer(QString str);
    quint16 nextBlockSize;


//
};

#endif // MAINWINDOW_H
