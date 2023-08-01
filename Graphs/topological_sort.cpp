#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

//Kahn's algorithm - uses BFS approach
vector<int> topologicalSortKahn(vector<vector<int>> &adjList){
    vector<int> res;
    int n = adjList.size();
    vector<int> inDegree(n);
    queue<int> q;

    for(int i = 0 ; i< n ; i++){
        for(auto j : adjList[i]){
            inDegree[j]++;
        }
    }

    for(int i = 0 ; i < n ; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        res.push_back(curr);

        for(auto i : adjList[curr]){
            if(--inDegree[i] == 0)
            q.push(i);
        }
    }

    if(res.size() != n){
        cout << "Invalid DAG " << endl;
        return {};
    }

    return res;

}



//using DFS
void doDFS(vector<vector<int>> &adjList, int node, vector<bool> &visited , stack<int> &st)
{
    visited[node] = true;
    for (int i = 0; i < adjList[node].size(); i++)
    {
        int currNode = adjList[node][i];
        if (!visited[currNode])
        {
            doDFS(adjList, currNode, visited ,st);
        }
    }
    st.push(node);
}

vector<int> topologicalSortDFS(vector<vector<int>> &adjList)
{
    vector<int> res;
    int n = adjList.size();
    vector<bool> visited(n, false);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            doDFS(adjList, i, visited ,st);
        }
    }

    while (!st.empty())
    {
        /* code */
        res.push_back(st.top());
        st.pop();
    }
    
    return res;
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

    vector<int> dfs = topologicalSortDFS(adjList);
    for(auto i :dfs){
        cout << i <<"   " ;
    }
    cout << endl;

    vector<int> kahns = topologicalSortKahn(adjList);
     for(auto i :kahns){
        cout << i <<"   " ;
    }
    cout << endl;
    return 0;
}


