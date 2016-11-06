#include <cstdio>
#include <vector>
#include <map>
#include <list>
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
    pair<int,int> extract_min()
    {
        pos[ vertex_key[0].first ] = heap_size-1;
        pos[ vertex_key[heap_size-1].first ] = 0;
        
        swap( vertex_key[0] , vertex_key[heap_size-1] );
        heap_size--;
        heapify(0);
        
        pair<int, int> temp = vertex_key.back();
        
        vertex_key.pop_back();
        return temp; // returns the vertex
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
    int *d;
public:

    graph(int vertex ) : v(vertex) 
    {
        adj= new list< pair<int , int> >[v+1]; // for v0 the one we used to calculate the value to be assigned to the vertices
        parent=new int[v];
    }

    void print(int size=-1)
    {
        if(size==-1)
            size=v;
        list< pair<int,int> >::iterator it;
        for(int i=0;i<size;i++)
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
    }
    int* dijkstra(int start=0)
    {
        int *t= new int[v];
        for(int i=0;i<v;i++)
        {
            parent[i]=-1;
            t[i]=INT_MAX;
        }
        minheap mh(v);

        mh.decrease_key(start,0);
        t[start]=0;

        //printf("vertex key    path");

        while(mh.getHeapSize()>0)
        {
            pair<int,int> temp=mh.extract_min();
            int u=temp.first;
            t[u]=temp.second;
            //printf("\n%2d  -  %2d  -",u,mh.vertex_key[mh.pos[u]].second);
            //print_list(start,u);
            for(list< pair<int,int> >::iterator it=adj[u].begin() ; it != adj[u].end() ; it++ )
            {
                int v=it->first;
                int weight=it->second;
                if ( mh.decrease_key( v , weight + mh.getkey(u) ) )
                {
                    parent[v]=u;
                }
            }

        }
        return t;
        //printf("\n");
    }
    int special_sum(int  a, int b)
    {
        if(a==INT_MAX || b==INT_MAX)
            return INT_MAX;
        return a+b;
    }
    bool relax(int u, int v, int weight , int *parent)
    {
        if(d[v]> special_sum(d[u],weight) )
        {
            d[v]=d[u]+weight;
            parent[v]=u;
            return true;
        }
        return false;
    }
    bool bellman_ford(int start=0)
    {
        // initialization
        d=new int[v+1];
        int *parent=new int[v+1];
        for(int i=0;i<v+1;i++)
        {
            d[i]=INT_MAX;
            parent[i]=-1;
        }   
        d[start]=0; 

        list< pair<int,int> >::iterator it;
        for(int l=0;l<v;l++)
            for(int i=0;i<(v+1);i++)
            {
                for(it=adj[i].begin() ; it!=adj[i].end() ; it++)
                    relax(i, it->first , it->second , parent);
            }
        for(int i=0;i<v+1;i++)
        { 
            for(it=adj[i].begin() ; it!=adj[i].end() ; it++)
                if(relax(i, it->first , it->second , parent))
                {
                    return false;
                }
        }
        // printf("\nThere exists a single source shortest path\n");
        // for(int i=0;i<v+1;i++)
        //     printf("%d\t",d[i]);
        return true;
    }
    void johnsons()
    {
        // add edge
        for(int i=0;i<v;i++)
            addEdge(v,i,0);
        if( bellman_ford(v) )
        {
            list< pair<int,int> >::iterator it;
            for(int i=0;i<v;i++)
                for(it=adj[i].begin() ; it!=adj[i].end() ; it++)
                    it->second = it->second + d[i] - d[it->first] ;

        }
        else
            printf("\nNOT POSSIBLE BITCHES\n");
        int **ans=new int*[v];
        for(int i=0;i<v;i++)
        {
            ans[i]=dijkstra(i);
        }
        for(int i=0;i<v;i++)
            for(int j=0;j<v;j++)
                if(i!=j && ans[i][j]!=INT_MAX)
                {
                    ans[i][j] = ans[i][j] + d[j] - d[i];
                }

        printf("\n\n");
        for(int i=0;i<v;i++,printf("\n"))
            for(int j=0;j<v;j++)
                if(ans[i][j]==INT_MAX)
                    printf("    INF\n");
                else
                    printf("%7d",ans[i][j]);
    }  
};

int main()
{
    graph g(5);
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 8);
    g.addEdge(0, 4, -4 );
    g.addEdge(1, 3, 1);
    g.addEdge(1, 4, 7);
    g.addEdge(2, 1, 4);
    g.addEdge(3, 0, 2);
    g.addEdge(3, 2, -5);
    g.addEdge(4, 3, 6);
    g.johnsons();
    return 0;
}