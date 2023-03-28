|***************************************************************************************|***************************************************************************************|
|                                =========================                              |                            ===================================                        |
|                                || Dijkstra Simulation ||                              |                            || Pseudocode & Complexity (OPT) ||                        |
|                                =========================                              |                            ===================================                        |
|--------------------------------------------------    " Undirected Weighted Graph "    |                                                                                       |
|| Selected Nodes || A || B || C || D || E || F ||           B         E                | * V ->  number of nodes,   * E -> number of edges                                     |
|--------------------------------------------------          | \     /   \              |                                                                                       |
||     ___        || ∞ || 0 || ∞ || ∞ || ∞ || ∞ ||           |  4   3     2             |                                                                                       |
||      B         || 4 || 0 || 4 || ↓ || ↓ || ↓ ||           |   \ /       \            | // Input  -> A Weighted Graph and A source                                            |
||      C         || ↓ || ↓ || ↓ || 10|| 7 || 5 ||           4    C ---6--- D           | // Output -> Distance of all nodes from the source                                    |
||      A         || ↓ || ↓ || ↓ || ↓ || ↓ || ↓ ||           |   / \       /            |                                                                                       |
||      F         || ↓ || ↓ || ↓ || 8 || ↓ || ↓ ||           |  2   1     3             | - Create a distance array "d"                                                         |
||      E         || ↓ || ↓ || ↓ || ↓ || ↓ || ↓ ||           | /     \   /              | - Initialize all values of "d" to infinity                       : TC, SC -> O(V)     |
||      D         || ↓ || ↓ || ↓ || ↓ || ↓ || ↓ ||            A        F                | - Create a visited array and mark all nodes as unvisited         : TC, SC -> O(V)     |
|-------------------------------------------------                                      | - Take an empty reverse priority_queue "pq"                                           |
|  source-node : B > 4    0    4    8    7    5                                         | - pq.push({0, src})                                                                   |
|                                                                                       |                                                                                       |
|  Shortest Path (B to B) : B -> B                       (cost 0)                       | - while !pq.empty():                                             : TC     -> O(E)     |
|  Shortest Path (B to A) : B -> A                       (cost 4)                       |       - head_distance, head = pq.front()                                              |
|  Shortest Path (B to C) : B -> C                       (cost 4)                       |       - pq.pop()                                                 : TC     -> O(log E) |
|  Shortest Path (B to E) : B -> C -> E                  (cost 7)                       |       - if visited[head] == 1 : ignore else make visited[head] = 1                    |
|  Shortest Path (B to F) : B -> C -> F                  (cost 5)                       |       - for all adj_node of head :                               : TC     -> O(E)     |
|  Shortest Path (B to D) : B -> C -> F -> D             (cost 8)                       |              - if d[head] + c(head, adj_node) < d[adj_node]:                          |
|***************************************************************************************|                   - d[adj_node] = d[head] + c(head, adj_node)                         |
|                              =============================                            |                   - pq.push({d[adj_node], adj_node})             : TC     -> O(log E) |
|                              || Pseudocode & Complexity ||                            |                                                                                       |
|                              =============================                            | - Output array "d"                                               : TC     -> O(V)     |
|                                                                                       |                                                                                       |
| // Input  -> A Weighted Graph and A source                                            | # SO,                                                                                 |                         
| // Output -> Distance of all nodes from the source                                    |   O(V) + O(E log E) + O(E log E)                                                      |
|                                                                                       | => O(|E| log |E|)                                                                     |
| /*                                                                                    | => O(|E| log |V^2|)                                                                   |
|    Relaxation of a "Node":                                                            | => O(2|E| log |V|)                                                                    |
|                                                                                       | => O(|E| log |V|)                                                                     |
|        If there is a edge between u and v, such that,                                 | ** here log base is 2 **                                                              |
|            u --> v                                                                    |                                                                                       |
|                                                                                       | *** Final Time Complexity : O(|E| log |V|)                                            | 
|        and                                                                            | *** This implementation works best for sparse graphs                                  |
|                                                                                       |                                                                                       |
|        If (d[u] + c(u, v)) < d[v]){                                                   |                                                                                       |
|            d[v] = d[u] + c(u, v)                                                      | * What is Sparse graph ?                                                              | 
|        }                                                                              |=> A graph in which the number of edges is much less than the possible number of edges.|
| */                                                                                    |                                                                                       |
|                                                                                       |                                                                                       |
| - Create a distance array "d"                                                         |                                                                                       |
| - Create all values of "d" to ∞ // --> SC : O(N)                                      |                                                                                       |
| - d[src node] = 0                                                                     |                                                                                       |
| - create a visited array and mark all nodes as visited                                |                                                                                       |
|                                                                                       |                                                                                       |
| - for i = 0 to n-1:    // --> TC : O(N)                                               |                                                                                       |
|                                                                                       |                                                                                       |
|    // TC : O(N) (If we use a loop to pick the node with minimum distance)             |                                                                                       |
|    - loop over the nodes and pick the one unvisted node with minimum d[node]          |                                                                                       |
|                                                                                       |                                                                                       |
|    - visited[node] = 1 (mark the node visited) // TC : O(1)                           |                                                                                       |
|    - for all adj_node of node: // TC : O(E) --> O(N^2) max limit of edges, is n^2     |                                                                                       |
|        - if d[node] + c(node, adj_node) < d[adj_node]:                                |                                                                                       |
|            - d[adj_node] = d[node] + c(node, adj_node)                                |                                                                                       |
|                                                                                       |                                                                                       |
| - output array "d"                                                                    |                                                                                       |
|                                                                                       |                                                                                       |
| *** Space Complexity : O(N) // here N denotes the number of Nodes                     |                                                                                       |
|        (O(N) is mainly caused for the distance array)                                 |                                                                                       |
|                                                                                       |                                                                                       |
| *** Time Complexity : O(N^2)                                                          |                                                                                       |
|                                                                                       |                                                                                       |
|*******************************************************************************************************************************************************************************|