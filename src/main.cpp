#include <iostream>
#include <string>
#include <stdexcept>
#include <typeinfo>
#include "../include/DynamicArray.h"

using namespace std;

int main() {
    cout << "Задание 2: вывод через <<" << endl;
    DynamicArray<int> a(3);
    a.set(0, 1);
    a.set(1, 2);
    a.set(2, 3);
    cout << "Массив int:    " << a << endl;

    DynamicArray<double> d(3);
    d.set(0, 1.5);
    d.set(1, 250.75);
    d.set(2, -3.25);
    cout << "Массив double: " << d << endl;

    DynamicArray<string> s(2);
    s.set(0, "привет");
    s.set(1, "мир");
    cout << "Массив string: " << s << endl;

    cout << endl << "Задание 1: проверка значений только для целых типов" << endl;

    try {
        a.set(0, 500);
    } catch (const invalid_argument& e) {
        cout << "int: поймано invalid_argument: " << e.what() << endl;
    }

    d.set(0, 500.5);
    cout << "double: значение 500.5 записалось без ошибки: " << d << endl;

    s.push_back("любая строка");
    cout << "string: строка добавилась без ошибки: " << s << endl;

    cout << endl << "Задание 3: расстояние между массивами" << endl;

    DynamicArray<int> p(3);
    p.set(0, 0);
    p.set(1, 0);
    p.set(2, 0);
    DynamicArray<int> q(3);
    q.set(0, 3);
    q.set(1, 4);
    q.set(2, 0);
    cout << "p = " << p << ", q = " << q << endl;
    cout << "Расстояние между p и q (int): " << p.distance(q) << endl;

    DynamicArray<double> d1(2);
    d1.set(0, 1.0);
    d1.set(1, 1.0);
    DynamicArray<double> d2(2);
    d2.set(0, 4.0);
    d2.set(1, 5.0);
    cout << "d1 = " << d1 << ", d2 = " << d2 << endl;
    cout << "Расстояние между d1 и d2 (double): " << d1.distance(d2) << endl;

    DynamicArray<int> shortArr(2);
    try {
        p.distance(shortArr);
    } catch (const invalid_argument& e) {
        cout << "Разные размеры: поймано invalid_argument: " << e.what() << endl;
    }

    DynamicArray<string> s1(2);
    DynamicArray<string> s2(2);
    try {
        s1.distance(s2);
    } catch (const bad_typeid& e) {
        cout << "string: поймано bad_typeid (для нечисловых типов расстояние не считается)" << endl;
    }

    return 0;
}
