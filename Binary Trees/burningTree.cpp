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

// same as breath first search (BFS)

void createMaps(Node *root, map<Node *, Node *> &mp, map<Node *, bool> &visited)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->left)
    {
        mp[root->left] = root;
        visited[root->left] = false;
        createMaps(root->left, mp, visited);
    }

    if (root->right)
    {
        mp[root->right] = root;
        visited[root->right] = false;
        createMaps(root->right, mp, visited);
    }
}

Node *findTarget(Node *root, int target)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->val == target)
    {
        return root;
    }

    Node *left = findTarget(root->left, target);
    Node *right = findTarget(root->right, target);

    if (left == nullptr && right == nullptr)
    {
        return nullptr;
    }
    if (left != nullptr)
    {
        return left;
    }
    return right;
}

int burnTree(Node *root, map<Node *, Node *> &mp, map<Node *, bool> &visited)
{
    int time = 0;
    if(root == nullptr){
        return time;
    }

    queue<Node *> q;
    q.push(root);
    visited[root] = true;

    while (!q.empty())
    {
        bool inserted = false;
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left && !visited[temp->left])
            {
                q.push(temp->left);
                visited[temp->left] = true;
                inserted = true;
            }

            if (temp->right && !visited[temp->right])
            {
                q.push(temp->right);
                visited[temp->right] = true;
                inserted = true;
            }

            if (mp[temp] && !visited[mp[temp]])
            {
                q.push(mp[temp]);
                visited[mp[temp]] = true;
                inserted = true;
            }
        }

        if (inserted)
        {
            time++;
        }
    }

    return time;
}

int minTime(Node *root, int target)
{

    // map representing parent node , child as a key
    map<Node *, Node *> mp;
    map<Node *, bool> visited;
    createMaps(root, mp, visited);
    Node *targetNode = findTarget(root, target);

    return burnTree(targetNode , mp , visited);
}