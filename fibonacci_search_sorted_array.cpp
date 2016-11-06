#include <iostream>
#include <algorithm>

using namespace std;

int fibSearch(int a[], int n, int x)
{
    int offset=-1;
    int f2=0 , f1=1 , f=f1+f2;

    while(f<n)
    {
        f2=f1;
        f1=f;
        f=f1+f2;
    }

    while(f > 1)
    {
        int i=min(offset+f2 , n-1);
        if(a[i] == x)
            return i;
        else if(a[i] < x)
        {
            offset=1;
            //offset=offset+f2; // this also works so chill
            f=f1;
            f1=f2;
            f2=f-f1;
        }
        else
        {
            f=f2;
            f1=f1-f2;
            f2=f-f1;
        }
    }
    // jab f 1 ho toh pata nahi hai ki kausa point hai it can be such that f1 is 0 and f2 is not defined // we must check if f1 is 1 or not
    if(f1 == 1 && a[offset+1]==x)
        return offset+1;
    return -1;
}

int main()
{
    int arr[]={1,12,14,16,19,23,33,45,56,67,78,98,123,1122,1123};
    int n=sizeof(arr)/sizeof(int);
    for(int i=0;i<n;i++)
        cout<<fibSearch(arr,n,arr[i])<<"\n";

    return 0;
}