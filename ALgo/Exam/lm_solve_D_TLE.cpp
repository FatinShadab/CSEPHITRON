/*
    Problem Link : https://www.eolymp.com/en/problems/4369
    gives TLE !
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector <int> adj_list[N];
int visited[N], level[N];

void bfs(int src){
    queue <int> nodeQ;

    visited[src] = 1;
    level[src] = 0;

    nodeQ.push(src);

    while (!nodeQ.empty()){
        int node = nodeQ.front();
        nodeQ.pop();

        for (int adjNode : adj_list[node]){
            if (!visited[adjNode]){

                if (level[adjNode] != -1){
                    level[adjNode] = min(level[adjNode], level[node] + 1);
                } else {
                    level[adjNode] =  level[node] + 1;
                }

                visited[adjNode] = 1;
                nodeQ.push(adjNode);
            }
        }
    }


}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset(level, -1, sizeof(level));

    int n, m, q, u, v, s;
    cin >> n >> m;

    while (m--){
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    cin >> q;

    while (q--){
        cin >> s;
        for (int i=1; i<=n; visited[i++] = 0);
        bfs(s);
    }

    // cause WA in 
    //int max_level = *max_element(level, level + n);

    int max_level = -1;
    for (int i=1; i<=n; i++){
        max_level = max(level[i], max_level);
        // printf("\t%d : %d\n", i, level[i]); // for debug
    }

    cout << max_level << "\n";

    for (int node = 1; node <= n; node++){
        if (level[node] == max_level){
            cout << node << "\n";
            break;
        }
    }

    return 0;
}