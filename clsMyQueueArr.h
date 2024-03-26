//
// Created by Ayman yassien on 15/02/2024.
//
#include "../Dynamic array/clsDynamicArray.h"

template<class T>
class clsMyQueueArr
{
protected:
    clsDynamicArray<int> dynamicArray;

public:
    virtual void push(T value)
    {
        dynamicArray.insertAtEnd(value);
    }

    void pop()
    {
        dynamicArray.deleteFirstItem();
    }

    int size()
    {
        return  dynamicArray.size();
    }

    bool isEmpty()
    {
        return dynamicArray.isEmpty();
    }

    T front()
    {
        return dynamicArray.getItem(0);
    }

    T back()
    {
        return dynamicArray.getItem(dynamicArray.size() - 1);
    }

    void print()
    {
        int size = dynamicArray.size();
        for (int i = 0; i < size; ++i)
            cout << dynamicArray.getItem(i) << ' ';
//        cout << endl;


    }

    T getItem(int index)
    {
        return dynamicArray.getItem(index);
    }

    void reverse()
    {
        dynamicArray.reverse();
    }

    void updateItem(int index, T value)
    {
        dynamicArray.setItem(index, value);
    }

    void insertAfter(int index, T value)
    {
        dynamicArray.insertAfter(index, value);
    }

    void insertAtFront(T value)
    {
        dynamicArray.insertAtBegaining(value);
    }

    void insertAtBack(T value)
    {
        dynamicArray.insertAtEnd(value);
    }

    void clear()
    {
        dynamicArray.clear();
    }

};