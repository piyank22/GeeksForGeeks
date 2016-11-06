#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <stack>
#include <list>
#include <queue>
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
    graph get_transpose()
    {
        graph g_t(vertex);
        list<int>::iterator it;
        for(int i=0 ; i<vertex ; i++)
            for( it=adj[i].begin(); it!=adj[i].end() ; it++ )
                g_t.addEdge(*it,i);
        return g_t;
    }

    void fillOrder(int i, bool *visited,stack<int> &s)
    {
        visited[i]=true;
        list<int>::iterator it;
        for(it=adj[i].begin() ; it!=adj[i].end() ; it++)
            if(!visited[*it])
                fillOrder(*it,visited,s);
        s.push(i);
    }

    void dfs_util(int i, bool *visited)
    {
        // this dfs util is for the changed meaning of true and false saving us from again making all the boolean veriables as false
        visited[i]=false;
        cout<<i<<" -- ";
        list<int>::iterator it;
        for( it=adj[i].begin() ; it!=adj[i].end() ; it++)
            if(visited[*it])
                dfs_util(*it,visited);
    }

    // print strongly connected components
    void printSCC()
    {
        stack<int> s;
        bool *visited=new bool[vertex];
        for(int i=0;i<vertex;i++)
            visited[i]=false;
        // Fill vertices in stack according to their finishing times
        for(int i = 0; i < vertex; i++)
            if(visited[i] == false)
                fillOrder(i, visited, s);
        // now note that all the visited bools are true
        // now the meaning of true and false changes
        graph g_t=get_transpose();
        while(!s.empty())
        {
            if(visited[s.top()]==false)
            {
                s.pop();
                continue;
            }
            int t=s.top();
            s.pop();
            cout<<"\n";
            g_t.dfs_util(t,visited);
        }
    }
};

int main()
{
    graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.print();
    (g.get_transpose()).print();
    g.printSCC();
    return 0;
}