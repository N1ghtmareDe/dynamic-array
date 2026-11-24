#include <iostream>
#include <stdexcept>  
#include <new>        
#include "../include/DynamicArray.h"

using namespace std;


void DynamicArray::checkIndex(int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("Индекс " + to_string(index) + " выходит за границы массива");
    }
}

void DynamicArray::checkValue(int value) {
    if (value < -100 || value > 100) {
        throw invalid_argument("Значение " + to_string(value) + " не входит в промежуток от -100 до 100");
    }
}


DynamicArray::DynamicArray(int size) {
    if (size < 0) {
        throw invalid_argument("Размер массива не может быть отрицательным");
    }
    this->size = size;
    
    this->data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = 0;
    }
}


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


void DynamicArray::set(int index, int value) {
    checkIndex(index);  
    checkValue(value);  
    data[index] = value;
}


int DynamicArray::get(int index) const {
    checkIndex(index);  
    return data[index];
}


void DynamicArray::push_back(int value) {
    checkValue(value); 

    int* newData = new int[size + 1];  
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    newData[size] = value;

    delete[] data;
    data = newData;
    size++;
}

void DynamicArray::add(const DynamicArray& other) {
    for (int i = 0; i < size; i++) {
        int otherValue = 0;
        if (i < other.size) {
            otherValue = other.data[i];
        }
        data[i] = data[i] + otherValue;
    }
}


void DynamicArray::subtract(const DynamicArray& other) {
    for (int i = 0; i < size; i++) {
        int otherValue = 0;
        if (i < other.size) {
            otherValue = other.data[i];
        }
        data[i] = data[i] - otherValue;
    }
}
