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

Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (!root)
        return nullptr;

    if (root->val > p->val && root->val > q->val)
    {
        return lowestCommonAncestor(root->left, p, q);
    }
    if (root->val < p->val && root->val < q->val)
    {
        return lowestCommonAncestor(root->right, p, q);
    }
    return root;
}