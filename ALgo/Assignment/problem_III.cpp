/*
==========================================================
Qus:
  Write a program to take an undirected graph as input and count the number of
  connected components in it.

Graph:
    1   4   6
   / \   \
  2---3   5

Input:
  6 4
  1 2
  1 3
  2 3
  4 5

Pseudo Code:

  nodes : 1 2 3 4 5 6

  visited : 1->F, 2->F, 3->F, 4->F, 5->F, 6->F

  int connected_comp = 0;

  bfs with src 1 bcz it is not visited.
  src = 1               mark : visited
            2           mark : visited
                3       mark : visited

  connected_comp++

  visited : 1->T, 2->T, 3->T, 4->F, 5->F, 6->F

  check for unvisited nodes if.

  bfs with src 4 bcz it is not visited after the 1st bfs.
  src = 4               mark : visited
            5           mark : visited

  visited : 1->T, 2->T, 3->T, 4->T, 5->T, 6->F

  connected_comp++

  bfs with src 6 bcz it is not visited after the 2nd bfs.
  src = 6               mark : visited

  visited : 1->T, 2->T, 3->T, 4->T, 5->T, 6->T

  connected_comp++

  output the connected_comp bcz no node left unvisited.
==========================================================
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

vector <int> nodes[1];
vector <int> visited[1];
vector <int> adj_list[N];

void dfs(int src){
  visited[1].push_back(src);

  for (int adj_node : adj_list[src]){
    if (count(visited[1].begin(), visited[1].end(), adj_node) == 0)
      dfs(adj_node);
  }
  
  return;
}

int main(){
  int n, e;
  int connected_components = 0;

  scanf("%d %d", &n, &e);

  for (int node=1; node<=n; node++){
    nodes[1].push_back(node);
  }

  for (int edge=0; edge<e; edge++){
    int u, v;
    scanf("%d %d", &u, &v);

    adj_list[u].push_back(v);
    adj_list[v].push_back(u);

  }

  for (int node : nodes[1]){
    if (count(visited[1].begin(), visited[1].end(), node) == 0)
      connected_components++;
      dfs(node);
  }

  printf("Connected Components : %d\n", connected_components);

  return 0;
}