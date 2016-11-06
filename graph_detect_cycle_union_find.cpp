#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <stack>
#include <list>

using namespace std;

class node_uf
{
    int *parent; // given an array the value at pos i is the parent of ith element initially each element is its own parent 
    int *rank; // the rank is the total number of elements stored in the set
    int count; // count is the number of sets  initially it is the the same as the number of elements
    int n; // it is the number of elements
public:
    node_uf(int number) : count(n) , n(number)  // make set is implicitly present in the constructor
    {
        parent = new int[n];
        rank = new int[n];
        for(int i=0 ; i < n ; i++ )
        {
            parent[i]=i;
            rank[i]=0;
        }
    }

    int find_set(int x)
    {
        if(parent[x]==x)
            return x;
        parent[x]=find_set(parent[x]);
        return parent[x];
    }

    // the only change here is that if already both in the same set we return as false and it implies that there is a cycle
    bool link(int x, int y)
    {
        if(x==y)
        {
            // printf("%d and %d are already linked\n",x,y );
            return false;
        }
        if( rank[x] > rank[y] )
            parent[y]=x;
        else
        {
            parent[x]=y;
            if(rank[x]==rank[y])
                rank[y]++;
        }
        return true;
    }

    bool UNION(int x, int y)
    {
        return link(find_set(x),find_set(y));
    }

    void print_parent()
    {
        cout<<"\nThe parent pointers are: \n";
        for(int i=0;i<n;i++)
            cout<<setw(5)<<parent[i];
        cout<<"\n";
    }
};

class graph
{
public:
    int v;
    list<int> *adj;
    graph(int vertex=1)
    {
        v=vertex;
        adj=new list<int>[v];
    }
    void addEdge(int u,int v)
    {
        // make this as undirected
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void print()
    {
        cout<<"\nThe graph presented as the adjaceny list is as follows :\n";
        list<int>::iterator it;
        for(int i=0;i<v;i++)
        {
            cout<<i<<" --> ";
            it=adj[i].begin();
            while( it!=adj[i].end() )
            {
                cout<<"-> "<<*it;
                it++;
            }
            cout<<"\n";
        }
    }
    void check_cycle()
    {
        node_uf uf(v); // number of vertices in the graph
        list<int>::iterator it;
        for(int i=0;i<v;i++)
            for(it=adj[i].begin() ; it!=adj[i].end() ; it++ )
                if( ( *it > i ) && !uf.UNION(i,*it) ) //  the most trickiest point here hum log union ko modify kiye hai ki if its possible to unite then return true if both sides present return false and first part which is *it > i is to make sure that since this is a undirected graph we dont consider each edge as twice in our computation ( we cannot in any case check for a cycle using this for directed graph )
                {
                    cout<<"\nCycle detected";
                    uf.print_parent();
                    return;
                }
        cout<<"\nThere is no cycle in this undirected graph";
    }
};
int main()
{
    graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    // graph g(5);
    // g.addEdge(0,1);
    // g.addEdge(0,2);
    // g.addEdge(1,2);
    // g.addEdge(0,3);
    // g.addEdge(3,4);
    g.print();
    g.check_cycle();
    return 0;
}