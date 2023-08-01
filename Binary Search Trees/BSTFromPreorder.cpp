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

Node *solve(vector<int> &preorder, int s, int e)
{
    if (s > e) return nullptr;

    int rootVal = preorder[s];

    int index = s;
    while(index <= e){
        if(preorder[index] > rootVal){
            break;
        }
        index++;
    }

    Node *root = new Node(rootVal);
    root->left = solve(preorder , s+1 , index-1);
    root->right= solve(preorder , index , e);

    return root;
}

Node *BSTfromPreorder(vector<int> &preorder)
{

    
}
