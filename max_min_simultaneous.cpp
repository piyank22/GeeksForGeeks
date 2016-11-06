#include <iostream>
#include <algorithm>

using namespace std;

int main()
{   
    int arr[]={1,10,13,4,9,100,200,12,8,7,19,15};
    int n=sizeof(arr)/sizeof(int);

    int max=arr[0];
    int min=arr[0];

    int tmi,tma;

    bool extra=false;
    if(n%2==0)
    {
        extra=true;
        n--;
    }
    for(int i=1;i<n;i+=2)
    {
        if(arr[i] > arr[i+1])
            tma=arr[i] ,  tmi= arr[i+1];
        else
            tma=arr[i+1] , tmi = arr[i+1];
        if(tma > max )
            max=tma;
        if(tmi < min )
            min=tmi;
    }
    // last comparison
    if(extra==true)
    {
        n++;
        if( max < arr[n-1] )
            max = arr[n-1];
        if( min > arr[n-1] )
            min = arr[n-1];
    }

    cout<<max<<"\t"<<min;

    return 0;
}