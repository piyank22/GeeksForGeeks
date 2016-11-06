#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int parent(int i)
{
    return floor((i-1)/2);
}
int left(int i)
{
    return (2*i+1);
}
int right(int i)
{
    return (2*i+2);
}
void max_heapify(int arr[],int heapsize,int i)
{

    int l=left(i);
    int r=right(i);
    int largest=i;
    if( l<heapsize && arr[i]<arr[l] )
        largest=l;
    if( r<heapsize && arr[largest]<arr[r] )
        largest=r;
    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        max_heapify(arr,heapsize,largest);
    }
}
void build_max_heap(int a[],int n)
{   
    for(int i=parent(n);i>=0;i--)
        max_heapify(a,n,i);
}
void print(int arr[], int length)
{
    printf("\n");
    for(int i=0;i<length;i++)
    {
        printf("%d\t",arr[i]);
    }
    cout<<"\n";
}
void heap_sort(int arr[],int heapsize)
{
    for(int i=heapsize-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        heapsize--;
        max_heapify(arr,heapsize,0);
    }
}

int heap_maximum(int arr[], int heapsize)
{
    if(heapsize==0)
        return INT_MIN;
    else
        return arr[0];
}

int heap_extract_max(int arr[], int &heapsize)
{
    if(heapsize<1)
    {
        cout<<"\nHeap Underflow\n";
        return INT_MIN;
    }
    swap(arr[0],arr[--heapsize]);
    max_heapify(arr,heapsize,0);
    return arr[heapsize];
}

void heap_increase_key(int arr[] , int heapsize , int i , int key)
{
    if(arr[i]>key)
    {
        cout<<"new key is smaller\n";
        return;
    }
    arr[i]=key;
    while(i>0 && arr[parent(i)] < arr[i] )
    {
        swap(arr[parent(i)] , arr[i] );
        i=parent(i);
    }
}

void max_heap_insert(int arr[], int &heapsize ,int key)
{
    arr[heapsize++]=INT_MIN;
    heap_increase_key(arr,heapsize,heapsize-1,key);
}

void heap_delete(int arr[], int &heapsize, int i)
{
    heap_increase_key(arr,heapsize,i,INT_MAX);
    heap_extract_max(arr,heapsize);
}

int main()
{
    int const length=40;
    int *a=new int[length];
    int aa[10]={4,1,3,2,16,9,10,14,8,7};

    int heapsize=sizeof(aa)/sizeof(int);

    for(int i=0;i<heapsize;i++)
        a[i]=aa[i];

    build_max_heap(a,heapsize);
    print(a,heapsize);

    cout<<"\n"<<heap_extract_max(a,heapsize);
    printf("\n");
    print(a,heapsize);
    heap_increase_key(a,heapsize,3,100);
    printf("\n");
    print(a,heapsize);
    max_heap_insert(a,heapsize,21);
    printf("\n");
    print(a,heapsize);
    heap_delete(a,heapsize,3);
    printf("\n");
    print(a,heapsize);

    heap_sort(a,heapsize);
    print(a,heapsize);
    return 0;
}