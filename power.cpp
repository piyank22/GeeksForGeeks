#include<iostream>
using namespace std;
float power(float x, int y)
{
	if(y==0)
		return 1;
	float a;
	a=power(x,y/2);
	if(y%2==0)
		return a*a;
	else
		if(y>0)
			return x*a*a;
		else
			return a*a/x;
}
int main()
{
	float n;
	int pow;
	cin>>n;
	cin>>pow;
	cout<<power(n,pow);
	return 0;
}