#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <stack>
#include <cstdio>

using namespace std;
 
int ceil(int arr[], int n ,int input , int i=0)
{
    if(i>n)
        return INT_MIN;
    int mid=i+n;
    mid=mid/2;
    if(arr[mid]==input)
        return arr[mid];
    else if(arr[mid] < input)
        return ceil(arr,n,input,mid+1);
    else
    {
        int temp=ceil(arr,mid-1,input,i);
        return (temp>=input)?temp:arr[mid];
    }
}

int floor(int arr[], int n ,int input , int i=0)
{
    if(i>n)
        return INT_MAX;
    int mid=i+n;
    mid=mid/2;
    if(arr[mid]==input)
        return arr[mid];
    else if(arr[mid] > input)
        return floor(arr,mid-1,input,i);
    else
    {
        int temp=floor(arr,n,input,mid+1);
        return (temp<=input)?temp:arr[mid];
    }
}

int main()
{
    int arr[]={1,2,4,5,6};
    int n=sizeof(arr)/sizeof(int);
    //for( int i=0 ; i<n ; i++ )
        printf("%d  %d\n",3,ceil(arr,n,3));
    return 0;
}