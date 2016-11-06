#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <stack>
#include <list>
#include <queue>

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

    void kahns_topological_sort()
    {
        int *indegree=new int[v];
        queue<int> q;
        for(int i=0;i<v;i++)
            indegree[i]=0;

        list<int>::iterator it;

        for(int i=0;i<v;i++)
        {
            for( it=adj[i].begin() ; it!=adj[i].end() ; it++ )
                indegree[*it]++;
        }
        
        for(int i=0;i<v;i++)
            if(indegree[i]==0)
                q.push(i);

        int count=0;
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            cout<<t<<" -- ";
            for(it=adj[t].begin() ; it!= adj[t].end() ; it++)
            {
                indegree[*it]--;
                if(indegree[*it]==0)
                    q.push(*it);
            }
            count++;
        }
        if(count!=v)
            cout<<"\nTopological_sort not possible\n";
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
    cout << "Following is the kahn's_topological_sort for the given graph\n";
    g.kahns_topological_sort();
    cout<<"\n";
    return 0;
}