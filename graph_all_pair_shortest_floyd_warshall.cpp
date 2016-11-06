#include <cstdio>
#include <vector>
#include <list>
#include <iostream>
#include <map>
#include <utility>
#include <iomanip>

#define V 5
#define INF INT_MAX

using namespace std;

void printSolution(int dist[V][V])
{
    printf ("Following matrix shows the shortest distances between every pair of vertices \n");
    for (int i = 0; i < V; i++,printf("\n"))
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
}
void printpath_util(int parent[V][V], int i, int j)
{
    if(i==j)
        printf("\t%d",i);
    else if(parent[i][j]==-1)
        return;
    else
    {
        printpath_util(parent,i,parent[i][j]);
        printf("\t%d",j);
    }
}

void printpath(int parent[V][V], int dist[V][V])
{
    int n=V;
    for(int i=0;i<n;i++,printf("\n"))
        for(int j=0;j<n;j++)
            if(dist[i][j]!=INF && i!=j)
            {
                printf("\nThe path from %d to %d is : ",i,j);
                printpath_util(parent, i, j);
            }
}   

int sum_Special(int a, int b)
{
    if(a==INT_MAX || b==INT_MAX)
        return INF;
    return a+b;
}

void mat_multiply_funny(int a[V][V] , int parent[V][V])
{
    int n=V;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
            {
                if(a[i][j] > sum_Special( a[i][k] ,  a[k][j] ))     // for parent 
                    parent[i][j]=k;                                    // for parent
                a[i][j] = min( a[i][j] , sum_Special( a[i][k] ,  a[k][j] ) ); // interger is circular in computer INT_MAX + 1 == INT_MIN
            }
}

void floydWarshall(int graph[V][V])
{
    int dist[V][V];
    int parent[V][V];
    int i,j;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
        {
            dist[i][j] = graph[i][j];
            if(i==j || dist[i][j]==INF)
                parent[i][j]=-1;
            else
                parent[i][j]=i;
        }
    int n=1;
    for(int k=0;k<V;k++)
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                if(dist[i][j] > sum_Special(dist[i][k],dist[k][j]))
                {
                    parent[i][j]=parent[k][j];
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
    printSolution(dist);
    printSolution(parent);
    printpath(parent,dist);
}

int main()
{
    int graph[V][V] = { {0,   3,8,  INF, -4},
                        {INF, 0,  INF,1,7},
                        {INF,4,0,INF, INF},
                        {2,INF, -5,0,INF},
                        {INF,INF,INF,6,0}
                      };
    // Print the solution
    floydWarshall(graph);
    return 0;
}