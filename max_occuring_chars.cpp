#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	//cout<<int('a');
	int letters[26];
	int n;
	cin>>n;
	char temp[121];
	for (int i=0;i<n;i++)
	{
		cin>>temp;

		for(int j=0;j<26;j++)
			letters[j]=0;

		for(int j=0;j<strlen(temp);j++)
			letters[int(temp[j])-97]++;

		int index=0;
		int max=0;
		for(int j=0;j<26;j++)
			if(letters[j]>max)
			{
				index=j;
				max=letters[j];
			}
		cout<<char(index+97);
	}
	return 0;
}