#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

void print(std::vector<int> v)
{
    cout<<endl;
    for(int i=0;i<v.size();i++)
        cout<<"\t"<<v.at(i);
    cout<<endl;
}

int main ()
{
	std::vector<int> v,v2;
	for(int i=1;i<=1000000;i++)
		v2.push_back(i);
	bool b=true;
	int j=1;
	while( v != v2 )
	{
		v=v2;
		v2.clear();
		for(int i=0;i<v.size();i++)
		{
			if( (i+1) % (j+1) != 0 )
				v2.push_back(v.at(i));	
		}
		j++;
	}
	cout<<v.size()<<"\t"<<j;
	return 0;
}