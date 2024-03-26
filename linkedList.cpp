//
// Created by Ayman yassien on 16/01/2024 AD.
//
#pragma once
#include <iostream>
#include "node.h"

using namespace std;

//why send by ref if you insert at begaining .

void insertAtBeganning(node* &head, int value)
{
    node * new_node =new node();

    new_node->value = value;
    new_node->next  = head;

    head = new_node;
}

void printList(node * head)
{
    while (head != NULL)
    {
        cout << head->value << '\n';
        head = head->next;
    }
}

node* find(node * head, int value)
{
    while (head != NULL)
    {
        if (head->value == value)
            return head;
        head = head->next;
    }
    return NULL;

}
// this function type is pointer of node, so must return object of node, and obj will create in main is pointer of node not node obj
// but if function type is node, we will return "*nodeName" => which mean actual value in this pointer "nodeName", and obj will be node type

void insertAfter(node * prev, int newValue)
{
    if (prev == NULL)
    {
        cout << "Node is Null ):\n";
        return;
    }
    node * new_node = new node();

    new_node->value = newValue;

    new_node->next = prev->next;
    prev->next     = new_node;

}

void insertAtEnd(node* &head, int newValue)
{

    node * new_node = new node();
    new_node->value = newValue;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
        return;
    }

    node* last_node = head;
    while (last_node->next != NULL)
        last_node = last_node->next;

    last_node->next = new_node;
    return;

}

void deleteNode(node* &head, int value)
{
    node * current = head, *prev = head;

    if (head == NULL)
    {
        cout << "Null";
        return;
    }

    if (current->value == value)
    {
        head = current->next;
        delete current;
    }

    while (current != NULL && current->value != value)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL) return;

    prev->next = current->next;
    delete current;

}

void deleteFirstNode(node * &head)
{
    node * current = head;

    if (head == NULL)
    {
        cout << "Null";
        return;
    }

    head = current->next;
    delete current;

}

void deleteLastNode(node* &head)
{
    node * current = head, *prev = head;

    if (head == NULL)
    {
        cout << "Null";
        return;
    }

    while (current != NULL && current->next != NULL )
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL) return;

    prev->next = NULL;
    delete current;
}

int main() {

    node* head;

    // declare pointer in stack
    node* node1 = NULL;
    node* node2 = NULL;
    node* node3 = NULL;

    //allocate 3 nodes in heap
    node1 = new node();
    node2 = new node();
    node3 = new node();

    // assign values
    node1->value = 10;
    node2->value = 20;
    node3->value = 30;

    // connect nodes
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    head = node1;

    insertAtBeganning(head,1);
    insertAtBeganning(head,2);
    insertAtBeganning(head,5);


    node* n1 = find(head, 5); // be smart when create and call this function .
    insertAfter(n1, 500);

    insertAtEnd(head, 1000);
    insertAtEnd(head, 5000);
    insertAtEnd(head, 6000);

    deleteNode(head, 1000);

    deleteFirstNode(head);

    deleteLastNode(head);

    printList(head);

    return 0;
}
