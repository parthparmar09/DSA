#include <iostream>
#include <queue>
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

Node *buildTree(Node *root)
{
    int x;
    cout << "enter data :" << endl;
    cin >> x;
    root = new Node(x);

    if (x == -1)
    {
        return nullptr;
    }

    cout << "enter data for left node of " << x << "node" << endl;
    root->left = buildTree(root->left);
    cout << "enter data for right node of " << x << "node" << endl;
    root->right = buildTree(root->right);

    return root;
}

void preOrder(Node *root)
{
    // vlr

    if (root == nullptr)
    {
        return;
    }

    cout << root->val << " , ";

    preOrder(root->left);

    preOrder(root->right);
}
void inOrder(Node *root)
{
    // lvr
    if (root == nullptr)
    {
        return;
    }

    inOrder(root->left);
    cout << root->val << " , ";
    inOrder(root->right);
}
void postOrder(Node *root)
{
    // lrv
    if (root == nullptr)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " , ";
}

vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> res;

    if (root == nullptr)
    {
        return res;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    vector<int> lvl;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        bool z = true;

        if (temp == NULL)
        {
            res.push_back(lvl);
            lvl.clear();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            lvl.push_back(temp->val);

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }

    return res;
}

vector<vector<int>> zigzagLevelOrder(Node *root)
{
    vector<vector<int>> res;

    if (root == nullptr)
    {
        return res;
    }

    queue<Node *> q;
    q.push(root);

    bool z = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> tmp(size);

        for(int i = 0 ; i<size ; i++){
            Node* temp = q.front();
            q.pop();

            int index = z ? i : size - i;
            tmp[index] = temp -> val;

            if(temp -> left) q.push(temp->left);
            if(temp -> right) q.push(temp->right);
        }

        res.push_back(tmp);

    }

    return res;
}



int main(int argc, char const *argv[])
{
    Node *root = nullptr;
    root = buildTree(root);

    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    levelOrder(root);

    // 1 2 4 8 -1 -1 9 -1 -1 5 10 -1 -1 -1 3 6 11 -1 -1 12 -1 -1 7 13 -1 -1 -1

    return 0;
}