#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

void longest_palindrome_subsequence(string a)
{
    int l;
    string temp;
    string palin[100][100];
    for(int i=a.length()-1;i>=0;--i)
        for(int j=i;j<a.length();j++)
        {
            if(i==j)
                palin[i][j]=a[i];
            else
            {
                if(a[i]==a[j])
                    palin[i][j]=a[i]+palin[i+1][j-1]+a[i];
                else
                {
                    if(palin[i+1][j].length() > palin[i][j-1].length() )
                        palin[i][j]=palin[i+1][j];
                    else
                        palin[i][j]=palin[i][j-1];
                }
            }
        }
    cout<<palin[0][a.length()-1]<<"\n";
}

int main()
{
    string a="character";
    longest_palindrome_subsequence(a);
    return 0;
}
