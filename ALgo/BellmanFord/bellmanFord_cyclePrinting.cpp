/*
    Problem Link : https://cses.fi/problemset/task/1197
*/
#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define N 2505

typedef struct {
    int adjNode;
    int cost;
} edge;

vector <edge> graph[N];
long long int dist[N];
int parent[N];

int main(){
    int n, m, u, v, w;
    scanf("%d %d", &n, &m);

    for (int e=0; e<m; e++){
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back(edge{v, w});
    }

    for (int i=0; i<N; dist[i++] = INF);

    bool has_negative_cycle = false;
    int last_updated_node = -1;

    for (int itr=1; itr<=n; itr++){
        for (int node=1; node<=n; node++){
            for (edge e : graph[node]){
                if (dist[node] + e.cost < dist[e.adjNode]){
                    dist[e.adjNode] = dist[node] + e.cost;
                    parent[e.adjNode] = node;

                    if (itr == n){
                        has_negative_cycle = true;
                        last_updated_node = e.adjNode;
                    }
                }
            }
        }
    }

    printf("%s\n", (has_negative_cycle) ? "YES":"NO");
    if (!has_negative_cycle) return 0;

    int selected_node = last_updated_node;
    for (int itr=1; itr <= n-1; itr++){
        selected_node = parent[selected_node];
    }

    stack <int> cycle;
    int cycle_start_node = selected_node;

    cycle.push(cycle_start_node);

    while (1){
        selected_node = parent[selected_node];
        cycle.push(selected_node);

        if (selected_node == cycle_start_node) break;
    }

    while (!cycle.empty()){
        printf("%d ", cycle.top());
        cycle.pop();
    }

    return 0;
}