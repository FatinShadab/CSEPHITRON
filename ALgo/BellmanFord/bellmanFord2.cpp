#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define INF 10000005

/*
    input:
        3 3
        1 2 -1
        2 3 -2
        3 1 -3
        1
    output:
        The graph has a negative cycle !

    input:
        3 2
        1 2 -1
        2 3 -5
        1
    output:
        0 -1 -6
*/

vector <pair <int, int>> adj_list[N];
int distanceArr[N];

int main(){

    for (int i=0; i<N; distanceArr[i++] = INF);

    int n, m, u, v, w;
    cin >> n >> m;

    for (int i=0; i<m; i++){
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
    }

    int src; cin >> src;

    distanceArr[src] = 0;

    bool has_negative_cycle = false;

    for(int i=1; i<=n; i++){
        for (int u = 1; u <= n; u++){
            for (pair<int, int> edgeEntry : adj_list[u]){
                int v = edgeEntry.first;
                int w = edgeEntry.second;

                if (distanceArr[u] + w < distanceArr[v]){
                    distanceArr[v] = distanceArr[u] + w;
                    if (i == n) has_negative_cycle = true;
                }
            }
        }
    }

    if (has_negative_cycle){
        cout<< "The graph has a negative cycle !"<<endl;
        return 0;
    }

    for (int node=1; node<=n; node++){
        cout<< distanceArr[node] << " ";
    }
    cout<<endl;

    return 0;
}