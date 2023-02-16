#include <bits/stdc++.h>
using namespace std;
int n, e;
const int N = 1e5 + 5;
const int INF = 1e9; // depends on the constent limit 

vector <pair<int, int>> adj_list[N];
int d[N], visited[N];

void dijkstra(int src){
    for (int i = 1; i <= n; i++){
        d[i] = INF;
    }

    d[src] = 0;

    for (int i = 1; i <= n; i++){
        int selectedNode = -1;
        for (int j = 1; j <= n; j++){
            if (visited[j]){
                continue;
            }
            if (selectedNode == -1){
                selectedNode = j;
            }
            if (d[j] < d[selectedNode]){
                selectedNode = j;
            }
        }

        visited[selectedNode] = 1;

        for (auto adjEntry : adj_list[selectedNode]){
            int adjNode = adjEntry.first;
            int edgeCst = adjEntry.second; 

            if (d[selectedNode] + edgeCst < d[adjNode]){
                d[adjNode] = d[selectedNode] + edgeCst;
            }
        }
    }

    return;
}

int main(){
    cin >> n >> e;

    for (int i = 0; i < e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        
        adj_list[u].push_back(make_pair(v, w));
        adj_list[v].push_back(make_pair(u, w));
    }

    int src = 1;
    dijkstra(src);

    for (int i = 1; i <= n; i++){
        cout << d[i] << " ";
    }
    cout<<endl;

    return 0;
}