#include<bits/stdc++.h>
using namespace std;

int main()
{
    int V,E;
    cout << "Enter Number of Vertex: ";
    cin >> V;
    cout << "Enter Number of Edge: ";
    cin >> E;

    vector<int> adj[V + 1];
    cout << "Enter " << E << " edges(a, b) : " << endl;
    for(int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); //comment this line for directed graph

    }

    cout << "\nAdjacency List:\n";
    for(int i = 1; i <= V; i++)
    {
        cout << i << " -> ";
        for(auto j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }

}