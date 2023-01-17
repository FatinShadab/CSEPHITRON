#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

int visited[N];
vector <int> adj_list[N];

void dfs(int src){
    stack <int> temp;
    
    temp.push(src);
    visited[src] = 1;
    
    while (!temp.empty()){
        int current_node = temp.top();
        temp.pop();

        printf("%d ", current_node);

        for (int node : adj_list[current_node]){
            if (!visited[node]){
                temp.push(node);
                visited[node] = 1;
            }
        }
    }

    return;
}

int main(){
    int n, e;
    scanf("%d %d", &n, &e);

    int src = '\0';
    int src_taken = 0;

    while (e--){
        int u, v;
        scanf("%d %d", &u, &v);

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);

        if (!src_taken)
            src = u;
            src_taken = 1;
    }

    printf("\nGraph dfs : ");
    dfs(src);

    return 0;
}