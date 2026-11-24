#include <iostream>
#include "../include/DynamicArray.h"

using namespace std;

int main() {
    cout << "Задание 1: класс, сеттер, геттер" << endl;
    DynamicArray a(5);
    cout << "Новый массив из 5 элементов: ";
    a.print();

    a.set(0, 10);
    a.set(1, -20);
    a.set(2, 100);
    a.set(3, -100);
    a.set(4, 7);
    cout << "После заполнения: ";
    a.print();

    cout << "Проверка ошибок сеттера:" << endl;
    a.set(5, 1);     
    a.set(-1, 1);    
    a.set(0, 101);   
    a.set(0, -101);  

    int x = 0;
    if (a.get(2, x)) {
        cout << "a[2] = " << x << endl;
    }
    cout << "Проверка ошибки геттера:" << endl;
    a.get(10, x);

    cout << endl << "Задание 2: конструктор копирования" << endl;
    DynamicArray b(a);  
    b.set(0, 55);       
    cout << "a: ";
    a.print();
    cout << "b (копия, b[0] изменён на 55): ";
    b.print();
    cout << "Массив a не изменился - значит копия независимая." << endl;

    cout << endl << "Задание 3: добавление в конец" << endl;
    DynamicArray c(2);
    c.set(0, 1);
    c.set(1, 2);
    cout << "Было: ";
    c.print();
    c.push_back(3);
    c.push_back(4);
    cout << "После push_back(3) и push_back(4): ";
    c.print();
    cout << "Размер: " << c.getSize() << endl;
    cout << "Проверка ошибки (push_back(500)):" << endl;
    c.push_back(500);

    cout << endl << " Задание 4: сложение и вычитание" << endl;
    DynamicArray p(3);
    p.set(0, 1);
    p.set(1, 2);
    p.set(2, 3);
    DynamicArray q(3);
    q.set(0, 10);
    q.set(1, 20);
    q.set(2, 30);
    cout << "p: ";
    p.print();
    cout << "q: ";
    q.print();

    p.add(q);
    cout << "p.add(q): ";
    p.print();
    p.subtract(q);
    cout << "p.subtract(q): ";
    p.print();

    cout << "Массивы разного размера:" << endl;
    DynamicArray longArr(4);
    longArr.set(0, 1);
    longArr.set(1, 1);
    longArr.set(2, 1);
    longArr.set(3, 1);
    DynamicArray shortArr(2);
    shortArr.set(0, 5);
    shortArr.set(1, 5);
    cout << "longArr: ";
    longArr.print();
    cout << "shortArr: ";
    shortArr.print();
    longArr.add(shortArr);
    cout << "longArr.add(shortArr) (недостающие = 0): ";
    longArr.print();

    DynamicArray shortArr2(2);
    shortArr2.set(0, 1);
    shortArr2.set(1, 2);
    DynamicArray longArr2(4);
    longArr2.set(0, 10);
    longArr2.set(1, 10);
    longArr2.set(2, 10);
    longArr2.set(3, 10);
    shortArr2.add(longArr2);
    cout << "shortArr2.add(longArr2) (размер не меняется): ";
    shortArr2.print();

    return 0;
}
