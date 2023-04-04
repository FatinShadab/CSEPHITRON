/*
    Problem Link : https://www.eolymp.com/en/problems/978
*/
#include <bits/stdc++.h>
using namespace std;
#define N 101

vector <int> adj_list[N];
int visited[N];

void dfs(int node){
    visited[node] = 1;

    for (int adjNode : adj_list[node]){
        if (!visited[adjNode]){
            printf("%d %d\n", node, adjNode);
            dfs(adjNode);
        }
    }
}

int main(){
    int root = -1;
    int n, m, u, v;
    scanf("%d %d", &n, &m);

    while (m--){
        scanf("%d %d", &u, &v);

        if (root == -1) root = u;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    dfs(root);

    return 0;
}