#include <iostream>
#include <algorithm>

using namespace std;

// m1

// class heap
// {
//     int data[100];
//     int heapsize;
// public:
//     int left(int i) { return 2*i+1 ; }
//     int right(int i) { return 2*i+2 ; }
//     int parent(int i) { return (i-1)/2 ; }
//     heap(int arr[] , int size=0): heapsize(size) 
//     {
//         for(int i=0;i<heapsize;i++)
//             data[i]=arr[i];
//     }
//     void heapify(int i)
//     {
//         int l=left(i) , r=right(i);
//         int largest=i;
//         if(l < heapsize && data[largest] < data[l] )
//             largest=l;
//         if(r < heapsize && data[largest] < data[r] )
//             largest=r;
//         if(largest != i )
//         {
//             swap(data[largest] , data[i]);
//             heapify(largest);
//         }
//     }
//     void buildheap()
//     {
//         for(int i=parent(heapsize-1) ; i>=0 ;i-- )
//             heapify(i);
//     }
//     void print()
//     {
//         printf("\nThe elements in data stored are:\n");
//         for(int i=0;i<heapsize;i++)
//             printf(" %d\t,",data[i] );
//         printf("\n");
//     }
//     int extract_max()
//     {
//         int ans=data[0];
//         swap(data[0] , data[--heapsize]);
//         heapify(0);
//     }
// };

// int main()
// {
//     int arr[]={1,23,12,9,30,2,50};
//     int size=sizeof(arr)/sizeof(int);
//     heap h(arr,size);
//     h.buildheap();
//     h.print();
//     // now extract max k times to get the desired output timecomplexity is building of heap in o(n) and extract max is o(log(n)) and finding k biggest is o(k*log(n))
//     // overall o( n + k*log(n) ) 
//     h.extract_max();
//     h.print();
//     return 0;
// }

// m2

class heap
{
public:
    int data[100];
    int heapsize;

    int left(int i) { return 2*i+1 ; }
    int right(int i) { return 2*i+2 ; }
    int parent(int i) { return (i-1)/2 ; }
    heap(int arr[] , int size=0): heapsize(size) 
    {
        for(int i=0;i<heapsize;i++)
            data[i]=arr[i];
    }
    void heapify(int i)
    {
        int l=left(i) , r=right(i);
        int smallest=i;
        if(l < heapsize && data[smallest] > data[l] )
            smallest=l;
        if(r < heapsize && data[smallest] > data[r] )
            smallest=r;
        if(smallest != i )
        {
            swap(data[smallest] , data[i]);
            heapify(smallest);
        }
    }
    void buildheap()
    {
        for(int i=parent(heapsize-1) ; i>=0 ;i-- )
            heapify(i);
    }
    void print(int n=0)
    {
        if(n==0)
            n=heapsize;
        printf("\nThe elements in data stored are:\n");
        for(int i=0;i<n;i++)
            printf(" %d\t,",data[i] );
        printf("\n");
    }
    int extract_min()
    {
        int ans=data[0];
        swap(data[0] , data[--heapsize]);
        heapify(0);
    }
};

// hear we build a heap of k elements only and call on the heapify for at max n-k so 
// o( k + (n-k)logk )
// very better than the previous method

int main()
{
    int arr[]={1,23,12,9,30,2,50};
    int size=sizeof(arr)/sizeof(int);
// find 3rd highest
    int k=4;
    heap h(arr,k);
    h.buildheap();
    h.print();
    for(int i=k;i<size;i++)
        if(h.data[0] < arr[i])
        {
            h.data[0]=arr[i];
            h.heapify(0);
        }
    cout<<"\nThe k th largest is heap.root.key: "<<h.data[0];
    return 0;
}