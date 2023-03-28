===================================================================================================================
||                     |\                                            ____            ____                        ||
||                     | \      |                 /\                |               |    \  |\                   ||
||                     | /      |    |   |\  /|  /__\               |____   _____   |____/  | \                  ||
||                     | \  ___ |    |   | \/ | /    \ |\  |  ----  |      /     \  |    \  |  |                 ||
||                     | / |___ |___ |   |    |        | \ |        |     (       ) |     \ | /                  ||
||                     |/  |___      |___              |  \|               \_____/          |/                   || 
===================================================================================================================
|                                                                                                                 |
|        // Presudocode : Bellman-Ford                                                                            |
|        // considering negative weight but not negative cycle                                                    |
|                                                                                                                 |
|        Input  -> A weighted graph & a src node (with no negative cycles)                                        |
|        Output -> Shortest distance from src node to all other nodes                                             |
|                                                                                                                 |
|                                                                                                                 |
|        - create a distance array "d" with all values to infinity    -> TC : O(N) | SC : O(N)                    |
|        - d[src] = 0                                                 -> TC : O(1)                                |
|                                                                            ---------------                      |
|        - for i = 1 to n-1:                                          -> TC : O(N)         |                      |
|            - for all edge "e" e(u, v, w): //  u |-- w --> v            -> TC : O(M)      |======> TC : O(N * M) |
|                - if d[u] + w < d[v]:                                       -> TC : O(1)  |                      |
|                    - d[v] = d[u] + w // edge relaxation                    -> TC : O(1)  |                      |
|                                                                            ---------------                      |
|        - print the distance array                                   -> TC : O(N)                                |
|                                                                                                                 |
|        ### TC : O(N*M) // N -> number of nodes, M -> number of edges                                            |
|            : O(N^3) // In worst case number of edges can be N^2                                                 |
|                                                                                                                 |
|        ### SC : O(N)                                                                                            |
|_________________________________________________________________________________________________________________|
|        // considering negative weight and negative cycle                                                        |
|                                                                                                                 |
|        Input  -> A weighted graph & a src node                                                                  |
|        Output -> Shortest distance from src node to all other nodes if no negative cycle                        |
|                                                                                                                 |
|                                                                                                                 |
|        - create a distance array "d" with all values to infinity    -> TC : O(N) | SC : O(N)                    |
|        - d[src] = 0                                                 -> TC : O(1)                                |
|        - has_negative_cycle = false                                 -> TC : O(1)                                |
|                                                                            ---------------                      |
|        - for i = 1 to n:                                            -> TC : O(N)         |                      |
|            - for all edge "e" e(u, v, w): //  u |-- w --> v            -> TC : O(M)      |======> TC : O(N * M) |
|                - if d[u] + w < d[v]:                                       -> TC : O(1)  |                      |
|                    - d[v] = d[u] + w // edge relaxation                    -> TC : O(1)  |                      |
|                    - if (i == n) has_negative_cycle = true                 -> TC : O(1)  |                      |
|                                                                            ---------------                      |
|        - if not has_negative_cycle:                                 -> TC : O(1)                                |
|           - print the distance array                                   -> TC : O(N)                             |
|                                                                                                                 |
|        ### TC : O(N*M) // N -> number of nodes, M -> number of edges                                            |
|            : O(N^3) // In worst case number of edges can be N^2                                                 |
|                                                                                                                 |
|        ### SC : O(N)                                                                                            |
===================================================================================================================