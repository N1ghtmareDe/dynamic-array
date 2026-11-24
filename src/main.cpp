#include <iostream>
#include <stdexcept>
#include <new>
#include <cstddef>  
#include "../include/DynamicArray.h"

using namespace std;

int main() {
    DynamicArray a(5);
    a.set(0, 10);
    a.set(1, -20);
    a.set(2, 100);
    cout << "Массив a: ";
    a.print();

    
    cout << endl << "Проверка out_of_range (индекс вне границ) " << endl;

    try {
        a.set(5, 1);  
    } catch (const out_of_range& e) {
        cout << "Поймано out_of_range (сеттер): " << e.what() << endl;
    }

    try {
        int x = a.get(-1);
        cout << x << endl;
    } catch (const out_of_range& e) {
        cout << "Поймано out_of_range (геттер): " << e.what() << endl;
    }

    
    cout << endl << " Проверка invalid_argument (значение вне -100...100) ===" << endl;

    try {
        a.set(0, 101);
    } catch (const invalid_argument& e) {
        cout << "Поймано invalid_argument (сеттер): " << e.what() << endl;
    }

    try {
        a.push_back(-500);
    } catch (const invalid_argument& e) {
        cout << "Поймано invalid_argument (push_back): " << e.what() << endl;
    }

    try {
        DynamicArray bad(-3); 
    } catch (const invalid_argument& e) {
        cout << "Поймано invalid_argument (конструктор): " << e.what() << endl;
    }

    
    cout << endl << "=== Проверка bad_alloc (не хватило памяти) ===" << endl;

    try {
        
        size_t hugeSize = static_cast<size_t>(-1) / 2;
        int* p = new int[hugeSize];
        delete[] p;  
    } catch (const bad_alloc& e) {
        cout << "Поймано bad_alloc: не удалось выделить память" << endl;
    }

    cout << endl << "=== Обычная работа (без ошибок) ===" << endl;
    try {
        a.push_back(42);
        cout << "После push_back(42): ";
        a.print();
        cout << "a.get(1) = " << a.get(1) << endl;
    } catch (const exception& e) {
        cout << "Неожиданная ошибка: " << e.what() << endl;
    }

    return 0;
}
