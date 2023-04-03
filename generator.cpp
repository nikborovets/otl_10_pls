#include "generator.h"

GENERATOR::GENERATOR(std::string &s,std::string &s1)
{
    this->path_file = s;
    this->path_pattern = s1;
}


void GENERATOR::scan()
{
    std::string line;
    long double a,b;
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
                this->path_file = line.substr(0,j);
                this->path_pattern = line.substr(j+1,line.size()-j);
            }
        }
        std::getline(in1, line);
        for(int l =0;l<1000;l++)
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
        }
     }
    in1.close();
}


void GENERATOR::amplitude(double max_val ,double min_val)
{
    double c = x[x.size()-1];
    for(long i =0;x[i] != c;i++)
    {
        if (not((abs(y[i])<=max_val)and(abs(y[i])>=min_val)))
        {
            y.remove(i);
            x.remove(i);
            i--;
        }
    }
    if (not((abs(y[y.size()-1])<=max_val)and(abs(y[y.size()-1])>=min_val)))
    {
        x.remove(y.size()-1);
        y.remove(y.size()-1);
    }
};

void GENERATOR::amplitude(double max_val)
{
    this->amplitude(max_val,0);
}


void GENERATOR::printfile()
{
for(long i =0;i < x.size();i++)
        std::cout<<x[i]<<" "<<y[i]<<'\n';
std::cout<<x.size()<<'\n';
};
