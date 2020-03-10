//
//  main.cpp
//  Pro1
//
//  Created by Thazin, Thin on 3/10/20.
//  Copyright © 2020 Thazin, Thin. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int maxGross = 0;
int avrg = 0;
int sum = 0;
int total = 0;

class Employee
{
public:
    Employee(string &n);
    Employee(int &i, int &r, int &w);
    Employee();
    void setName(string &n);
    void set(int &i, int &r, int &w);
    string getName();
    int getId();
    int getRate();
    int getWork();
    void input(ifstream &inFile);
    void output();
private:
    string name;
    int id;
    int hourlyRate;
    int hourWork;
    int grossPay;
};

void Employee::input(ifstream &inFile)
{
    if(inFile.is_open())
    {
        inFile >> name >> id >> hourlyRate >> hourWork;
    }
    else
        cout<< "The file does not exit. " << endl;
}
void Employee::output()
{
    this->grossPay = this->hourlyRate * this->hourWork;
    if (maxGross < this->grossPay)
    {
        maxGross = this->grossPay;
    }
    cout <<  name << setw(10) << id  << setw(10) <<  hourlyRate << setw(10) <<hourWork << setw(10) << grossPay<< endl;
}

int main(int argc, const char * argv[])
{
    Employee data[5];
    ifstream inFile;
    
    inFile.open("Project 3.dat");
    
    for(int i =0; i < 5; i++)
    {
        data[i].input(inFile);
    }
    cout <<  "Name" << "\t\t" << "ID"  << "\t\t" <<  "Hourly Rate" <<"\t" << "Hours Work" << "\t" << "Gross Pay"<< endl;
    for(int i =0; i < 5; i++)
    {
        data[i].output();
    }
    for(int i =0; i < 5; i++)
    {
        sum = data[i].getRate() * data[i].getWork();
        total = total + sum;
    }
    cout << endl;
    
    avrg = total /5;
    inFile.close();
    cout << "Hightest gross pay of the company: " << maxGross << endl;
    cout << "Average gross pay of the company: " << avrg << endl;
    cout<< endl;
    
    system("pause");
    return 0;
}
void Employee::set(int &i, int &r, int &w)
{
    id = i;
    hourlyRate = r;
    hourWork = w;
}
void Employee::setName(string &n)
{
    name = n;
}
int Employee::getId()
{
    return id;
}
int Employee::getRate()
{
    return hourlyRate;
}
int Employee::getWork()
{
    return hourWork;
}
string Employee::getName()
{
    return name;
}
Employee::Employee(string &n)
{
    setName(n);
}
Employee::Employee(int &i, int &r, int &w)
{
    set(i, r, w);
}
//Default Constructor
Employee::Employee()
{
    name = "";
    id = 0;
    hourlyRate=0;
    hourWork =0;
}
