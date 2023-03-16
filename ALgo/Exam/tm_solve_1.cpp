/*
    Question:
    ---------
        Write code to create a directed graph with 100 nodes where each node is numbered
        between 2 and 101. There exists an edge from node-A to node-B if  node-B is a 
        multiple of node-A.	10

        For example, the node 50 should have directed edges to node 50 and node 100.
        (as both 50 and 100 are multiples of 50)

        Use adjacency list as your graph representation.
*/

#include <bits/stdc++.h>
using namespace std;
#define N 102

int main(){
    vector <int> adjList[N];

    for (int i=2; i<N; i++){
        for (int j=1; j==j; j++){
            if (i*j < N){
                adjList[i].push_back(i*j);
            }
            else{
                break;
            }
        }
    }

    for (int i=2; i<N; i++){
        printf("%d -> ", i);
        for (int j : adjList[i]){
            printf("%d ", j);
        }
        puts("");
    }

    return 0;
}