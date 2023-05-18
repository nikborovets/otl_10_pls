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
    void on_action_remove_triggered();
    void on_save_filters_clicked();
    void on_push_button_clicked();
    void on_set_button_clicked();
    void ReDrawLines();
    void on_calculate_clicked();

    void slotReadyRead();

    void paint_filters(const QString& value);
    void settings_filter();
    void setSelectedItem(MoveItem *item);


    void on_filters_itemChanged(QListWidgetItem *item);

    void on_delete_button_clicked();

    void delete_item();

private:
    Ui::MainWindow* ui;
    QGraphicsScene* scene;

    QSettings* shish;
    GraphWidget* plot;

    DataBase* db;
    QSqlTableModel* modelDevice;

    QVector<MoveItem*> item_list;
    QVector<QGraphicsLineItem*> line_list;

    MoveItem* m_selected_item = nullptr;

//  client code

    QTcpSocket *socket;
    QByteArray Data;
    void SendToServer(QString str);
    quint16 nextBlockSize;


//
};

#endif // MAINWINDOW_H
