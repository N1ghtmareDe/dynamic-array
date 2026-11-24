#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <typeinfo>

template <typename T>
class DynamicArray {
private:
    T* data;
    int size;

    void checkIndex(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Индекс " + std::to_string(index) + " выходит за границы массива");
        }
    }

    static void checkValue(const T& value) {
        if constexpr (std::is_integral_v<T>) {
            if (value > 100 || value < -100) {
                throw std::invalid_argument("Значение " + std::to_string(value) + " не входит в промежуток от -100 до 100");
            }
        }
    }

public:
    DynamicArray(int size) {
        if (size < 0) {
            throw std::invalid_argument("Размер массива не может быть отрицательным");
        }
        this->size = size;
        this->data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = T();
        }
    }

    DynamicArray(const DynamicArray& other) {
        this->size = other.size;
        this->data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    ~DynamicArray() {
        delete[] data;
    }

    int getSize() const {
        return size;
    }

    void set(int index, const T& value) {
        checkIndex(index);
        checkValue(value);
        data[index] = value;
    }

    T get(int index) const {
        checkIndex(index);
        return data[index];
    }

    void push_back(const T& value) {
        checkValue(value);

        T* newData = new T[size + 1];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        newData[size] = value;

        delete[] data;
        data = newData;
        size++;
    }

    void add(const DynamicArray& other) {
        for (int i = 0; i < size; i++) {
            T otherValue = T();
            if (i < other.size) {
                otherValue = other.data[i];
            }
            data[i] = data[i] + otherValue;
        }
    }

    void subtract(const DynamicArray& other) {
        for (int i = 0; i < size; i++) {
            T otherValue = T();
            if (i < other.size) {
                otherValue = other.data[i];
            }
            data[i] = data[i] - otherValue;
        }
    }

    double distance(const DynamicArray& other) const {
        if constexpr (std::is_arithmetic_v<T>) {
            if (size != other.size) {
                throw std::invalid_argument("Размеры массивов должны быть одинаковыми");
            }
            double sum = 0;
            for (int i = 0; i < size; i++) {
                double diff = static_cast<double>(data[i]) - static_cast<double>(other.data[i]);
                sum = sum + diff * diff;
            }
            return std::sqrt(sum);
        } else {
            throw std::bad_typeid();
        }
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const DynamicArray<T>& arr) {
    out << "[";
    for (int i = 0; i < arr.getSize(); i++) {
        out << arr.get(i);
        if (i < arr.getSize() - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}

#endif
