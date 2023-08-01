#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dijkstras(int n, vector<vector<int>> adj[], int S) {
    vector<int> dist(n, INT16_MAX); 
    dist[S] = 0; 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, S));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto i : adj[u]) {
            int v = i[0];
            int weight = i[1];

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}

vector<int> shortestPath(int src, int dest, vector<int> dist, vector<vector<int>> adj[]) {
    vector<int> path;
    path.push_back(dest);
    int cur = dest;
    while (cur != src) {
        for (auto neighbor : adj[cur]) {
            int neighborNode = neighbor[0];
            int edgeWeight = neighbor[1];
            if (dist[neighborNode] + edgeWeight == dist[cur]) {
                path.push_back(neighborNode);
                cur = neighborNode;
                break;
            }
        }
    }
    
    reverse(path.begin(), path.end());
    return path;
}