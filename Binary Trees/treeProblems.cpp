#include <iostream>
#include <queue>
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

int heightOfTree(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int height = 1 + max(heightOfTree(root->left), heightOfTree(root->right));

    return height;
}

pair<int, int> diameterOfBinaryTree(Node *root)
{
    // returns both height and diameter
    // can exist in 3 ways, 1(diameter of LST) , 2(diameter RST) ,3(height of LST + RST +1)
    if (root == nullptr)
    {
        return make_pair(0, 0);
    }

    pair<int, int> lst = diameterOfBinaryTree(root->left);
    pair<int, int> rst = diameterOfBinaryTree(root->right);

    int o1 = lst.first;
    int o2 = rst.first;
    int o3 = lst.second + rst.second;

    pair<int, int> res;
    res.first = max(o1, max(o2, o3));
    res.second = max(lst.second, rst.second) + 1;

    return res;
}

pair<bool, int> isBalanced(Node *root)
{
    // returns both height and balanced check
    if (root == nullptr)
    {
        return make_pair(true, 0);
    }
    pair<bool, int> lst = isBalanced(root->left);
    pair<bool, int> rst = isBalanced(root->right);

    pair<bool, int> ans = make_pair((lst.first && rst.first && (abs(lst.second - rst.second) <= 1)), (max(lst.second, rst.second) + 1));

    return ans;
}

bool isSameTree(Node *p, Node *q)
{
    if(p == nullptr && q == nullptr){
        return true;
    }
    if(p == nullptr || q == nullptr){
        return false;
    }
    if(p -> val != q -> val){
        return false;   
    }
    return (isSameTree(p ->left , q -> left ) & isSameTree(p ->right , q ->right));

}

pair<bool , int> isSumTree(Node* root)
    {
        if(root == nullptr){
            return make_pair(1 , 0);
        }
        
        if(root -> left == nullptr && root -> right == nullptr) return make_pair(1,root->val);
        
        pair<bool , int> l = isSumTree(root -> left);
        pair<bool , int> r = isSumTree(root -> right);

        return make_pair(l.first && r.first && (l.second + r.second == root ->val) , 2*root->val);
         
    }

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
