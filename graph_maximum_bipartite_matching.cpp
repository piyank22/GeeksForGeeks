#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring> // for memset
#include <vector>
#include <iomanip>

#define M 6
#define N 6

using namespace std;

bool does_match(int u, int graph[M][N] ,bool seen[N] , int matchR[N])
{
    for(int j=0;j<N;j++)
        if(seen[j]==false && graph[u][j]==1 )
        {
            seen[j]=true;
            if( matchR[j]==-1 || does_match(matchR[j],graph,seen,matchR))
            {
                matchR[j]=u;
                return true;
            }
        }

    return false;
}

int max_bipartite_matching(int graph[M][N])
{
    // An array to keep track of the applicants assigned to jobs. The value of matchR[i] is the applicant number assigned to job i, the value -1 indicates nobody is assigned.
    int matchR[N];
    // Initially all jobs are available
    memset(matchR, -1, sizeof(matchR));
    
    int res=0;
    for(int i=0;i<M;i++)
    {
        bool seen[N];
        memset(seen,false,sizeof(seen));
        if(does_match(i,graph,seen,matchR))
            res++;
    }
    return res;
}

int main()
{
    // graph where M is the L in the bipartite graph and N is the R in the bipartite graph
    int graph[M][N]= {  {0, 1, 1, 0, 0, 0},
                        {1, 0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 1}
                      };
 
    cout << "Maximum number of applicants that can get job is "<< max_bipartite_matching(graph);
 
    return 0;
}