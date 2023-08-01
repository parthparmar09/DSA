#include <iostream>
#include <vector>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    vector<int> dist(V, INT16_MAX);
    dist[S] = 0;

    for (int i = 0; i < V; i++)
    {
        for (auto edge : edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (auto edge : edges)
    {
        int u = edge[0], v = edge[1], w = edge[2];
        if (dist[v] > dist[u] + w)
        {
            cout << "Negative cycle detected" << endl;
            return {};
        }
    }

    return dist;
}