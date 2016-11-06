#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <stack>
#include <list>

using namespace std;

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
        adj[u].push_back(v);
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

    void topological_sort_util(int i, stack<int> &s, bool visited[])
    {
        visited[i]=true;

        list<int>::iterator it;
        for(it=adj[i].begin() ; it!=adj[i].end() ; it++)
            if(visited[*it]==false)
                topological_sort_util(*it,s,visited);

        s.push(i);
    }

    void topological_sort()
    {
        bool *visited = new bool[v];
        for(int i=0;i<v;i++)
            visited[i]=false;

        stack<int> s;

        for(int i=0;i<v;i++)
            if(visited[i]==false)
                topological_sort_util(i,s,visited);

        while(!s.empty())
        {
            cout<<s.top()<<" -- ";
            s.pop();
        }
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
    g.print();
    cout << "Following is the topological_sort for the given graph\n";
    g.topological_sort();
    cout<<"\n";
    return 0;
}