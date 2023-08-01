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

// build from Inorder and Postorder

Node *solveInPost(vector<int> &inorder, vector<int> &postorder, int s, int e, int &index)
{
    if (s > e)
    {
        return nullptr;
    }
    int rootVal = postorder[index--];

    int in = s;
    // can also use map instead of loop to reduce Time complexity
    while (inorder[in] != rootVal)
    {
        in++;
    }

    Node *root = new Node(rootVal);
    root->right = solveInPost(inorder, postorder, in + 1, e, index);
    root->left = solveInPost(inorder, postorder, s, in - 1, index);

    return root;
}

Node *inPostBuild(vector<int> &inorder, vector<int> &postorder)
{
    int end = inorder.size() - 1;
    return solveInPost(inorder, postorder, 0, end, end);
}

// build from Inorder and Preorder

Node *sovleInPre(vector<int> &inorder, vector<int> &preorder, int s, int e, int &index, map<int, int> &mp)
{
    if (s > e)
    {
        return nullptr;
    }
    int rootVal = preorder[index++];

    int in = mp[rootVal];

    Node *root = new Node(rootVal);
    root->left = sovleInPre(inorder, preorder, s, in - 1, index, mp);
    root->right = sovleInPre(inorder, preorder, in + 1, e, index, mp);

    return root;
}

Node *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int size = inorder.size();
    map<int, int> mp;
    for (int i = 0; i < size; i++)
    {
        mp[inorder[i]] = i;
    }
    int index = 0;
    return sovleInPre(inorder, preorder, 0, size - 1, index, mp);
}