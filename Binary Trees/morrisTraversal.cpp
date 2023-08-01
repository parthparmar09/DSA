#include <iostream>
#include <queue>
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

void morrisPreorder(Node *root)
{
    Node *curr = root;
    Node *prev = nullptr;

    while (curr)
    {
        if (curr->left)
        {
            prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }

            if (prev->right == curr)
            {
                prev->right = nullptr;
                curr = curr->right;
            }
            else
            {
                cout << curr->val << " ,  ";
                prev->right = curr;
                curr = curr->left;
            }
        }
        else
        {
            cout << curr->val << " ,  ";
            curr = curr->right;
        }
    }
}

void morrisInorder(Node *root)
{
    Node *curr = root;
    Node *prev = nullptr;

    while (curr)
    {
        if (curr->left)
        {
            prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }

            if (prev->right == curr)
            {
                cout << curr->val << " ,  ";
                prev->right = nullptr;
                curr = curr->right;
            }
            else
            {
                prev->right = curr;
                curr = curr->left;
            }
        }
        else
        {
            cout << curr->val << " ,  ";
            curr = curr->right;
        }
    }
}

// flatten a binary tree into linked list
// same as morris's preorder traversal

void flatten(Node *root)
{
     Node *curr = root;
    Node *prev = nullptr;

    while (curr)
    {
        if (curr->left)
        {
            prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }

            if (prev->right == curr)
            {
                prev->right = nullptr;
                curr = curr->right;
            }
            else
            {
                prev->right = curr->right;
                curr->right= curr->left;
                curr->left = nullptr;
            }
        }
        else
        {
            curr = curr->right;
        }
    }

}