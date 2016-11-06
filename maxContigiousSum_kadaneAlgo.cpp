#include <iostream>
#include <vector>

using namespace std;

// kadane algorithm
int contigiousSubSum(vector<int> v)
{
    /*
    // this method doesnt take into account if all numbers are negative so either do that seperately or see next method direct efficient solution
    int max_so_far=0;
    int max_till_here=0;

    for(int i=0;i<v.size();i++)
    {
        max_till_here += v[i];
        if(max_till_here<0)
            max_till_here=0;
        else if(max_so_far < max_till_here)
            max_so_far=max_till_here;
    }

    return max_so_far;
    */

    int max_so_far = v[0];
    int curr_max = v[0];
 
    for (int i = 1; i < v.size(); i++)
    {
        curr_max = max(v[i], curr_max+v[i]);
        max_so_far = max(max_so_far, curr_max);
    }

    return max_so_far;
}

// this thing that i tried adds up all the positive elements lol
// int contigiousSubSum(vector<int> a)
// {
//     int m = a[0];
//     for (int i = 1; i < a.size(); i++)
//         m = max( m , max( a[i], m+a[i] ) );
//     return m;
// }

int main() 
{
    int n;
    cin>>n;
    int c=0;
    int t;
    while(c<n)
    {
        c++;
        cin>>t;
        vector<int> v(t);
        for(int i=0;i<t;i++)
            cin>>v.at(i);
        cout<<contigiousSubSum(v);
    }
    return 0;
}

/*

-2 -3 4 -1 -2  1  5 -3
    ^                       at this point current max is -5 and the max so far is -2
      ^                     at this point current max is 4 and max s0 far is 4
         ^                  .. 3 .. 4
            ^               .. 1 .. 4
               ^            .. 2 .. 4
                  ^         .. 7 .. 7
                     ^      .. 4 .. 7

and we display the max so far works on all general cases if all negative all positive what not


_ _ _ _ _ | _

   done     left
till now we have what is the current max and what is the max so far

1 4 -2 -1  |  10
  .......             so current max is 1
  ..                  and max so far is 4

when we encounter 10 
current max is 11  as max ( 10 , 11 )   max( a[l] , current max + a[l] )
max so far becomes max ( 4 ,11)  max(current max , max so far)
*/