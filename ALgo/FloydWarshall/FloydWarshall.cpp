#include <bits/stdc++.h>
/*
    Implementation of Pesudocode in readme.txt
*/

using namespace std;

const int N = 1e3 + 3;
const int INF = 1e9;

int d[N][N];

int main(){
    int n, m; cin >> n >> m;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            d[i][j] = INF;
        }
    }

    for (int i=1; i<=n; i++){
        d[i][i] = 0;
    }

    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = w;
    }

    for(int k=1; k<=n; k++){
        for(int u=1; u<=n; u++){
            for(int v=1; v<=n; v++){
                d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}