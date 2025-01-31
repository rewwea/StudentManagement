#include "Student.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

void input(string** a, int n)
{
    for (int i = 1; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4] >> a[i][5];
    }
}

void input_from_file(string** a, const string& filename)
{
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл!" << endl;
        exit(1);
    }

    int i = 0; 
    while (infile >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4] >> a[i][5]) {
        ++i;
    }
    infile.close();
}

int count_lines(ifstream& file)
{
    file.clear(); 
    file.seekg(0, ios::beg); 

    int lines = 0;
    string line;
    while (getline(file, line))
    {
        ++lines;
    }

    file.clear(); 
    file.seekg(0, ios::beg); 

    return lines;
}

void output(string** a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i][0] << "\t" << a[i][1] << "\t" << a[i][2] << "\t" << a[i][3] << "\t" << a[i][4] << "\t" << a[i][5];
        cout << endl;
    }
}

void find_group(string** a, int n, ofstream* outfile)
{
    string group;
    cout << "Введите группу: ";
    cin >> group;
    for (int i = 1; i < n; i++)
    {
        if (a[i][2].find(group) != -1)
        {
            if (outfile)
                (*outfile) << a[i][0] << "\t" << a[i][1] << "\t" << a[i][2] << "\t" << a[i][3] << "\t" << a[i][4] << "\t" << a[i][5] << endl;
            else
                cout << a[i][0] << "\t" << a[i][1] << "\t" << a[i][2] << "\t" << a[i][3] << "\t" << a[i][4] << "\t" << a[i][5] << endl;
        }
    }
}

void find_rpm_above_3(string** a, int n, ofstream* outfile)
{
    for (int i = 1; i < n; i++)
    {
        if (stod(a[i][3]) > 3)
        {
            if (outfile)
                (*outfile) << a[i][0] << "\t" << a[i][1] << "\t" << a[i][2] << "\t" << a[i][3] << "\t" << a[i][4] << "\t" << a[i][5] << endl;
            else
                cout << a[i][0] << "\t" << a[i][1] << "\t" << a[i][2] << "\t" << a[i][3] << "\t" << a[i][4] << "\t" << a[i][5] << endl;
        }
    }
}

void find_test_above_3(string** a, int n, ofstream* outfile)
{
    for (int i = 1; i < n; i++)
    {
        if (stod(a[i][4]) > 3)
        {
            if (outfile)
                (*outfile) << a[i][0] << "\t" << a[i][1] << "\t" << a[i][2] << "\t" << a[i][3] << "\t" << a[i][4] << "\t" << a[i][5] << endl;
            else
                cout << a[i][0] << "\t" << a[i][1] << "\t" << a[i][2] << "\t" << a[i][3] << "\t" << a[i][4] << "\t" << a[i][5] << endl;
        }
    }
}

void find_math_above_3(string** a, int n, ofstream* outfile)
{
    for (int i = 1; i < n; i++)
    {
        if (stod(a[i][5]) > 3)
        {
            if (outfile)
                (*outfile) << a[i][0] << "\t" << a[i][1] << "\t" << a[i][2] << "\t" << a[i][3] << "\t" << a[i][4] << "\t" << a[i][5] << endl;
            else
                cout << a[i][0] << "\t" << a[i][1] << "\t" << a[i][2] << "\t" << a[i][3] << "\t" << a[i][4] << "\t" << a[i][5] << endl;
        }
    }
}

double average_rpm(string** a, int n)
{
    double sum = 0;
    for (int i = 1; i < n; i++)
        sum += stod(a[i][3]);
    return sum / (n - 1);
}

double average_test(string** a, int n)
{
    double sum = 0;
    for (int i = 1; i < n; i++)
        sum += stod(a[i][4]);
    return sum / (n - 1);
}

double average_math(string** a, int n)
{
    double sum = 0;
    for (int i = 1; i < n; i++)
        sum += stod(a[i][5]);
    return sum / (n - 1);
}

void find_rpm_above_avg(string** a, int n, ofstream* outfile)
{
    double avg = average_rpm(a, n);
    for (int i = 1; i < n; i++)
    {
        if (stod(a[i][3]) > avg)
            if (outfile)
                (*outfile) << a[i][0] << "\t" << a[i][1] << "\t" << a[i][2] << "\t" << a[i][3] << "\t" << a[i][4] << "\t" << a[i][5] << endl;
            else
                cout << a[i][0] << "\t" << a[i][1] << "\t" << a[i][2] << "\t" << a[i][3] << "\t" << a[i][4] << "\t" << a[i][5] << endl;
    }
}

void find_test_above_avg_rpm_below_avg(string** a, int n, ofstream* outfile)
{
    double avgTest = average_test(a, n);
    double avgRPM = average_rpm(a, n);
    for (int i = 1; i < n; i++)
    {
        if (stod(a[i][4]) > avgTest && stod(a[i][3]) < avgRPM)
            if (outfile)
                (*outfile) << a[i][0] << "\t" << a[i][1] << "\t" << a[i][2] << "\t" << a[i][3] << "\t" << a[i][4] << "\t" << a[i][5] << endl;
            else
                cout << a[i][0] << "\t" << a[i][1] << "\t" << a[i][2] << "\t" << a[i][3] << "\t" << a[i][4] << "\t" << a[i][5] << endl;
    }
}

void find_all_above_avg(string** a, int n, double avg_rpm, double avg_test, double avg_math, ofstream* outfile)
{
    if (outfile)
        (*outfile) << "Студенты с оценками выше средней по всем предметам:" << endl;
    else
        cout << "Студенты с оценками выше средней по всем предметам:" << endl;

    for (int i = 1; i < n; i++)
    {
        double rpm = stod(a[i][3]);
        double test = stod(a[i][4]);
        double math = stod(a[i][5]);
        if (rpm > avg_rpm && test > avg_test && math > avg_math)
        {
            if (outfile)
                (*outfile) << a[i][0] << "\t" << a[i][1] << "\t" << a[i][2] << "\t" << a[i][3] << "\t" << a[i][4] << "\t" << a[i][5] << endl;
            else
                cout << a[i][0] << "\t" << a[i][1] << "\t" << a[i][2] << "\t" << a[i][3] << "\t" << a[i][4] << "\t" << a[i][5] << endl;
        }
    }
}