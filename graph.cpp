#include<iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
    int numVertices;
    bool isDirected;
    vector<list<int>> adjList;


public:
    Graph(int vertices, bool directed=false){
        numVertices = vertices;
        isDirected = directed;
        adjList.resize(vertices);
    }

    void addEdge(int u, int v){
        adjList[u].push_back(v);
        if(!isDirected){
            adjList[v].push_back(u);
        }
    }

    void printGraph(){
        for(int i=0;i<numVertices; ++i){
            cout<< "Vertex "<<i<<"-->";
            for(int neighbor : adjList[i]){
                cout<<neighbor<<" ";
            }
            cout<<endl;
        }
    }

};

int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();



    return 0;
}