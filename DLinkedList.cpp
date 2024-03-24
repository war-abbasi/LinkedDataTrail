#include "DLinkedList.h"
#include <iostream>
using namespace std;

bool DLinkedList :: IsEmpty()
{
    if (First == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void DLinkedList :: Display()
{
    Node *temp = First;
    while(temp != nullptr)
    {
        cout << "Registration Number: " << temp->RegNo << ", Name: " << temp->Name <<endl;
        temp=temp->next;
    }
}
void DLinkedList :: DisplayReverse()
{
    Node *temp = Last;
    while(temp != nullptr)
    {
        cout << "Registration Number: " << temp->RegNo << ", Name: " << temp->Name <<endl;
        temp=temp->prev;
    }
}
void DLinkedList :: InsertAtStart(int RegNo, string Name)
{
  Node* temp = new Node(RegNo, Name);
    if (First == nullptr)
    {
        First = temp;
        Last = temp;
    }
    else
    {
        temp->next = First;
        First->prev = temp;
        First = temp;
    }
    Display();
}
void DLinkedList :: InsertAtEnd(int RegNo, string  Name)
{
    Node* temp = new Node(RegNo, Name);
    if (First == nullptr)
    {
        First = temp;
        Last = temp;
    }
    else
    {
        Last->next = temp;
        temp->prev = Last;
        Last = temp;
    }

    Display();
}


void DLinkedList::InsertBefore(int RegNo, string Name)
{
    if (First == nullptr)
    {
        cout << "List is empty. Cannot insert before." << endl;
        return;
    }

    Node* c = First;
    while (c != nullptr && c->RegNo != RegNo)
    {
        c = c->next;
    }

    if (c == nullptr)
    {
        cout << "Registration number not found. Cannot insert before." << endl;
        return;
    }

    // Create a new registration number for the new node
    int newRegNo; // You may generate this dynamically or from user input
    cout << "Enter the registration number for the new node: ";
    cin >> newRegNo;

    Node* temp = new Node(newRegNo, Name); // Use the new registration number
    if (c == First) {
        temp->next = First;
        First->prev = temp;
        First = temp;
    } else {
        temp->prev = c->prev;
        temp->next = c;
        c->prev->next = temp;
        c->prev = temp;
    }
    Display();
}


void DLinkedList::InsertAfter(int RegNo, string Name) {
    if (First == nullptr) {
        cout << "List is empty. Cannot insert after." << endl;
        return;
    }

    Node* c = First;
    while (c != nullptr && c->RegNo != RegNo) {
        c = c->next;
    }

    if (c == nullptr) {
        cout << "Registration number not found. Cannot insert after." << endl;
        return;
    }

    // Create a new registration number for the new node
    int newRegNo; // You may generate this dynamically or from user input
    cout << "Enter the registration number for the new node: ";
    cin >> newRegNo;

    Node* temp = new Node(newRegNo, Name); // Use the new registration number
    if (c == Last) {
        temp->prev = Last;
        Last->next = temp;
        Last = temp;
    } else {
        temp->next = c->next;
        temp->prev = c;
        c->next->prev = temp;
        c->next = temp;
    }
    Display();
}
void DLinkedList::DeleteItem(int RegNo) {
    if (First == nullptr) {
        cout << "List is empty. Cannot delete item." << endl;
        return;
    }

    Node* current = First;
    Node* prev = nullptr;

    // Search for the node to delete
    while (current != nullptr && current->RegNo != RegNo) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Registration number not found. Cannot delete item." << endl;
        return;
    }

    // If the node to delete is the first node
    if (prev == nullptr) {
        First = current->next;
    } else {
        prev->next = current->next;
    }

    // If the node to delete is the last node
    if (current == Last) {
        Last = prev;
    }

    delete current;
    cout << "Node with registration number " << RegNo << " deleted successfully." << endl;
}

void DLinkedList::FindByName( string Name) {
    if (First == nullptr) {
        cout << "List is empty. Cannot find by name." << endl;
        return;
    }

    Node* current = First;
    bool found = false;

    while (current != nullptr) {
        if (current->Name == Name) {
            cout << "Node found with registration number: " << current->RegNo << endl;
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        cout << "No node found with name: " << Name << endl;
    }
}

void DLinkedList::FindByRegNo(int RegNo) {
    if (First == nullptr) {
        cout << "List is empty. Cannot find by registration number." << endl;
        return;
    }

    Node* current = First;
    bool found = false;

    while (current != nullptr) {
        if (current->RegNo == RegNo) {
            cout << "Node found with name: " << current->Name << endl;
            found = true;
            break;
        }
        current = current->next;
    }

    if (!found) {
        cout << "No node found with registration number: " << RegNo << endl;
    }
}
