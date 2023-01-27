/*
Top Sort using BFS Algo :

- create an array "indegree" to maintain the number of indegrees to a node. 
	i.e. for every edge a -> b perform indegree[b]++
 
- create an empty queue to store the topsort order
 
- create a queue and push all the nodes in the queue with indegree[node] == 0
 
- while the queue is not empty:
	- pop "head" from queue
 
	- stack.push(head)
 
	- for adj_node in adj_list[head]:
		- decrement indegree[adj_node] by 1
 
		- if indegree[adj_node] == 0:
			- queue.push(adj_node)
 
- pop every node in the queue and print in the output
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 10e5;

vector <int> adj_list[N];
int indegree[N];
int n, m;

void topSort(){
    queue <int> temp;
    queue <int> nodeQueue;

    for (int i=1; i<=n; i++){
        if (!indegree[i]){
            printf("\nStart : Pushed %d to temp queue\n", i);
            temp.push(i);
        }
    }

    while (!temp.empty()){
        int node = temp.front();
        printf("\tPushed %d to topsort order queue\n", node);
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

    printf("\nTopological Order : ");
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

    for (int i=1; i<=n; i++){
        printf("\t%d -> %d\n", i, indegree[i]);
    }

    topSort();

    return 0;
}