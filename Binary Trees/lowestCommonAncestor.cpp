#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int x, Node *l = nullptr, Node *r = nullptr)
    {
        val = x;
        left = l;
        right = r;
    }
};

Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (root == nullptr)
    {
        return root;
    }

    if (root == p || root == q)
    {
        return root;
    }

    Node *left = lowestCommonAncestor(root->left, p, q);
    Node *right = lowestCommonAncestor(root->right, p, q);

    if (left != nullptr && right != nullptr)
    {
        return root;
    }
    if (left == nullptr)
    {
        return right;
    }
    return left;
}