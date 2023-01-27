/*
    https://cses.fi/problemset/task/1666

    Byteland has n
    cities, and m
    roads between them. The goal is to construct new roads so that there is a route between any two cities.

    Your task is to find out the minimum number of roads required, and also determine which roads should be built.

    Input

        The first input line has two integers n
        and m
        : the number of cities and roads. The cities are numbered 1,2,…,n
        .

        After that, there are m
        lines describing the roads. Each line has two integers a
        and b
        : there is a road between those cities.

        A road always connects two different cities, and there is at most one road between any two cities.

    Output

        First print an integer k
        : the number of required roads.

        Then, print k
        lines that describe the new roads. You can print any valid solution.

    Constraints
        1≤n≤105

        1≤m≤2⋅105

        1≤a,b≤n

    Example

        Input:
            4 2
            1 2
            3 4

        Output:
            1
            2 3
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

vector <int> adj_list[N];
vector <int> CC[N];
int visited[N];
int n, m;
int cc = 0;

void DFS(int node){
    CC[cc].push_back(node);
    visited[node] = 1;

    for (int adjNode : adj_list[node]){
        if (!visited[adjNode]){
            DFS(adjNode);
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);

    for (int e=0; e<m; e++){
        int u, v;
        scanf("%d %d", &u, &v);

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int road[n+1]; for (int i=0; i<=n; road[i++] = -1);
    for (int node=1; node<=n; node++){
        if (!visited[node]){
            road[node] = node-1;
            DFS(node);
            cc++;
        }
    }

    if (cc > 1){
        printf("Roads needed : %d\n", cc-1);

        for (int i=0; i<cc-1; i++){
            for (int node : CC[i]){
                printf("%d ", node);
                break;
            }
            for (int node : CC[i+1]){
                printf("%d", node);
                break;
            }
            puts("");
        }
        
    }
    return 0;
}