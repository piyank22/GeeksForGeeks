#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

void construct_optimal_bst( int root[100][100] , int i , int  j , int prev , bool left=true)
{
    if(i>j+1)
        return;
    else if(i==j+1)
    {
        if(left)
            printf("d_%d is the left child of k_%d\n",j,prev);
        else if(!left) 
            printf("d_%d is the right child of k_%d\n",j,prev);
    }
    else
    {
        int r = root[i][j];
        if(prev==-1)
            printf("k_%d is the root\n",r );
        else if(left)
            printf("k_%d is the left child of k_%d\n",r,prev );
        else
            printf("k_%d is the right child of k_%d\n",r,prev );
        construct_optimal_bst(root,i,r-1,r,true);
        construct_optimal_bst(root,r+1,j,r,false);
    }
}

void get_optimal_binary_search_tree(double p[],double q[],int n, double e[100][100] , double w[100][100] , int root[100][100] )
{
    for(int i=n+1;i>=1;i--)
        for(int j=i-1;j<=n;j++)
            if(i == j+1 ) // e[i][i-1] that means only the dummy variable d[i-1] which has the probability of q[i-1]
            {
                e[i][j]=q[i-1];
                w[i][j]=q[i-1];
            }
            else
            {
                e[i][j]=INT_MAX;
                for(int k=i;k<=j;k++)
                    if(e[i][j] > e[i][k-1] + e[k+1][j] + w[i][k-1] + w[k+1][j] + p[k] )
                    {
                        e[i][j] = e[i][k-1] + e[k+1][j] + w[i][k-1] + w[k+1][j] + p[k] ;
                        w[i][j] = w[i][k-1] + w[k+1][j] + p[k];
                        root[i][j]=k;
                    }
            }

    for(int i=1;i<=n+1;i++ , printf("\n") )
        for(int j=0;j<=n;j++)
        {
            cout<<setw(7)<<e[i][j];
        }

    cout<<"\n\n\n";
    for(int i=1;i<=n;i++ , printf("\n") )
        for(int j=1;j<=n;j++)
            cout<<setw(7)<<root[i][j];

    cout<<"\n\n\n";
    construct_optimal_bst( root,1,n ,-1);
}

int main()
{
    double p[]={ 0 , .15 , .1 , .05 , .10 , .20 };
    double q[]={.05,.1,.05,.05,.05,.1};
    int n=sizeof(p)/sizeof(double);
    n--; // we need the positions

    double e[100][100]={0};
    double w[100][100]={0};
    int root[100][100];

    get_optimal_binary_search_tree(p,q,n,e,w,root);

    return 0;
}
