#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10000]; //adjacency list
int main()
{
    int nodes;
    cout << "Enter Number of Nodes: ";
    cin >> nodes;
    int edges;
    cout << "Enter Number of Edges: ";
    cin >> edges;

    cout << "Enter edges(x,y) : " << endl;
    while(edges --)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int visited[nodes] = {0};
    int distance[nodes], parent[nodes];
    int s = 0; //source vertex
    visited[s] = 1;
    distance[s] = 0;
    parent[s] = -1;

    queue<int> q;
    q.push(s);

    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int u : adj[v])
        {
            if(!visited[u])
            {
                visited[u] = 1;
                q.push(u);
                distance[u] = distance[v] + 1; 
                parent[u] = v;
            }
        }
    }

    for(int i = 0; i < nodes; i++)
    {
        cout << distance[i] <<" ";
    }

    cout << endl;

/* the graph
0 1
0 2
0 3
2 4
2 5
3 5 
so the destination is 5   */

    //path till destination
    int destination = 5;
    vector<int>path;

    if(visited[destination] == 0)
    {
        cout << "No path" << endl;
    }
    else
    {
       
        int x = destination;
        while(x!= -1)
        {
            path.push_back(x);
            x = parent[x];
        }

        reverse(path.begin(), path.end());
    }

    for(int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
}