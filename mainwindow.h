#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include <move_item.h>


class Settings
{
public:

    char* get_path() const;
    void set_path(char* path);

private:
    char *path;

};

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

    void on_pushButton_clicked();

private:
    Ui::MainWindow* ui;
    QGraphicsScene* scene;

    Settings* shish;
};

#endif // MAINWINDOW_H
