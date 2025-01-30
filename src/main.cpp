#include <iostream>
#include <string>
#include <algorithm>
#include "Student.h"
using namespace std;
int main()
{
  setlocale(LC_ALL, "Russian");

  int cnt = 0;
  cout << "Введите количество студентов: ";
  cin >> cnt;
  cnt++;

  string** students = new string*[cnt];
  for (int i = 0; i < cnt; i++)
  {
    students[i] = new string[6];
  }

  students[0][0] = "Имя";
  students[0][1] = "Возраст";
  students[0][2] = "Группа";
  students[0][3] = "РПМ";
  students[0][4] = "Тест";
  students[0][5] = "Матем";

  input(students, cnt);
  output(students, cnt);
  find_group(students, cnt);
  find_age_older(students, cnt);
  find_age_younger(students, cnt);
  find_rpm_above_3(students, cnt);
  find_test_above_3(students, cnt);
  find_math_above_3(students, cnt);
  average_rpm(students, cnt);
  average_test(students, cnt);
  average_math(students, cnt);
  find_rpm_above_avg(students, cnt);
}
