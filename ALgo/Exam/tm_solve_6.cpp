/*
    problem link --> https://codeforces.com/problemset/problem/580/C
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

vector<int> adjList[N];
int cats[N];
bool visited[N];
int n, m;
int u, v;
int c = 0;
int s = 1;

void DFS(int node, int cat){
    visited[node] = true;

    if (cat > m) return;

    bool isLeaf = true;
    for (int adjNode : adjList[node]){
        if (!visited[adjNode]){
            isLeaf = false;
            int newCat = (cats[adjNode] == 1) ? cat + 1 : 0;
            DFS(adjNode, newCat);
        }
    }

    if (isLeaf) c++;
}

int main(){

    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) scanf("%d", &cats[i]);
    for (int i=0; i<n-1; i++){
        scanf("%d %d", &u, &v);
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    DFS(s, cats[s]);

    printf("%d\n", c);

    return 0;
}