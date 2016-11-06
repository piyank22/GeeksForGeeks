#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <iomanip>

#define n 9

using namespace std;

void printGrid(int grid[n][n])
{
    for (int row = 0; row < n; row++)
    {
       for (int col = 0; col < n; col++)
             printf("%2d", grid[row][col]);
        printf("\n");
    }
}

bool issafe(int grid[n][n] , int i, int j, int put)
{
  for(int k=0 ; k<n ; k++ )
    if( grid[i][k] == put || grid[k][j] == put )
      return false;

  // check in grid
  int grid_i=3*(i/3);
  int grid_j=3*(j/3);
  for(int row=grid_i ; row<grid_i+3 ; row++)
    for(int col=grid_j ; col<grid_j+3 ; col++)
      if(grid[row][col]==put)
        return false;
  return true;
}

bool SolveSudoku( int grid[n][n] )
{
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
          if(grid[i][j]==0)
          {
            for(int put=1;put<=n;put++)
            {
              if(issafe(grid,i,j,put))
              {
                grid[i][j]=put;
                if(SolveSudoku(grid))
                  return true;
                grid[i][j]=0;
              }
            }
            return false; // agar koi ek bhi fill nahi hua toh load hai aage nahi bhar sakte 
          }
    return true;
}

int main()
{
    // 0 means unassigned cells
    int grid[n][n] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if (SolveSudoku(grid) == true)
          printGrid(grid);
    else
         printf("No solution exists");
 
    return 0;
}