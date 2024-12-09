#include <bits/stdc++.h>

#define INF 1e18 + 7
#define ll long long

using namespace std;

set < pair <int , int> > st;

void dijkstraShortestPath(vector< pair <int , int> > adjList[] , vector<ll>& shortestDistanceFromSource , vector<int>& immediateParent , int source , int parent)
{
    for(auto entry : adjList[parent])
    {
        int child = entry.first;

        int distOfChildFromParent = entry.second;
        int distOfParentFromSource = shortestDistanceFromSource[parent];

        int distOfChildFromSource = distOfChildFromParent + distOfParentFromSource;

        if(distOfChildFromSource < shortestDistanceFromSource[child])
        {
            shortestDistanceFromSource[child] = distOfChildFromSource;
            immediateParent[child] = parent;
            dijkstraShortestPath(adjList , shortestDistanceFromSource , immediateParent , source , child);
        }
        else
        {
            continue;
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

    // Adjacency List for a weighted graph
    vector < pair <int , int> > adjList[vertices];

    cout << "Enter the edges and their weights: " << endl;

    for(int i = 1 ; i <= edges ; i++)
    {
        int v1 , v2 , weight;
        cin >> v1 >> v2 >> weight;
        adjList[v1].push_back( {v2 , weight});
        adjList[v2].push_back( {v1 , weight} );
    }

    int source;

    cout << "Enter the source vertex: ";
    cin >> source;

    vector <ll> shortestDistanceFromSource(vertices , INF);

    shortestDistanceFromSource[source] = 0;

    vector <int> immediateParent(vertices , -1);

    dijkstraShortestPath(adjList , shortestDistanceFromSource , immediateParent , source , source);

    cout << "Shortest distance of all vertices from the source vertex is: " << endl;
    for(int i = 0 ; i < vertices ; i++)
    {
        cout << "Vertex: " << i << " ---> Shortest Distance: " << shortestDistanceFromSource[i] << endl; 
    }

    cout << "Shortest Path from source vertex: " << endl;

    for(int i = 0 ; i < vertices ; i++)
    {
        cout << "Shortest Path from source to vertex " << i << " : ";
        int vertex = i;
        
        vector <int> shortestPath;
        shortestPath.push_back(vertex);
        while(immediateParent[vertex] != -1)
        {
            shortestPath.push_back(immediateParent[vertex]);
            vertex = immediateParent[vertex];
        }

        reverse(shortestPath.begin() , shortestPath.end());

        for(auto it : shortestPath)
        {
            cout << it << " ";
        }

        cout << endl;
    }

    return 0;
}