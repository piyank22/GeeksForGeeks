#include <iostream>
#include <bitset>
#include <vector>
#include <iomanip>

using namespace std;

int add(int x,int y)
{
	while(y!=0)
	{
		int carry=x&y;
		x=x^y;
		y=carry<<1;
	}
	return x;
}
int new_add(int x,int y)
{
	int carry=x&y;
	int sum=x^y;
	if(carry==0)
		return sum;
	else
		return new_add(sum,carry<<1);
}
int main() 
{
	int a=7,b=7;
	//cout<< add ( a , add(a<<2,a<<1) );
	cout<<new_add(2,3)<<"\n";
	cout<<new_add(8,3)<<"\n";
	cout<<new_add(9,1)<<"\n";
	return 0;
}

/*

multiply with 2 n<<1

multiply with 3 (n<<1)+n

multiply with 4 (n<<2)

multiply with 5 (n<<2)+n

multiply with 6 (n<<2)+(n<<1)

multiply with 7 (n<<3)-n   or (n<<2) + (n<<1) + n

multiply with 8 (n<<3)

multiply with 9 (n<<3)+n

multiply with 10 (n<<3)+(n<<1)

n<<k multiplies n by 2^k

*/