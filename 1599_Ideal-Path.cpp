#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector < vector<int> > allPaths;

void getAllPaths(vector< pair <int , int> > adjList[] , vector<bool>& visited , vector<int>& path , int src , int n)
{
    visited[src] = true;
    if(src == n)
    {
        allPaths.push_back(path);
        visited[src] = false;
        return;
    }
    for(auto entry : adjList[src])
    {
        int childNode = entry.first;
        int color = entry.second;

        if(visited[childNode] == false)
        {
            path.push_back(color);
            getAllPaths(adjList , visited , path , childNode , n);
            path.pop_back();
        }
    }
    visited[src] = false;
}

int main()
{
    ll n , m;
    cin >> n >> m;

    vector < pair <int , int> > adjList[n + 1];

    for(int i = 1 ; i <= m ; i++)
    {
        ll v1 , v2 , c;
        cin >> v1 >> v2 >> c;
        adjList[v1].push_back( { v2 , c} );
        adjList[v2].push_back( { v1 , c } );
    }

    vector <bool> visited(n + 1 , false);

    vector <int> path;

    getAllPaths(adjList , visited , path , 1 , n);

    int ideal_path_index;

    int ideal_path_length = 1e9;

    for(int i = 0 ; i < allPaths.size() ; i++)
    {
        if(allPaths[i].size() < ideal_path_length)
        {
            ideal_path_length = allPaths[i].size();
            ideal_path_index = i;
        }
        else if(allPaths[i].size() == ideal_path_length)
        {
            for(int j = 0 ; j < allPaths[i].size() ; j++)
            {
                if(allPaths[i][j] < allPaths[ideal_path_index][j])
                {
                    ideal_path_index = i;
                    break;
                }
                else if(allPaths[i][j] > allPaths[ideal_path_index][j])
                {
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
    }

    cout << ideal_path_length << endl;

    for(auto color : allPaths[ideal_path_index])
    {
        cout << color << " ";
    }

    cout << endl;

    return 0;
}