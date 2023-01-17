/*
Example Graph:

    0 ----- 1 ----- 2 ----- 3
            |       |
            |       |
            5 ----- 4

    Graph properties:

        # number of nodes -> 6
        # number of edges -> 6

    list of adj nodes ->
    0 1
    1 2
    2 3
    1 5
    2 4
    5 4

    Input format : 
    6 6
    0 1
    1 2
    2 3
    1 5
    2 4
    5 4
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

int visited[N];

vector <int> adj_list[N];

void dfs(int node){
    cout<<node<<" -> ";
    visited[node] = 1;

    for (int adj_node: adj_list[node]){ // for each loop syntax
        if (visited[adj_node] != 1){
            dfs(adj_node);
        }
    }
}

int main(){
    int src;
    int nodes, edges;
    scanf("%d %d", &nodes, &edges);

    for (int edge=0; edge < edges; edge++){
        int u, v;
        cin>>u>>v;
        
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);

        if (!edge){
            src = u;
        }
    }

    cout<<"The Graph : ";
    dfs(src);
    cout<<"NULL"<<endl;

    return 0;
}