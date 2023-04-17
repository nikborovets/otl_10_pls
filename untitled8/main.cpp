#include <QCoreApplication>
#include <iostream>
#include "generator.h"
using namespace std;






int main()
{
    string s = "/home/ilay_kar/Документы/untitled7/AKIP0001.csv";
    GENERATOR a(s);
    a.produce();
    //a.scan();
    //a.amplitude(0.0009);
    //a.graph_multiplication(4);
    //a.printfile();
    return 0;
}
