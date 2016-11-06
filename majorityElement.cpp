#include <iostream>
#include <vector>
using namespace std;

void printMajority(vector<int> arr)
{
    int hash[101]={0};
	for(int j=0;j<arr.size();j++)
	{
	    hash[arr.at(j)]++;
	    if(hash[arr.at(j)] > (arr.size()/2) )
	    {
	        cout<<arr.at(j)<<endl;
	        return;
	    }
	}
	cout<<"NO Majority Element"<<endl;
	return;
}
int main() {
	int n;
	int size;
	int i;
	cin>>n;
	for(i=0;i<n;i++)
	{
	    cin>>size;
	    vector<int> arr(size);
	    for(int j=0;j<size;j++)
	        cin>>arr.at(j);
	    printMajority(arr);
	}
	return 0;
}

/*

here pls note that it is a majority if a number comes more than floor(n/2) times

if not majority arbitary results may come

This is a two step process.
1. Get an element occurring most of the time in the array. This phase will make sure that if there is a majority element then it will return that only.
2. Check if the element obtained from above step is majority element.

1. Finding a Candidate:
The algorithm for first phase that works in O(n) is known as Moore’s Voting Algorithm. Basic idea of the algorithm is if we cancel out each occurrence of an element e with all the other elements that are different from e then e will exist till end if it is a majority element.

findCandidate(a[], size)
1.  Initialize index and count of majority element
     maj_index = 0, count = 1
2.  Loop for i = 1 to size – 1
    (a)If a[maj_index] == a[i]
        count++
    (b)Else
        count--;
    (c)If count == 0
        maj_index = i;
        count = 1
3.  Return a[maj_index]
Above algorithm loops through each element and maintains a count of a[maj_index], If next element is same then increments the count, if next element is not same then decrements the count, and if the count reaches 0 then changes the maj_index to the current element and sets count to 1.
First Phase algorithm gives us a candidate element. In second phase we need to check if the candidate is really a majority element. Second phase is simple and can be easily done in O(n). We just need to check if count of the candidate element is greater than n/2.

Example:
A[] = 2, 2, 3, 5, 2, 2, 6
Initialize:
maj_index = 0, count = 1 –> candidate ‘2?
2, 2, 3, 5, 2, 2, 6

Same as a[maj_index] => count = 2
2, 2, 3, 5, 2, 2, 6

Different from a[maj_index] => count = 1
2, 2, 3, 5, 2, 2, 6

Different from a[maj_index] => count = 0
Since count = 0, change candidate for majority element to 5 => maj_index = 3, count = 1
2, 2, 3, 5, 2, 2, 6

Different from a[maj_index] => count = 0
Since count = 0, change candidate for majority element to 2 => maj_index = 4
2, 2, 3, 5, 2, 2, 6

Same as a[maj_index] => count = 2
2, 2, 3, 5, 2, 2, 6

Different from a[maj_index] => count = 1

Finally candidate for majority element is 2.

First step uses Moore’s Voting Algorithm to get a candidate for majority element.

2. Check if the element obtained in step 1 is majority

printMajority (a[], size)
1.  Find the candidate for majority
2.  If candidate is majority. i.e., appears more than n/2 times.
       Print the candidate
3.  Else
       Print "NONE"


// Program for finding out majority element in an array
# include<stdio.h>
# define bool int
  
int findCandidate(int *, int);
bool isMajority(int *, int, int);
  
// Function to print Majority Element 
void printMajority(int a[], int size)
{
  // Find the candidate for Majority
  int cand = findCandidate(a, size);
  
  // Print the candidate if it is Majority
  if(isMajority(a, size, cand))
    printf(" %d ", cand);
  else
    printf("NO Majority Element");
}
  
//Function to find the candidate for Majority
int findCandidate(int a[], int size)
{
    int maj_index = 0, count = 1;
    int i;
    for(i = 1; i < size; i++)
    {
        if(a[maj_index] == a[i])
            count++;
        else
            count--;
        if(count == 0)
        {
            maj_index = i;
            count = 1;
        }
    }
    return a[maj_index];
}

// Function to check if the candidate occurs more than n/2 times 
bool isMajority(int a[], int size, int cand)
{
    int i, count = 0;
    for (i = 0; i < size; i++)
      if(a[i] == cand)
         count++;
    if (count > size/2)
       return 1;
    else
       return 0;
}
  
// Driver function to test above functions 
int main()
{
    int a[] = {1, 3, 3, 1, 2};
    int size = (sizeof(a))/sizeof(a[0]);
    printMajority(a, size);
    getchar();
    return 0;
}



excersise:

Now give a try to below question
Given an array of 2n elements of which n elements are same and the remaining n elements are all different.
Write a C program to find out the value which is present n times in the array. There is no restriction on the elements in the array. 
They are random (In particular they not sequential).

// i do this is as check if the last digit is the occuring n times or not
// if so we r done
// else in the remaining 2n-1 numbers we can find the majority

#include <iostream>
#include <bitset>
#include <vector>
#include <iomanip>

using namespace std;

int findcandidate(int arr[],int n)
{
	int cand_index=0;
	int count=1;
	for (int i=1;i<n;i++)
	{
		if(arr[cand_index]==arr[i])
			count++;
		else
			count--;
		if(count==0)
		{
			cand_index=i;
			count=1;
		}
	}
	return arr[cand_index];
}
bool checkiflast(int arr[], int n)
{
	for(int i=0;i<n-1;i++)
		if(arr[i]==arr[n-1])
			return true;
	return false;
}
int main()
{
	int arr[]={1,1,1,2,3,4};
	if ( checkiflast(arr, sizeof(arr)/sizeof(arr[0]) ) )
		cout<<arr[ sizeof(arr)/sizeof(arr[0]) -1 ];
	else
		cout<<findcandidate(arr, sizeof(arr)/sizeof(arr[0])-1);
}




*/


