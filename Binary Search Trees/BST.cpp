// BST insertion complexity = O(log n) worst O(n)
// search O(log n) worst O(n)
// deletion

// BST inorder traversal gives element in sorted form

// inorder predeccesor - max node in LST
// inorder succesor - min node in RST

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

void insert(Node *&root, int x)
{
    if (!root)
    {
        root = new Node(x);
        return;
    }

    if (x > root->val)
    {
        insert(root->right, x);
    }
    else
    {
        insert(root->left, x);
    }
}

Node *search(Node *root, int x)
{
    if (!root)
    {
        return nullptr;
    }

    if (root->val == x)
    {
        return root;
    }

    if (x > root->val)
    {
        return search(root->right, x);
    }

    return search(root->left, x);
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

Node *findMin(Node *root)
{
    if (!root->left)
        return root;

    return findMin(root->left);
}

Node *findMax(Node *root)
{
    if (!root->right)
        return root;

    return findMax(root->right);
}

pair<Node *, Node *> inorderPredecessorAndSuccessor(Node *root, int key)
{

    pair<Node *, Node *> p = make_pair(nullptr, nullptr);

    root = search(root, key);

    if (!root)
        return p;

    if (root->left)
        p.first = findMax(root->left);
    if (root->right)
        p.second = findMin(root->right);

    return p;
}

Node *deleteNode(Node *root, int x)
{
    if (!root)
        return nullptr;

    if (x < root->val)
    {
        root->left = deleteNode(root->left, x);
    }
    else if (x > root->val)
    {
        root->right = deleteNode(root->right, x);
    }
    else
    {

        if (!root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *max = findMax(root->left);
        root->val = max->val;
        root->left = deleteNode(root->left , max->val);
    }

    return root;
}

int main(int argc, char const *argv[])
{
    vector<int> v = {3, 5, 1, -1, 0, 8, 4};
    Node *root = nullptr;
    for (int i = 0; i < v.size(); i++)
    {
        insert(root, v[i]);
    }

    // cout<<(bool)search(root , 11) << endl;

    inOrder(root);
    cout << endl;

    cout << findMin(root)->val << " , " << findMax(root)->val << endl;

    pair<Node *, Node *> p = inorderPredecessorAndSuccessor(root, 3);
    cout << p.first->val << " , " << p.second->val << endl;

    return 0;
}
