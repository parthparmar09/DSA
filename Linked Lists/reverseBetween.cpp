#include <iostream>
using namespace std;

class ListNode
{

public:
    int data;
    ListNode *next;

    ListNode(int val)
    {
        this->data = val;
        this->next = nullptr;
    }
    ListNode(int val, ListNode *head)
    {
        this->data = val;
        this->next = head;
    }
};
void print(ListNode *head)
{
    ListNode *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << "   ";
        curr = curr->next;
    }
    cout << endl;
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
        
}

int main(int argc, char const *argv[])
{
    ListNode *ll = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    print(ll);
    return 0;
}
