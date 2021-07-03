// Coding Solution For MAR
// Name: Harsh Vardhan Singh
// University Roll No. : 16900219042
// Department : Information Technology
// Year : 2nd year (4th Sem)


// Problem :- Find Bridges in a graph


#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> &visited, vector<int> &tin, vector<int> &lowtin, 
                                                            int &timer, vector<int>adj[])
{
    visited[node] = 1;
    tin[node] = lowtin[node] = timer++;

    for(auto it : adj[node])      
    {
        if(it == parent) continue;

        if(!visited[it])
        {
            dfs(it, node, visited, tin, lowtin, timer, adj);
            lowtin[node] = min(lowtin[node], lowtin[it]);

            if(lowtin[it] > tin[node])
            {
                cout<<"( "<<node<<" -- "<<it<<" ) "<<endl;
            }
        }
        else
        {
            lowtin[node] = min(lowtin[node], tin[it]);
        }
    }
}



int main()
{
    

    int n, m;
    cin >> n >> m;   

    vector<int> adj[n];
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> tin(n, -1);
    vector<int> lowtin(n, -1);
    vector<int> visited(n, 0);
    int timer=0;


    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            dfs(i, -1, visited, tin, lowtin, timer, adj);
        }
    }
    return 0;    
}

