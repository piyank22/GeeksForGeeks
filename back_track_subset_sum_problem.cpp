#include <iostream>
#include <vector>
#include <map>

#define ARRAYSIZE(a) (sizeof(a))/(sizeof(a[0]))

using namespace std;

bool check_sum_util(int weights[] , int start , int n , int target)
{
    if(target==0)
        return true;
    if(target < 0)
        return false;
    for(int i=start;i<n;i++)
        if(check_sum_util( weights, i+1 , n , target-weights[i] ) )
            return true;
    return false;

}

bool check_sum(int weights[] , int n , int target )
{
    for(int i=0;i<n;i++)
        if(check_sum_util(weights,i,n,target))
            return true;
    return false;
} 

int main()
{
    int weights[] = {15, 22, 14, 26, 32, 9, 16, 8};
    int target = 53;
 
    int size = ARRAYSIZE(weights);
    if( check_sum(weights,size,target) )
        cout<<"YES\n";
    else
        cout<<"NO\n";
}