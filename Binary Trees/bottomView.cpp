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



void doTraverse(Node * root , map<int,int> &mp , int col){
    if(root == nullptr){
        return ;
    }

    doTraverse(root->left , mp , col -1);
    mp[col] = root -> val;
    doTraverse(root->right , mp , col +1);
}

vector<int> bottomView(Node *root)
{
    vector<int> res; 
    if(root == nullptr){
        return res;
    }   
    map<int  , int> mp;

    doTraverse(root , mp , 0);

    for(auto i : mp){
        res.push_back(i.second);
    }

    return res;

}






int main(int argc, char const *argv[])
{
    /* code */
    Node * root = nullptr;
    root = buildTree(root);
    vector<int> res = bottomView(root);

    for(int i = 0 ; i < res.size(); i++){
        cout << res[i] << endl;
    }
    //14 14 3 -1 8 8 12 -1 6 17 3 -1 1 11 10 -1 6 6 13 -1 10 17 7 -1 11 7

    return 0;
}
