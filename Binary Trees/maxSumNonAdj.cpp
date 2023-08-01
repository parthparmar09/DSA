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

pair<int,int> solve(Node* root){
    if(root == nullptr){
        return make_pair(0,0);
    }

    pair<int,int> left = solve(root -> left);
    pair<int,int> right = solve(root -> right);

    pair<int, int> send;
    //include self , cant include childs
    send.first = root -> val + left.second + right .second;
    //include childs, cant include self
    send.second = max(left.first , left.second) + max(right.first , right.second)  ;

    return send;
}

int getMaxSum(Node *root)
{
    pair<int ,int> p = solve(root);

    return max(p.first , p.second);
}