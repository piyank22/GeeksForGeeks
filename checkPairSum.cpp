#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;


/*

A very elegant solution using hash map

#include <stdio.h>
#define MAX 100000

void printPairs(int arr[], int arr_size, int sum)
{
int i, temp;
bool binMap[MAX] = {0}; //initialize hash map as 0

for (i = 0; i < arr_size; i++)
{
	temp = sum - arr[i];
	if (temp >= 0 && binMap[temp] == 1)
		printf("Pair with given sum %d is (%d, %d) \n", sum, arr[i], temp);
	binMap[arr[i]] = 1;
}
}

//Driver program to test above function
int main()
{
	int A[] = {1, 8, 45, 10, 6, 8}; // binMap[10]=1 phele step mein then when 6 comes it checks the binMap of 16-6=10 which is one and prints it
	int n = 16;
	int arr_size = sizeof(A)/sizeof(A[0]);

	printPairs(A, arr_size, n);

	getchar();
	return 0;
}


*/

//implementing using vectors and sort

void printvec(std::vector<int> a)
{
	for(int i =0;i<a.size();i++)
		cout<<setw(4)<<a.at(i);
	cout<<endl;
}

void checkpairsum(std::vector<int> v, int x)
{
	int f=0;
	int l=v.size()-1;
	bool found=false;

	while(f<l)
	{
		if ( v.at(f)+v.at(l) == x)
		{
			cout<<"\nPair is "<<v.at(f)<<" , "<<v.at(l);
			found=true;
			if(v.at(f)==v.at(f+1))
				f++;
			else if (v.at(l)==v.at(l-1))
				l--;
			else
			{
				f++;
				l--;
			}
		}
		else if ( v.at(f)+v.at(l) < x )
			f++;
		else
			l--;
	}

	if(found == false)
		cout<<"\nThere is no such pair";
}

int main()
{
	int n,x;
	cin>>n;

	vector<int> a(n);

	for(int i =0;i<a.size();i++)
		cin>>a.at(i);

	sort(a.begin(),a.end());

	printvec(a);

	cout<<"\nEnter sum ";
	cin>>x;
	checkpairsum(a,x);

	return 0;
}