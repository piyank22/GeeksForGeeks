#include <cstdio>
#include <iostream>

using namespace std;

void print_matrix(int graph[][100] , int n)
{
    printf("\n");
    for(int i=1;i<n+1;i++ , printf("\n") )
        for (int j = 1; j < n+1; ++j)
        {
            printf("%9d",graph[i][j]);
        }
    return;
}

void matrix_chain_multiply(int p[], int m[][100], int s[][100] , int n)
{
    for(int i=n-1;i>=1;i--)
        for(int j=i+1;j<=n;j++)
        {
            m[i][j]=INT_MAX;
            for(int k=i;k<=j-1;k++)
            {
                if( m[i][j] > m[i][k] + m[k+1][j] + (p[i-1] * p[k] * p[j] ) )
                {
                    m[i][j] = m[i][k] + m[k+1][j] + (p[i-1] * p[k] * p[j]);
                    s[i][j] = k;
                }
            }
        }
}

void print_matrix_solution(int i, int f, int p[], int s[100][100], int n)
{
    if(i==f)
        printf(" A_%d ",i);
    // else if(i+1 == f )
    //     printf(" A_%d X A_%d",i,f);
    else
    {
        int k=s[i][f];
        printf(" ( ");
        print_matrix_solution(i,k,p,s,n);
        print_matrix_solution(k+1,f,p,s,n);
        printf(" ) ");
    }
}

int main()
{
    //int p[] = {30,35,15,5,10,20,25};
    int p[]={5,10,3,12,5,50,6};
    // the dimension of Matrix A_i is p_i-1 X p_i
    int n=sizeof(p)/sizeof(int);
    n--; // this is because n counts one more because the matrix has dimension as A X B which takes up an extra space overall
    int m[100][100] = {0} ;
    int s[100][100] = {0} ; // the index of matrix m and s is considered from 1..n

    matrix_chain_multiply(p,m,s,n);
    print_matrix(m,n);
    print_matrix(s,n);
    print_matrix_solution(1,n,p,s,n);
    return 0;
}
