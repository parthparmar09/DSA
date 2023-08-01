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

//boundary traversal
//first print all left nodes(excluding leaf nodes) , then print all leaf nodes and then all right nodes in reverse order(excluding leaf)
vector <int> boundary(Node *root)
{
    vector<int> res;
    if(root == nullptr){
        return res;
    }

    res.push_back(root -> val);

    //for left nodes
    goLeft(root->left , res);

    //for leaf nodes
    //same as InOrder traversal
    forLeaf(root->left , res);
    forLeaf(root->right , res);

    //for right nodes in reverse
    goRight(root->right ,res);
}

void goLeft(Node* root , vector<int> &res){
    if((root == nullptr) || (root->left == nullptr && root->right == nullptr)){
        return;
    }
    res.push_back(root->val);
    if(root->left){
    goLeft(root->left , res);
    }else{
        goLeft(root->right , res);
    }
}

void forLeaf(Node* root , vector<int> & res){
    if(root == nullptr){
        return;
    }
    if(root->left == nullptr && root->right == nullptr){
        res.push_back(root->val);
        return;
    }

    forLeaf(root ->left , res);
    forLeaf(root ->right  ,res);
}

void goRight(Node* root , vector<int> &res){
    if((root == nullptr) || (root->left == nullptr && root->right == nullptr)){
        return;
    }
    if(root->right){
    goRight(root->right , res);
    }else{
        goRight(root->left , res);
    }
    res.push_back(root->val);
}
