#include <QCoreApplication>
#include <iostream>
#include "generator.h"
using namespace std;






int main()
{
    string s = "/home/ilay_kar/Документы/untitled7/AKIP0001.csv";
    GENERATOR a;
    a.scan(s);
    a.amplitude(0.0009);
    a.printfile();
    return 0;

}
