#ifndef MYPLOT_H
#define MYPLOT_H

#include <QWidget>

#include "qcustomplot.h"

class GraphWidget: public QWidget
{

    Q_OBJECT

public:
    GraphWidget(QWidget* parent = nullptr);

private:
    QWidget* m_widget;
    double xBegin, xEnd, yBegin, yEnd, h;
    int N;
    QVector<double> x,y;

    QCustomPlot* m_plot;
};


#endif // MYPLOT_H
