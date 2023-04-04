/*
    Problem Link : https://www.eolymp.com/en/problems/1455
*/
#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define N 101

typedef struct {
    int adjNode;
    int cost;
} edge;

vector <edge> graph[N];
long long int dist[N];
int parent[N];

int main(){
    int n, w;
    scanf("%d", &n);

    for (int u=1; u<=n; u++){
        for (int v=1; v<=n; v++){
            scanf("%d", &w);

            switch (w){
                case 100000:
                    case -100000:
                        case 0:
                            continue;
                default:
                    graph[u].push_back(edge{v, w});

            }
        }
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

    printf("%d\n", cycle.size());

    while (!cycle.empty()){
        printf("%d ", cycle.top());
        cycle.pop();
    }

    return 0;
}