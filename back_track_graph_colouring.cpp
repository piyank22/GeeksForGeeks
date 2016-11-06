#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>

#define v 4

using namespace std;

int *queenPos;

void print_colour_board(int *colour)
{
    cout<<"\n";
    for(int i=0;i<v;i++)
        cout<<setw(4)<<colour[i];
}

bool isSafe(int *colour,int vertex,int colour_number,int graph[v][v])
{
    for (int i = 0; i < v; ++i)
    {
        if(graph[vertex][i]==1)
        {
            if( colour[i] == colour_number )
                return false;
        }
    }
    return true;
}

bool solve_util(int vertex , int graph[v][v] , int *colour , int m)
{
    int colour_number=1;
    while(colour_number <= m)
    {  
        if( isSafe(colour,vertex,colour_number,graph) )
        {
            colour[vertex]=colour_number;
            if( vertex == v-1 )
                return true;
            if( solve_util( vertex+1 , graph , colour , m ) )
                return true;
            else
                colour[vertex]=-1;
        }
        colour_number++;
    }
    return false;
}

void solve_graph_colouring( int graph[v][v] , int m)
{
    int *colour=new int[v];
    for(int i=0;i<v;i++)
        colour[i]=-1;

    if( solve_util( 0 , graph , colour, m ) )
        print_colour_board( colour );
    else
    {
        cout<<"\ncannot be solved";
    }    
}

int main()
{
    int graph[v][v] = { {0, 1, 1, 1},
                        {1, 0, 1, 0},
                        {1, 1, 0, 1},
                        {1, 0, 1, 0} };
    int m=2; //  number of colours
    solve_graph_colouring( graph , m );
    return 0;
}