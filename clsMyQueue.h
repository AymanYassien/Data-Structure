//
// Created by Ayman yassien on 13/02/2024.
//

// print, size, front, back, pop
#include <iostream>
#include "../DblLinkedList/clDblLinkedList.h"
#include <iomanip>

using namespace std;

template<class T>
class clsMyQueue
{
protected:
    clsDblLinkedList<T> _myList; // composition(obj from cls A into cls B// ) not inherit,

public:
    void push(T value) {
        _myList.insertAtEnd(value);
    }

    void pop()
    {
        _myList.deleteFirstNode();
    }

    int size()
    {
        return _myList.getSize();
    }

    bool isEmpty()
    {
        return _myList.isEmpty();
    }

    T front()
    {
        return _myList.getItem(0);
    }

    T back()
    {
        return _myList.getItem(_myList.getSize() - 1);
    }

    void print()
    {
        int size = _myList.getSize();
        for (int i = 0; i < size; ++i)
            cout << _myList.getItem(i) << ' ';
//        cout << endl;


    }

    T getItem(int index)
    {
        return _myList.getItem(index);
    }

    void reverse()
    {
        _myList.reverse();
    }

    void updateItem(int index, T value)
    {
        _myList.updateItem(index, value);
    }

    void insertAfter(int index, T value)
    {
        _myList.insertAfter(index, value);
    }

    void insertAtFront(T value)
    {
        _myList.insertAtBegin(value);
    }

    void insertAtEnd(T value)
    {
        _myList.insertAtEnd(value);
    }

    void clear()
    {
        _myList.clear();
    }


};

/*
 *
 * #include <iostream>
#include "Queue/clsMyQueue.h"

using namespace std;

int main()
{
    clsMyQueue<int> myQueue;

    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    myQueue.push(40);
    myQueue.push(50);
    myQueue.push(60);
    myQueue.push(70);
    myQueue.push(80);
    myQueue.push(90);
    myQueue.push(100);
    myQueue.push(110);
    myQueue.push(120);

    cout << "\nQueue:\n";
    myQueue.print();

    cout << "\n\nQueue Size  : " << myQueue.size();
    cout << "\nQueue Front : " << myQueue.front();
    cout << "\nQueue Back  : " << myQueue.back();

    myQueue.pop();

    cout << "\n\nQueue after pop() :\n";
    myQueue.print();

    cout << "\n\nItem(2) : " << myQueue.getItem(2);

    myQueue.reverse();
    cout << "\n\nQueue after reverse() :\n";
    myQueue.print();

    myQueue.updateItem(2,1000);
    cout << "\n\nQueue after update item (2) to 1000 :\n";
    myQueue.print();

    myQueue.insertAfter(2, 1001);
    cout << "\n\nQueue after inserting (1001) after item(2) :\n";
    myQueue.print();

    myQueue.insertAtFront(10000);
    cout << "\n\nQueue after inserting 10000 at front :\n";
    myQueue.print();

    myQueue.insertAtBack(999);
    cout << "\n\nQueue after inserting 999 at back :\n";
    myQueue.print();

    myQueue.clear();
    cout << "\n\nQueue after Clear(): \n";
    myQueue.print();

    return 0;
}*/