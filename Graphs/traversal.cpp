#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Breadth First Search
void BFS(vector<vector<int>> adjList, int node)
{
    int n = adjList.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(node);
    visited[node] = true;

    while (!q.empty())
    {
        int currNode = q.front();
        q.pop();

        cout << currNode << "  ";

        for (int i = 0; i < adjList[currNode].size(); i++)
        {
            int nxtNode = adjList[currNode][i];
            if (!visited[nxtNode])
            {
                visited[nxtNode] = true;
                q.push(nxtNode);
            }
        }
    }

    cout << endl;
}

// Depth First Search

void doDFS(vector<vector<int>> &adjList, int node, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << "  ";
    for (int i = 0; i < adjList[node].size(); i++)
    {
        int currNode = adjList[node][i];
        if (!visited[currNode])
        {
            doDFS(adjList, currNode, visited);
        }
    }
}

void DFS(vector<vector<int>> &adjList)
{

    int n = adjList.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            doDFS(adjList, i, visited);
        }
    }

    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> adjList(6);
    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[1].push_back(3);
    adjList[1].push_back(4);
    adjList[2].push_back(3);
    adjList[2].push_back(5);
    adjList[3].push_back(4);
    adjList[3].push_back(5);

    DFS(adjList);
    BFS(adjList , 0);
    return 0;
}
