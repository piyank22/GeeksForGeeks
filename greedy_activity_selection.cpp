#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

struct activity
{
    int start, end , number;
    activity(int n, int s, int e) : start(s) , end(e) , number(n) { }
};

bool cmp(activity a1, activity a2)
{
    return (a1.end < a2.end);
}

int main()
{
    activity a[] = { {2,3,5} , {1,1,4} , {7,6,10} , {3,0,6} , {4,5,7} , {5,3,9} , {6,5,9} , {8,8,11} , {9,8,12} , {10,2,14} , {11,12,16} };
    int n=sizeof(a)/sizeof(activity);
    sort(a,a+n,cmp);
    // for(int i=0;i<n;i++)
    //     printf("(%d %d %d)\n",a[i].number , a[i].start , a[i].end );

    cout<<a[0].number<<"\t";
    int f=0;
    for(int i=1;i<n;i++)
    {
        if(a[i].start >= a[f].end )
        {
            cout<<a[i].number<<"\t";
            f=i;
        }
    }

    return 0;
}
