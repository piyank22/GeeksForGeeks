#include <iostream>
#include <bitset>
#include <vector>
#include <iomanip>

using namespace std;

/*
Position of rightmost set bit
Write a one line C function to return position of first 1 from right to left, in binary representation of an Integer.

I/P    18,   Binary Representation 010010
O/P   2
I/P    19,   Binary Representation 010011
O/P   1

Let I/P be 12 (1100)

Algorithm: (Example 18(010010))

1. Take two's complement of the given no as all bits are reverted
except the first '1' from right to left (10111)

2  Do an bit-wise & with original no, this will return no with the
required one only (00010)

3  Take the log2 of the no, you will get position -1 (1)

4  Add 1 (2)
*/

int main() 
{
	int n=18&-18;
	cout<<bitset<8>(18)<<"\n";
	cout<<bitset<8>(~18)<<"\n";
	cout<<bitset<8>(18&-18)<<"\n";
	int count=0;
	while(n!=0)
	{
		count++;
		n=n>>1;
	}
	cout<<count;
	return 0;
}
