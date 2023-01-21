/*
Problem link - https://cses.fi/problemset/task/1192

INPUT:
5 8
########
#..#...#
####.#.#
#..#...#
########

Output -> 3

INPUT:
5 8
########
#..#...#
#..#.#.#
#......#
########

Output -> 1
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1000;

int n, m;
int visited[N][N];
int maze[N][N];

int dX[] = {0, 0, -1, 1};
int dY[] = {1, -1, 0, 0};

int inMaze(pair <int, int> node){
    int x = node.first;
    int y = node.second;

    return ((x >= 0 && x < n) && (y >= 0 && y < m)) ? 1:0;
}

int available(pair <int, int> node){
    int x = node.first;
    int y = node.second;

    return maze[x][y];
}

void DFS(pair <int, int> node){
    visited[node.first][node.second] = 1;

    for (int i=0; i<4; i++){
        pair <int, int> adj_node = {node.first + dX[i], node.second + dY[i]};

        if (inMaze(adj_node) && available(adj_node) && !visited[adj_node.first][adj_node.second]){
            DFS(adj_node);
        }
    }

    return;
}

int main(){
    int rooms = 0;
    pair <int, int> node;

    scanf("%d %d", &n, &m);
    getchar();
    for (int row=0; row<n; row++){
        char str[m+1];
        gets(str);

        for (int col=0; col<m; col++){
            if (str[col] == '#'){
                maze[row][col] = 0;
            }else{
                maze[row][col] = 1;
            }
        }
    }
/*
    // To print the maze
    for (int row=0; row<n; row++){
        for (int col=0; col<m; col++){
            printf("%d\t", maze[row][col]);
        }
        printf("\n");
    }
*/
    for (int row=0; row<n; row++){
        for (int col=0; col<m; col++){
            if (maze[row][col] && !visited[row][col]){
                rooms++;
                node = {row, col};
                DFS(node);
            }
        }
    }

    printf("%d", rooms);

    return 0;
}