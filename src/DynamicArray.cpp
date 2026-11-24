#include <iostream>
#include "../include/DynamicArray.h"

using namespace std;


bool DynamicArray::isValueOk(int value) {
    return value >= -100 && value <= 100;
}


DynamicArray::DynamicArray(int size) {
    if (size < 0) {
        size = 0;  
    }
    this->size = size;
    this->data = new int[size];  
    for (int i = 0; i < size; i++) {
        data[i] = 0;             
    }
}

// (Задание 2
DynamicArray::DynamicArray(const DynamicArray& other) {
    this->size = other.size;
    this->data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}


DynamicArray::~DynamicArray() {
    delete[] data;  
}

// Вывод
void DynamicArray::print() const {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int DynamicArray::getSize() const {
    return size;
}


bool DynamicArray::set(int index, int value) {
    if (index < 0 || index >= size) {
        cout << "Ошибка: индекс " << index << " выходит за границы массива" << endl;
        return false;
    }
    if (!isValueOk(value)) {
        cout << "Ошибка: значение " << value << " не входит в промежуток от -100 до 100" << endl;
        return false;
    }
    data[index] = value;
    return true;
}


bool DynamicArray::get(int index, int& value) const {
    if (index < 0 || index >= size) {
        cout << "Ошибка: индекс " << index << " выходит за границы массива" << endl;
        return false;
    }
    value = data[index];
    return true;
}

// Задание 3
bool DynamicArray::push_back(int value) {
    if (!isValueOk(value)) {
        cout << "Ошибка: значение " << value << " не входит в промежуток от -100 до 100" << endl;
        return false;
    }
    
    int* newData = new int[size + 1];
    // 2. Копируем в него старые элементы
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    
    newData[size] = value;
   
    delete[] data;
    data = newData;
    size++;
    return true;
}

//Задание 4

void DynamicArray::add(const DynamicArray& other) {
    for (int i = 0; i < size; i++) {
        int otherValue = 0;
        if (i < other.size) {
            otherValue = other.data[i];
        }
        data[i] = data[i] + otherValue;
    }
}

// (Задание 4
void DynamicArray::subtract(const DynamicArray& other) {
    for (int i = 0; i < size; i++) {
        int otherValue = 0;
        if (i < other.size) {
            otherValue = other.data[i];
        }
        data[i] = data[i] - otherValue;
    }
}
