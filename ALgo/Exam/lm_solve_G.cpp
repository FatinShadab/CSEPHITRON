/*
    Problem Link : https://www.eolymp.com/en/problems/1941
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

vector <int> tree[N];
int int_time[N], out_time[N];
int node_visited = 0;

void dfs(int node){
    int_time[node] = ++node_visited;
    for (int cNode : tree[node]){
        dfs(cNode);
    }
    out_time[node] = ++node_visited;
}

int main(){
    int n, m, a, b, root;

    scanf("%d", &n);

    for (int node=1; node<=n; node++){
        int parentNode;
        scanf("%d", &parentNode);

        if (parentNode == 0){
            root = node;
        }

        tree[parentNode].push_back(node);
    }

    dfs(root);

    scanf("%d", &m);

    while (m--){
        int a, b;
        scanf("%d %d", &a, &b);

        printf("%d\n", (int_time[a] < int_time[b] && out_time[a] > out_time[b]) ? 1:0);
    }

    return 0;
}