// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int n,m;
// const int N = 1e5 + 3;
// vector<vector<int>> g[N];
// int cost = 0;
// vector<int> dist(N), parent(N);
// vector<bool> vis(N);
// const int INF = 1e9;

// void primsMST(int source){
//     for(int i = 0; i < n; i++){
//         dist[i] = INF;
//     }
//     set<vector<int>> s;
//     dist[source] = 0;
//     s.insert({0, source});
//     // {wt, vertex}
//     while(!s.empty()){
//         auto x = *(s.begin());
//         s.erase(x);
//         vis[x[1]] = true;
//         int u = x[1];
//         int v = parent[x[1]];
//         int w = x[0];
//         cout << u << " " << v << " " << w << "\n";
//         cost += w;
//         for(auto it : g[x[1]]){
//             if(vis[it[0]]){
//                 continue;
//             }
//             if(dist[it[0]] > it[1]){
//                 s.erase({dist[it[0]], it[0]});
//                 dist[it[0]] = it[1];
//                 s.insert({dist[it[0]], it[0]});
//                 parent[it[0]] = x[1];
//             }
//         }
//     }
// }
// int main()
// {
//     cout << "Enter the number of vertices: ";
//     cin >> n;
//     cout << "Enter the number of edges: ";
//     cin >> m;

//     cout << "Enter " << m << " edges(u,v) & weight w: ";
//     for(int i = 0; i < m; i++){
//         int u, v, w;
//         cin >> u >> v >> w;
//         g[u].push_back({v,w});
//         g[v].push_back({u,w});
//     }
//     primsMST(0);
//     cout << cost;
// }


#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int N = 1e5 + 3;
const int INF = 1e9;

int n, m; // number of vertices and edges
vector<vector<int>> g[N]; // adjacency list: g[u] = {{v, weight}, ...}
vector<int> dist(N, INF); // shortest known edge to connect each vertex to MST
vector<int> parent(N, -1); // parent of each vertex in MST
vector<bool> vis(N, false); // to track visited (MST-included) vertices
int totalCost = 0; // total weight of the MST

void primsMST(int source) {
    dist[source] = 0;
    set<pair<int, int>> s; // {weight, vertex}
    s.insert({0, source});

    while (!s.empty()) {
        auto current = *(s.begin());
        s.erase(current);

        int currentVertex = current.second;
        int currentWeight = current.first;

        vis[currentVertex] = true; // include in MST

        int parentVertex = parent[currentVertex];
        cout << parentVertex << " " << currentVertex << " " << currentWeight << "\n";
        totalCost += currentWeight;

        // Check all neighbors
        for (auto neighbor : g[currentVertex]) {
            int nextVertex = neighbor[0];
            int edgeWeight = neighbor[1];

            // Skip if already in MST
            if (vis[nextVertex]) continue;

            // If this edge is better than previously known one
            if (dist[nextVertex] > edgeWeight) {
                s.erase({dist[nextVertex], nextVertex}); // remove old pair if exists
                dist[nextVertex] = edgeWeight;           // update to better weight
                parent[nextVertex] = currentVertex;      // update parent
                s.insert({dist[nextVertex], nextVertex}); // insert new pair
            }
        }
    }
}

int main() {
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    cout << "Enter " << m << " edges (u v w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w}); // undirected graph
    }

    cout << "u, v, w: "<< endl;
    primsMST(0); // start from vertex 0
    cout << "Total cost of MST: " << totalCost << endl;

    return 0;
}
