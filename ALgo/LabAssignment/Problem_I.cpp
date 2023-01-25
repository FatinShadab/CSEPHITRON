/*
    Write code to solve the single source shortest path problem on a DAG using DFS.
    Take both the DAG and the source node as input and output the distance of each
    node.
    (You can choose any graph representation or input format of your choice)

    Sample Input:
        The DAG :
            0 -----> 1       2 -----> 3
                    |        |
                    |        |
                    5 -----> 4

        Input:
            6 5
            0 1
            2 3
            1 5
            5 4
            4 2
            0

    Sample Input:
        Output:
            if src : 0
                src : 0 --> node : 0 --> distance : 0
                src : 0 --> node : 1 --> distance : 1
                src : 0 --> node : 2 --> distance : 4
                src : 0 --> node : 3 --> distance : 5
                src : 0 --> node : 4 --> distance : 3
                src : 0 --> node : 5 --> distance : 2
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 10e5;

vector <int> adj_list[N];
int visited[N];
int levels[N];

void DFS(int node){
    visited[node] = 1;
    if (levels[node] == -1)
        levels[node] = 0;

    for (int adjNode : adj_list[node]){
        if (!visited[adjNode]){
            levels[adjNode] = levels[node] + 1;
            DFS(adjNode);
        }
    }
}

int main(){
    int n, m;
    printf("\nEnter the n and m : ");
    scanf("%d %d", &n, &m);

    // Initially set the levels to -1
    for(int i=0; i<n; levels[i++] = -1);

    printf("\nEnter the %d edges (u, v) [0 <= u,v < %d]: \n", m, n);
    while (m--){
        int u, v;
        scanf("%d %d", &u, &v);

        adj_list[u].push_back(v);
    }

    int srcNode;
    printf("\nEnter the srouce node [0<= src < %d]: ", n);
    scanf("%d", &srcNode);

    DFS(srcNode);

    printf("\nShortest Distance of all nodes from '%d' :\n", srcNode);
    for (int node=0; node < n; node++){
        printf("\tSRC : %d ---> Node : %d ---> Distance : %d\n", srcNode, node, levels[node]);
    }

    return 0;
}