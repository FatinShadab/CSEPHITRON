/*
Find out the minimum number of block A 
have to travel to reach out to B

Input : 
5 8
########
#.A#...#
#.##.#B#
#......#
########

Output -> 9
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 2002;

int maze[N][N];
int level[N][N];
int visited[N][N];

int n, m;
int dX[] = {0, 0, -1, 1};
int dY[] = {1, -1, 0, 0};

int is_inside(pair <int, int> node){
    int x = node.first;
    int y = node.second;

    return (x >= 0 && x < n && y >= 0 && y < m) ? 1:0;
}

int is_available(pair <int, int> node){
    int x = node.first;
    int y = node.second;

    return (maze[x][y] != -1) ? 1:0;
}

void BFS(pair<int, int> src){
    queue < pair<int, int> > temp;

    visited[src.first][src.second] = 1;
    level[src.first][src.second] = 0;
    temp.push(src);

    while (!temp.empty()){
        pair <int, int> node = temp.front();
        temp.pop();

        for (int itr=0; itr<4; itr++){
            pair <int, int> adj_node = {node.first + dX[itr], node.second + dY[itr]};

            if (is_inside(adj_node) && is_available(adj_node) && !visited[adj_node.first][adj_node.second]){
                visited[adj_node.first][adj_node.second] = 1;
                level[adj_node.first][adj_node.second] = level[node.first][node.second]+1;
                temp.push(adj_node);
            }
        }        
    }

    return;
}

int main(){
    scanf("%d %d", &n, &m);

    pair <int, int> src, dst;

    for (int i=0; i<n; i++){
        string input;
        cin>>input;
        for (int j=0; j<m; j++){
            if (input[j] == '#')
                maze[i][j] = -1;
            else if (input[j] == 'A')
                src = {i, j};
            else if (input[j] == 'B')
                dst = {i, j};
        }
    }

/*
    // To print the converted maze
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            printf("%d\t", maze[i][j]);
        }
        puts("");
    }
*/

    BFS(src);

    if (visited[dst.first][dst.second]){
        printf("YES, BY %d STEP.\n", level[dst.first][dst.second]);
    }else{
        printf("NO.\n");
    }

    return 0;
}