#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> col;
bool bipartite;

void color(int u, int curent_col) // u--> current node;  curent_col--> the color we want to assign
{
    if(col[u] != -1 && col[u] != curent_col){
        bipartite = false;
        return;
    }
    col[u] = curent_col;
    if(vis[u]){
        return;
    }
    vis[u] = true;
    for(auto i : adj[u]){
        color(i, curent_col xor 1);
    }
}

int main()
{
    bipartite = true;
    int n, m;
    cout << "Enter the number of vertex: " ;
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    adj = vector<vector<int>>(n);
    vis = vector<bool>(n, false);
    col = vector<int>(n, -1);

    cout << "Enter " << m << " edges(u,v): "<< endl;
    for(int i = 0; i < m; i++)
    {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    for(int i = 0; i < n; i++)
    {
        if(!vis[i]){
            color(i, 0);
        }
    }

    if(bipartite){
        cout << "Graph is bipartite" << endl;
    }else{
        cout << "Graph is not bipartite" << endl;
    }
}

///////////////////////////////////////////////////////////////////////////
// for adjacency list
/*
int main()
{
    bipartite = true;
    int n, m;

    // ===== OPTION 1: User input using edges =====
    /*
    cout << "Enter the number of vertex: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    adj = vector<vector<int>>(n);
    vis = vector<bool>(n, false);
    col = vector<int>(n, -1);

    cout << "Enter " << m << " edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    */

    // ===== OPTION 2: Hardcoded input =====
   /* adj = {{1,2,3}, {0,2}, {0,1,3}, {0,2}};
    n = adj.size();
    vis = vector<bool>(n, false);
    col = vector<int>(n, -1);

    // Run bipartite check
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            color(i, 0);
        }
    }

    if (bipartite) {
        cout << "Graph is bipartite" << endl;
    } else {
        cout << "Graph is not bipartite" << endl;
    }

    return 0;
}


*/