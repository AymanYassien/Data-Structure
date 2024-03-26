//
// Created by Ayman yassien on 15/02/2024.
//

#include "../Queue/clsMyQueueArr.h"

using namespace std;

template<class T>
class clsMyStackArr : public clsMyQueueArr<T>
{
public:
    void push(T value)
    {
        clsMyQueueArr<T> ::dynamicArray.insertAtBegaining(value);
    }

//    T top()
//    {
//        clsMyQueueArr <T> ::front();
//    }

    T bottom()
    {
        clsMyQueueArr <T> ::back();
    }
};

