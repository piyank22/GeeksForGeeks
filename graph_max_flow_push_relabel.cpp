#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define V 6
using namespace std;

int *height;
int *e_flow;

void intialize_preflow(int capacity[V][V] , int residual_capacity[V][V] , int flow[V][V] , int start )
{
	height=new int[V];
	e_flow=new int[V];

	for(int i=0;i<V;i++)
		height[i]=e_flow[i]=0;

	height[start]=V;

	for(int i=0;i<V;i++)
		if(i!=start && capacity[start][i])
		{
			flow[start][i] = capacity[start][i];
			e_flow[i] = capacity[start][i];
			e_flow[start] -= capacity[start][i];

			residual_capacity[start][i]=0;
			residual_capacity[i][start]=flow[start][i];
		}
}

int overflow(int start, int end)
{
	for(int i=0;i<V;i++)
		if(i!=start && i!=end)
			if(e_flow[i] > 0)
				return i;
	return -1;
}

bool push_flow(int u , int residual_capacity[V][V] , int flow[V][V] , int capacity[V][V] )
{
	for(int i=0;i<V;i++)
		if( residual_capacity[u][i] > 0 && height[u] == height[i]+1 )
		{
			int delta = min(e_flow[u] , residual_capacity[u][i]);
			printf("pushing to %d amount %d\n",i,delta);
			if(capacity[u][i]>0)// if this is edge
				flow[u][i] += delta;
			else
				flow[i][u] -= delta;

			e_flow[u] -= delta;
			e_flow[i] += delta;

			residual_capacity[u][i] -= delta;
			residual_capacity[i][u] += delta;

			return true;
		}

	return false;
}

void relabel(int u , int residual_capacity[V][V] )
{
	int new_h=INT_MAX;
	for(int i=0;i<V;i++)
		if( residual_capacity[u][i] > 0 )
			new_h =  min(new_h,height[i]);
	height[u] = 1+new_h;
	printf("Relabeled height of %d to %d\n",u,height[u]);
}

int push_relabel(int capacity[V][V],int start, int end)
{	
	int flow[V][V]={0};

	int residual_capacity[V][V];
	for (int i = 0; i < V; ++i)
		for (int j = 0; j < V; ++j)
			residual_capacity[i][j] = capacity[i][j];

	intialize_preflow( capacity , residual_capacity , flow , start );

	while(overflow(start,end) != -1)
	{
		int u=overflow(start,end);
		printf("Overflowing vertex is %d with amount %d\t",u,e_flow[u] );
		if(!push_flow(u , residual_capacity , flow , capacity ))
			relabel(u , residual_capacity);
	}

	return e_flow[end];
}

int main()
{
	int capacity[V][V]={{0, 16, 13, 0, 0, 0},
                        {0, 0, 0, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0} };
    // now the max flow using push_relable
    cout<<"\n\nThe max flow is : "<<push_relabel(capacity,0,5)<<"\n\n";
    return 0;
}