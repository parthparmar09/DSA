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

bool findPath(Node* root ,int node , vector<int> &path){
    if(root == nullptr){
        return false;
    }

    path.push_back(root ->val);

    if(root -> val == node){
        return true;
    }

    if(findPath(root->left , node , path) || findPath(root ->right , node ,path)){
        return true;
    }

    path.pop_back();
    return false;

}
int kthAncestor(Node *root, int k, int node)
{
    vector<int> path;
    findPath(root , node , path);

       if(path.size() > k){
        return path[path.size() - k - 1]; // subtract 1 from k to get correct index
    }
    
    return -1;
}