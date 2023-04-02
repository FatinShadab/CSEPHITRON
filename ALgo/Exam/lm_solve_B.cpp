/*
    Problem Link : https://www.eolymp.com/en/problems/2470
*/
#include <bits/stdc++.h>
using namespace std;
#define N 101

int graphAdjMat[N][N];

vector <pair<int, int>> directd_edges;

int main(){
    bool undirected_graph = true;
    int n; cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> graphAdjMat[i][j];

            if (graphAdjMat[i][j] != 0 && i == j){
                undirected_graph = false;
            }

            if (graphAdjMat[i][j] > 1){
                undirected_graph = false;
            }

            if (graphAdjMat[i][j] == 1){
                directd_edges.push_back(make_pair(i, j));
            }


        }
    }

    if (!undirected_graph){
        cout<<"NO\n";
        return 0;
    }

    for (pair<int, int> uv : directd_edges){
        int u = uv.first;
        int v = uv.second;

        undirected_graph = (graphAdjMat[v][u] == 1) ? true:false;

        if (!undirected_graph) break;
    }

    (undirected_graph) ? cout<<"YES\n":cout<<"NO\n";

    return 0;
}