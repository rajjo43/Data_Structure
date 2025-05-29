#include <bits/stdc++.h>
using namespace std;

int main()
{
    int e;
    cout << "Enter number of edges: ";
    cin >> e;

    map <string, vector<string>> adj;
    cout << "Enter " << e << " edges(vertex1, vertex2): " << endl;
    for(int i = 0 ; i < e; i++){
        string u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // comment this line for directed graph
    }
        cout << "\nAdjacency List:\n";
        for(const auto& pair : adj)
        {
            cout << pair.first << " -> ";
            for(const auto& neighbor : pair.second)
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
        return 0;
}