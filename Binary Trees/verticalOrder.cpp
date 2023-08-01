#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
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
//traverse column wise , if multiple nodes be on same row(level) and same column(horizontal distance) then sort them in increasing order

vector<vector<int>> verticalTraversal(Node *root)
{

    vector<vector<int>> res;

    if(root == nullptr){
        return res;
    }


    map<int , map<int , vector<int>>> mp;

    doTraverse(root , 0, 0 , mp);

    for(auto i : mp){
        vector<int> temp;
        for(auto j : i.second){
            sort(j.second.begin() , j.second.end());
            for(auto k : j.second){
                temp.push_back(k);
            }
        }
        res.push_back(temp);
    }


    return res;

}

void doTraverse(Node * root , int col , int row , map<int , map<int , vector<int>>> &mp){
    //following inOrder Traversal
    if(root == nullptr){
        return;
    }
    
    //go left
    doTraverse(root -> left , col-1 , row+1 , mp);

    //visit
    mp[col][row].push_back(root -> val);

    //go right
    doTraverse(root -> right , col+1 , row+1 , mp);
}