//
// Created by Ayman yassien on 14/02/2024.
//
#include "iostream"
//#include "../DblLinkedList/clDblLinkedList.h"
#include "vector"

using namespace std;

template<class T>
class clsDynamicArray
{
    int _size = 0;
    T * _tempArray ;
public:

    T * originalArray;

    clsDynamicArray(int size = 0)
    {
        if (size < 0)
            size = 0;

        _size = size;
        originalArray = new T[_size];
    }
    ~clsDynamicArray()
    {
        delete [] originalArray;
    }

    bool setItem(int index, T value)
    {
        // this bool, meaning when u write "objName.setItem (idx, value)...
        // that will setIndex case true else : just ignore"
        if (index >= _size || 0 > index)
            return false;

        originalArray[index] = value;
        return true;
    }

    int size ()
    {
        return _size;
    }

    bool isEmpty()
    {
        return _size == 0;
    }

    void print()
    {
        for (int i = 0; i < _size; ++i)
            cout << originalArray[i] << ' ';

        cout << endl;

    }

    void resize(int newSize)
    {
        if (newSize == _size)
            return;

        if (newSize < 0)
            newSize = 0;

        _tempArray = new T[newSize];

        if (_size > newSize)
            _size = newSize;

        for (int i = 0; i < _size; ++i)
            _tempArray[i] = originalArray[i];

        _size = newSize;

        // Deallocate the original array
        delete [] originalArray; // just delete what was assigned in memory when "new T [_size]" called
        originalArray = _tempArray; // Update the original array pointer to point to the temporary array

//        delete [] _tempArray; => temp actually is a pointer to original, delete it = delete original.

    }

    T getItem(int index)
    {
        return originalArray[index];
    }

    void clear()
    {
        _size = 0;
        delete[] originalArray;
        originalArray = new T[_size];// without this line will point to null,
        // so after delete if program still running need to assign zero (my think )
    }

    void reverse()
    {


        //mySol
        _tempArray = originalArray;
        for (int i = 0; i < _size/ 2 ; ++i)
        {
            T tempo = originalArray [i];
            originalArray [i] = _tempArray[_size - i - 1];
            _tempArray[_size - i - 1] = tempo;
        }
        return;

//        _tempArray = new T[_size];
//        int counter = 0;
//
//        for (int i = _size - 1; i >= 0 ; --i) {
//            _tempArray[counter] = originalArray[i];
//            ++counter;
//        }
//
//        delete[] originalArray;
//        originalArray = _tempArray;

    }

    bool  deleteItemAt(int index)
    {
        // this bool, meaning when u write "objName.setItem (idx, value)...
        // that will setIndex case true else : just ignore"
        if (index >= _size || 0 > index)
            return false;

        _size --;
        _tempArray = new T[_size];

        //copy all  be4 idx;
        for (int i = 0; i < index; ++i) {
            _tempArray[i] = originalArray[i];
        }
        
        // copy all after idx;
        for (int i = index + 1; i <= _size; ++i) {
            _tempArray[i - 1] = originalArray[i]; // take in ur mind index deleted vso i - 1;
        }

//        int counter = 0;
//        for (int i = 0; i < _size; ++i) {
//            if (i == index)
//                continue;
//            _tempArray[counter] = originalArray[i];
//                ++counter;
//        }

        delete[] originalArray;
        originalArray = _tempArray;
        return true;

    }

    bool insertAt(int index, T value)
    {
        if (index > _size || 0 > index)
            return false;

        _size ++;
        _tempArray = new T[_size];

        //copy all  be4 idx;
        for (int i = 0; i < index; ++i) {
            _tempArray[i] = originalArray[i];
        }

        _tempArray[index] = value;

        // copy all after idx;
        for (int i = index + 1; i <= _size; ++i) {
            _tempArray[i] = originalArray[i - 1]; // take in ur mind index deleted vso i - 1;
        }

        delete[] originalArray;
        originalArray = _tempArray;
        return true;

    }

    void deleteFirstItem()
    {
        deleteItemAt(0);
    }

    void deleteLastItem()
    {
        deleteItemAt(_size - 1);
    }

    // find(int idx), deleteItem(value)
    int find(T value)
    {
        for (int i = 0; i < _size; ++i)
            if (originalArray[i] == value)
                return i;

        return -1;

    }

    void deleteItem(T value)
    {
        deleteItemAt(find(value));
    }

    void insertAtBegaining(T value)
    {
         insertAt(0, value);
    }

    bool insertAtEnd(T value)
    {
       return insertAt(_size, value);

    }

    bool insertBefore(int index, T value)
    {
        if (index < 1)
            return insertAt( 0, value);
        else
            return insertAt(index - 1, value);

    }

    bool insertAfter(int index, T value)
    {
        if (index >= _size)
            return insertAt(_size - 1, value);// not ensure!
        else
            return insertAt(index + 1, value);

    }

};


/*
 * //A pragma is a compiler directive that allows you to provide additional information to the compiler
#include <iostream>
#include "Dynamic array/clsDynamicArray.h"

using namespace std;

int main()
{
    // garbage data
    clsDynamicArray<int> dynamicArray(7);

    dynamicArray.setItem(0, 10);
    dynamicArray.setItem(1, 20);
    dynamicArray.setItem(2, 30);
    dynamicArray.setItem(3, 40);
    dynamicArray.setItem(4, 50);
    dynamicArray.setItem(5, 60);
    dynamicArray.setItem(6, 70);

    cout << "Is Empty      : " << dynamicArray.isEmpty() << '\n';
    cout << "Array Size    : " << dynamicArray.size()    << '\n';

    cout << "\nArray items :\n";
    dynamicArray.print();

    cout << "\n\nvalue 30 in index: " << dynamicArray.find(30);

    dynamicArray.deleteItem(30);
    cout << "\nArray items after delete 30 :\n";
    dynamicArray.print();

    dynamicArray.insertAtBegaining( 600);
    cout << "\nArray after insert 600 @ Begaining :\n";
    dynamicArray.print();

    dynamicArray.insertAtBack(999);
    cout << "\nArray after insert 999 @ end :\n";
    dynamicArray.print();

    dynamicArray.insertBefore(2, 109);
    cout << "\nArray items after insert 109 Be4 2 :\n";
    dynamicArray.print();

    dynamicArray.insertAfter(2, 199);
    cout << "\nArray items after insert 199 after 2 :\n";
    dynamicArray.print();

    dynamicArray.deleteFirstItem();
    cout << "Array Items after deleting First item ():\n";
    dynamicArray.print();

    dynamicArray.deleteLastItem();
    cout << "Array Items after deleting Last item ():\n";
    dynamicArray.print();

    dynamicArray.deleteItemAt(3);
    cout << "Array Items after deleting item(3):\n";
    dynamicArray.print();

    dynamicArray.resize(3);
    cout << "Array Size: " << dynamicArray.size() << '\n';
    cout << "Dynamic array items after resize to 3 :\n";
    dynamicArray.print();

    dynamicArray.resize(10);
    cout << "Array Size: " << dynamicArray.size() << '\n';
    cout << "Dynamic array items after resize to 10 :\n";
    dynamicArray.print();

    // I think some compilers assign garbage data and another assign zero like my own

    cout << "\nItem (1): " << dynamicArray.getItem(1);

    dynamicArray.reverse();
    cout << "\nDynamic array after reverse:\n";
    dynamicArray.print();

    dynamicArray.clear();
    cout << "\nDynamic array size after Clear: " << dynamicArray.size() << '\n';
    cout << "\nDynamic array after Clear:\n";
    dynamicArray.print();



    return 0;
}*/