#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

// Function to check if it is valid to color vertex `v` with color `c`
bool isValid(vector<int> graph[], vector<int>& color, int c, int v)
{
    for(auto u : graph[v]) // Check all adjacent vertices of `v`
    {
        if(color[u] == c) // If any adjacent vertex has the same color `c`, it's invalid
            return false;
    }
    return true; // Safe to color
}

// Recursive function to try to color the graph using at most `m` colors
bool graphColoring(vector<int> graph[], vector<int> color, int m, int v, int V)
{
    if(v == V) // If all vertices are colored, solution is found
        return true;

    for(int c = 1; c <= m; c++) // Try all colors 
    {
        if(isValid(graph, color, c, v)) // Check if color `c` is valid for vertex `v`
        {
            color[v] = c; // Assign color
            if(graphColoring(graph, color, m, v+1, V)) // Recur for next vertex
                return true; // If coloring was successful, return true
            color[v] = 0; // Backtrack (remove color)
        }
    }

    return false; // If no color could be assigned, return false
}

// Utility function to add an undirected edge between vertex `u` and `v`
void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].emplace_back(v); // Add `v` to the adjacency list of `u`
    graph[v].emplace_back(u); // Add `u` to the adjacency list of `v` (since undirected)
}

int main()
{
    int V = 10; // Total number of vertices in the graph
    vector<int> graph[V]; // Array of adjacency lists to represent the graph
    vector<int> color(V, 0); // Initialize color array with 0 (no color assigned yet)

    // Adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 0, 5);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 6);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 8);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 9);
    addEdge(graph, 4, 7);
    addEdge(graph, 5, 8);
    addEdge(graph, 5, 9);
    addEdge(graph, 6, 7);
    addEdge(graph, 6, 9);
    addEdge(graph, 7, 8);

    int m = 1; // Try with 1 color
    cout << "Is coloring possible using 1 color: " << graphColoring(graph, color, m, 0, V) << endl;

    m = 2; // Try with 2 colors
    cout << "Is coloring possible using 2 colors: " << graphColoring(graph, color, m, 0, V) << endl;

    m = 3; // Try with 3 colors
    cout << "Is coloring possible using 3 colors: " << graphColoring(graph, color, m, 0, V) << endl;

    return 0;
}
