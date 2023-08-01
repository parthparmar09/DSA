#include <iostream>
#include <vector>
using namespace std;

void doDFS(int node, int parent, int time, vector<int> &res, vector<int> &start, vector<int> &low, vector<bool> &visited, vector<int> adjList[])
{
    visited[node] = true;
    start[node] = low[node] = time++;

    for (auto adj : adjList[node])
    {
        if (adj == parent)
            continue;
        if (!visited[adj])
        {
            doDFS(adj, node, time, res, start, low, visited, adjList);
            low[node] = min(low[node], low[adj]);

            if (low[adj] >= start[node] && parent != -1)
            {
                res.push_back(node);
            }
        }
        else
        {
            low[node] = min(low[node], start[adj]);
        }
    }
}

vector<int> articulationPoints(int n, vector<int> adjList[])
{
    vector<int> res;
    vector<int> start(n, -1);
    vector<int> low(n, -1);
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            doDFS(i, -1, 0, res, start, low, visited, adjList);
    }

    return res;
}