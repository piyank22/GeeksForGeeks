#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

int c[100][100];
string op[100][100];
int kill_switch;

void print_Sequence(int i, int j)
{
    int _i=i,_j=j;
    if(i==0 && j==0)
        return;
    else if(op[i][j] == "copy" || op[i][j] == "replace" )
        i-- , j-- ;
    else if(op[i][j] == "twiddle" )
        i=i-2 , j=j-2 ;
    else if(op[i][j] == "delete" )
        i--;
    else if(op[i][j] == "insert" )
        j--;
    // else
    //     i=kill_switch ;
    print_Sequence(i,j);
    cout<<"\n"<<op[_i][_j];
    printf("\t%d\t%d",_i,_j);
}

void edit_distance(string x , string y)
{
    int n=x.length();
    int m=y.length();
    n--;
    m--;
    c[0][0]=0;
    for(int i=1;i<=n;i++)
        c[i][0] = i*2 , op[i][0] = "delete"; // i * cost_of_delete 
    for(int j=1;j<=m;j++)
        c[0][j] = j*2 , op[0][j] = "insert"; // j * cost_pf_insert

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            c[i][j]=INT_MAX;
            if( x[i] == y[j] )
            {
                c[i][j] = c[i-1][j-1] - 1 ;
                op[i][j] = "copy" ; // cost_of_copy
            }

            if( x[i]!=y[j] && c[i-1][j-1] + 1 < c[i][j] )
            {
                c[i][j] = c[i-1][j-1] + 1 ;
                op[i][j] = "replace" ; 
            }

            if( c[i-1][j] + 2 < c[i][j] )
            {
                c[i][j] = c[i-1][j] + 2 ;
                op[i][j] = "delete" ;
            }
            // if( i>=2 && j>=2 && x[i]==y[i-1] && y[i]==x[i-1] && c[i][j] > c[i-2][j-2] + 0 ) // cost_for_twiddle 
            //     c[i][j] = c[i-2][j-2] + 0 , op[i][j] = "twiddle" ;
            
            if( c[i][j] > c[i][j-1] + 2) // cost_of_insert
            {
                c[i][j] = c[i][j-1] + 2 ;
                op[i][j] = "insert" ;
            }
        }

    // c[n][m]=INT_MAX;
    // for(int i=0;i<n;i++)
    //     if( c[i][m] + 3 <= c[n][m] ) // cost_of_kill
    //     {
    //         c[n][m] = c[i][m] + 3 ;
    //         op[n][m] = "kill" ;
    //         kill_switch=i ;
    //     }        

    for(int i=0;i<=n;i++,printf("\n"))
        for(int j=0;j<=m;j++)
            cout<<setw(7)<<c[i][j];
    printf("\n\n\n");
    for(int i=0;i<=n;i++,printf("\n"))
        for(int j=0;j<=m;j++)
            cout<<setw(9)<<op[i][j];

    cout<<"the edit_min cost is: "<<-c[n][m];
    print_Sequence(n,m);
}

int main()
{
    string x = "-GATCGGCAT";
    string y = "-CAATGTGAATC";
    edit_distance(x,y);
    return 0;
}
