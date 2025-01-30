#include "Student.h"
#include <string>
#include <iostream>

using namespace std;
void input(string** a, int n)
{
  for (int i = 1; i < n; i++)
  {
    cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4] >> a[i][5];
  }
}

void output(string** a, int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << a[i][0] << "\t" << a[i][1] << "\t" << a[i][2] << "\t" << a[i][3] << "\t" << a[i][4] << "\t" << a[i][5];
    cout << endl;
  }
}
//вывести студентой указанной группы
void find_group(string** a, int n)
{
  string group;
  cout << "Введите группу: ";
  cin >> group;
  for (int i = 0; i < n; i++)
  {
    if (a[i][2].find(group) != -1)
    {
      cout << a[i][0] << "\t" << a[i][1] << "\t" << a[i][2] << "\t" << a[i][3] << "\t" << a[i][4] << "\t" << a[i][5];
      cout << endl;
    }
  }
}
//вывести студентов возраста старше указанного
void find_age(string** a, int n)
{
  int age;
  cout << "Введите возраст: ";
  cin >> age;
  for (int i = 0; i < n; i++)
  {
    if (stoi(a[i][1]) > age)
    {
      cout << a[i][0] << "\t" << a[i][1] << "\t" << a[i][2] << "\t" << a[i][3] << "\t" << a[i][4] << "\t" << a[i][5];
      cout << endl;
    }
    if (stoi(a[i][1]) < age);
    {
      cout << a[i][0] << "\t" << a[i][1] << "\t" << a[i][2] << "\t" << a[i][3] << "\t" << a[i][4] << "\t" << a[i][5];
      cout << endl;
    }
  }
}
