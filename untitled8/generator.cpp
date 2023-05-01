#include "generator.h"
#include "qdebug.h"

GENERATOR::GENERATOR(std::string &s,std::string &s1)
{
    this->path_file = s;
    this->path_pattern = s1;
}

GENERATOR::GENERATOR(std::string &s)
{
    this->path_file = s;
}

void GENERATOR::scan()
{
    std::string line;
    std::ifstream in1(this->path_file);
    if (in1.is_open())
    {
        std::getline(in1, line);
        std::string a;
        std::string b;
        for(int j =0;j<line.size();j++)
        {
            if (line[j]==',')
            {
                a = line.substr(0,j);
                b = line.substr(j+1,line.size()-j);
                x_head = QString::fromStdString(a);
                y_head = QString::fromStdString(b);
                break;
            }
        }


        int i = 0;
        while(i<20000)
        {
            std::getline(in1, line);
            for(int j =0;j<line.size();j++)
            {
                if (line[j]==',')
                {
                    a = line.substr(0,j);
                    b = line.substr(j+1,line.size()-j);
                }
            }
            this->x.push_back(std::stod(a));
            this->y.push_back(std::stod(b));
            i++;
         }

     }
    in1.close();
}

void GENERATOR::amplitude(double max_val ,double min_val)
{
    double c = x.size()-1;
    int j = 0;
    for(long i =0 ; i < c ;i++)
    {
        if (not((abs(y[j]) <= max_val) and (abs(y[j]) >= min_val)))
        {
            qDebug()<<i;
            y.remove(j);
            x.remove(j);
            j--;
        }
        j++;
    }
    if (not((abs(y[y.size()-1]) <= max_val) and (abs(y[y.size()-1]) >= min_val)))
    {
        x.remove(y.size()-1);
        y.remove(y.size()-1);
    }
};

void GENERATOR::amplitude(double max_val)
{
    this->amplitude(max_val, 0);
}

void GENERATOR::graph_multiplication(double k)
{
    double c = 0;
    for(long i =0; i < this->x.size(); i++)
    {
        c = this->y[i];
        c = c * k;
        this->y[i] = c;
    }
};

void GENERATOR::printfile()
{
    std::ofstream out;
    out.open("C://c++//AKIP0001.csv");
    if (out.is_open())
    {
        qDebug()<<"QWQQWQW";
        out << x_head.toStdString() << " " << y_head.toStdString() << '\n';
        for(long i =0; i < x.size(); i++)
                {

                    out << x[i] << "," << y[i] << '\n';
                }
    }
    out.close();
};

void GENERATOR::derivative()
{
    dydx.push_back((this->y[1] - this->y[0]) / (this->x[1] - this->x[0]));
    for (size_t i = 1; i < this->y.size(); ++i)
    {
        dydx.push_back((this->y[i] - this->y[i - 1]) / (this->x[i] - this->x[i - 1]));
    }
};

void GENERATOR::produce()
{

    if (not(  this->path_file.size() == 0))
    {
        this->scan();
    }
    if (true
        //    not(  this->path_pattern.size() == 0)
       )
    {
        //this->amplitude(0.0009);
        this->graph_multiplication(4);
    }

    this->printfile();
};

void GENERATOR::change_path_file(std::string &path)
{
    this->path_file = path;
}

