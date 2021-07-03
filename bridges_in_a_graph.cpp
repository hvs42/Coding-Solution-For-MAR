#include<bits/stdc++.h>
using namespace std;

// dfs

void dfs(int node, int parent, vector<int> &visited, vector<int> &tin, vector<int> &lowtin, 
                                                            int &timer, vector<int>adj[])
{
    visited[node] = 1;
    tin[node] = lowtin[node] = timer++;

    for(auto it : adj[node])        //iterate through adjacent nodes
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
    //first create graph

    int n, m;
    cin >> n >> m;   //no. of nodes and no. of edges respectively

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

    // applying dfs

    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            dfs(i, -1, visited, tin, lowtin, timer, adj);
        }
    }
    return 0;    
}

/*Note :-  This is correct programe all test cases from gfg have passed in this program

Test Case 1 :-  Graph Link:- https://media.geeksforgeeks.org/wp-content/cdn-uploads/Bridge1.png

        Input:-
                5 5
                1 0
                0 2
                2 1
                0 3
                3 4
        Output:-
                ( 3 -- 4 ) 
                ( 0 -- 3 )

Test Case 2 :-   Graph Link:- https://media.geeksforgeeks.org/wp-content/cdn-uploads/Bridge2.png

        Input:-
                4 3
                0 1
                1 2
                2 3
        Output:-
                ( 2 -- 3 ) 
                ( 1 -- 2 )
                ( 0 -- 1 )

Test Case 3 :-   Graph Link:- https://media.geeksforgeeks.org/wp-content/cdn-uploads/Bridge3.png

        Input:-
                7 8
                0 1
                1 2
                2 0
                1 3
                1 4
                1 6
                3 5
                4 5
        Output:-
                ( 1 -- 6 )

*/