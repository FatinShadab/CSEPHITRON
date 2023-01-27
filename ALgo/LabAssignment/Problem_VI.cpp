/*
Write code to solve the topological sorting problem
https://cses.fi/problemset/task/1679/ using BFS.

You can find the pseudocode for implementing topsort using BFS in this link:
https://ideone.com/6L967A
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

vector <int> adj_list[N];
int indegree[N];
int n, m;

void topSort(){
    queue <int> temp;
    queue <int> nodeQueue;

    for (int i=1; i<=n; i++){
        if (!indegree[i]){
            //printf("\nStart : Pushed %d to temp queue\n", i);
            temp.push(i);
        }
    }

    if (temp.empty()){
        printf("IMPOSSIBLE.\n");
        return;
    }

    while (!temp.empty()){
        int node = temp.front();
        //printf("\tPushed %d to topsort order queue\n", node);
        nodeQueue.push(node);
        temp.pop();

        for (int adjNode : adj_list[node]){
            indegree[adjNode] -= 1;
            if (indegree[adjNode] == 0){
                temp.push(adjNode);
                //printf("\t\t%d with indegree %d pushed to queue\n", adjNode, indegree[adjNode]);
            }
        }
    }

    //printf("\nTopological Order : ");
    while (!nodeQueue.empty()){
        printf("%d ", nodeQueue.front());
        nodeQueue.pop();
    }
    puts("");
}

int main(){
    scanf("%d %d", &n, &m);

    for (int i=0; i<m; i++){
        int a, b;
        scanf("%d %d", &a, &b);

        adj_list[a].push_back(b);
        indegree[b]++;
    }

    //for (int i=1; i<=n; i++){
    //    printf("\t%d -> %d\n", i, indegree[i]);
    //}

    topSort();

    return 0;
}