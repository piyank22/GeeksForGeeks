#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

#define v 5

using namespace std;

bool issafe(int prev_vertex,int new_vertex, int graph[v][v], bool check[])
{
    if(!graph[prev_vertex][new_vertex])
        return false;
    if( check[new_vertex] || (new_vertex==0 && prev_vertex==0) )
        return false;
    return true;
}

bool ham_cycle_util(int graph[v][v] , bool check[] , vector<int> &cycle)
{
    for(int i=0;i<v;i++)
        if(issafe(cycle.back(),i,graph,check))
        {
            cycle.push_back(i);
            check[i]=true;
            if( cycle.size() == v+1 && i==0 )
                return true;
            if( ham_cycle_util(graph,check,cycle) )
                return true;
            cycle.pop_back();
            check[i]=false;
        }
    return false;
}

bool hamCycle(int graph[v][v])
{
    bool check[v]={false};
    vector<int> cycle;
    cycle.push_back(0);
    if(ham_cycle_util(graph,check,cycle))
    {
        for(int i=0;i<v+1;i++)
            cout<<setw(5)<<cycle[i];
        return true;
    }
    cout<<"\nNOt possible";
    return false;
} 

int main()
{
   /* Let us create the following graph
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)-------(4)    */
   int graph1[v][v] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };
    hamCycle(graph1);
 
   /* Let us create the following graph
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)       (4)    */
    int graph2[v][v] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 0},
                      {0, 1, 1, 0, 0},
                     };
    hamCycle(graph2);
 
    return 0;
}