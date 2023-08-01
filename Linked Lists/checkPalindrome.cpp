#include <iostream>
using namespace std;

class ListNode
{

public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
    ListNode(int val, ListNode *head)
    {
        this->val = val;
        this->next = head;
    }
};

void print(ListNode *head)
{
    ListNode *curr = head;
    while (curr != nullptr)
    {
        cout << curr->val << "   ";
        curr = curr->next;
    }
    cout << endl;
}

ListNode *reverse(ListNode *&head)
{
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *temp = nullptr;

    while (curr != nullptr)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

ListNode *findMid(ListNode *&head)
{
    if (head == nullptr)
        return nullptr;

    ListNode *slow = head, *fast = head;

    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->next;
}

bool isPalindrome(ListNode *head)
{

    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *p1 = head;
    ListNode *p2 = findMid(head);
    p2 = reverse(p2);

    while (p2 != nullptr)
    {
        if (p1->val == p2->val)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main(int argc, char const *argv[])
{

    ListNode * l1 = new ListNode(5 , new  ListNode(4 , new ListNode(3 , new ListNode(3 , new  ListNode(4 , new ListNode(5) ) ))) );
    cout << isPalindrome(l1) << endl;

    return 0;
}
