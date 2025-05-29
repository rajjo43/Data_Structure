#include <bits/stdc++.h>
#include <set>
#include <vector>

using namespace std;

class Dijkstra {
public:
    // Function to find the shortest distances from source vertex S to all other vertices
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S, vector<int>& parent) {
        set<pair<int, int>> st; // {distance, node}, sorted by distance
        vector<int> dist(V, 1e9); // Distance vector initialized to "infinity" (1e9)

        st.insert({0, S}); // Insert source node with distance 0
        dist[S] = 0;       // Distance to source from itself is 0
        parent[S] = -1;    // Source has no parent

        while (!st.empty()) {
            auto it = *(st.begin()); // Get the pair with the smallest distance
            int node = it.second;    // Current node
            int dis = it.first;      // Current distance
            st.erase(it);            // Remove it from the set

            // Traverse all neighbors of the current node
            for (auto it : adj[node]) {
                int adjNode = it[0]; // Adjacent node
                int edge = it[1];    // Edge weight between current node and adjNode

                // Relaxation: check if we found a shorter path to adjNode
                if (dis + edge < dist[adjNode]) {
                    // If adjNode already has a distance (not infinity), remove old pair from set
                    if (dist[adjNode] != 1e9)
                        st.erase({dist[adjNode], adjNode});

                    dist[adjNode] = dis + edge; // Update to shorter distance
                    parent[adjNode] = node;    // Set current node as parent for adjNode
                    st.insert({dist[adjNode], adjNode}); 
                }
            }
        }

        return dist; 
    }

    // Function to reconstruct the shortest path from source to destination
    void printPath(int node, vector<int>& parent) {
        if (node == -1) return;
        printPath(parent[node], parent);
        cout << node << " ";
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    // Create an array of adjacency lists (each entry is a list of [neighbor, weight])
    vector<vector<int>> adj[V];

    cout << "Enter " << E << " edges (format: u v w):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w; // u = source node, v = destination node, w = edge weight
        adj[u].push_back({v, w}); // Add edge u -> v with weight w
        adj[v].push_back({u, w}); // comment this line if the graph is directed
    }

    int source;
    cout << "Enter source node: ";
    cin >> source;

    Dijkstra obj;
    vector<int> parent(V, -1); // Parent vector to reconstruct path
    vector<int> result = obj.dijkstra(V, adj, source, parent); // Call the Dijkstra algorithm

    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "Node " << i << " -> Distance: " << result[i] << "\n";
    }

    cout << "Shortest paths from source " << source << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "Path to node " << i << ": ";
        if (result[i] == 1e9) {
            cout << "No path\n";
        } else {
            obj.printPath(i, parent);
            cout << "\n";
        }
    }

    return 0;
}
