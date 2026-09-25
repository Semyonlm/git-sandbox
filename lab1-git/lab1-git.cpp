// Лабораторная работа №1. Вариант 39.
#include <iostream>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <locale.h>
using namespace std;

double centripetalAccel(double v, double r) {
    if (r == 0) {
        cout << "Ошибка: радиус не может быть нулём.\n";
        return numeric_limits<double>::quiet_NaN();
    }
    return (v * v) / r;
}

double centripetalForce(double m, double v, double r) {
    if (r == 0) {
        cout << "Ошибка: радиус не может быть нулём.\n";
        return numeric_limits<double>::quiet_NaN();
    }
    return m * (v * v) / r;
}

double revolutionPeriod(double v, double r) {
    if (v == 0) return numeric_limits<double>::quiet_NaN();
    return 2 * 3.14159265358979 * r / v;
}

int main() {
    setlocale(LC_ALL, "Rus");
    system("chcp 1251 > nul");
    int choice;
    double v, r, m;
    do {
        cout << "\n== Вариант 39: Движение по окружности ==\n";
        cout << "1. Центростремительное ускорение\n";
        cout << "2. Центростремительная сила\n";
        cout << "3. Период обращения\n";
        cout << "0. Выход\n";
        cout << "Выберите пункт: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Введите скорость v (м/с) и радиус r (м): ";
            cin >> v >> r;
            if (v < 0 || r <= 0) {
                cout << "Ошибка: v ≥ 0, r > 0\n";
                break;
            }
            cout << "Ускорение = " << centripetalAccel(v, r) << " м/с²\n";
            break;
        case 2:
            cout << "Введите массу m (кг), скорость v (м/с), радиус r (м): ";
            cin >> m >> v >> r;
            if (m <= 0 || v < 0 || r <= 0) {
                cout << "Ошибка: m > 0, v ≥ 0, r > 0\n";
                break;
            }
            cout << "Сила = " << centripetalForce(m, v, r) << " Н\n";
            break;
        case 3:
            cout << "Введите v и r: ";
            cin >> v >> r;
            if (v <= 0 || r <= 0) {
                cout << "Ошибка: v > 0, r > 0\n";
                break;
            }
            cout << "Период = " << revolutionPeriod(v, r) << " с\n";
            break;
        case 0:
            cout << "Работа завершена.\n";
            break;
        default:
            cout << "Такого пункта нет.\n";
        }
    } while (choice != 0);
    return 0;
}