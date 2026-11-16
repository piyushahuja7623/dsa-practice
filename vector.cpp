#include<iostream>
using namespace std;
Struct Vector
{
    int * data;
    int size;
    int capacity;
    Vector()
    {
        size = 0;
        capacity = 2;
        data = new int[capacity];
    }
    void push_back(int val)
    {
        if(size == capacity)
        {
            int * newData = new int[capacity * 2];
            for(int i = 0; i < size; i++)
            {
                newData[i] = data[i];
            }
            
            delete[] data;
            data = newData;
            capacity = capacity * 2;
        }
        data[size] = val;
        size++;
    }
};