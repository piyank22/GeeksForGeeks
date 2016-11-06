#include <iostream>
#include <cstdio>

using namespace std;

bool ans(int arr[], int t, int x)
{
    int hash_map[1001]={0};
    for(int i=0;i<t;i++)
    {
        hash_map[arr[i]]++;
        if(x-arr[i] > 0 && hash_map[x-arr[i]] > 0)
            return true;
    }
    return false;
}

int main() 
{
    int n;
    cin>>n;
    while(n--)
    {
        int arr[200]={0};
        int t,x;
        cin>>t>>x;
        for(int i=0;i<t;i++)
            cin>>arr[i];
        cout<<(ans(arr,t,x)?"Yes\n":"No\n");
    }
    return 0;
}