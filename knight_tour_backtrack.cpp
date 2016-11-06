#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

void printboard(int **board, int n)
{
    cout<<"\n";
    for(int i=0;i<n;i++,cout<<"\n")
        for(int j=0;j<n;j++)
            cout<<setw(4)<<board[i][j];
}

bool isSafe(int i, int j, int n, int **board)
{
    if( i>=0 && i<n && j>=0 &&j<n && board[i][j]==0)
        return true;
    return false;
}

bool solve_util(int **board, int n , int i, int j, int number)
{
    int next_i, next_j;
    int move_number=0;
    while(move_number<8)
    {   
        next_i = i + xMove[move_number];
        next_j = j + yMove[move_number];
        if( isSafe( next_i , next_j , n , board ) )
        {
            board[next_i][next_j]=number;
            if( number == (n*n) )
                return true;

            if( solve_util(board , n , next_i , next_j , number+1 ) )
                return true;
            else
                board[next_i][next_j]=0;
        }
        move_number++;
    }
    return false;
}

void solve_knight_tour(int n)
{
    int **board = new int*[n];
    for(int i=0;i<n;i++)
    {
        board[i]=new int[n];
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            board[i][j]=0;

    board[0][0]=1;

    if(solve_util( board , n ,0 , 0 , 2))
        printboard(board,n);
    else
        cout<<"\ncannot be solved";
}

int main()
{
    int n;
    cin>>n;
    solve_knight_tour(n);
    return 0;
}