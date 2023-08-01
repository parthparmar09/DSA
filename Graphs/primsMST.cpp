#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int primsMST(int n , vector<vector<int>> adjList[] , int S){
    vector<bool> visited(n , false);
    vector<int> dist(n , INT16_MAX);
    vector<int> parent(n , -1);
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

    //for source node--
    dist[S] = 0;
    parent[S] = S;
    pq.push(make_pair(0 , S));

    while (!pq.empty())
    {
        int curr = pq.top().second;
        pq.pop();

        visited[curr] = true;

        for(auto i : adjList[curr]){
            int v = i[0] , w = i[1];

            if(visited[v]) continue;

            if(dist[v] > w){
                dist[v] = w;
                parent[v] = curr;
                pq.push(make_pair(dist[v] , v));
            }
        }


    }

    int sum = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        // check if all vertices are visited
        if (!visited[i])
            return -1;

        sum += dist[i];
        count++;
    }

    // check for disconnected graph
    if (count != n)
        return -1;

    return sum;
        
}