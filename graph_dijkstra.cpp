#include <cstdio>
#include <vector>
#include <list>
#include <map>
#include <utility>
#include <iomanip>

using namespace std;

class minheap // min heap data structure for priority queue
{
public:
    vector< pair<int,int> > vertex_key; // pair containing the vertex number and the key value stored in it
    int n;
    int *pos;
    int heap_size;
    minheap(int N): n(N) , heap_size(N)
    {
        pos=new int[n];
        for(int i=0;i<n;i++)
        {
            vertex_key.push_back(make_pair(i,INT_MAX));
            pos[i]=i;
        }
    }
    int parent(int i) { return (i-1)/2; }
    int left(int i) { return (2*i+1); }
    int right(int i) { return (2*i+2); }
    void heapify(int i)
    {
        int l=left(i);
        int r=right(i);
        int smallest=i;
        if( l < heap_size && vertex_key[smallest].second > vertex_key[l].second )
            smallest=l;
        if( r < heap_size && vertex_key[smallest].second > vertex_key[r].second )
            smallest=r;
        if( smallest != i )
        {
            pos[ vertex_key[smallest].first ] = i;
            pos[ vertex_key[i].first ] = smallest;
            swap( vertex_key[smallest] , vertex_key[i] );
            heapify( smallest );
        }
    }
    void buildheap()
    {
        for(int i=parent(n-1) ; i>=0 ; i-- )
            heapify(i);
    }
    int extract_min()
    {
        pos[ vertex_key[0].first ] = heap_size-1;
        pos[ vertex_key[heap_size-1].first ] = 0;
        
        swap( vertex_key[0] , vertex_key[heap_size-1] );
        heap_size--;
        heapify(0);
        
        pair<int, int> temp = vertex_key.back();
        
        vertex_key.pop_back();
        return temp.first; // returns the vertex
    }
    bool decrease_key(int i,int key)
    {
        i=pos[i];
        if(vertex_key[i].second<=key)
            return false;
        vertex_key[i].second=key;
        while(i && vertex_key[ parent(i) ].second > vertex_key[i].second )
        {
            pos[ vertex_key[parent(i)].first ] = i;
            pos[ vertex_key[i].first ] = parent(i);
            swap( vertex_key[ parent(i) ] , vertex_key[i] );
            i=parent(i);
        }
        return true;
    }
    void print()
    {
        printf("\n(vertex, key)\n");
        for(int i=0;i<vertex_key.size();i++)
            printf("( %d , %d )\t", vertex_key[i].first , vertex_key[i].second );
        printf("\npos[i]\n");
        for(int i=0;i<n;i++)
            printf( "( %d )\t", pos[i]);
    }
    int getHeapSize()
    {
        return heap_size;
    }
    int getkey(int i)
    {
        return vertex_key[ pos[i] ].second;
    }
};

class graph
{
	int v;
    list< pair<int,int> > *adj; // destination , weigth
    int *parent;
public:

    graph(int vertex ) : v(vertex) 
    {
        adj= new list< pair<int , int> >[v];
        parent=new int[v];
        for(int i=0;i<v;i++)
            parent[i]=-1;
    }

    void print()
    {
        list< pair<int,int> >::iterator it;
        for(int i=0;i<v;i++)
        {
            for(it=adj[i].begin() ; it!=adj[i].end() ; it++)
            {
                printf("( u=%d , v=%d , weight=%d)\n", i , it->first , it->second );
            }
        }
    }
    void print_list(int s, int u)
    {
        if(s==u)
            printf("\t%d",s);
        else
        {
            print_list(s, parent[u]);
            printf("\t%d",u);
        }
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    void dijkstra(int start=0)
    {
        minheap mh(v);

        bool *in_queue = new bool[v];
        for(int i=0;i<v;i++)
            in_queue[i]=false;

        mh.decrease_key(start,0);

        printf("vertex key    path");

        while(mh.getHeapSize()>0)
        {
            int u=mh.extract_min();
            in_queue[u]=true;
            int key_u = mh.vertex_key[mh.pos[u]].second ;
            printf("\n%2d  -  %2d  -", u , key_u );
            print_list(start,u);
            for(list< pair<int,int> >::iterator it=adj[u].begin() ; it != adj[u].end() ; it++ )
            {
                int v=it->first;
                int weight=it->second;
                if (!in_queue[v] && weight < mh.getkey(v) )
                {
                    mh.decrease_key( v , weight );
                    parent[v]=u;
                }
            }

        }
    printf("\n");
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
    g.dijkstra();
    return 0;
}