#include <iostream>
#include <cmath>
#include <bitset>
#include <cstdlib>

const int n=5;

using namespace std;

void printboard(int board[n][n])
{
	int static c=1;
	cout<<"\nThe "<< c++<<" board is: \n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<"\t"<<board[i][j];
		cout<<endl;
	}
}

void addqueen( int board[n][n] , int queenNo , int pos )
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(board[i][j]==0)
				if( i==pos || j==queenNo || (i+j == queenNo+pos) || (i-j == pos - queenNo) )
					board[i][j]=queenNo+1;
}

void delqueen( int board[n][n], int queenNo)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(board[i][j]==queenNo+1)
				board[i][j]=0;
}

void delqueen_bin(int board[n][n] , int queenNo)
{
	for(int i=0;i<n;i++)
		board[i][queenNo]=0;
}

int main()
{
	int board[n][n]={0};
	int queenpos[n]={-1,-1,-1,-1,-1};//,-1,-1,-1,-1,-1,-1,-1,-1};
	int board_bin[n][n]={0};
	int queenNo=0;
	int pos;
	int total=0;

	while(queenNo<n && queenNo>=0)
	{
		for(pos= queenpos[queenNo]+1 ;pos<n;pos++)
		{
			if(board[pos][queenNo]==0)
			{
				addqueen(board,queenNo,pos);
				board_bin[pos][queenNo]=1;
				queenpos[queenNo]=pos;
				break;
			}
		}

		if(queenNo==n-1 && pos<n)
		{
			printboard(board_bin);
			total++;
			delqueen(board,queenNo);	
			delqueen_bin(board_bin,queenNo);
			pos=n;
		}

		if(pos==n)
		{
			queenpos[queenNo]=-1;
			queenNo--;
			delqueen(board,queenNo);	
			delqueen_bin(board_bin,queenNo);
		}
		else
			queenNo++;
	}
	cout<<"Solutions are: "<<total;
	return 0;
}


/*

backtracking as in geeks for geeks and deitel c++

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
//const int n=8;
int chess[20];
static int c=0;
void print(int n)
{
    cout<<"\n soln no :"<<++c<<endl;
    for(int i=0;i<n;i++)
    {
        for (int j = 0; j < n; j++)
    		if(chess[i]==j)
                cout<<setw(2)<<"Q";
    		else
                cout<<setw(2)<<"-";
    		cout<<endl;
    }
    return;
}
bool issafe(int queenNumber , int rowPos)
{
    for(int i=0;i<queenNumber;i++)
    {
        int otherPos=chess[i];
        if( otherPos==rowPos || otherPos+i == rowPos+queenNumber || otherPos-i == rowPos-queenNumber )
            return false;
    }
    return true;
}
void solve(int k, int n)
{
    if(k==n)
    {
        print(n);
        return;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(issafe(k,i))
            {
                chess[k]=i;
                solve(k+1,n);
            }
        }
    }
    return;
}
int main()
{
    int n;
    cin>>n;
    solve(0,n);
    cout<<c;
    return 0;
}

*/