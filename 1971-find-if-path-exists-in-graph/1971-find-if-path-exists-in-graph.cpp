class Solution {
public:

    bool dfs(int node,
             int destination,
             vector<vector<int>>& adj,
             vector<bool>& visited)
    {
        // Mark current node as visited
        visited[node] = true;

        // Destination found
        if (node == destination)
            return true;

        // Visit all neighbors
        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                // If destination is found in any recursive call
                // immediately return true
                if (dfs(neighbor, destination, adj, visited))
                {
                    return true;
                }
            }
        }

        // Destination not found from this path
        return false;
    }

    bool validPath(int n,
                   vector<vector<int>>& edges,
                   int source,
                   int destination)
    {
        // Step 1: Create Adjacency List
        vector<vector<int>> adj(n);

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);   // Undirected Graph
        }

        // Step 2: Visited Array
        vector<bool> visited(n, false);

        // Step 3: Run DFS
        return dfs(source, destination, adj, visited);
    }
};