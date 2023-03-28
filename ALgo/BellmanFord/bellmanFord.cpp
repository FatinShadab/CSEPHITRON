#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define INF 10000005

/*
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

    for(int i=1; i<=n-1; i++){
        for (int u = 1; u <= n; u++){
            for (pair<int, int> edgeEntry : adj_list[u]){
                int v = edgeEntry.first;
                int w = edgeEntry.second;

                if (distanceArr[u] + w < distanceArr[v]){
                    distanceArr[v] = distanceArr[u] + w;
                }
            }
        }
    }

    for (int node=1; node<=n; node++){
        cout<< distanceArr[node] << " ";
    }
    cout<<endl;

    return 0;
}