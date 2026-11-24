#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H


class DynamicArray {
private:
    int* data;  
    int size;   

    
    void checkIndex(int index) const;

    static void checkValue(int value);

public:
    
    DynamicArray(int size);
    
    DynamicArray(const DynamicArray& other);

    
    ~DynamicArray();

    void print() const;

    
    int getSize() const;

    void set(int index, int value);

    
    int get(int index) const;
   
    void push_back(int value);
    
    void add(const DynamicArray& other);
    void subtract(const DynamicArray& other);
};

#endif
