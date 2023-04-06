/*
    Problem Link : https://www.eolymp.com/en/problems/1941
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

vector <int> tree[N];

bool dfs(int node, int tNode){
    bool is_ancestor = false;

    if (node == tNode){
        return true;
    }

    for (int cNode : tree[node]){
        is_ancestor = dfs(cNode, tNode);
        if (is_ancestor){
            break;
        }
    }

    return is_ancestor;
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

    scanf("%d", &m);

    while (m--){
        int a, b;
        scanf("%d %d", &a, &b);

        printf("%d\n", (dfs(a, b)) ? 1:0);
    }

    return 0;
}