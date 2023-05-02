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
    void paint_filters(const QString& value);

private slots:
    void on_action_open_triggered();
    void on_action_remove_triggered();

    void on_add_pattern_2_clicked();

    void on_push_button_clicked();

    void on_set_button_clicked();




    void on_calculate_clicked();

private:
    Ui::MainWindow* ui;
    QGraphicsScene* scene;

    MoveItem* my_item;

    QSettings* shish;
    GraphWidget* plot;

    DataBase* db;
    QSqlTableModel* modelDevice;

//  client code

    QTcpSocket *socket;
    QByteArray Data;
    void SendToServer(QString str);
    quint16 nextBlockSize;
public slots:
    void slotReadyRead();
//
};

#endif // MAINWINDOW_H
