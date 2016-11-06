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

class adjlistnode
{
    int v;
    int weight;
public:
    adjlistnode(int vv,int w=1) : v(vv) , weight(w) { }
    int getv() { return v; }
    int getweight() { return weight; }
};

class graph
{
    int vertex;
    list<adjlistnode> *adj;
public:
    graph(int v)
    {
        vertex=v;
        adj=new list<adjlistnode>[vertex];
    }
    void addEdge(int u, int v, int w)
    {
        adjlistnode temp(v,w);
        adj[u].push_back(temp);
    }
    void print()
    {
        cout<<"\nThe graph is:";
        for(int i=0;i<vertex;i++)
        {
            cout<<"\nEdges from vertex "<<i<<" are: ";
            list<adjlistnode>::iterator it;
            for(it=adj[i].begin() ; it!=adj[i].end() ; it++)
            {
                printf("( u = %d , v = %d , weight = %d ) , ", i , (*it).getv() , (*it).getweight() );
            }
        }
        printf("\n");
    }

    void topological_sort_util(int i,vector<bool> &visited, stack<int> &s)
    {
        visited[i]=true;

        list<adjlistnode>::iterator it;
        for( it=adj[i].begin() ; it!=adj[i].end() ; it++ )
            if(!visited[(*it).getv()])
                topological_sort_util((*it).getv(),visited,s);
        s.push(i);
    }

    void topological_sort(stack<int> &s)
    {
        vector<bool> visited(vertex,false);

        for(int i=0;i<vertex;i++)
            if(!visited[i])
                topological_sort_util(i,visited,s);
    }

    void shortest_path(int start)
    {
        // first do topological sort
        stack<int> s;
        topological_sort(s);

        vector<int> dist(vertex,INT_MAX);
        dist[start]=0;

        list<adjlistnode>::iterator it;

        while(s.empty()==false)
        {
            int t=s.top();
            if(dist[t]!=INT_MAX)
            {
                for(it=adj[t].begin() ; it !=adj[t].end() ; it++ )
                    if( dist[it->getv()] > dist[t] + it->getweight() )
                        dist[it->getv()] = dist[t] + it->getweight();
            }
            s.pop();
        }

        printf("\n");
        for(int i=0;i<vertex;i++)
            (dist[i]==INT_MAX) ? cout<<setw(5)<<"INF" : cout<<setw(5)<<dist[i];

    }

    void longest_path(int start)
    {
        // first do topological sort
        stack<int> s;
        topological_sort(s);

        vector<int> dist(vertex,INT_MIN);
        dist[start]=0;

        list<adjlistnode>::iterator it;

        while(s.empty()==false)
        {
            int t=s.top();
            if(dist[t]!=INT_MAX)
            {
                for(it=adj[t].begin() ; it !=adj[t].end() ; it++ )
                    if( dist[it->getv()] < dist[t] + it->getweight() )
                        dist[it->getv()] = dist[t] + it->getweight();
            }
            s.pop();
        }

        printf("\n");
        for(int i=0;i<vertex;i++)
            (dist[i]==INT_MIN) ? cout<<setw(5)<<"INF" : cout<<setw(5)<<dist[i];

    }
};

int main()
{
    graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    g.addEdge(3, 5, 1);
    g.print();
    g.shortest_path(1);
    g.longest_path(1);
    return 0;
}