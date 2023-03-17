/*
    Question:
    ---------
        Write code to create a directed graph with 100 nodes where each node is numbered
        between 2 and 101. There exists an edge from node-A to node-B if  node-B is a 
        multiple of node-A.	10

        For example, the node 50 should have directed edges to node 50 and node 100.
        (as both 50 and 100 are multiples of 50)

        Use adjacency list as your graph representation.

        Can you find the length of the longest path?
        What graph traversal would you use? Can it be solved with both BFS and DFS?
        Finally, write code to print the longest path.
*/
#include <bits/stdc++.h>
using namespace std;
#define N 102
typedef queue<int> Q;

vector <Q> nodeQueue[N];
vector <int> adjList[N];
vector <int> srcNodes;
int indegree[N];

void generateGraph(){
    for (int i=2; i<N; i++){
        for (int j=1; j==j; j++){
            if (i*j < N){
                adjList[i].push_back(i*j);
            }
            else{
                break;
            }
        }
    }
}

void printGraph(){
    puts("Graph : ");
    for (int i=2; i<N; i++){
        printf("%d -> ", i);
        for (int j : adjList[i]){
            printf("%d ", j);
        }
        puts("");
    }

    printf("Possible src nodes : ");
    for (int n : srcNodes){
        printf("%d ", n);
    }
    puts("");
}

void getSrcNodes(){
    for (int node=2; node < N; node++){
        for (int n : adjList[node]){
            indegree[n]++;
        }
    }

    for (int node=2; node < N; node++){
        if (indegree[node] == 1){
            srcNodes.push_back(node);
            nodeQueue[node].push_back(Q());
        }
    }
}

void bfs(int srcNode){
    int visited[N] = {0};
    Q temp;

    temp.push(srcNode);
    visited[srcNode] = 1;

    while (!temp.empty()){
        int head = temp.front();
        nodeQueue[srcNode][0].push(head);
        temp.pop();

        int nodeWithmaxAdj = -1;
        for (int adjNode : adjList[head]){
            if (!visited[adjNode]){
                int sflag = adjList[adjNode].size();
                if (nodeWithmaxAdj != -1){
                    if (sflag > adjList[nodeWithmaxAdj].size()){
                        nodeWithmaxAdj = adjNode;
                    }
                } else {
                    nodeWithmaxAdj = adjNode;
                }
            }
        }

        if (nodeWithmaxAdj != -1){
            //printf("\t src : %d <--> %d\n", head, nodeWithmaxAdj);
            temp.push(nodeWithmaxAdj);
            visited[nodeWithmaxAdj] = 1;
        }
    }
}

void showLongestPath(){
    /*
    // For Debug
    for (int srcNode : srcNodes){
        printf("Path with srcNode : %d -> ", srcNode);
        while (!nodeQueue[srcNode][0].empty()){
            printf("%d ", nodeQueue[srcNode][0].front());
            nodeQueue[srcNode][0].pop();
        }
        puts("");
    }*/

    
    int longestPathSrcNode = -1;
    for (int srcNode : srcNodes){
        if (longestPathSrcNode != -1){
            if (nodeQueue[srcNode][0].size() > nodeQueue[longestPathSrcNode][0].size()){
                longestPathSrcNode = srcNode;
            }
        } else {
            longestPathSrcNode = srcNode;
        }
    }

    while (!nodeQueue[longestPathSrcNode][0].empty()){
        printf("%d ", nodeQueue[longestPathSrcNode][0].front());
        nodeQueue[longestPathSrcNode][0].pop();
    }
}

int main(){
    generateGraph();
    getSrcNodes();

    for (int srcNode : srcNodes){
        bfs(srcNode);
    }

    printGraph();
    showLongestPath();

    return 0;
}