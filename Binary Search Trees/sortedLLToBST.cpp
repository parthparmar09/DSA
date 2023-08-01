#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Node
{
public:
    int val;
    Node *left, *right;

    Node(int x)
    {
        this->val = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};
class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x)
    {
        this->val = x;
        this->next = nullptr;
    }
};

Node* solve(ListNode * head , map<int ,int> mp , int s , int e){
    if(s>e) return nullptr;

    int mid = s +( e-s)/2;

    Node* root = new Node(mp[mid]);
    root->left = solve(head , mp , s , mid-1);
    root->right = solve(head , mp , mid+1 , e);

    return root;
}

Node *sortedListToBST(ListNode *head)
{
    if(head == nullptr) return nullptr;

    map<int ,int> mp;
    ListNode *temp = head;

    int size = 0;
    while (temp != nullptr)
    {
        mp[size] = temp->val;
        size++;
        temp = temp->next;
    }
    return solve(head , mp , 0 ,size-1);
    
}

void inOrder(Node *root)
{
    // vlr
    if (!root)
        return;

    inOrder(root->left);
    cout << root->val << " , ";
    inOrder(root->right);
}

int main(int argc, char const *argv[])
{
    /* [-10,-3,0,5,9]*/
    ListNode* head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(-0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);


    Node * tree = sortedListToBST(head);

    inOrder(tree);
    return 0;
}
