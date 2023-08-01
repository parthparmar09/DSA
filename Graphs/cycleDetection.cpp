#include<iostream>
#include<vector>
using namespace std;

//most efficient way to detect cycles in a graph - using DFS

//in undirected graphs--
bool checkUG(vector<vector<int>> &adjList , int node ,vector<bool> visited , int parent ){
    visited[node] = true;
    for (int i = 0; i < adjList[node].size(); i++)
    {
        int currNode = adjList[node][i];
        if (!visited[currNode])
        {
            return checkUG(adjList, currNode, visited , node);
        }else{
            if(currNode != parent){
                return true;
            }
        }

    }
    return false;
}

bool cycleDetectUG(vector<vector<int>> &adjList){
    int n = adjList.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool check = checkUG(adjList, i, visited , -1);
            if(check) return true;
        }
    }

    return false;
}


//in directed graphs--
bool checkDG(vector<vector<int>> &adjList , int node ,vector<bool> visited , int parent ){
    visited[node] = true;
    for (int i = 0; i < adjList[node].size(); i++)
    {
        int currNode = adjList[node][i];
        if (!visited[currNode])
        {
            return checkDG(adjList, currNode, visited , node);
        }else{
            if(currNode != parent){
                return true;
            }
        }

    }
    visited[node] = false;
    return false;
}
bool cycleDetectDG(vector<vector<int>> &adjList){
    int n = adjList.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool check = checkDG(adjList, i, visited , -1);
            if(check) return true;
        }
    }

    return false;
}