#ifndef GENERATOR_H
#define GENERATOR_H

#include <fstream>
#include <string>
#include <iostream>
#include <QVector>
#include <QString>
#include <cmath>


class GENERATOR
{
    QVector<double> x;
    QVector<double>  y;
    QVector<double>  dydx;
    QString x_head;
    QString y_head;
    std::string path_file;
    std::string path_pattern;

public:
    GENERATOR(std::string &s,std::string &s1);
    GENERATOR(std::string &s);
    void scan();
    void printfile();
    void c_function(std::string &path,QVector<double> &params);
    void amplitude(double max_val ,double min_val);
    void graph_multiplication(double k);
    void amplitude(double max_val);
    void derivative();
};




#endif // GENERATOR_H
