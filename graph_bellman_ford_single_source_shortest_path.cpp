#include <cstdio>
#include <vector>
#include <map>
#include <utility>
#include <iomanip>

using namespace std;

class graph
{
	int v;
  	vector< pair< int, pair<int,int> > > edges; // { weight , { u, v } }
public:
  	graph(int vertex) :v(vertex) { }
  	void addEdge(int u, int v, int weight)
  	{
    	edges.push_back(make_pair(weight , make_pair(u,v)));
  	}
  	void print()
  	{
  		for(int i=0;i<edges.size();i++)
  		{
  			printf("( u=%d , v=%d , weight=%d)\n" , edges[i].second.first , edges[i].second.second , edges[i].first );
  		}
  	}
  	void relax(int u, int v, int weight , int *d , int *parent)
  	{
  		if(d[v]>d[u]+weight)
  		{
  			d[v]=d[u]+weight;
  			parent[v]=u;
  		}
  	}
  	bool bellman_ford(int start=0)
  	{
  		// initialization
  		int *d=new int[v];
  		int *parent=new int[v];
  		for(int i=0;i<v;i++)
  		{
  			d[i]=INT_MAX;
  			parent[i]=-1;
  		}	
  		d[start]=0;	

  		// relaxation
  		for(int i=0;i<v-1;i++)
  			for(int i=0;i<edges.size();i++)
  				relax(edges[i].second.first , edges[i].second.second , edges[i].first , d , parent );

  		for(int i=0;i<edges.size();i++)
  			if( d[edges[i].second.second] > d[edges[i].second.first] + edges[i].first )
  				return false;

  		printf("\nThere exists a single source shortest path\n");
  		for(int i=0;i<v;i++)
  			printf("%d\t",d[i]);
  		return true;
  	}
};
int main()
{
	graph g(5);
	g.addEdge(0,1,-1);
	g.addEdge(0,2,4);
	g.addEdge(1,2,3);
	g.addEdge(1,3,2);
	g.addEdge(1,4,2);
	g.addEdge(3,2,5);
	g.addEdge(3,1,1);
	g.addEdge(4,3,-3);
	g.print();
	g.bellman_ford();
	return 0;
}