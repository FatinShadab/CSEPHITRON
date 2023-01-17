/*
Algo : Single Source Shortest Path

The graph :
0 ----- 1 ----- 2 ----- 3
        |       |
        |       |
        5 ----- 4

Input:
6 6
0 1
1 2
2 3
1 5
5 4
2 4
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 10e5;

int visited[N];
int nodeLevels[N];
vector <int> adj_list[N];

void BFS(int node){
    queue <int> temp;

    temp.push(node);
    visited[node] = 1;
    nodeLevels[node] = 0;

    while (!temp.empty()){
        int current_node = temp.front();
        temp.pop();

        for (int adj_node : adj_list[current_node]){
            if (!visited[adj_node]){
                temp.push(adj_node);
                visited[adj_node] = 1;
                nodeLevels[adj_node] = nodeLevels[current_node] + 1;
            }
        }
    }

    return;
}

int main(){
    int n, e;
    scanf("%d %d", &n, &e);

    while (e--){
        int u, v;
        scanf("%d %d", &u, &v);

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    BFS(0);

    for (int i=0; i<n; i++){
        printf("Node: %d, Level: %d\n", i, nodeLevels[i]);
    }

    return 0;
}