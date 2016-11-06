#include <iostream>

using namespace std;

int countsetbit(int n)
{
	int count =0;

	while(n)
	{
		count += n&1;
		n = n>>1;
	}

	return count;
}

int countsetbit_brianKernighan(int n)
{
	int count=0;

	while(n)
	{
		n=n&(n-1);
		count++;
	}

	return count;
}

int main()
{
	int n;

	n=100;
	cout<<countsetbit(n);
	cout<<"\n"<<countsetbit_brianKernighan(n);

	return 0;
}

/*

Example for Brian Kernighan’s Algorithm:

   n =  9 (1001)
   count = 0

   Since 9 > 0, subtract by 1 and do bitwise & with (9-1)
   n = 9&8  (1001 & 1000)
   n = 8
   count  = 1

   Since 8 > 0, subtract by 1 and do bitwise & with (8-1)
   n = 8&7  (1000 & 0111)
   n = 0
   count = 2

   Since n = 0, return count which is 2 now.
Time Complexity: O(logn)

1. Simple Method Loop through all bits in an integer, check if a bit is set and if it is then increment the set bit count. See below program

*/

/*

//count the number of bits to be flipped

#include <iostream>
using namespace std;

int countsetbits(int n)
{
    int count=0;
    while(n)
    {
        n=n&(n-1);
        count++;
    }
    return count;
}

int main() {
	//code
	int n,i,a,b;
	
	cin>>n;
	for(i=0;i<n;i++)
	{
	    cin>>a>>b;
	    cout<<countsetbits(a^b)<<endl;
	}
	
	return 0;
}

*/