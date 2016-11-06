#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#define V 8

using namespace std;

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

    int temp=start;
    for(int i=0;i<V;i++)
        temp += f[start][i];

    return temp;
}

int main()
{
     int capacity[V][V] = { {0, 1, 1, 1, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 1, 0},
                        {0, 0, 0, 0, 0, 0, 1, 0},
                        {0, 0, 1, 0, 0, 0, 0, 1},
                        {0, 1, 0, 0, 0, 0, 0, 1},
                        {0, 0, 0, 0, 0, 1, 0, 1},
                        {0, 0, 0, 0, 0, 0, 0, 0}
                      };
    //get_auguenting_path(graph,0,5,parent);
    printf("\nThe MAxIMUM flow is %d\n",ford_fulkerson(capacity,0,7) );
    return 0;
}