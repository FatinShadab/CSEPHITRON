/*
    Path print without negative cycle.
*/

#include <bits/stdc++.h>
using namespace std;
#define NODE 100005
#define INF 100000005

typedef struct {
    int v;
    int w;
} edge;

vector <edge> graph[NODE];
int parent[NODE];
int dist[NODE];

void printPath(int currentNode, int srcNode, int destNode){
    if (currentNode == srcNode){
        printf("%d -> ");
        return;
    }

    printPath(parent[currentNode], srcNode, destNode);

    printf("%d", currentNode);
    if (currentNode != destNode) printf(" -> ");
}

int main(){
    int n, m; cin>> n >> m;

    for (int e=1; e<=m; e++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(edge{v, w});
    }

    for (int n=0; n<=NODE; dist[n++] = INF);

    int src = 1; 
    int dest = n;
    dist[src] = 0;
    parent[src] = -1;

    for (int i=1; i<= n-1; i++){
        for (int u=1; u<= n; u++){
            for (edge e : graph[u]){
                if (dist[u] + e.w < dist[e.v]){
                    dist[e.v] = dist[u] + e.w;
                    parent[e.v] = u;
                }
            }
        }
    }

    printf("Shortest Destance from src node to every node :\n");
    for (int i=1; i<=n; i++){
        printf("\t%d ---(%d)---> %d\n", src, dist[i], i);
    }

    printf("Shortest path from %d to %d : ", src, dest);
    printPath(dest, src, dest);

    return 0;
}