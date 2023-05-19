#include "generator.h"
#include "qdebug.h"
#include "QFile"
GENERATOR::GENERATOR(std::string &s,std::string &s1)
{
    this->path_file = s;
    this->path_pattern = s1;
    this->path_result = "";
}

GENERATOR::GENERATOR(std::string &s)
{
    this->path_file = s;
    this->path_pattern = "";
    this->path_result = "";
}

GENERATOR::GENERATOR()
{
    this->path_file = "";
    this->path_pattern = "";
    this->path_result = "";
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
        for(int j = 0;j < line.size();j++)
        {
            if (line[j] == ',')
            {
                a = line.substr(0,j);
                b = line.substr(j+1,line.size()-j);
                x_head = QString::fromStdString(a);
                y_head = QString::fromStdString(b);
                break;
            }
        }


        int i = 0;
        while(std::getline(in1, line))
        {

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
    QFile f(QString::fromStdString(this->path_result));
    if (f.open(QIODevice::Append | QIODevice::Text))
    {
                QTextStream out(&f);
                out << x_head << " " << y_head << '\n';
                for(long i =0; i < x.size(); i++)
                {

                    out << x[i] << "," << y[i] << '\n';
                }
    }
    else {
                qDebug() << "Файл не открыт\n";
    }
};

void GENERATOR::derivative()
{
    dydx.push_back((this->y[1] - this->y[0]) / (this->x[1] - this->x[0]));
    for (size_t i = 1; i < this->y.size(); ++i)
    {
        dydx.push_back((this->y[i] - this->y[i - 1]) / (this->x[i] - this->x[i - 1]));
    }
};

#define SETTINGS "settings"
#define PULL_TO_AXIS "multiply"
#define LIMIT_AMPLITUDE "amplitude"
#define FILTER_1 "filter_1"
#define FILTER_2 "filter_2"
#define END "end"

void GENERATOR::produce()
{

    if (not(  this->path_file.size() == 0))
    {
        this->scan();
    }
    if (not(  this->path_pattern.size() == 0))
    {
        QFile file(QString::fromStdString(this->path_pattern));
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);
            while (!in.atEnd())
            {
                QString line = in.readLine(); // читаем строку из файла
                QStringList words = line.split(" "); // разбиваем на слова
                QString label = words.at(0);
                if (label == SETTINGS)
                    continue;
                else if (label == PULL_TO_AXIS)
                    graph_multiplication(words.at(1).toDouble());
                else if (label == LIMIT_AMPLITUDE)
                    amplitude(words.at(1).toDouble());
                else if (label == FILTER_1)
                    continue;
                else if (label == FILTER_2)
                    continue;
                else if (label == END)
                    break;
            }

        }
    }


    this->printfile();
};

void GENERATOR::clear()
{
    this->path_file = "";
    this->path_pattern = "";
    this->path_result = "";
}

bool GENERATOR::ready()
{
    if ( (path_file != "") and (path_pattern != "") and (path_result != "") )
        return true;
    return false;
}

void GENERATOR::fill(QString str)
{
    QStringList l = str.split("$");

    path_file = l[0].toStdString();
    path_pattern = l[1].toStdString();
    path_result = l[2].toStdString();
    return;
}

void GENERATOR::change_path_file(std::string &path)
{
    this->path_file = path;
}

void GENERATOR::change_path_pattern(std::string &path)
{
    this->path_pattern = path;
}

void GENERATOR::change_path_result(std::string &path)
{
    this->path_result = path;
}
