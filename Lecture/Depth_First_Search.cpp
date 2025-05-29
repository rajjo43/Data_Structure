//  #include <iostream>
// #include <vector>
// #include <stack>
// #include <algorithm>  // For sorting
// using namespace std;

// // DFS class that performs DFS traversal from a given starting node
// class DFS {
// public:
//     // DFS traversal function
//     vector<int> dfsOfGraph(int V, vector<int> adj[], int start) {
//         vector<int> dfs;              // Stores DFS traversal result
//         vector<int> vis(V, 0);        // Visited array to track visited nodes

//         stack<int> s;                 // Stack for DFS
//         s.push(start);                // Push the starting node to the stack

//         while (!s.empty()) {
//             int node = s.top();       // Get the top node from the stack
//             s.pop();

//             if (vis[node]) {          // Skip if the node is already visited
//                 continue;
//             }

//             vis[node] = 1;            // Mark the node as visited
//             dfs.push_back(node);      // Add the node to the DFS result

//             // Traverse all adjacent unvisited nodes
//             for (auto it : adj[node]) {
//                 if (!vis[it]) {
//                     s.push(it);      // Push the neighbor to the stack
//                 }
//             }
//         }
//         return dfs;                   // Return the DFS traversal list
//     }
// };

// int main() {
//     int V, E;
//     cout << "Enter number of vertices: ";
//     cin >> V;

//     cout << "Enter number of edges: ";
//     cin >> E;

//     // Create adjacency list for V vertices (0-based indexing)
//     vector<int> adj[V];

//     cout << "Enter " << E << " edges (u v):" << endl;
//     for (int i = 0; i < E; i++) {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);         // Add edge u -> v
//         adj[v].push_back(u);         // comment for directed graph
//     }

//     // Sort the adjacency list for consistent traversal order
//     for (int i = 0; i < V; i++) {
//         sort(adj[i].begin(), adj[i].end());
//     }

//     int start;
//     cout << "Enter starting vertex: ";
//     cin >> start;

//     // Check for valid starting vertex
//     if (start < 0 || start >= V) {
//         cout << "Invalid starting vertex!" << endl;
//         return 1;
//     }

//     // Create DFS object and perform DFS traversal
//     DFS obj;
//     vector<int> result = obj.dfsOfGraph(V, adj, start);

//     // Output the DFS traversal
//     cout << "DFS Traversal from node " << start << ": ";
//     for (int node : result) {
//         cout << node << " ";
//     }
//     cout << endl;

//     return 0;
// }



////////////////////////////////////////////////////////////////////////////////////////
// Using Recursive function

#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>> &adjList, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited);
        }
    }
}

int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    vector<vector<int>> adjList(vertices);

    cout << "Enter edges (u v) where u and v are vertex indices starting from 0:\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        // For undirected graph
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<bool> visited(vertices, false);

    int start;
    cout << "Enter starting vertex for DFS: ";
    cin >> start;

    cout << "DFS Traversal starting from node " << start << ": ";
    dfs(start, adjList, visited);
    cout << endl;

    return 0;
}
