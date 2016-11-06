#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

void print_matrix(int graph[][100] , int m , int n, int start=1, int end=1)
{
    printf("\n");
    for(int i=start;i<m+end;i++ , printf("\n") )
        for (int j = start; j < n+end; ++j)
        {
            printf("%9d",graph[i][j]);
        }
    return;
}

void get_lcs( char x[] , int m , char y[] , int n , int c[100][100] , string b[100][100] )
{
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(x[i]==y[j])
            {
                c[i+1][j+1]=c[i][j]+1;
                b[i][j]="dia";
            }
            else if(c[i+1][j] <= c[i][j+1])
            {
                c[i+1][j+1]=c[i][j+1];
                b[i][j]="up";
            }
            else
            {
                c[i+1][j+1]=c[i+1][j];
                b[i][j]="side";
            }

    print_matrix(c,m,n);
    printf("\n\n\n\n");
    for(int i=0;i<m;i++ , printf("\n") )
        for (int j = 0; j < n; ++j)
            cout<<setw(9)<<b[i][j];

    return;
}

void get_data(char x[] , string b[100][100] , int m , int n )
{
    if( m < 0 || n < 0 )
        return;
    else if( b[m][n] == "up" )
        get_data(x,b,m-1,n) ;
    else if( b[m][n] == "side" )
        get_data(x,b,m,n-1) ;
    else if( b[m][n] == "dia" )
    {
        get_data(x,b,m-1,n-1);
        cout<<"\t"<<x[m];
    }
}

int main()
{
    char x[]={'A','B','C','B','D','A','B'};
    char y[]={'B','D','C','A','B','A'};
    int m=sizeof(x)/sizeof(char);
    int n=sizeof(y)/sizeof(char);
    int c[100][100]={0};
    string b[100][100];
    get_lcs(x,m,y,n,c,b);

    printf("\n\n\n");
    get_data(x,b,m-1,n-1);
    printf("\n");

    return 0;
}
