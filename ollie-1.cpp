#include <iostream>
#include <vector>

using namespace std;

// DFS Traversal --> Undirected Graph

void dfs(vector<int> adjList[] , vector<bool>& visited , int src)
{
    visited[src] = true;
    cout << src << " ";
    for( auto child : adjList[src] )
    {
        if( visited[child] == true )
        {
            continue;
        }
        else
        {
            dfs(adjList , visited , child);
        }
    }
    return;
}

int main()
{
    int vertices , edges;
    
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edges;

    vector <int> adjacencyList[vertices];

    cout << "Enter the edges: " << endl;

    for(int i = 1 ; i <= edges ; i++)
    {
        int v1 , v2;
        cin >> v1 >> v2;
        adjacencyList[v1].push_back(v2);
        adjacencyList[v2].push_back(v1);
    }

    vector <bool> visited(vertices , false);

    cout << "DFS Traversal: ";

    dfs(adjacencyList , visited , 0);

    cout << endl;

    return 0;
}
