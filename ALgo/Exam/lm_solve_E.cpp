/*
    Problem Link : https://www.eolymp.com/en/problems/1060
*/
#include <bits/stdc++.h>
using namespace std;
#define N 41

const int wall = 0;
const int path = 1;
const int dstB = 2;
const int srtB = 3;
const int usedPath = 4;

typedef struct{
    int x;
    int y;
} loc;

int dX[] = {-1, 1, 0, 0};
int dY[] = {0, 0, -1, 1};

int n;
int mat[N][N];
int visited[N][N];
loc parent[N][N];

void bfs(loc srcLoc){
    bool dstReached = false;
    queue <loc> nodeQ;

    visited[srcLoc.x][srcLoc.y] = 1;

    nodeQ.push(srcLoc);

    while (!nodeQ.empty() && !dstReached){
        loc node = nodeQ.front();
        nodeQ.pop();

        for (int i=0; i<4; i++){
            loc adjNode = {node.x + dX[i], node.y + dY[i]};

            if (mat[adjNode.x][adjNode.y] == dstB){
                visited[adjNode.x][adjNode.y] = 1;
                parent[adjNode.x][adjNode.y] = node;
                dstReached = true;
                break;
            }

            if (!visited[adjNode.x][adjNode.y] && mat[adjNode.x][adjNode.y] != wall && ((adjNode.x >= 0 && adjNode.x < n) && (adjNode.y >= 0 && adjNode.y < n))){
                    visited[adjNode.x][adjNode.y] = 1;
                    parent[adjNode.x][adjNode.y] = node;
                    nodeQ.push(adjNode);
                }
        }
    }
}

int main(){
    cin >> n;

    loc srcLoc, dstLoc;

    for (int i=0; i<n; i++){
        string row; cin >> row;

        for (int j=0; j<n; j++){
            switch (row[j]){
                case '.':
                    mat[i][j] = path;
                    break;
                case 'O':
                    mat[i][j] = wall;
                    break;
                case '@':
                    srcLoc = {i, j};
                    mat[i][j] = srtB;
                    break;
                case 'X':
                    dstLoc = {i, j};
                    mat[i][j] = dstB;
            }    
        }
    }

    //for debug
    //for (int i=0; i<n; i++){
    //    for (int j=0; j<n; j++){
    //        cout<<mat[i][j]<<" ";
    //    }
    //    cout<<"\n";
    //}

    bfs(srcLoc);

    if (visited[dstLoc.x][dstLoc.y] == 0){
        cout << "N\n";
        return 0;
    }

    cout << "Y\n";

    int x = dstLoc.x;
    int y = dstLoc.y;

    while (x != srcLoc.x || y != srcLoc.y){
        mat[x][y] = usedPath;

        loc prev_node = parent[x][y];

        x = prev_node.x;
        y = prev_node.y;
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            switch (mat[i][j]){
                case path:
                    cout<<'.';
                    break;
                case wall:
                    cout<<'O';
                    break;
                case usedPath:
                    if (i == srcLoc.x && j == srcLoc.y){
                        cout<<'@';
                        continue;
                    }
                    cout<<'+';
                    break;
                case srtB:
                    cout<<'@';
                    continue;
            }
        }
        cout<<"\n";
    }

    return 0;
}