#include <iostream>
#include <algorithm>

using namespace std;

void print(int arr[],int n)
{
    printf("\nThe array is:\n");
    for(int i=0; i<n; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

int partition(int a[] , int l , int r)
{
    int pivot=a[r];
    int i=l;
    for(int j=l;j<r;j++)
        if( a[j] <= pivot )
            swap(a[i++],a[j]);
    swap(a[i],a[r]);
    return i;
}

int randomPartition(int arr[], int l, int r)
{
    int n = r-l+1;
    int pivot = rand() % n;
    swap(arr[l + pivot], arr[r]);
    return partition(arr, l, r);
}

int get_k_quick_sort(int arr[] , int l , int r , int k)
{
    if(l>r)
        return INT_MIN;
    int part=randomPartition(arr,l,r);

    if(part==k)
        return arr[part];
    else if( part > k )
        return get_k_quick_sort(arr,l,part-1,k);
    else    
        return get_k_quick_sort(arr,part+1,r,k);
}

int main()
{
    int arr[]={3,4,2,5,1,6,7,100,11,15,23,654};
    int n = sizeof(arr)/sizeof(int);
    int k=n-3; // find 7th smallest
    cout<<get_k_quick_sort(arr,0,n-1,k-1);
    print(arr,n);
}