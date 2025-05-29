//////////////////////////////////////////////////////////////////////////////////
// for just 1 topological order (queue-based Kahn’s algorithm)

// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// int main()
// {
//     int n, m;
//     cout << "Enter the number of vertices: ";
//     cin >> n;
//     cout << "Enter the number of edges: ";
//     cin >> m;

//     vector<vector<int>> adj_list(n);
//     vector<int> indeg(n, 0);

//     cout << "Enter " << m << " edges (u v): " << endl;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj_list[u].push_back(v); // u --> v
//         indeg[v]++;
//     }

//     queue<int> pq;
//     for (int i = 0; i < n; i++)
//     {
//         if (indeg[i] == 0)
//         {
//             pq.push(i);
//         }
//     }

//     int count = 0; // To count processed vertices
//     vector<int> topo; // To store topological order

//     while (!pq.empty())
//     {
//         int x = pq.front();
//         pq.pop();
//         topo.push_back(x);
//         count++;

//         for (auto it : adj_list[x])
//         {
//             indeg[it]--;
//             if (indeg[it] == 0)
//             {
//                 pq.push(it);
//             }
//         }
//     }

//     // Check for cycle
//     if (count != n)
//     {
//         cout << "Cycle detected! Topological sort not possible." << endl;
//     }
//     else
//     {
//         cout << "Topological Sort: ";
//         for (int node : topo)
//             cout << node << " ";
//         cout << endl;
//     }

//     return 0;
// }



///////////////////////////////////////////////////////////////////////////////////////////
// for all topological order(using backtracking)
#include <iostream>
#include <vector>
using namespace std;

void allTopologicalSorts(vector<vector<int>>& adj, vector<int>& indegree, vector<bool>& visited, vector<int>& result, int n) {
    bool flag = false;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && indegree[i] == 0) {
            visited[i] = true;
            result.push_back(i);

            for (int neighbor : adj[i]) {
                indegree[neighbor]--;
            }

            allTopologicalSorts(adj, indegree, visited, result, n);

            // Backtrack
            visited[i] = false;
            result.pop_back();
            for (int neighbor : adj[i]) {
                indegree[neighbor]++;
            }

            flag = true;
        }
    }

    // If no node was added in this call, it's a complete sort
    if (!flag) {
        for (int node : result) {
            cout << node << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> adj(n + 1); // 1 based indexing
    vector<int> indegree(n + 1, 0);

    cout << "Enter " << m << " edges (u v): " << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    vector<bool> visited(n + 1, false);
    vector<int> result;

    cout << "All Topological Sorts:\n";
    allTopologicalSorts(adj, indegree, visited, result, n);

    return 0;
}
