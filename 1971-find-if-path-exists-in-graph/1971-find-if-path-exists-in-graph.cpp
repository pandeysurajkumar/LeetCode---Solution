
// // bfs
// class Solution {
// public:
//     bool validPath(int n,
//                    vector<vector<int>>& edges,
//                    int source,
//                    int destination)
//     {
//         // Step 1: Create adjacency list
//         vector<vector<int>> adj(n);

//         for (auto &edge : edges)
//         {
//             int u = edge[0];
//             int v = edge[1];

//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }

//         // Step 2: Visited array
//         vector<bool> visited(n, false);

//         // Step 3: Queue for BFS
//         queue<int> q;

//         q.push(source);
//         visited[source] = true;

//         // Step 4: BFS Traversal
//         while (!q.empty())
//         {
//             int node = q.front();
//             q.pop();

//             // Destination found
//             if (node == destination)
//                 return true;

//             // Visit neighbors
//             for (int neighbor : adj[node])
//             {
//                 if (!visited[neighbor])
//                 {
//                     visited[neighbor] = true;
//                     q.push(neighbor);
//                 }
//             }
//         }

//         // No path exists
//         return false;
//     }
// };




// dfs

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
            // return true;

        // Visit all neighbors
        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                // If destination is found in any recursive call
                // immediately return true
                dfs(neighbor, destination, adj, visited);
                // if (dfs(neighbor, destination, adj, visited))
                // {
                //     return true;
                // }
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
        dfs(source, destination, adj, visited);
        // return dfs(source, destination, adj, visited);
        return visited[destination];
    }
};