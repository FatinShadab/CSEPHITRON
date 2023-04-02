/*
    Problem Link : https://www.eolymp.com/en/problems/2472
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

vector <int> adjList[N];

int main(){
    int n, q, op, u, v;
    cin >> n; cin >> q;


    while (q--){
        cin >> op;

        switch (op){
            case 1:
                cin >> u >> v;
                
                adjList[u].push_back(v);
                adjList[v].push_back(u);

                break;

            case 2:
                cin >> u;
                
                for (int adjNode : adjList[u]){
                    cout << adjNode << " ";
                }
                if (adjList[u].size() > 0)
                    cout << "\n";

                break;
        }
    }

    return 0;
}