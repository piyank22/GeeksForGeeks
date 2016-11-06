#include <iostream>
#include <utility>
#include <list>
#include <vector>
#include <iomanip>
#include <algorithm>

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
        
        cout<<"\nthe extracted value has ( vertex, key_value ) "<<temp.first<<" , "<<temp.second;
        
        vertex_key.pop_back();
        return temp.first; // returns the vertex
    }
    void decrease_key(int i,int key)
    {
        i=pos[i];
        if(vertex_key[i].second<=key)
            return;
        vertex_key[i].second=key;
        while(i && vertex_key[ parent(i) ].second > vertex_key[i].second )
        {
            pos[ vertex_key[parent(i)].first ] = i;
            pos[ vertex_key[i].first ] = parent(i);
            swap( vertex_key[ parent(i) ] , vertex_key[i] );
            i=parent(i);
        }
    }
    void print()
    {
        printf("\n(vertex, key)\n");
        for(int i=0;i<heap_size;i++)
            printf("( %d , %d )\t", vertex_key[i].first , vertex_key[i].second );
        printf("\npos[i]\n");
        for(int i=0;i<n;i++)
            printf( "( %d )\t", pos[i]);
    }
    int getHeapSize()
    {
        return heap_size;
    }
};

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

    void prims_mst()
    {
        minheap mh(v);

        mh.decrease_key(0,0); // set s=0

        vector < pair<int,bool> > vertices_processed;
        for(int i=0;i<v;i++)
            vertices_processed.push_back(make_pair(i,false));

        list< pair<int,int> >::iterator it;

        while(mh.getHeapSize() > 0)
        {
            int t=mh.extract_min();
            vertices_processed[t].second=true;
            for( it = adj[t].begin() ; it != adj[t].end() ; it++ ) // u = t , v = it->first , weight = it->second
                if( vertices_processed[ it->first ].second==false && mh.vertex_key[ mh.pos[it->first] ].second > it->second )
                    mh.decrease_key( it->first , it->second );
        }
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
    g.prims_mst();
    return 0;
}