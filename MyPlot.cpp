#include <QApplication>
#include <fstream>
#include <iostream>
#include <QTextStream>
//#include <QText>
#include <QDebug>

#include "MyPlot.h"


void scan(std::string path_file, QVector<double> &x, QVector<double> &y)
{
    x.clear();
    y.clear();

    std::string line;
    std::ifstream in1(path_file);
    if (in1.is_open())
    {
        std::getline(in1, line);
        std::string a;
        std::string b;
        for(int j = 0; j < line.size(); j++)
        {
            if (line[j]==',')
                path_file = line.substr(0, j);
        }
        std::getline(in1, line);
        for(int l = 0; l < 100; l++)
        {
            std::getline(in1, line);
            for(int i = 0; i < line.size(); i++)
            {
                if (line[i] == ',')
                {
                    a = line.substr(0, i);
                    b = line.substr(i + 1, line.size() - i);

                }
            }

            std::cout << a << " " << std::stod(b) << "\n";
            x.push_back(QString::fromStdString(a).toDouble());
            y.push_back(QString::fromStdString(b).toDouble());
        }
     }
    in1.close();
}

GraphWidget::GraphWidget(QWidget* parent)
    : QWidget(parent)
{
    std::string fpath = "C://c++//AKIP0001.csv";
    // Создаем экземпляр QCustomPlot
    m_plot = new QCustomPlot(this);

    // Добавляем элементы для масштабирования
    m_plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    QPushButton* button = new QPushButton("Обновить график", this);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(m_plot);
    layout->addWidget(button);

    // Устанавливаем размеры виджета
    setFixedSize(640, 480);

    // Создаем график
    QCPGraph* graph = m_plot->addGraph();

    scan(fpath, this->x, this->y);
    qDebug() << x << y;

    graph->setPen(QPen(Qt::blue));
    graph->setBrush(QBrush(QColor(0, 0, 255, 20)));

    graph->setData(x, y);

    // Масштабируем график
    m_plot->rescaleAxes();
    m_plot->replot();

    connect(button, &QPushButton::clicked, this, [this](){
        // Обновляем график случайными данными


        m_plot->graph(0)->setData(x, y);
        m_plot->rescaleAxes();
        m_plot->replot();
    });

}
