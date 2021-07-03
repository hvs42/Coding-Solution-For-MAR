#include<bits/stdc++.h>
#include<map>

using namespace std;

template <typename T>

class Graph
{
    private:
        map<T, list<T> > l;
    public:
        void addEdge(int x, int y){
            l[x].push_back(y);  


            // l[y].push_back(x);  

            //because in snake and ladder the graph is unidirectional graph so we instead of connecting both (x -> y) and (y -> x), we will only connect (x -> y), so we will comment the second line. 
        }


        int bfs(T src, T dest)
        {
            
            map<T, int> dist; //map to calculate distance from a node
            map<T,T> parent;
            queue<T> q;

            //All other nodes will have int_max, i.e infinity

            for(auto node_pair : l)
            {
                T node = node_pair.first;
                dist[node] = INT_MAX;
            }

            q.push(src);
            dist[src] = 0;
            parent[src] = src;

            while (!q.empty())
            {
                T node = q.front();
                q.pop();

                for(int nbr : l[node])
                {
                    if(dist[nbr] == INT_MAX)
                    {
                        q.push(nbr);

                        dist[nbr] = dist[node] + 1;

                        parent[nbr] = node;
                    }
                }
            }
            
            // for(auto node_pair : l)
            // {
            //     T node = node_pair.first;
            //     int d = dist[node];
            //     cout<<node<<" and dist "<<d<<endl;
            // }

            //Dest to src

            // T temp = dest;
            // while(temp != src)
            // {
            //     cout<<temp<<"<--";
            //     temp = parent[temp];
            // }

            // cout<<src<<endl;

            return dist[dest];

        }
};

int main()
{

    int board[50] = {0};

    //for ladder
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[25] = 10;

    //for snake
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[32] = -2;
    board[34] = -22;

    //Add Edges to the graph

    Graph<int> g;

    for(int i=0; i<36; i++)
    {
        for(int dice=1; dice<=6; dice++)  //dice can be selected in random manner in real game.
        {
            int j = i + dice;

            j += board[j];

            if(j<=36)
            {
                g.addEdge(i,j);
            }
        }
    }

    g.addEdge(36 , 36);

    cout<<g.bfs(0, 36);
    

    return 0;
}


// Line 12: Char 20: warning: address of stack memory associated with local variable 'arr' returned [-Wreturn-stack-address]
//             return arr;
//                    ^~~
// Line 19: Char 20: warning: address of stack memory associated with local variable 'arr' returned [-Wreturn-stack-address]
//             return arr;
//                    ^~~
// Line 26: Char 23: error: no member named 'length' in 'std::vector<std::vector<int, std::allocator<int>>, std::allocator<std::vector<int, std::allocator<int>>>>'
//         int n = board.length();
                ~~~~~ ^