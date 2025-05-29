// #include <iostream>
// #include <vector>
// using namespace std;

// const int MAX = 100;
// bool adj[MAX][MAX];
// int V;

// // Function to check if the graph is K5
// bool isK5() {
//     if (V != 5) return false;

//     for (int i = 0; i < V; ++i) {
//         int count = 0;
//         for (int j = 0; j < V; ++j) {
//             if (i != j && adj[i][j]) count++;
//         }
//         if (count != 4) return false;
//     }
//     return true;
// }

// // Function to check if the graph is K3,3
// bool isK33() {
//     if (V != 6) return false;

//     int set1[3] = {0, 1, 2};
//     int set2[3] = {3, 4, 5};

//     // No internal edges in either set
//     for (int i = 0; i < 3; ++i)
//         for (int j = i + 1; j < 3; ++j)
//             if (adj[set1[i]][set1[j]] || adj[set2[i]][set2[j]])
//                 return false;

//     // Full connection between the sets
//     for (int i = 0; i < 3; ++i)
//         for (int j = 0; j < 3; ++j)
//             if (!adj[set1[i]][set2[j]])
//                 return false;

//     return true;
// }

// bool isPlanar() {
//     if (isK5() || isK33())
//         return false;
//     return true;
// }

// int main() {
//     V = 5; // number of vertices
//     int edges[][2] = {
//         {0, 1}, {0, 2}, {0, 4}, {1, 3},
//         {1, 5}, {2, 3}, {2, 5},
//         {3, 4}, {4, 5}
//     };
//     int E = sizeof(edges) / sizeof(edges[0]);

//     // Initialize adjacency matrix
//     for (int i = 0; i < V; ++i)
//         for (int j = 0; j < V; ++j)
//             adj[i][j] = false;

//     // Add edges
//     for (int i = 0; i < E; ++i) {
//         int u = edges[i][0];
//         int v = edges[i][1];
//         adj[u][v] = adj[v][u] = true;
//     }

//     if (isPlanar())
//         cout << "Graph is probably planar." << endl;
//     else
//         cout << "Graph is NOT planar (K5 or K3,3 detected)." << endl;

//     return 0;
// }


// #include <iostream>
// #include <vector>

// using namespace std;

// const int Max = 100;
// vector<int> adj[Max];
// int V;

// // Add an undirected edge between u and v
// void addEdge(vector<int> graph[], int u, int v){
//     graph[u].emplace_back(v);
//     graph[v].emplace_back(u);
// }

// // Function to check if two vertices has edge
// bool hasEdge(int u, int v)
// {
//     for(int neighbor : adj[u]){
//         if(neighbor == v){
//             return true;
//         }
//     }
//     return false;
// }

// // Check if the graph is K5(complete graph of 5 vertices)
// bool isK5()
// {
//     if(V != 5){
//         return false;
//     }

//     for(int i = 0; i < V; i++){
//         int count = 0;
//         for(int j = 0; j < V; j++){
//             if(i != j && hasEdge(i, j))
//                 count++;
//         }
//         if(count != 4){
//             return false;
//         }
//     }
//     return true;
// }

// // Check if the graph is K3,3(Complete bipartite graph)
// bool isK33()
// {
//     if(V != 6){
//         return false;
//     }

//     int set1[3] = {0,1,2};
//     int set2[3] = {3,4,5};

//     // No internal edges in either set
//     for(int i = 0; i < 3; i++){
//         for(int j = i + 1; j < 3; j++){
//             if(hasEdge(set1[i], set1[j]) || hasEdge(set2[i], set2[j])){
//                 return false;
//             }
//         }
//     }

//     // Full connection between the sets
//     for(int i = 0; i < 3; i++){
//         for(int j = 0; j < 3; j++){
//             if(!hasEdge(set1[i], set2[j])){
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// // Determine if the graph is planar
// bool isPlanar() {
//     if (isK5() || isK33())
//         return false;
//     return true;
// }

