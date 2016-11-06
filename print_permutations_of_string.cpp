#include <iostream>
#include <iomanip>
#include <cmath>
#include <bitset>
#include <map>
#include <cstring>

using namespace std;

void swap(char *a, char *b)
{
	char temp=*a;
	*a=*b;
	*b=temp;
}

void permute(char a[], int s, int e)
{
	static int count =1;
	if(s==e)
	{
		cout<<count++<<" "<<a<<endl;
		return;
	}
	else
	{
		for (int i=s;i<=e;i++)
		{			
			//if(a[i]!=a[s] || i==s) // handles the case of duplicates also  but only when there is one duplicate if more make a set and check if new found already exists or not
				// works on AABC but fails on AABB
			//{
				swap(a+s,a+i);
				permute(a,s+1,e);
				swap(a+s,a+i);
			//}
		}
	}
}

int main()
{
	char a[]="ABC";
	int l=strlen(a);
	permute(a,0,l-1);
}