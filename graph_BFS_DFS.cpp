#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
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
    void BFS(int start)
    {
        bool *visited= new bool[v];
        for(int i=0;i<v;i++)
            visited[i]=false;
        visited[start]=true;
        list<int> queue;
        queue.push_back(start);
        list<int>::iterator it;

        while(!queue.empty())
        {
            int temp=queue.front();
            queue.pop_front();
            cout<<temp<<" ";

            for(it=adj[temp].begin() ; it != adj[temp].end() ; it++ )
                if(!visited[*it])
                {
                    visited[*it]=true;
                    queue.push_back(*it);
                }
        }
    }
    void DFS(int start)
    {
        bool *visited= new bool[v];
        for(int i=0;i<v;i++)
            visited[i]=false;
        visited[start]=true;
        list<int> queue;
        queue.push_back(start);
        // be careful depth first aur breath first mein khas koi diff nahi hai
        list<int>::reverse_iterator it;

        while(!queue.empty())
        {
            int temp=queue.front();
            queue.pop_front();
            cout<<temp<<" ";

            for(it=adj[temp].rbegin() ; it != adj[temp].rend() ; it++ )
                if(!visited[*it])
                {
                    visited[*it]=true;
                    queue.push_front(*it);
                }
        }
    }
};
int main()
{
    graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.print();
    cout << "\nFollowing is Breadth First Traversal (starting from vertex 2)\n";
    g.BFS(2);
    cout << "\nFollowing is Depth First Traversal (starting from vertex 2)\n";
    g.DFS(2);
    cout<<"\n";
}