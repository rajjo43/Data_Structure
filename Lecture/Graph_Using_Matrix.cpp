#include<iostream>
using namespace std;

int main()
{
    int n, m;
    cout <<"Enter number of nodes/vertices: ";
    cin >> n;
    cout <<"Enter number of edges: ";
    cin >> m;

    int adj[n + 1][n + 1] = {0};

    cout <<"Enter " << m <<" edges(u, v): ";
    for(int i = 0; i < m ; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;  // comment this line for directed graph
    }

   // Print adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    // Print as adjacency list
    cout << "\nGraph connections:\n";
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int j = 1; j <= n; j++) {
            if (adj[i][j] == 1) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
    return 0;
}