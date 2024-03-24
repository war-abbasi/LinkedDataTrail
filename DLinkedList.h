#include "Node.h"
class DLinkedList
{
    Node *First;
    Node *Last;
public:
    DLinkedList()
    {
        First = nullptr;
        Last = nullptr;
    }
    bool IsEmpty();
    void Display();
    void DisplayReverse();
    void InsertAtStart(int RegNo, string  Name);
    void InsertAtEnd(int RegNo, string Name);
    void InsertBefore(int RegNo, string Name);
    void InsertAfter(int RegNo, string Name);
    void DeleteItem(int RegNo);
    void FindByName(string Name);
    void FindByRegNo(int RegNo);
    ~DLinkedList()
    {
        Node* temp = First;
        while (temp != nullptr)
        {
            First = First->next;
            delete temp;
            temp = First;
        }
        First = nullptr;
        Last = nullptr;
    }
};