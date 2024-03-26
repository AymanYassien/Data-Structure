//
// Created by Ayman yassien on 23/01/2024 AD.
//
#include <iostream>
#include <iomanip>
#include "node.h"
using namespace std;

template<class T>
class clsDblLinkedList : public node<T>
        // tricky way here, inheritance ... this way can create an object of class through another class
{
    node<T> * head = NULL;
    int _size = 0;

    void printListInDetails(node<T>* head)
    {
        (head->prev != NULL)? cout <<setw(4) << right  << head->prev->value : cout << "NULL";
        cout << " <--> " << head->value << " <--> ";
        (head->next != NULL)? cout<<setw(4) << right  << head->next->value << '\n' : cout << "NULL\n";
    }

public:
    int getSize()
    {
        return _size;
    }

    void insertAtBegin(T value)
    {

        node<T> * newNode = new node<T>;

        newNode->value = value;
        (head != NULL)? newNode->next = head : newNode->next = NULL;
        newNode->prev = NULL;

        if (head != NULL)
            head->prev = newNode;

        head = newNode;
        ++_size;

    }

    node<T> * find(T value)
    {
        node<T> * originalHead = head;

        while (originalHead != NULL)
        {
            if (originalHead->value == value)
                return originalHead;
            originalHead = originalHead->next;
        }
        return NULL;

    }

    void insertAfter(node<T> * current, T newValue)
    {

        node<T> * new_node = new node<T>();
        new_node->prev = current;
        new_node->value = newValue;
        new_node->next = current->next;

        if (current->next != NULL)
            current->next->prev = new_node;

        current->next     = new_node;
        ++_size;

    }

    void insertAfter(int index, T newValue)
    {
        node<T> * current = getNode(index);

        if (current != nullptr)
            insertAfter(current, newValue);
        else
            return;
        // can set this function as bool

    }

    void insertAtEnd(T newValue)
    {

        node<T> * new_node = new node<T>();
        new_node->value = newValue;
        new_node->next = NULL;

        if (head == NULL)
        {
            new_node->prev = NULL;
            head = new_node;
            ++_size;
            return;
        } else {
            node<T> *last_node = head;
            while (last_node->next != NULL)
                last_node = last_node->next;

            new_node->prev = last_node;
            last_node->next = new_node;
            ++_size;
        }


        return;

    }

    void deleteNode(node<T>* & nodeToDelete)
    {


        if(head == NULL || nodeToDelete == NULL) // 1 0 0 0
            return;

        if(nodeToDelete == head) // 0 1 0 0
            head = nodeToDelete->next; // or NULL

        if (nodeToDelete->next != NULL) // 0 0 1 1
            nodeToDelete->next->prev = nodeToDelete->prev;

        if (nodeToDelete->prev != NULL) // 0 0 1 1
            nodeToDelete->prev->next = nodeToDelete->next;

        delete nodeToDelete;
        --_size;

    }

    void deleteFirstNode()
    {

        //node * _tempArray = head;

        if (head == NULL)
        {
            cout << "Null";
            return;
        }

        head = head->next;
        if (head != NULL)
            head->prev = NULL;

        //delete _tempArray;
        --_size;

    }

    void deleteLastNode()
    {
        if (head == NULL)
        {
            cout << "Null";
            return;
        }

        if (head->next == NULL)
        {
            --_size;
            delete head;
            head = NULL;
            return;
        }


        node<T> * current = head;
        while (current->next->next != NULL )
            current = current->next;

        //node * _tempArray = current->next;
        current->next = NULL;
        //delete _tempArray;

        --_size;

    }

    void printList()
    {
        node<T> * originalHead = head;

        while (head != NULL)
        {
            printListInDetails(head);
            head = head->next;
        }

        head = originalHead;
    }

    bool isEmpty()
    {
        return (_size == 0? true : false);
    }

    void clear()
    {
//        head = nullptr;
//        _size = 0;

        while (_size > 0)
            deleteLastNode();
    }

    void reverse()
    {

//        node<T> * _tempArray = nullptr;
//        for (int i = 0; i < _size; ++i)
//        {
//            _tempArray = head->prev;
//            head->prev = head->next;
//            head->next = _tempArray;
//
//            if (i + 1 < _size)
//                head = head->prev;
//        }
//        delete _tempArray;


//        /*
         // this code from abu-Hadhoud, complex to understand, but i trace it and its really true
        node<T> * current = head;
        node<T> * temp = nullptr;

        while (current != nullptr)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr)// to avoid case which no node;
        {
            head = temp->prev;
        }
//         */

    }

    node<T> * getNode(int index)
    {
        node<T> * start = head;

        if (_size == 0 || _size < index)
            return NULL;

        for (int i = 1; i <= index; ++i)
            start = start->next;
        return start;

        // sol below from hadhoud, may complex!

        int counter = 0;

        if (index > _size - 1 || index < 0)
            return NULL;

        node<T>* current = head;
        while(current != NULL && (current->next != NULL))
        {
            if (counter == index)
                break;
            current = current->next;
            ++counter;
        }
        return current;

    }

    T getItem(int index ){

        return getNode(index)->value;

        // P.Advices Sol!
//        node<T> * item = getNode(index);
//        if(item == NULL)
//            return NULL;
//        else
//            return item->value;


    }

    void updateItem(int index, T value)
    {
        node<T> * currentNode = getNode(index);
        if (currentNode != nullptr)
            currentNode->value = value;
        else
            return;
        // can set this function as bool

    }

};

