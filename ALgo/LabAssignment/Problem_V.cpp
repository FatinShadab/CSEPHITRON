/*
    Write code to solve the problem https://cses.fi/problemset/task/1669 using
    BFS
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;

vector <int> adj_list[N];
vector <int> parentNodes[N];
int numberOfcities = 0;
int visited[N];

bool is_parent(int node, int adj_node){
    for (int p : parentNodes[node]){
        if (p == adj_node){
            return true;
        }
    }
    return false;
}

bool BFS(int src){
    queue <int> temp;

    visited[src] = 1;
    temp.push(src);

    while (!temp.empty()){
        int node = temp.front();
        temp.pop();
        numberOfcities++;

        for (int adjNode : adj_list[node]){
            if (!visited[adjNode]){
                visited[adjNode] = 1;
                parentNodes[adjNode].push_back(node);
                temp.push(adjNode);
            }
            else if (!is_parent(node, adjNode)){
                numberOfcities++;
                return true;
            }
        }
    }

    return false;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    for (int road=0; road<m; road++){
        int city1, city2;
        scanf("%d %d", &city1, &city2);

        adj_list[city1].push_back(city2);
        adj_list[city2].push_back(city1);
    }


    for (int city=1; city<=n; city++){
        if (!visited[city]){
            bool tripPossible = BFS(city);
            if (tripPossible){
                printf("Round Trip Possible by %d cities.\n", numberOfcities+1);
                return 0;
            } 
        }
    }
   
   printf("Impossible.\n");

    return 0;
}