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
    bool **tc;
public:
    graph(int v)
    {
        vertex=v;
        adj=new list<int>[vertex];
        tc = new bool* [vertex];
        for (int i=0; i<vertex ; i++)
        {
            tc[i] = new bool[vertex];
            memset(tc[i], false, vertex*sizeof(bool));
        }
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

    void dfs_util(int i, int j)
    {
        tc[i][j]=true;
        list<int>::iterator it;
        for( it=adj[j].begin() ; it!=adj[j].end() ; it++) // be carefull adjaceny list hum log j ka dekhne ge
            if(tc[i][*it]==false)
                dfs_util(i,*it);
    }
    void transitiveClosure()
    {
        for (int i = 0; i < vertex; i++)
            dfs_util(i, i);

        for (int i=0; i<vertex; i++)
        {
            for (int j=0; j<vertex; j++)
                cout << tc[i][j] << " ";
            cout << endl;
        }
    }
};

int main()
{
    graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(6, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 2);
    g.addEdge(6, 0);
    g.print();
    cout << "Transitive closure matrix is \n";
    g.transitiveClosure();
    return 0;
}