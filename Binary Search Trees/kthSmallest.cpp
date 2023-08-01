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

int inorder(Node* root, int k , int &ref){
    if(!root) return -1;

    int left = inorder(root->left , k , ref);
    ref++;
    if(ref == k){
        return root->val;
    }
    
    int right = inorder(root->right , k , ref);

    if(left >= 0){
        return left;
    }
    return right;
}

int kthSmallest(Node * root  , int k){
    int ref = 0;
    return inorder(root , k , ref);
}