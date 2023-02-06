/*
Problem Link : https://cses.fi/problemset/task/1667
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

vector <int> adj_list[N];
int visited[N], level[N], parent[N];

void bfs(int src){
    queue <int> temp;
    visited[src] = 1;
    level[src] = 1;
    parent[src] = -1;
    temp.push(src);

    while (!temp.empty()){
        int node = temp.front();
        temp.pop();

        for (int adjNode : adj_list[node]){
            if (!visited[adjNode]){
                visited[adjNode] = 1;
                parent[adjNode] = node;
                level[adjNode] = level[node] + 1;
                temp.push(adjNode);
            }
        }
    }

    return;
}

int main(){
    int n, m;
    cin >> n >> m;

    for (int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int srcNode = 1;
    
    bfs(srcNode);

    int destNode = n;

    if (visited[destNode]){
        cout<< level[destNode] << endl;

        vector <int> path;
        int selectedNode = destNode;

        while (1){
            path.push_back(selectedNode);
            if (selectedNode == srcNode){
                break;
            }
            selectedNode = parent[selectedNode];
        }

        reverse(path.begin(), path.end());

        for (int node : path){
            cout << node << " ";
        }
        cout<<endl;

        return 0;
    }

    cout<<"IMPOSSIBLE"<<endl;

    return 0;
}