// // Main function
// int main() {
//     V = 6; // Number of vertices

//     // Build the graph using your given edges
//     addEdge(adj, 0, 1);
//     addEdge(adj, 0, 2);
//     addEdge(adj, 0, 4);
//     addEdge(adj, 1, 3);
//     addEdge(adj, 1, 5);
//     addEdge(adj, 2, 5);
//     addEdge(adj, 2, 3);
//     addEdge(adj, 3, 4);
//     addEdge(adj, 4, 5);
    

//     // Output result
//     if (isPlanar())
//         cout << "Graph is probably planar." << endl;
//     else
//         cout << "Graph is NOT planar (K5 or K3,3 detected)." << endl;

//     return 0;
// }



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int Max = 100;
vector<int> adj[Max];
int V;

void addEdge(vector<int> graph[], int u, int v){
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
}

bool hasEdge(int u, int v) {
    for(int neighbor : adj[u]) {
        if(neighbor == v) return true;
    }
    return false;
}

// Check if a subset of 5 vertices is K5
bool containsK5() {
    if (V < 5) return false;

    vector<int> nodes(V);
    for (int i = 0; i < V; i++) nodes[i] = i;

    vector<bool> select(V, false);
    fill(select.begin(), select.begin() + 5, true);

    do {
        vector<int> subset;
        for (int i = 0; i < V; ++i) {
            if (select[i]) subset.push_back(i);
        }

        bool isComplete = true;
        for (int i = 0; i < 5 && isComplete; ++i) {
            for (int j = i + 1; j < 5; ++j) {
                if (!hasEdge(subset[i], subset[j])) {
                    isComplete = false;
                    break;
                }
            }
        }

        if (isComplete) return true;

    } while (prev_permutation(select.begin(), select.end()));

    return false;
}

// Check if any subset of 6 vertices forms K3,3
bool containsK33() {
    if (V < 6) return false;

    vector<int> nodes(V);
    for (int i = 0; i < V; i++) nodes[i] = i;

    vector<bool> select(V, false);
    fill(select.begin(), select.begin() + 6, true);

    do {
        vector<int> subset;
        for (int i = 0; i < V; ++i) {
            if (select[i]) subset.push_back(i);
        }

        // Try all possible 3-3 partitions
        for (int a = 0; a < 6; ++a) {
            for (int b = a + 1; b < 6; ++b) {
                for (int c = b + 1; c < 6; ++c) {
                    int set1[3] = {subset[a], subset[b], subset[c]};
                    int set2[3], idx = 0;

                    for (int i = 0; i < 6; i++) {
                        if (i != a && i != b && i != c)
                            set2[idx++] = subset[i];
                    }

                    // Check for bipartite connection: no internal edges
                    bool valid = true;
                    for (int i = 0; i < 3 && valid; i++) {
                        for (int j = i + 1; j < 3; j++) {
                            if (hasEdge(set1[i], set1[j]) || hasEdge(set2[i], set2[j])) {
                                valid = false;
                                break;
                            }
                        }
                    }

                    // Check full connection across sets
                    if (valid) {
                        for (int i = 0; i < 3 && valid; i++) {
                            for (int j = 0; j < 3; j++) {
                                if (!hasEdge(set1[i], set2[j])) {
                                    valid = false;
                                    break;
                                }
                            }
                        }
                    }

                    if (valid) return true;
                }
            }
        }

    } while (prev_permutation(select.begin(), select.end()));

    return false;
}

bool isPlanar() {
    if (containsK5() || containsK33())
        return false;
    return true;
}

int main() {
    V = 6;

    // Non-planar graph (subdivision of K3,3)
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 1, 5);
    addEdge(adj, 2, 5);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 5);

    if (isPlanar())
        cout << "Graph is probably planar." << endl;
    else
        cout << "Graph is NOT planar (K5 or K3,3 detected)." << endl;

    return 0;
}
