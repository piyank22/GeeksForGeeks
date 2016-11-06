#include <iostream>
#include <algorithm>

using namespace std;

class minheap
{
public:
    int *arr;//k length array
    int size;
    minheap( int k )
    {
        size=k;
        arr=new int[size];
    }
    int parent(int i){ return (i-1)/2; }
    int left(int i){ return 2*i+1; }
    int right(int i){ return 2*i+2; }
    void heapify(int i)
    {
        int l=left(i);
        int r=right(i);
        int smallest=i;
        if( l<size && arr[smallest] > arr[l] )
            smallest=l;
        if( r<size && arr[smallest] > arr[r] )
            smallest=r;
        if(smallest != i)
        {
            swap(arr[smallest],arr[i]);
            heapify(smallest);
        }
    }
    int buildheap()
    {
        for(int i=parent(size-1) ; i>=0 ; i-- )
            heapify(i);
    }
    void print()
    {
        printf("\n");
        for(int i=0;i<size;i++)
            printf("%d\t",arr[i]);
        printf("\n");
    }
    int extract_min()
    {
        swap(arr[0],arr[--size]);
        heapify(0);
        int temp = arr[size];
        arr[size] = INT_MAX;
        return temp;
    }
    int insert(int key)
    {
        arr[size++] = INT_MAX;
        decrease_key(size-1,key);
    }
    void decrease_key(int i, int key)
    {
        if(arr[i] < key)
            return;
        arr[i]=key;
        while(i>0 && arr[parent(i)] > arr[i])
        {
            swap( arr[parent(i)] , arr[i] );
            i = parent(i);
        }
    }
};

int main()
{
    int k = 3, n =  4;
    int arr[k][n]= { {1, 3, 5, 7},
                    {2, 4, 6, 8},
                    {0, 9, 10, 11} } ;
    minheap h(k);
    for(int i=0;i<k;i++)
        h.arr[i]=arr[i][0];
    h.buildheap();

    // assuming diff keys
    int index[k]={0};
    while( h.size > 0 )
    {
        int temp = h.extract_min();
        printf("%d , ",temp );
        for(int i=0;i<k;i++)
            if(index[i]<n && arr[i][index[i]]==temp )
            {
                index[i]++;
                if(index[i]<n)
                    h.insert( arr[i][index[i]]);
                break;
            }
    }


    // while(1)
    // {
    //     if(h.arr[0]==INT_MAX)
    //         printf("finished\n");
    //     else
    //         printf("%d\t", h.arr[0] );
    //     int m;
    //     for(m=0;m<k;m++)
    //         if( index[m]<n && h.arr[0] == arr[m][index[m]] )
    //         {
    //             ++index[m];
    //             h.arr[0] = ( index[m]!=n ) ? arr[m][ index[m] ] : INT_MAX ;
    //             h.heapify(0);
    //             break;
    //         }
    //     if(m==k)
    //         break;
    // }
}