#include <iostream>
#include <utility>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

bool comparision_weight( pair< int , pair<int,int> > a , pair< int , pair<int,int> > b)
{
    return (a.first<b.first);
}

class disjointSets
{
    int n;
    int *parent, *rank;
public:
    disjointSets(int N) : n(N)
    {
        parent=new int[n];
        rank=new int[n];
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
    }
    // find , link , union
    int find(int x)
    {
        if(parent[x]==x)
            return x;
        parent[x]=find(parent[x]);
        return parent[x];
    }
    void link(int x, int y)
    {
        if(x==y)
            return;
        if( rank[x] > rank[y] )
            parent[y]=x;
        else
        {
            parent[x]=y;
            if(rank[x]==rank[y])
                rank[y]++;
        }
    }

    void UNION(int x, int y)
    {
        link( find(x), find(y) );
    }
};

class graph
{
    int v,e; // v is the number of vertices and e is the number of edges
    vector< pair< int , pair<int,int> > > edges; //  {weight , {src,dest} }
public:
    graph(int vertex ) : v(vertex) , e(0) { }
    void print()
    {
        for(int i=0;i<e;i++)
            printf("( u=%d , v=%d , weight=%d)\n", edges[i].second.first , edges[i].second.second , edges[i].first );
    }
    void addEdge(int u, int v, int w)
    {
        e++;
        edges.push_back( make_pair(w,make_pair(u,v) ) );
    }
    void kruskal_mst()
    {
        int weight=0;
        disjointSets ds(v);
        vector< pair< int , pair<int,int> > > kruskal_mst_vector;
        sort(edges.begin(),edges.end(),comparision_weight);
        for(int i=0;i<e;i++)
        {
            int u= ds.find(edges[i].second.first);
            int v= ds.find(edges[i].second.second);
            if(  u != v )
            {
                kruskal_mst_vector.push_back(edges[i]);
                ds.UNION(u,v);
                weight+=edges[i].first;
            }
        }
        cout<<"\nThe weight of the MST is "<<weight;
        cout<<"\n";
        for(int i = 0; i< kruskal_mst_vector.size() ; i++)
            printf("\n( u=%d , v=%d , weight=%d )", kruskal_mst_vector[i].second.first , kruskal_mst_vector[i].second.second , kruskal_mst_vector[i].first );
    }
};

int main()
{
    graph g(9);
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
    g.kruskal_mst();
}