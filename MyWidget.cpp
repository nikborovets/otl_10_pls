#include "MyWidget.h"

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    QLabel* label = new QLabel("Частота:", this);
    QLineEdit* edit = new QLineEdit(this);
    QPushButton* button = new QPushButton("OK", this);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(label);
    layout->addWidget(edit);
    layout->addWidget(button);

    connect(button, &QPushButton::clicked, this, [=]() {

    });
}
