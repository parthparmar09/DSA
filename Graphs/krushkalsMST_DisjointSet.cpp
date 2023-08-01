#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


class DisjointSet{
    vector<int> parent;
    vector<int> rank;

    public:
    DisjointSet(int n){
        parent.resize(n);
        rank.resize(n);

        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }


    int findSet(int i){
        int p = parent[i];
        if(p != i){
            p = findSet(p);
        }
        return p;
    }


    void unionSet(int i , int j){
        int pi = findSet(i) ,pj = findSet(j);
        if(pi == pj) return;

        if(rank[pi] >= rank[pj]){
            parent[pj] = pi;
            rank[pi]++;
        }else{
            parent[pi] = pj;
            rank[pj]++;
        }
    }
};

bool cmp(vector<int> &a , vector<int> &b){
    return a[0] < b[0];
}

int krushkalsMST(int n , vector<vector<int>> adjList[]){

 
    // priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
    vector<vector<int>> pq;

    for(int i = 0 ; i <n ; i++){
        for(auto j : adjList[i]){
            pq.push_back({j[1] , i , j[0]}); 
        }
    }

    sort(pq.begin() , pq.end() , cmp);

    DisjointSet ds(n);
    vector<int> parent(n , -1);
    int sum = 0;

    for(int i = 0 ; i< pq.size() ; i++){

        int w = pq[i][0] ,u = pq[i][1] , v = pq[i][2]; 

        if(ds.findSet(u) != ds.findSet(v)){
            ds.unionSet(u ,v);
            sum+= w;
            parent[v] = u;
        }
    }

    return sum;
}