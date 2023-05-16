#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QFileDialog>

class MyWidget : public QWidget {
public:
    MyWidget(QWidget* parent = 0);
};


#endif // MYWIDGET_H
