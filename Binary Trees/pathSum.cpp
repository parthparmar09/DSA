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
//return the count of all paths whose sum is equal to the target
void solve(Node * root, vector<int> path , int target, int &count){
    if(root == nullptr){
        return;
    }

    path.push_back(root -> val);
    int sum = 0;
    for(int i = path.size() -1 ; i >= 0 ; i --){
        sum+= path[i];

        if(sum == target) count++;
    }

    solve(root->left , path,target,count);
    solve(root->right , path,target,count);
}
int pathSum(Node *root, int targetSum)
{
    int count = 0;
    vector<int> path;
    if(root == nullptr){
        return count;
    }

    solve(root , path , targetSum , count );
    return count;

}