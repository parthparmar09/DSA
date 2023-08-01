#include<iostream>
using namespace std;

class Node {
    public:
    int val;
    Node * left;
    Node * right;
    Node(int x , Node * l = nullptr , Node * r = nullptr){
        val = x;
        left = l;
        right = r;
    }
};

Node * buildTree(Node * root){
    int x;
    cout << "enter data :" << endl;
    cin >> x;
    root = new Node(x);

    if(x == -1){
        return nullptr;
    }

    cout << "enter data for left node of " << x << "node" << endl;
    root -> left = buildTree(root ->left);
    cout << "enter data for right node of " << x << "node" << endl;
    root -> right = buildTree(root ->right);

    return root;

}
int main(int argc, char const *argv[])
{
    Node * root = nullptr;
    root = buildTree(root);

    return 0;
}
