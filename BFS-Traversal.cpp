#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<int> adjList[] , vector<bool>& visited , int src)
{
    queue <int> q;
    q.push(src);

    visited[src] = true;

    int size = q.size();

    while( !q.empty() )
    {
        int size = q.size();

        while(size--)
        {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for( auto child: adjList[node] )
            {
                if(visited[child] == true)
                {
                    continue;
                }
                visited[child] = true;
                q.push(child);
            }
        }

        cout << endl;
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

    vector <int> adjList[vertices];

    cout << "Enter the edges of the graph: " << endl;

    for(int i = 1 ; i <= edges ; i++)
    {
        int v1 , v2;
        cin >> v1 >> v2;
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }

    vector <bool> visited(vertices , false);

    cout << "BFS Traversal: " << endl;

    bfs(adjList , visited , 0);

    return 0;
}