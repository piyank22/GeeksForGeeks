#include <cstdio>
#include <vector>
#include <list>
#include <iostream>
#include <map>
#include <utility>
#include <iomanip>

#define V 4
#define inf INT_MAX

using namespace std;

int shortestPath(int graph[V][V] , int u, int v, int k)
{
    int sp[V][V][k+1];

    // e is the number of edges
    for(int e=0;e<=k;e++)
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
            {
                // intialize
                sp[i][j][e]=inf;

                if(e==0 && i==j)
                    sp[i][j][e]=0;
                else if(e==1 && graph[i][j]!=inf)
                    sp[i][j][e]=graph[i][j];
                else if(e>1)
                {
                    // there is a edge from i to p and there is a path of length e-1 from p to j , p must be different from both i and j , but i and j can be same
                    for(int p=0;p<V;p++)
                        if( p!=i && p!=j && graph[i][p]!=inf && sp[p][j][e-1]!=inf )
                            sp[i][j][e] = min( sp[i][j][e] , sp[p][j][e-1]+graph[i][p] );
                }
            }
    return sp[u][v][k];
}

int main()
{
    /* Let us create the graph shown in above diagram*/
     int graph[V][V] = { {0, 10, 3, 2},
                        {inf, 0, inf, 7},
                        {inf, inf, 0, 6},
                        {inf, inf, inf, 0}
                      };
    int u = 0, v = 3, k = 2;
    cout << "Weight of the shortest path is " <<
          shortestPath(graph, u, v, k);
    return 0;
}