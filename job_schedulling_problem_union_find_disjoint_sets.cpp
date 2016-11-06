#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

struct job
{
	char a;
	int deadline;
	int profit;
};

bool com(job a, job b) // comparision function used as a utility in sorting values through stl sort
{
	return (a.profit > b.profit);
}

class disjointsets
{
	int *latest_available;
public:
	disjointsets(int n)
	{
		latest_available=new int[n+1]; // 0 corresponds to no time slot available and 1 corresponds to time slot 0-1 
		for(int i=0;i<n+1;i++)
			latest_available[i]=i; // initially the latest available timeslot corresponding to time slot t is t itself 
	}
	int find_latest_available_time_slot(int x) // uses path compression
	{
		if(latest_available[x]==x)
			return x;
		latest_available[x]=find_latest_available_time_slot(latest_available[x]);
		return latest_available[x];
	}
	void merge(int x, int y) // we cleaverly send items to merge so that we dont need an analogous link here
	{
		latest_available[y]=x;
	}
};

int get_max_time_slot(job arr[], int n)
{
	int m=INT_MIN;
	for(int i=0;i<n;i++)
		m=max(m,arr[i].deadline);
	return m;
}

void print_job_scheduling(job arr[] , int n)
{
	int max_deadline=get_max_time_slot(arr,n);
	disjointsets ds(max_deadline);

	sort(arr,arr+n,com);

	for(int i=0;i<n;i++)
	{
		int available_time_slot= ds.find_latest_available_time_slot(arr[i].deadline);
		if(available_time_slot > 0)
		{
			ds.merge( ds.find_latest_available_time_slot(available_time_slot-1) , available_time_slot );
			cout<<setw(5)<<arr[i].a;
		}
	}
	cout<<endl;
}

int main()
{
	job arr[]={{ 'a', 2, 100 }, { 'b', 1, 19 }, { 'c', 2, 27 },  { 'd', 1, 25 }, { 'e', 3, 15 }};
	int n=5;
	cout << "Following jobs need to be executed for maximum profit\n";
	print_job_scheduling(arr,n);
}