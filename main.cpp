#include <iostream>
#include "DLinkedList.h"
using namespace std;

int main()
{
    DLinkedList L;
    int choice;
    int RegNo;
    string Name;

    do {
        cout << "\t\t\tSELECT AN OPTION" << endl;
        cout << "1. Display all Nodes" << endl;
        cout << "2. Display in Reverse Order" << endl;
        cout << "3. Insert Node at Start" << endl;
        cout << "4. Insert Node at End" << endl;
        cout << "5. Insert Node Before" << endl;
        cout << "6. Insert Node After" << endl;
        cout << "7. Delete Item" << endl;
        cout << "8. Find RegNo" << endl;
        cout << "9. Find Name " << endl;
        cout << "10. Exit" << endl;
        cout<<"Enter Choice "<<endl;
        cin>>choice;
        if (choice == 1)
            L.Display();
        if (choice == 2)
            L.DisplayReverse();
        if (choice == 3)
        {
            cout << "Enter registration number: ";
            cin >> RegNo;
            cout << "Enter name: ";
            cin >> Name;
            L.InsertAtStart(RegNo, Name);
        }
        if (choice == 4)
        {
            cout << "Enter registration number: ";
            cin >> RegNo;
            cout << "Enter name: ";
            cin >> Name;
            L.InsertAtEnd(RegNo, Name);
        }
        if (choice == 5)
        {
            int targetRegNo;
            cout << "Enter registration number before which you want to insert: ";
            cin >> targetRegNo;
            cout << "Enter name: ";
            cin >> Name;
            L.InsertBefore(targetRegNo, Name);
        }
        if (choice == 6)
        {
            int targetRegNo;
            cout << "Enter registration number after which you want to insert: ";
            cin >> targetRegNo;
            cout << "Enter name: ";
            cin >> Name;
            L.InsertAfter(targetRegNo, Name);
        }

        if (choice == 7)
        {
            cout << "Enter registration number to delete: ";
            cin >> RegNo;
            L.DeleteItem(RegNo);
        }
        if (choice == 8)
        {
            cout << "Enter registration number to find: ";
            cin >> RegNo;
            L.FindByRegNo(RegNo);
        }
        if (choice == 9)
        {
            cout << "Enter name to find: ";
            cin >> Name;
            L.FindByName(Name);
        }

    }while (choice != 10);
    return 0;
}