/*______________________ main________________________
 *
 * #include <iostream>
#include "DblLinkedList/clDblLinkedList.h"

using namespace std;

int main()
{
 _______________________________________comment
   // *
     * template     --
     * find         --
     * insertAfter  --
     * null vs nullptr
     * *
_______________________________________
clsDblLinkedList<int> myDblLinkedList;

if (myDblLinkedList.isEmpty())
cout << "\nYes, List is empty\n";
else
cout << "\nNo, List is not empty\n";

myDblLinkedList.insertAtBegin(4);
myDblLinkedList.insertAtBegin(3);
myDblLinkedList.insertAtBegin(2);
myDblLinkedList.insertAtBegin(1);
myDblLinkedList.insertAfter(3, 5);

cout << "\nNumber of items in the Linked List = " << myDblLinkedList.getSize() << '\n';

cout << "\nLinked List Content:\n";
myDblLinkedList.printList();


clsDblLinkedList<int>::node* N1 = myDblLinkedList.find(3);
if (N1 != nullptr)
cout << "\nNode with value 3 is Found :,-)";
else
cout << "\nNode is not Found :(";


myDblLinkedList.insertAfter(N1, 500);
cout << "\nAfter inserting 500 after 3:\n";
myDblLinkedList.printList();

myDblLinkedList.insertAtBack(700);
cout << "\nInsert at end 700:\n";
myDblLinkedList.printList();

myDblLinkedList.deleteFirstNode();
cout << "\nDelete First Node:\n";
myDblLinkedList.printList();

myDblLinkedList.deleteLastNode();
cout << "\nDelete Last Node:\n";
myDblLinkedList.printList();

myDblLinkedList.deleteNode(N1);
cout << "\nDelete 3:\n";
myDblLinkedList.printList();

myDblLinkedList.reverse();
cout << "\nList after reverse\n";
myDblLinkedList.printList();

clsDblLinkedList<int>::node * N2;
N2  = myDblLinkedList.getNode(1);
cout << "\nNode value is: " << N2->value << endl;

int res = myDblLinkedList.getItem(1);
cout << "\nItem(1) Value is: " << res;

myDblLinkedList.updateItem(1, 200);
cout << "\nAfter Updating item:\n";
myDblLinkedList.printList();

myDblLinkedList.clear();
cout << "\nNumber of items in the Linked List after Clear = " << myDblLinkedList.getSize() << '\n';

if (myDblLinkedList.isEmpty())
cout << "\nYes, List is empty\n";
else
cout << "\nNo, List is not empty\n";


return 0;
}

*/