#include <iostream>
#include <queue>
#include <string>
 
using namespace std;

class kStacks
{
    int *data;
    int *top;
    int free;
    int *next;
    int n;
    int k;
public:
    kStacks(int n1, int k1) : n(n1) , k(k1)
    {
        data=new int[n];
        top=new int[k];
        next=new int[n];
        free=0;
        for (int i=0;i<k;i++)
            top[i]=-1;
        for(int i=0;i<n-1;i++)
            next[i]=i+1;
        next[n-1]=-1;
    }

    bool isfull()
    {
        return free == -1;
    }

    bool isempty(int sn)
    {
        return top[sn]==-1;
    }

    void push(int d, int sn)
    {
        if(isfull())
        {
            cout<<"Arr full\n";
            return;
        }
        int i=free;
        data[i]=d;
        free=next[i];
        next[i]=top[sn];
        top[sn]=i;
    }

    int pop(int sn)
    {
        if(isempty(sn))
        {
            cout<<"Already Empty\n";
            return -1111;
        }
        int i=top[sn];
        int d=data[i];
        top[sn]=next[i];
        next[i]=free;
        free=i;
        return d;
    }
};

int main()
{
    int k = 3, n = 10;
    kStacks ks(n,k);
 
    // Let us put some items in stack number 2
    ks.push(15, 2);
    ks.push(45, 2);
 
    // Let us put some items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);
 
    // Let us put some items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);
 
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
 
    return 0;
}