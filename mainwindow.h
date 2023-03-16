#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>

#include <move_item.h>

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


    void on_add_pattern_clicked();

private:
    Ui::MainWindow* ui;
    QGraphicsScene* scene;
};
#endif // MAINWINDOW_H
