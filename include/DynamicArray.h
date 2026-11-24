#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H


class DynamicArray {
private:
    int* data;  
    int size;   

    static bool isValueOk(int value);

public:
    DynamicArray(int size);

    DynamicArray(const DynamicArray& other);

    ~DynamicArray();

  
    void print() const;

    int getSize() const;

    
    bool set(int index, int value);

    
    bool get(int index, int& value) const;

    bool push_back(int value);

    void add(const DynamicArray& other);
    void subtract(const DynamicArray& other);
};

#endif
