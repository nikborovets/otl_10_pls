#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QSettings>
#include <QString>


#include "move_item.h"


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


    void on_add_pattern_clicked();

    void on_push_button_clicked();

private:
    Ui::MainWindow* ui;
    QGraphicsScene* scene;

    QSettings* shish;
};

#endif // MAINWINDOW_H
