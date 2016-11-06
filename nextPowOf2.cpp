#include <iostream>
#include <bitset>
#include <iomanip>

using namespace std;

// int main()
// {
// 	int n;
// 	n=122;
// 	if(n>0)
// 		if( !( n&(n-1) ) )
// 			cout<<n;
// 		else
// 		{
// 			int p=2;
// 			while(p<n)
// 			{
// 				p=p<<1;
// 			}
// 			cout<<p;
// 		}	
// 	return 0;
// }

int main()
{
	int n;
	n=768;
	if(n>0)
		if( !( n&(n-1) ) )
			cout<<n;
		else
		{
			n=n<<1;
			while( n&(n-1) )
			{
				printf("the new val is %d\n",n&(n-1) );
				n=n&(n-1);
			}
			cout<<n;
		}	
	return 0;
}

/*
 1. Subtract n by 1
       n = n -1

    2. Set all bits after the leftmost set bit.

    /* Below solution works only if integer is 32 bits 
                n = n | (n >> 1);
                n = n | (n >> 2);
                n = n | (n >> 4);
                n = n | (n >> 8);
                n = n | (n >> 16);
    3. Return n + 1
Example:

Steps 1 & 3 of above algorithm are to handle cases 
of power of 2 numbers e.g., 1, 2, 4, 8, 16,

    Let us try for 17(10001)
    step 1
       n = n - 1 = 16 (10000)  
    step 2
       n = n | n >> 1
       n = 10000 | 01000
       n = 11000
       n = n | n >> 2
       n = 11000 | 00110
       n = 11110
       n = n | n >> 4
       n = 11110 | 00001
       n = 11111
       n = n | n >> 8
       n = 11111 | 00000
       n = 11111
       n = n | n >> 16
       n = 11110 | 00000
       n = 11111    

    step 3: Return n+1
     We get n + 1 as 100000 (32)

     # include <stdio.h>

/* Finds next power of two for n. If n itself
is a power of two then returns n

unsigned int nextPowerOf2(unsigned int n)
{
	n--;
	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	n++;
	return n;
}

/* Driver program to test above function
int main()
{
	unsigned int n = 25632432;
	for(;n<25632433;n++)
	printf("%d ,\t", nextPowerOf2(n));

	getchar();
	return 0;

}

my solutions doesnt matter if more than 32 bots also, maybe problem in storing it

# include <stdio.h>

/* Finds next power of two for n. If n itself
is a power of two then returns n

unsigned int nextPowerOf2(unsigned int n)
{
	n--;
	int pow=1;
	while(n>>pow)
	{
	    n |= n >> pow;
	    pow *= 2;
	}
	n++;
	return n;
}

/* Driver program to test above function 
int main()
{
	unsigned int n = 184;
	printf("%d", nextPowerOf2(n));
	getchar();
	return 0;

}

*/

