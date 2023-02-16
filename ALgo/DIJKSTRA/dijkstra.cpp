#include <bits/stdc++.h>
using namespace std;
int n, e;
const int N = 1e5 + 5;
const int ∞ = 1e9; // depends on the constent limit 

vector <pair<int, int>> adj_list[N];

void dijkstra(pair <int, int> src){
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

    return 0;
}