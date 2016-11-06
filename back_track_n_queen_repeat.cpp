#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

int *queenPos;

void printboard(int n)
{
    cout<<"\n";
    for(int i=0;i<n;i++,cout<<"\n")
        for(int j=0;j<n;j++)
            cout<<setw(4)<< ( queenPos[j]==i ? 'Q' : '-' );
}

bool is_safe_util( int x , int y , int z , int w , int n )
{
    if(y==w)
        return false;
    else if(x+y == z+w)
        return false;
    else if(x-y == z-w)
        return false;
    else
        return true;
}

bool isSafe(int queenNo , int pos , int n)
{
    for (int i = 0; i < queenNo; ++i)
        if ( !is_safe_util(i , queenPos[i] , queenNo , pos , n ) )
            return false;
    return true;
}

bool solve_util(int queenNo , int n)
{
    int move_number=0;
    while(move_number<n)
    {  
        if( isSafe( queenNo , move_number , n) )
        {
            queenPos[queenNo]=move_number;
            if( queenNo == n-1 )
                return true;

            if( solve_util( queenNo+1 , n ) )
                return true;
            else
                queenPos[queenNo]=-1;
        }
        move_number++;
    }
    return false;
}

void solve_n_queen(int n)
{
    queenPos=new int[n];
    for(int i=0;i<n;i++)
        queenPos[i]=-1;

    if( solve_util( 0 , n) )
        printboard(n);
    else
    {
        cout<<"\ncannot be solved";
    }    
}

int main()
{
    int n = 20;
    solve_n_queen(n);
    return 0;
}