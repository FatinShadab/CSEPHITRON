/*
    Write code to solve cycle detection in a directed graph using BFS.

    Input:
        4 5
        1 3
        2 1
        2 4
        3 2
        3 4

    Output:
        Cycle exists.
*/
#include <bits/stdc++.h>
using namespace std;
const int N  = 2e5;

vector <int> adj_list[N];
int visited[N];

bool detectCycle(int src){
    queue <int> temp;
    bool cycle_detected = false;

    visited[src] = 1;
    temp.push(src);

    while (!temp.empty()){
        int node = temp.front();
        temp.pop();

        for (int adj_node : adj_list[node]){
            if (!visited[adj_node]){
                visited[adj_node] = 1;
                temp.push(adj_node);
            }
            else if (visited[adj_node] == 1){
                cycle_detected = true;
            }
        }
        visited[node] = 2;
    }

    return cycle_detected;
};

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i=0; i<m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj_list[u].push_back(v);
    }

    for (int i=1; i<=n; i++){
        if (visited[i] == 0){
            bool got_cycle = detectCycle(i);
            if (got_cycle){
                printf("Cycle exists.\n");
                return 0;
            }
        }
    }

    printf("No cycle exists.\n");

    return 0;
}