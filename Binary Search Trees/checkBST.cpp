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

bool checkBST(Node* root , int min  , int max){
    if(!root) return true;

    if(root->val > max || root->val < min){
        return false;
    }

    return checkBST(root->left , min , root->val) && checkBST(root->right, root->val , max);
}
bool isValidBST(Node* root) {
    return checkBST(root , INT_MIN , INT_MAX);
}