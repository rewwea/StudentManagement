#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include "Student.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int cnt = 0;
    string** students = nullptr;
    bool isFileInput = false;

    cout << "Выберите способ ввода данных (1 - Ручной ввод, 2 - Ввод из файла): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "Введите количество студентов: ";
        cin >> cnt;
        cnt++;
        students = new string*[cnt];
        for (int i = 0; i < cnt; i++) {
            students[i] = new string[6];
        }
        students[0][0] = "Имя";
        students[0][1] = "Возраст";
        students[0][2] = "Группа";
        students[0][3] = "РПМ";
        students[0][4] = "Тест";
        students[0][5] = "Матем";

        input(students, cnt);
    } else if (choice == 2) {
        string filename;
        cout << "Введите имя файла: ";
        cin >> filename;
        ifstream infile(filename);
        if (!infile.is_open()) {
            cerr << "Ошибка: Файл не найден!" << endl;
            return 1;
        }

        cnt = count_lines(infile);
        infile.close();

        students = new string*[cnt];
        for (int i = 0; i < cnt; i++) {
            students[i] = new string[6];
        }

        input_from_file(students, filename);
        isFileInput = true;
    } else {
        cerr << "Неправильный выбор!" << endl;
        return 1;
    }

    output(students, cnt);

    ofstream group_file, above_3_file, avg_points_file, all_above_avg_file;
    string group_name;
    double avg_rpm = average_rpm(students, cnt);
    double avg_test = average_test(students, cnt);
    double avg_math = average_math(students, cnt);

    cout << "Введите группу для поиска: ";
    cin >> group_name;
    group_file.open(group_name + ".txt");
    find_group(students, cnt, &group_file);
    group_file.close();

    above_3_file.open("above_3.txt");
    find_rpm_above_3(students, cnt, &above_3_file);
    find_test_above_3(students, cnt, &above_3_file);
    find_math_above_3(students, cnt, &above_3_file);
    above_3_file.close();

    avg_points_file.open("avg_points.txt");
    find_rpm_above_avg(students, cnt, &avg_points_file);
    find_test_above_avg_rpm_below_avg(students, cnt, &avg_points_file);
    avg_points_file.close();

    all_above_avg_file.open("avg_for_all_points.txt");
    find_all_above_avg(students, cnt, avg_rpm, avg_test, avg_math, &all_above_avg_file);
    all_above_avg_file.close();
    
    for (int i = 0; i < cnt; i++) {
        delete[] students[i];
    }
    delete[] students;

    return 0;
}