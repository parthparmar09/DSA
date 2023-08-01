
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
    class Cmp
    {
    public:
        bool operator()(ListNode *x, ListNode *y) const
        {
            return x->val > y->val;
        }
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = new ListNode(-1);

        priority_queue<ListNode *, vector<ListNode *>, Cmp> pq;
        for (auto head : lists)
        {
            if (head == nullptr)
                continue;
            pq.push(head);
        }

        ListNode *temp = head;
        while (!pq.empty())
        {
            ListNode *tmp = pq.top();
            pq.pop();

            temp->next = tmp;

            if (tmp->next)
                pq.push(tmp->next);

            temp = temp->next;
        }

        return head->next;
    }
};