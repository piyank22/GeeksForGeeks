#include <iostream>
using namespace std;

bool check_dup(int arr[], int n, int k)
{
    bool hash[1001]={0};
    int i=0;
    while(i<n)
    {
        if(hash[arr[i]]==true)
            return true;
        else
            hash[arr[i]]=true;
        if(i>=k)
            hash[arr[i-k]]=false;
        i++;
    }
    return false;
}

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int k,n;
        cin>>k>>n;
        int arr[100];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<((check_dup(arr,n,k))?"True\n":"False\n");
    }
    return 0;
}