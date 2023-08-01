#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node * left;
    Node * right;
    Node(int x , Node * l = nullptr , Node * r = nullptr){
        data = x;
        left = l;
        right = r;
    }
};


class Solution {
    private:
    int countNodes(Node* root){
        if(root == nullptr) return 0;
        return 1+countNodes(root->left) +countNodes(root->right);
    }
    
    bool isCBT(Node* root , int n , int i){
        if(root == nullptr) return true;
        if(i >= n) return false;
        
        return isCBT(root->left, n , 2*i+1) && isCBT(root->right, n , 2*i+2);
        
    }
    
    bool isMaxHeap(Node* root){
        if(root == nullptr) return true;
        if(root->left == nullptr && root->right == nullptr){
            return true;
        }
        if(root ->right == nullptr){
            return (root->left->data < root->data) && isMaxHeap(root->left);
        }
        
        return ((root->left->data < root->data) && (root->right->data < root->data)) && (isMaxHeap(root->left) && isMaxHeap(root->right));
    }
  public:
    bool isHeap(struct Node* tree) {
        // code here
        int nodes = countNodes(tree);
        return isCBT(tree , nodes , 0) && isMaxHeap(tree);
    }
};