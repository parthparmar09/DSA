
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
    class Node
    {
    public:
        int data;
        int row;
        int col;

        Node(int d, int r, int c)
        {
            this->data = d;
            this->row = r;
            this->col = c;
        }
    };
    class Cmp
    {
    public:
        bool operator()(Node *x, Node *y) const
        {
            return x->data > y->data;
        }
    };

public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        // code here
        vector<int> res;
        priority_queue<Node *, vector<Node *>, Cmp> pq;

        for (int i = 0; i < arr.size(); i++)
        {
            pq.push(new Node(arr[i][0], i, 0));
        }

        while (!pq.empty())
        {
            Node *temp = pq.top();
            pq.pop();

            res.push_back(temp->data);

            int row = temp->row;
            int col = temp->col;

            if (++col < k)
            {
                pq.push(new Node(arr[row][col], row, col));
            }
        }

        return res;
    }
};