#include <iostream>
#include <cmath>
#include <bitset>
#include <queue>
#include <vector>
#include <map>

using namespace std;

int lookup[500][500];

void preprocess(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        lookup[i][0]=i;
    }
    for(int j=1;j<=floor(log2(n));j++)
    {
        for(int i=0; i+(1<<j) <= n  ;i++) // or i+pow(2,j)<=n
        {
            if(a[ lookup[i][j-1] ] > a[ lookup[i+int(pow(2,j-1))][j-1] ] )
                lookup[i][j] = lookup [i+int(pow(2,j-1))] [j-1];
            else
                lookup[i][j] = lookup[i][j-1];
        }
    }
}

void query(int arr[],int l, int r)
{
    int j=floor(log2(r-l+1));
    if( arr[ lookup[l][j] ] > arr[ lookup[r+1-(int)(pow(2,j))][j] ] )
        cout<<lookup[r+1-(int)(pow(2,j))][j];
    else
        cout<<lookup[l][j];
}

int main()
{
    int a[] = {0 , 1 , 2 , 3 , 4 , 3 , 2 , 1 , 2 , 1 , 0 , 1 , 2 , 3 , 2 , 1 , 0 , 1 , 0};
    int n=sizeof(a)/sizeof(2);
    preprocess(a,n);
    for(int j=0;j<=floor(log2(n));j++)
    {
        for(int i=0; i+(1<<j) <= n  ;i++) // or i+pow(2,j)<=n
        {
            cout<<"\t"<<lookup[i][j];
        }
        cout<<endl;
    }
    query(a,7,8);
    return 0;
}