#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topologicalSortKahn(vector<vector<int>> &adjList, int n)
{
    vector<int> res;
    vector<int> inDegree(n);
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        for (auto j : adjList[i])
        {
            inDegree[j]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        res.push_back(curr);

        for (auto i : adjList[curr])
        {
            if (--inDegree[i] == 0)
                q.push(i);
        }
    }

    if (res.size() != n)
    {
        cout << "Invalid DAG " << endl;
        return {};
    }

    return res;
}

void doDFS(int node, vector<vector<int>> &transpose, vector<bool> &visited, int &SCC)
{
    visited[node] = true;

    for (auto adj : transpose[node])
    {
        if (visited[adj])
        {
            SCC++;
        }
        else
        {
            doDFS(adj, transpose, visited, SCC);
        }
    }
}

int kosaraju(int n, vector<vector<int>> &adjList)
{
    int SCC = 0;
    vector<bool> visited(n, false);
    vector<int> topSort = topologicalSortKahn(adjList, n);
    vector<vector<int>> transpose(n);

    for (int u = 0; u < n; u++)
    {
        for (auto v : adjList[u])
        {
            transpose[v].push_back(u);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[topSort[i]])
            doDFS(topSort[i], transpose, visited, SCC);
    }
    return SCC;
}