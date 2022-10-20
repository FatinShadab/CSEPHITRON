#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> edge_weight_pair;

class Graph{
    public:
        int vertices;
        list <edge_weight_pair> *adjList;

    public:
        Graph(int vertices){
            this->vertices = vertices;
            this->adjList = new list <edge_weight_pair> [vertices];
        }

        void addEdge(int vertex, int neighbour_vertex, int weight){
            this->adjList[vertex].push_back(make_pair(neighbour_vertex, weight));
            this->adjList[neighbour_vertex].push_back(make_pair(vertex, weight));
        }

        void printNeighbor(int vertex){
            for (auto i = this->adjList[vertex].begin(); i != this->adjList[vertex].end(); i++){
                cout<<"Vertex : "<<vertex<<", Neighbor vertex : "<<(*i).first <<", Edge weight : "<<(*i).second<<endl;
            }
        }
};

int main(){
    int numberOfVertices, numberOfEdges;
    
    cout<<"Enter the number of vertices of the graph - ";
    cin>>numberOfVertices;
    cout<<"Enter the number of edges of the graph - ";
    cin>>numberOfEdges;

    Graph myGraph(numberOfVertices);

    cout<<"Enter the vertex, neighbour_vertex, weight for each vertex - "<<endl;
    for (int i=0; i<numberOfEdges; i++){
        int u, v, w;
        cin>>u>>v>>w;
        myGraph.addEdge(u, v, w);
    }

    for (int i=0; i<numberOfVertices; i++){
        myGraph.printNeighbor(i);
    }

    return 0;
}


/*
Input:
==========
7 10
0 1 7
0 2 1
0 5 3
1 3 11
2 3 3
2 5 8
3 6 1
4 5 6
4 6 4
5 6 2
*/