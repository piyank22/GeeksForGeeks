#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <cstring> // for memset
#include <string>

using namespace std;

class graph
{
    int vertex;
    list<int> *adj;
public:
    graph(int v)
    {
        vertex=v;
        adj=new list<int>[vertex];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    void print()
    {
        cout<<"\nThe graph is:";
        for(int i=0;i<vertex;i++)
        {
            cout<<"\nEdges from vertex "<<i<<" are: ";
            list<int>::iterator it;
            for(it=adj[i].begin() ; it!=adj[i].end() ; it++)
            {
                printf("( u = %d , v = %d) , ", i , *it);
            }
        }
        printf("\n");
    }
    bool iscyclic_util(int i , vector<bool> &visited,vector<bool> &current_tree)
    {
        if(visited[i]==false)
        {
            visited[i] = current_tree[i] = true;
            list<int>::iterator it;
            for(it = adj[i].begin() ; it != adj[i].end() ; it++ )
                if( ( !visited[*it] && iscyclic_util(*it,visited,current_tree) ) || ( current_tree[*it] ) )
                    return true;
        }
        current_tree[i]=false;
        return false;
    }
    int iscyclic()
    {
        int v=vertex;
        vector<bool> visited(v,false);
        vector<bool> current_tree(v,false);
        int count = 0;
        for(int i=0;i<v;i++)
            if( iscyclic_util(i,visited,current_tree) )
                return true;
        return false;
    }
};

int main()
{
    int k = 3;
    graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(3,2);
    g.print();
    if(g.iscyclic())
        cout<<"\nCycle exists.";
    else
        cout<<"\nCycle doesnt exist.";
    return 0;
}