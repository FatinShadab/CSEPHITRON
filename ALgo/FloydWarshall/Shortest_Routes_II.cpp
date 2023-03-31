/*
    Problem Link : https://cses.fi/problemset/task/1672
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 501;
const long long INF = 1e18;

long long d[N][N];

int main(){
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            d[i][j] = INF;
        }
    }

    for (int i=1; i<=n; i++){
        d[i][i] = 0;
    }

    while(m--){
        int u, v;
        long long w;

        scanf("%d %d %lld", &u, &v, &w);

        d[u][v] = min(d[u][v], w);
        d[v][u] = d[u][v];
    }

    for (int k=1; k<=n; k++){
        for (int u=1; u<=n; u++){
            for (int v=1; v<=n; v++){
                d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
            }
        }
    }

    while(q--){
        int u, v;
        scanf("%d %d", &u, &v);

        printf("%lld\n", (d[u][v] == INF) ? (long long)-1:d[u][v]);
    }

    return 0;
}