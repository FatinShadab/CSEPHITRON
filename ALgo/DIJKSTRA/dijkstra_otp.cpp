#include <bits/stdc++.h>
using namespace std;

// Assuming Max limit of n is 1e5 + 5
// and sum of all weight's < 1e9 
const unsigned int N = 1e5 + 5;
const unsigned int INF = 1e9;

int d[N], visited[N];
vector <pair<int, int>> adj_list[N];

int V, E;

void dijkstra(int src){
    for (int node=0; node<N; node++){
        d[node] = INF;
    }

    d[src] = 0;

    priority_queue <pair<int, int>> pq;
    pq.push(make_pair(d[src], src));

    while (!pq.empty()){
        pair <int, int> nodeEntry = pq.top();
        int nodeD = nodeEntry.first;
        int node = nodeEntry.second;

        pq.pop();

        if (visited[node]){
            continue;
        }

        visited[node] = 1;

        for (auto adjEntry : adj_list[node]){
            int adjNode = adjEntry.first;
            int adjEdgeCst = adjEntry.second;

            if (d[node] + adjEdgeCst < d[adjNode]){
                d[adjNode] = d[node] + adjEdgeCst;
                pq.push(make_pair(-1*d[adjNode], adjNode));
            }
        }
    }

    return;
}

int main(){
    cout << "Enter the number of nodes and edges : ";
    cin >> V >> E;

    for (int itr=0; itr<E; itr++){
        int u, v, w;
        cin >> u >> v >> w;

        adj_list[u].push_back(make_pair(v, w));
        adj_list[v].push_back(make_pair(u, w));
    }

    cout << "Enter the source node in range [1," <<V<<"] : ";
    int src;
    cin >> src;

    dijkstra(src);

    for (int node=1; node<=V; node++){
        cout << "Distance of node : "<<node<<" from "<<src<<" => "<<d[node]<<endl;
    }

    return 0;
}