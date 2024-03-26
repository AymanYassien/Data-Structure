//
// Created by Ayman yassien on 14/02/2024.
//

#include "../Queue/clsMyQueue.h"

using namespace std;

template<class T>
class clsMyStack : public clsMyQueue<T>
{
public:
    void push(T value)
    {
        clsMyQueue<T> :: _myList.insertAtBegin(value);
    }

    T top()
    {
        clsMyQueue <T>::front();
    }

    T bottom()
    {
       clsMyQueue <T> ::back();
    }

};


