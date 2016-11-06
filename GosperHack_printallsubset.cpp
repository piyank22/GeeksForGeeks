#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

void printCoefOfSetBits ( char set[] , int c )
{
	cout<<"Element is: { ";
	int pos = 0;
	while ( c )
	{
		if ( ( c & 1) == 1 )
			cout<<set[ pos ]<<" ,";
		c=c>>1;
		pos++;
	}
	cout<<" }\n";
	return;
}

void printPowerSet ( char set [], int n)
{
	int c = pow ( 2, n);
	for ( int i =0; i < c ; i++ )
		printCoefOfSetBits ( set , i  );
	return;
}

void printPowerSetGOSPERhack ( char set [], int n)
{
	cout<<"Element is: { }\n";
	int m=pow(2,n);
	for(int i=1 ; i<m ; i = (i<<1) + 1 )
	{
		int x=i;
		int y,c;
		while(x<m)
		{
			printCoefOfSetBits (set,x);
			y=x&-x;
			c=x+y;
			x=((x^c)>>2)/y | c;
		}
	}
	return;
}

void printPowerSetGOSPERhack_highbit( char set [], int n)
{
	cout<<"Element is: { }\n";
	int m=pow(2,n);

	int x=1;
	int y,c;
	int highbit=1<<n;
	while(x<m)
	{
		printCoefOfSetBits (set,x);
		y=x&-x;
		c=x+y;
		x=((x^c)>>2)/y | c;
		if( x & highbit )
			x = ( ( x & ( highbit -1 ) ) << 2 ) | 3;	
	}

	return;
}

void printsubset(char set[], int n, int k)
{
	int a= (1<<k)-1;
	int highbit = 1<<n;
	while ( (highbit & a) == 0)
	{
		printCoefOfSetBits(set,a);
		int y= a & -a;
		int c= y + a;
		a = ( ( (a^c)>>2 ) / y ) | c;
	}
}

int main()
{
	char set[] = { 'a', 'b', 'c' ,'d','e'};
	printPowerSetGOSPERhack ( set , 5 ); 
	cout<<endl;
	printPowerSet (set,5) ;
	cout<<endl;
	printPowerSetGOSPERhack_highbit(set, 5);
	cout<<endl;
	printsubset(set,5,3);
	return 0;
}

/*

http://read.seas.harvard.edu/cs207/2012/?p=64

*/