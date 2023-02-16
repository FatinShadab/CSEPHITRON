|***************************************************************************************|
|                                =========================                               |
|                                || Dijkstra Simulation ||                               |
|                                =========================                              |
|--------------------------------------------------    " Undirected Weighted Graph "    |
|| Selected Nodes || A || B || C || D || E || F ||           B         E                |
|--------------------------------------------------          | \     /   \              |
||     ___        || ∞ || 0 || ∞ || ∞ || ∞ || ∞ ||           |  4   3     2             |
||      B         || 4 || 0 || 4 || ↓ || ↓ || ↓ ||           |   \ /       \            |
||      C         || ↓ || ↓ || ↓ || 10|| 7 || 5 ||           4    C ---6--- D           |
||      A         || ↓ || ↓ || ↓ || ↓ || ↓ || ↓ ||           |   / \       /            |
||      F         || ↓ || ↓ || ↓ || 8 || ↓ || ↓ ||           |  2   1     3             |
||      E         || ↓ || ↓ || ↓ || ↓ || ↓ || ↓ ||           | /     \   /              |
||      D         || ↓ || ↓ || ↓ || ↓ || ↓ || ↓ ||            A        F                |
|-------------------------------------------------                                      |
|  source-node : B > 4    0    4    8    7    5                                         |
|                                                                                       |
|  Shortest Path (B to B) : B -> B                       (cost 0)                       |
|  Shortest Path (B to A) : B -> A                       (cost 4)                       |
|  Shortest Path (B to C) : B -> C                       (cost 4)                       |
|  Shortest Path (B to E) : B -> C -> E                  (cost 7)                       |
|  Shortest Path (B to F) : B -> C -> F                  (cost 5)                       |
|  Shortest Path (B to D) : B -> C -> F -> D             (cost 8)                       |
|***************************************************************************************|
|                              =============================                            |
|                              || Pseudocode & Complexity ||                            |
|                              =============================                            |
|                                                                                       |
| // Input  -> A Weighted Graph and A source                                            |
| // Output -> Distance of all nodes from the source                                    |
|                                                                                       |
| /*                                                                                    |
|    Relaxation of a "Node":                                                            |
|                                                                                       |
|        If there is a edge between u and v, such that,                                 |
|            u --> v                                                                    |
|                                                                                       |
|        and                                                                            |
|                                                                                       |
|        If (d[u] + c(u, v)) < d[v]){                                                   |
|            d[v] = d[u] + c(u, v)                                                      |
|        }                                                                              |
| */                                                                                    |
|                                                                                       |
| - Create a distance array "d"                                                         |
| - Create all values of "d" to ∞ // --> SC : O(N)                                      |
| - d[src node] = 0                                                                     |
| - create a visited array and mark all nodes as visited                                |
|                                                                                       |
| - for i = 0 to n-1:    // --> TC : O(N)                                               |
|                                                                                       |
|    // TC : O(N) (If we use a loop to pick the node with minimum distance)             |
|    - loop over the nodes and pick the one unvisted node with minimum d[node]          |    
|                                                                                       |
|    - visited[node] = 1 (mark the node visited) // TC : O(1)                           |
|    - for all adj_node of node: // TC : O(E) --> O(N^2) max limit of edges, is n^2     |
|        - if d[node] + c(node, adj_node) < d[adj_node]:                                |
|            - d[adj_node] = d[node] + c(node, adj_node)                                |
|                                                                                       |
| - output array "d"                                                                    |
|                                                                                       |
| *** Space Complexity : O(N) // here N denotes the number of Nodes                     |
|        (O(N) is mainly caused for the distance array)                                 |
|                                                                                       |
| *** Time Complexity : O(N^2)                                                          |
|                                                                                       |
|***************************************************************************************|