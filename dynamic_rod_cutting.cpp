#include <cstdio>

using namespace std;

void rod_cut(int p[], int r[], int s[], int n)
{    
    for(int i=1;i<n;i++)
    {
        int temp=-1; // revenue generated must be positive
        for(int j=0;j<=i;j++)
            if(temp < p[j] + r[i-j] )
            {
                temp = p[j] + r[i-j];
                if( i-j != 0 )
                    temp--; // if cutting the rod has a cost associated with it of 1
                s[i]=j;
            }  
        r[i]=temp;  
    }

}

int main()
{
    int p[]={0,1,5,8,9,10,17,17,20,24,30}; // p[i] denotes price of buying a rod of length i
    int n = sizeof(p)/sizeof(int);
    int r[n]={0}; // r[i] denotes revenue from a rod of length i
    int s[n]={0}; // s[i] denotes the size of first cut of length i
    rod_cut(p,r,s,n);

    for(int i=0;i<n;i++)
        printf("%5d",i);
    printf("\n");
    for(int i=0;i<n;i++)
        printf("%5d",p[i]);
    printf("\n");
    for(int i=0;i<n;i++)
        printf("%5d",r[i]);
    printf("\n");
    for(int i=0;i<n;i++)
        printf("%5d",s[i]);
    printf("\n");
    // to print solution
    // int k=9;
    // while(k)
    // {
    //     printf("%5d",s[k]);
    //     k=k-s[k];
    // }
    return 0;
}
