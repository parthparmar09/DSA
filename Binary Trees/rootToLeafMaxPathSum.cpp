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

//return maximum sum of the longest path from the root to a leaf in the tree
void doTraverse(Node* root , pair<int,int> &res , pair<int,int> tmp){

    if(root == nullptr){
        if(tmp.first > res.first){
            res = tmp;
        }
        else if(tmp.first == res.first){
            res.second = max(res.second , tmp.second);
        }

        return;
    }

    tmp.first++;
    tmp.second += root -> val;

    doTraverse(root ->left , res , tmp);
    doTraverse(root ->right , res , tmp);

}

int sumOfLongRootToLeafPath(Node *root)
{
    pair<int ,int> res = make_pair(0,0);
    pair<int ,int> tmp = make_pair(0,0);
    if(root == nullptr){
        return 0;
    }
    doTraverse(root , res , tmp);

    return res.second;
}

int main(int argc, char const *argv[])
{

    return 0;
}
