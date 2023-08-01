#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


class UndirectedGraph{
    //using adjacency list
    public:
    int nodes;
    vector<vector<int>> adjList;

    UndirectedGraph(int n){
        this->nodes = n;
        adjList.resize(n);
    }

    void insertEdge(int u , int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void printGraph(){
        for(int i = 0 ; i < this->nodes ; i++){
            cout << i << " --> " ;
            for(int j = 0 ; j < adjList[i].size() ; j++){
                cout << adjList[i][j] << "  ";
            }
            cout << endl;
        }
    }
};

class DirectedGraph{
    //using adjacency matrix
    public:
    int nodes;
    vector<vector<int>> adjMat;

    DirectedGraph(int n){
        this->nodes = n;
        adjMat.resize(n);

        for(int i = 0 ; i < n ; i++){
            adjMat[i].resize(n);
            for(int j = 0 ; j < n ; j++){
                adjMat[i][j] = 0;
            }
        }
    }

    void insertEdge(int u , int v){
        adjMat[u][v] = 1;
    }

    void printGraph(){
        for(int i = 0 ; i < this->nodes ; i++){
            for(int j = 0 ; j < this->nodes  ; j++){
                cout << adjMat[i][j] << "  ";
            }
            cout << endl;
        }
    }

};


int main(int argc, char const *argv[])
{
    UndirectedGraph ug(5);

    ug.insertEdge(0, 1);
    ug.insertEdge(0, 4);
    ug.insertEdge(1, 2);
    ug.insertEdge(1, 3);
    ug.insertEdge(1, 4);
    ug.insertEdge(2, 3);
    ug.insertEdge(3, 4);


    DirectedGraph dg(5);
    dg.insertEdge(0, 1);
    dg.insertEdge(0, 4);
    dg.insertEdge(1, 2);
    dg.insertEdge(1, 3);
    dg.insertEdge(1, 4);
    dg.insertEdge(2, 3);
    dg.insertEdge(3, 4);


    ug.printGraph();
    cout << endl;
    dg.printGraph();

    return 0;
}
