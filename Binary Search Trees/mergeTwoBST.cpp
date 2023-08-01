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

void inorder(Node *root, vector<int> &v)
{
    if (root == nullptr)
        return;
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
}

void merge(vector<int> &res, vector<int> v1, vector<int> v2)
{
    int i = 0, j = 0;

    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] > v2[j])
        {
            res.push_back(v2[j]);
            j++;
        }
        else
        {
            res.push_back(v1[i]);
            i++;
        }
    }

    while (i < v1.size())
    {

        res.push_back(v1[i]);
        i++;
    }
    while (j < v2.size())
    {
        res.push_back(v2[j]);
        j++;
    }
}

vector<int> merge(Node *root1, Node *root2)
{
    // Your code here
    vector<int> v1;
    vector<int> v2;
    vector<int> res;
    inorder(root1, v1);
    inorder(root2, v2);

    merge(res, v1, v2);

    return res;
}