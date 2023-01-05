/*

DFS Time Complexity   : O(V+E)
DFS Space Cpmplexity  : O(V)

// DFS for FULL Binary Tree
void dfs(int node){
    output node

    // base case
    if node does not have any child:
        return
    
    // general case
    dfs(node.left_child);
    dfs(node.right_child);
}

// DFS for any graph
void dfs(int node){
    output node
    visited[node] = true;

    for adj_node in all_adj_nodes:
        if visited[adj_node] != 1:
            dfs(adj_node)
}
*/