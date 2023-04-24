#include <QCoreApplication>
#include <iostream>
#include "generator.h"
#include <windows.h>
using namespace std;






int main()
{
    string s = "C://c++//AKIP0001.csv";
    string s2;
    GENERATOR a(s);
    a.produce();
    std::cout << " " << s2 <<"\n";
    return 0;
}
