/*
Pseudocode of BFS
=====================
In a Graph:
    number of total node : V
    number of total edge : E

Time complexity  : O(V+E)
Space Complexity : O(V)

Input  -> Connected Graph and a Source
Output -> Tracerse all nodes and print the traversal order

BFS(graph, source):

    - initiate an array called "visited" and an empty queue "q"
    - mark visited[source] = 1 and q.push(source)

                    <----------------------------------------------------------------------------------
    - while the queue is not empty:                                                                   |
                        <----------------------                                                       |
        - head = q.front()                    |                                                       |
        - q.pop()                             |----> Time Complexity : O(V)                           |
        - print the node "head"               |                                                       |
                        <----------------------                                                       |----> Time Complexity : O(V+E)  
                                        <-----------------------                                      |
        - for all adjacent nodes of "head":                    |                                      |
            - if visited[adj_node] == 0:                       |----> Time Complexity : O(2E) -> O(E) |
                - visited[adj_node] = 1 and q.push(adj_node)   |                                      |
                                        <-----------------------                                      |
                    <----------------------------------------------------------------------------------
*/