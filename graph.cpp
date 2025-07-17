#include<iostream>
#include <vector>
#include <list>
#include<queue>
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

    void BFS(int start){
        vector<bool> visited(numVertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout<<"BFS starting from vertex "<<start<<": ";

        while (!q.empty()){
            int vertex = q.front();
            q.pop();
            cout<<vertex<<" ";
            for(int neighbor: adjList[vertex]){
                if (!visited[neighbor]){
                    visited[neighbor]=true;
                    q.push(neighbor);
                }
            }
        }

        cout<<endl;
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

    g.BFS(0);



    return 0;
}