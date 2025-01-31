#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void input(string** a, int n);
void input_from_file(string** a, const string& filename);
int count_lines(ifstream& file);
void output(string** a, int n);
void find_group(string** a, int n, ofstream* outfile = nullptr);
void find_age_older(string** a, int n);
void find_age_younger(string** a, int n);
void find_rpm_above_3(string** a, int n, ofstream* outfile = nullptr);
void find_test_above_3(string** a, int n, ofstream* outfile = nullptr);
void find_math_above_3(string** a, int n, ofstream* outfile = nullptr);
double average_rpm(string** a, int n);
double average_test(string** a, int n);
double average_math(string** a, int n);
void find_rpm_above_avg(string** a, int n, ofstream* outfile = nullptr);
void find_test_above_avg_rpm_below_avg(string** a, int n, ofstream* outfile = nullptr);
void find_all_above_avg(string** a, int n, double avg_rpm, double avg_test, double avg_math, ofstream* outfile = nullptr);

#endif // STUDENT_H