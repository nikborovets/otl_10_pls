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
    QString x_head;
    QString y_head;
    std::string path_file;
    std::string path_pattern;

public:
    GENERATOR(std::string &s);
    void scan(std::string &s);
    void printfile();
    void c_function(std::string &path,QVector<double> &params);
    void amplitude(double max_val ,double min_val);
    void amplitude(double max_val);
};




#endif // GENERATOR_H
