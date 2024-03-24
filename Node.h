#include "string"
using namespace std;

class Node {
public:
    int RegNo;
    string Name;
    Node* next;
    Node* prev;
    Node(int RegNo, string Name) : RegNo(RegNo), Name(Name), next(nullptr), prev(nullptr) {}
};