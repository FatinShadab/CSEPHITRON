/*
We have seen cycle detection in a directed graph .
Now we are interested in detecting cycles in an undirected graph using DFS. A
cycle in an undirected graph has at least 3 nodes in it. For example, the following
graph has a cycle consisting nodes 1, 2 & 3.

problem : https://cses.fi/problemset/task/1669
*/
#include <bits/stdc++.h>
using namespace std;
const int N  = 2e5;

vector <int> adj_list[N];
vector <int> parentNodes[N];
vector <int> validPath;
int visited[N];

bool is_parent(int node, int adj_node){
    for (int p : parentNodes[node]){
        if (p == adj_node){
            return true;
        }
    }
    return false;
}

bool detectCycle(int node){

    visited[node] = 1;
    validPath.push_back(node);

    for (int adj_node: adj_list[node]){
        if (!is_parent(node, adj_node)){
            if (visited[adj_node] == 0){
                parentNodes[adj_node].push_back(node);
                bool got_cycle = detectCycle(adj_node);
                if (got_cycle){
                    return true;
                }
            }
            else if (visited[adj_node] == 1){
                validPath.push_back(adj_node);
                return true;
            }
        }
    }

    visited[node] = 2;

    return false;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i=0; i<m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for (int i=1; i<=n; i++){
        if (!visited[i]){
            bool got_cycle = detectCycle(i);
            if (got_cycle){
                printf("Number of cities in the round trip : %d\n", validPath.size());
                puts("The city visit sequence :");
                for (int city : validPath){
                    printf("%d ", city);
                }
                return 0;
            }
        }
    }

    printf("IMPOSSIBLE\n");

    return 0;
}