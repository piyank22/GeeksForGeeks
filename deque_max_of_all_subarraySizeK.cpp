#include <iostream>
#include <deque>
 
using namespace std;

void printKMax(int arr[], int n, int k)
{
    if(k>n)
        return;
    deque<int> dq;
    dq.push_back(0);
    for(int i=1;i<k;i++)
    {
        while( ( !dq.empty() ) && arr[i] >= arr[dq.back()] )
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout<<arr[dq.front()]<<" ";
    for(int i=k;i<n;i++)
    {
        while( (!dq.empty()) && dq.front() <= i-k )
            dq.pop_front();

        while( (!dq.empty()) && arr[i]>=arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        cout<<arr[dq.front()]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[100];
    int n,N;
    int k;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        N=n;
        while(n)
        {
            cin>>arr[N-n];
            n--;
        }
        printKMax(arr, N, k);   
    }
    return 0;
}