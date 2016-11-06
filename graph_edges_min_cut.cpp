#include <cstdio>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>

#define V 6

using namespace std;

void print_graph(int graph[V][V])
{
    printf("\n");
    for(int i=0;i<V;i++,printf("\n"))
        for(int j=0;j<V;j++)
            cout<<setw(5)<<graph[i][j];
}

void get_path(int parent[V], int i, int j , vector<int> &v)
{
    if(i==j)
        v.push_back(i);
    else if(parent[j]==-1)
        printf("There is no path\n");
    else
    {
        get_path(parent,i,parent[j],v);
        v.push_back(j);
    }
}

int get_residual_capacity(vector<int> v,int f[V][V] )
{
    int t=INT_MAX;
    for(int i=0;i<v.size()-1;i++)
        t=min( t , f[ v[i] ][ v[i+1] ] );
    return t;
}

bool get_auguenting_path(int G_f[V][V] , int start , int end , int parent[V] ) // here the graph we get is the residual graph
{
    queue<int> q;
    bool visited[V]={0};

    q.push(start);

    for(int i=0;i<V;i++)
        parent[i]=-1;

    while(!q.empty())
    {
        int temp=q.front();
        visited[temp]=true;
        q.pop();
        
        for(int i=0;i<V;i++)
            if(G_f[temp][i]!=0 && visited[i]==false)
            {
                parent[i]=temp;
                q.push(i);
                if(i==end)
                    return true;
            }
    }
    return false;
}

void find_print_paths_reachable(int start, int graph[V][V] , int capacity[V][V] )
{
    queue<int> q;
    q.push(start);
    vector<bool> visited(V,false);
    
    while( !q.empty() )
    {
        int vertex = q.front();
        q.pop();
        if(visited[vertex]==false)
        {
            visited[vertex]=true;
            for(int i=0;i<V;i++)
            if(graph[vertex][i]!=0 && visited[i]==false)
                q.push(i);
        }
    }

    printf("\n\nThe minimum cut has the corresponding edges \n");

    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            if(i!=j && visited[i]==true && visited[j]==false && capacity[i][j]!=0 )
                printf("\n%d -> %d",i,j);
}

int ford_fulkerson( int capacity[V][V] , int start , int end )
{
    int f[V][V]={0};
    int E_f[V][V];
    int parent[V];
    
    int cf;
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            E_f[i][j]=capacity[i][j];
    
    while(get_auguenting_path(E_f,start,end,parent))
    {
        vector<int> v;
        get_path(parent,start,end,v);
        cf=get_residual_capacity(v,E_f);

        cout<<"The increase in flow in this iteration is : "<<cf<<endl;

        for(int i=0;i<v.size()-1;i++)
        {
            int a=v[i];
            int b=v[i+1];

            if(capacity[a][b]!=0)
                f[a][b]+=cf;
            else
                f[a][b]-=cf;

            // for E_f
            E_f[a][b]-=cf;
            E_f[b][a]+=cf;
        }
    }

    find_print_paths_reachable(start,E_f,capacity);

    int temp=start;
    for(int i=0;i<V;i++)
        temp += f[start][i];

    return temp;
}

int main()
{
    int capacity[V][V]={{0, 16, 13, 0, 0, 0},
                        {0, 0, 0, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };
    //get_auguenting_path(graph,0,5,parent);
    printf("\nThe MAxIMUM flow is %d\n",ford_fulkerson(capacity,0,5) );
    return 0;
}