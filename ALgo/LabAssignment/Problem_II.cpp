/*
    Write code to solve the following grid traversal problem. You don’t need to print the
    path. https://cses.fi/problemset/task/1194

    Sample Input:
    ---------------
        5 8
        ########
        #M..A..#
        #.#.M#.#
        #M#..#..
        #.######
*/
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
const int N = 1000;

int dX[] = {0, 0, 1, -1};
int dY[] = {1, -1, 0, 0};

int n, m;
int maze[N][N];
int levels[N][N];
int visited[N][N];

pair <int, int> human;
pair <int, int> safePath;
vector <pair<int, int>> posiible_exits;
vector <pair<int, int>> monsters;

void draw_info(){
    // For Debug
    // 0 : A (Human)
    // 1 : # (Wall)
    // 2 : M (Monster)
    // 3 : . (Safe Path)
    // 6 : . (Possible safe exit path)
    system("cls");
    printf("\nThe integer representation of the graph :\n");
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            printf("%d ", maze[i][j]);
        }
        puts("");
    }
    printf("\nHuman in (x:%d, y:%d)\n", human.first, human.second);
    for (pair<int, int> monster : monsters){
        printf("Monster in (x:%d, y:%d)\n", monster.first, monster.second);
    }
    for (pair<int, int> exit : posiible_exits){
        printf("Possible Exit in (x:%d, y:%d)\n", exit.first, exit.second);
    }
}

bool is_inside(pair<int, int> node){
    if ((node.first >= 0 && node.first < n) && (node.second >= 0 && node.second < m))
        return true;

    return false;
}

bool is_safe(pair<int, int> node){
    if (maze[node.first][node.second]%3 == 0)
        return true;
    return false;
}

void update_exits(int X, int Y){
    int idx = 0;
    int already_counted = 0;
    for (pair<int, int> exit : posiible_exits){
        if (exit.first == X && exit.second == Y){
            already_counted = 1;
        }
    }

    if (!already_counted){
        posiible_exits.push_back(make_pair(X, Y));
    }
}

void move_monster(int dx, int dy){
    int idx = 0;
    for (pair <int, int> monster : monsters){
        int monsterNewX = monster.first + dx;
        int monsterNewY = monster.second + dy;

        if (maze[monsterNewX][monsterNewY] != 1 && is_inside(make_pair(monsterNewX, monsterNewY))){
            maze[monsterNewX][monsterNewY] = 2;

            if (monster.first == 0 || monster.first == n-1 || monster.second == 0 || monster.second == m-1){
                maze[monster.first][monster.second] = 6;
                update_exits(monster.first, monster.second);
            }
            else
                maze[monster.first][monster.second] = 3;

            monsters.at(idx) = make_pair(monsterNewX, monsterNewY);
        }

        idx++;
    }
}

bool DFS(pair <int, int> node){
    int nodeX = node.first;
    int nodeY = node.second;
    
    visited[nodeX][nodeY] = 1;

    if (levels[nodeX][nodeY] == -1)
        levels[nodeX][nodeY] = 0;

    for (int i=0; i<4; i++){
        int adjNodeX = nodeX + dX[i];
        int adjNodeY = nodeY + dY[i];
        pair <int, int> adj_node = {adjNodeX, adjNodeY};

        if (maze[adjNodeX][adjNodeY] == 6){
            levels[adjNodeX][adjNodeY] = levels[nodeX][nodeY];
            maze[adjNodeX][adjNodeY] = 0;
            maze[nodeX][nodeY] = 3;
            safePath = make_pair(adjNodeX, adjNodeY);
            // Uncomment to see the simulation
            //draw_info();
            return true;
        }

        if (!visited[adjNodeX][adjNodeY] && is_inside(adj_node) && is_safe(adj_node)){
            int temp = maze[adjNodeX][adjNodeY];
            maze[adjNodeX][adjNodeY] = 0;
            maze[nodeX][nodeY] = temp;
            human = make_pair(adjNodeX, adjNodeY);
            
            move_monster(dX[i], dY[i]);
            levels[adjNodeX][adjNodeY] = levels[nodeX][nodeY] + 1;
            
            // Uncomment to see the simulation
            //draw_info();
            //getchar();

            bool exit_found = DFS(adj_node);

            if (exit_found){
                return true;
            }
            move_monster((dX[i]) ? -1*dX[i]:dX[i], (dY[i]) ? -1*dY[i]:dY[i]);
            maze[nodeX][nodeY] = 0;
            maze[adjNodeX][adjNodeY] = temp;
            human = make_pair(nodeX, nodeY);

            // Uncomment to see the simulation
            //draw_info();
            //getchar();
        }
    }

    return false;
}

int main(){
    scanf("%d %d", &n, &m);

    for (int row=0; row<n; row++){
        string rowStr;
        cin>>rowStr;
        for (int col=0; col<m; col++){
            switch (rowStr[col]){
                case '#':
                    maze[row][col] = 1;
                    break;
                case 'M':
                    maze[row][col] = 2;
                    monsters.push_back(make_pair(row, col));
                    break;
                case '.':
                    if (row == 0 || row == n-1 || col == 0 || col == m-1){
                        maze[row][col] = 6;
                        posiible_exits.push_back(make_pair(row, col));
                    }
                    else{
                        maze[row][col] = 3;
                    }
                    break;
                case 'A':
                    maze[row][col] = 0;
                    human = {row, col};
                    break;
            }
            levels[row][col] = -1;
        }

    }
    
    // Uncomment to see the simulation
    //getchar();
    //draw_info();
    //getchar();
    
    bool exit_found = DFS(human);

    if (exit_found){
        printf("\nYES. Exit found in %d steps.\n", levels[safePath.first][safePath.second]+1);
    }
    else{
        printf("\nNO\n");
    }

    return 0;
}