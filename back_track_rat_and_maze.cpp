#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

int xMove[2] = { 0 , 1 };
int yMove[2] = { 1 , 0 };
int **maze;
int **sol;

void printboard(int **board, int n)
{
    cout<<"\n";
    for(int i=0;i<n;i++,cout<<"\n")
        for(int j=0;j<n;j++)
            cout<<setw(4)<<board[i][j];
}

bool isSafe(int i, int j, int n)
{
    if( i>=0 && i<n && j>=0 &&j<n && maze[i][j]==1)
        return true;
    return false;
}

bool solve_util(int i, int j, int n)
{
    int next_i, next_j;
    int move_number=0;
    while(move_number<2)
    {   
        next_i = i + xMove[move_number];
        next_j = j + yMove[move_number];
        if( isSafe( next_i , next_j , n) )
        {
            sol[next_i][next_j]=1;
            if( next_i == n-1 && next_j == n-1 )
                return true;

            if( solve_util(next_i , next_j , n ) )
                return true;
            else
                sol[next_i][next_j]=0;
        }
        move_number++;
    }
    return false;
}

void solve_rat_maze(int n)
{
    sol = new int*[n];
    for(int i=0;i<n;i++)
    {
        sol[i]=new int[n];
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            sol[i][j]=0;

    sol[0][0]=1;

    if( solve_util( 0 , 0 , n) )
        printboard(sol,n);
    else
    {
        cout<<"\ncannot be solved";
    }    
}

int main()
{
    int n = 4;
    maze=new int*[n];
    for(int i=0;i<n;i++)
        maze[i]=new int[n];

    maze[0][0]=maze[1][0]=maze[1][1]=maze[1][3]=maze[2][1]=maze[3][0]=maze[3][1]=maze[3][2]=maze[3][3]=1;
    maze[0][1]=maze[0][2]=maze[0][3]=maze[1][2]=maze[2][0]=maze[2][2]=maze[2][3]=0;
    //printboard(maze,n);
    solve_rat_maze(n);
    return 0;
}