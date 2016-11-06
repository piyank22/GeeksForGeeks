#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

struct item
{
    int size , price;
    item(int n, int s) : size(n) , price(s) { }
};

bool cmp(item a1, item a2)  {   return ( a1.size < a2.size );   }

int main()
{
    item a[] = { {0,0} , {1,60} , {2,100} , {3,120} , {4,161} };
    int n=sizeof(a)/sizeof(item);
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++)
        printf("(%d %d )\n",a[i].size , a[i].price );

    int W=5;
    int w[n+1][W+1] = {0} ;

    int keep[n+1][W+1];

    for(int i=0;i<=W;i++)
        w[0][i] = keep[0][i] = 0;

    for(int i=1;i<n;i++)
        for(int weight =0 ; weight <= W ; weight ++)
        {
            if( a[i].size <= weight )
            {
                if(w[i-1][weight] < a[i].price + w[i-1][weight - a[i].size ])
                {
                    w[i][weight] =a[i].price + w[i-1][weight - a[i].size ];
                    keep[i][weight]=i;
                }
                else
                {
                    w[i][weight] = w[i-1][weight];
                    keep[i][weight]=keep[i-1][weight];
                }
            }
            else
            {
                w[i][weight]=w[i-1][weight];
                keep[i][weight]=keep[i-1][weight];
            }
        }

    cout<<"\n\n";
    for(int i=0;i<n;i++,printf("\n"))
        for(int j=0;j<=W;j++)
            cout<<setw(9)<<keep[i][j];

    cout<<"\n\n";
    for(int i=0;i<n;i++,printf("\n"))
        for(int j=0;j<=W;j++)
            cout<<setw(9)<<w[i][j];

    cout<<"\n\n";
    cout<<"\n\n";
    int price = w[n-1][W];
    for(int i=n-1;i>0;i--)
    {
        if(price == 0)
            break;
        for(int j=0;j<=W;j++)
        {
            if( w[i][j] == price )
            {
                cout<<"\t"<<keep[i][j];
                price = price - a[ keep[i][j] ].price ;
            }
        }
    }

    return 0;
}
