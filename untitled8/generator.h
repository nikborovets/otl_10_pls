#ifndef GENERATOR_H
#define GENERATOR_H

#include <fstream>
#include <string>
#include <iostream>
#include <QVector>
#include <QString>
#include <cmath>
#include <QRegExp>

class GENERATOR
{
    QVector<double> x;
    QVector<double>  y;
    QVector<double>  dydx;

    QString x_head;
    QString y_head;


    void amplitude(double max_val , double min_val);
    void amplitude(double max_val);
    void c_function(std::string &path, QVector<double> &params);
    void graph_multiplication(double k);

    void derivative();
    void scan();
    void printfile();

public:
    GENERATOR(std::string &s, std::string &s1);
    GENERATOR(std::string &s);
    GENERATOR();
    // временно
    std::string path_file;
    std::string path_pattern;
    std::string path_result;
    //
    void fill(QString str);
    void clear();
    bool ready();
    void produce();
    void change_path_file(std::string &path);
    void change_path_pattern(std::string &path);
    void change_path_result(std::string &path);
};




#endif // GENERATOR_H
