#include <iostream>
#include <utility>
#include <list>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

class graph
{
    int v;
    list< pair<int,int> > *adj; // destination , weigth
public:

    graph(int vertex ) : v(vertex) 
    {
        adj= new list< pair<int , int> >[v];
    }

    void print()
    {
        int count=0;
        list< pair<int,int> >::iterator it;
        for(int i=0;i<v;i++)
        {
            for(it=adj[i].begin() ; it!=adj[i].end() ; it++)
            {
                count++;
                printf("( u=%d , v=%d , weight=%d)\n", i , it->first , it->second );
            }
        }
        cout<<count;
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    int max_path(int s)
    {
        vector<bool> path_till_now(v,false);
        path_till_now[s]=true;
        int number_of_vertex_in_path=1;
        int sum=0; // sum represents sum so far
        return max_path_util( s , path_till_now , number_of_vertex_in_path , sum );
    }

    int max_path_util(int s, vector<bool> path , int number_of_vertex_in_path , int sum)
    {
        if( number_of_vertex_in_path == v )
            return sum; // clearly we return the total sum bitch

        list< pair<int,int> >::iterator it;
        int total=sum;
        for( it=adj[s].begin() ; it!=adj[s].end() ; it++ )
        {
            
            if( path[it->first]==false )
            {
                path[it->first]=true;
                total = max ( total , max_path_util( it->first , path , number_of_vertex_in_path + 1 , sum + (it->second) ) ); // since we return the total sum
                path[it->first]=false;
            }
        }
        return total;
    }
};

int main()
{
    int V = 9;
    graph g(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    cout<<g.max_path(0);
    // int src = 0;
    // int k = 62;
    // g.path_more_than_k(src, k)? cout << "Yes\n" : cout << "No\n";
 
    // k = 60;
    // g.path_more_than_k(src, k)? cout << "Yes\n" : cout << "No\n";
 
    return 0;
}