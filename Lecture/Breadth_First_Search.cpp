// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// // BFS class that performs BFS traversal from a given starting node
// class BFS {
// public:
//     // BFS traversal function
//     vector<int> bfsOfGraph(int V, vector<int> adj[], int start) {
//         vector<int> bfs;              // Stores BFS traversal result
//         vector<int> vis(V, 0);        // Visited array to track visited nodes

//         queue<int> q;                 // Queue for BFS
//         vis[start] = 1;               // Mark the starting node as visited
//         q.push(start);                // Enqueue the starting node

//         while (!q.empty()) {
//             int node = q.front();     // Get the front node from the queue
//             q.pop();                  
//             bfs.push_back(node);      // Add the node to the BFS result

//             // Traverse all adjacent unvisited nodes
//             for (auto it : adj[node]) {
//                 if (!vis[it]) {
//                     vis[it] = 1;      // Mark as visited
//                     q.push(it);       // Enqueue the neighbor
//                 }
//             }
//         }
//         return bfs;                   // Return the BFS traversal list
//     }
// };

// int main() {
//     int V, E;
//     cout << "Enter number of vertices: ";
//     cin >> V;

//     cout << "Enter number of edges: ";
//     cin >> E;

//     // Create adjacency list for V vertices
//     vector<int> adj[V];

//     cout << "Enter " << E << " edges (u v):" << endl;
//     for (int i = 0; i < E; i++) {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);         // Add edge u -> v
//          adj[v].push_back(u);      // comment if the graph is directed
//     }

//     int start;
//     cout << "Enter starting vertex: ";
//     cin >> start;

//     // Check for valid starting vertex
//     if (start < 0 || start >= V) {
//         cout << "Invalid starting vertex!" << endl;
//         return 1;
//     }

//     // Create BFS object and perform BFS traversal
//     BFS obj;
//     vector<int> result = obj.bfsOfGraph(V, adj, start);

//     // Output the BFS traversal
//     cout << "BFS Traversal from node " << start << ": ";
//     for (int node : result) {
//         cout << node << " ";
//     }
//     cout << endl;

//     return 0;
// }


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int start, vector<vector<int>> &adjList, vector<bool> &visited) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal starting from node " << start << ": ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    cout << endl;
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
    cout << "Enter starting vertex for BFS: ";
    cin >> start;

    bfs(start, adjList, visited);

    return 0;
}
