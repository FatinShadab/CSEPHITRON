+===============================================================+
|                        Floyd-Warshall                         |
+===============================================================+
|                         Pesudocode                            |
+---------------------------------------------------------------+
|// Input   -> A weighted graph as an adjacency matrix          |
|// Output  -> All pair shortest distance                       |
+---------------------------------------------------------------+
|- create a distance matrix "d" where,                          |
|                                                               |
|      * d[i][j]= x "i --(x)--> j"                              |
|                                                               |
|      * for all node "i", d[i][i] = 0                          |
|                                                               |
|      * for all node "u" & "v" where there isn't any direct    |
|        edge from u ---> v, d[u][v] = INF                      |
|                                                               |
|- for all node "k"         (k means Intermediate Node)         |
|   - for all node "u"                                          |
|       - for all node "v"                                      |
|           - d[u][v] = min(d[u][v], d[u][k] + d[k][v])         |
|                                                               |
|- output all pair shortest distance "d"                        |
+---------------------------------------------------------------+
|### TC : O(V^3)    [V -> Total number of nodes]                |
|### SC : O(V^2)                                                |
+===============================================================+