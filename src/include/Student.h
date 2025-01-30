#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void input(string** a, int n);
void output(string** a, int n);
void find_group(string** a, int n);
void find_age_older(string** a, int n);
void find_age_younger(string** a, int n);
void find_rpm_above_3(string** a, int n);
void find_test_above_3(string** a, int n);
void find_math_above_3(string** a, int n);
double average_rpm(string** a, int n);
double average_test(string** a, int n);
double average_math(string** a, int n);
void find_rpm_above_avg(string** a, int n);
void find_test_above_avg_rpm_below_avg(string** a, int n);