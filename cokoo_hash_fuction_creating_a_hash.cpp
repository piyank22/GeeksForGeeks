#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

#define h 11
#define v 2

int hashtable[v][h];

void initTable()
{
    for (int j=0; j<h; j++)
        for (int i=0; i<v; i++)
            hashtable[i][j] = INT_MIN;
}

void printTable()
{
    printf("Final hash tables:\n");
 
    for (int i=0; i<v; i++, printf("\n"))
        for (int j=0; j<h; j++)
            (hashtable[i][j]==INT_MIN)? cout<<setw(5)<<"-" :cout<<setw(5)<<hashtable[i][j];
    printf("\n");
}

int hash(int function, int key)
{
    if(function==1)
        return key % h;
    if(function==2)
        return (key/h) % h;
}

void place(int key, int tableID , int count , int n)
{
    //if a maximum of n times we have changed we can can definetly say that we have encountered a loop
    if(count==n)
    {
        printf("%d unpositioned\n", key);
        printf("Cycle present. REHASH.\n");
        return;
    }
    // check if already present
    for (int i=0; i<v; i++)
    {
        if (hashtable[i][hash(i+1, key)] == key)
           return;
    }

    if( hashtable[tableID][hash(tableID+1,key)] != INT_MIN )
    {
        int temp=hashtable[tableID][hash(tableID+1,key)];
        hashtable[tableID][hash(tableID+1,key)]=key;
        place( temp , (tableID+1)%v , count+1 , n);
    }
    else
        hashtable[tableID][hash(tableID+1,key)]=key;
    return;
}

void cuckoo(int keys[], int n)
{
    initTable();

    for (int i=0, cnt=0; i<n; i++, cnt=0)
        place(keys[i], 0, cnt, n);
 
    printTable();
}

int main()
{
    int keys_1[] = {20, 50, 53, 75, 100, 67, 105, 3, 36, 39};
 
    int n = sizeof(keys_1)/sizeof(int);
 
    cuckoo(keys_1, n);
    int keys_2[] = {20, 50, 53, 75, 100, 67, 105, 3, 36, 39, 6};
 
    int m = sizeof(keys_2)/sizeof(int);
 
    cuckoo(keys_2, m);
 
    return 0;
}
