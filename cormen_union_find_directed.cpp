#include <iostream>
#include <iomanip>

using namespace std;

class node_uf
{
    int *parent; // given an array the value at pos i is the parent of ith element initially each element is its own parent 
    int *rank; // the rank is the total number of elements stored in the set
    int count; // count is the number of sets  initially it is the the same as the number of elements
    int n; // it is the number of elements
public:
    node_uf(int number) : count(n) , n(number)  // make set is implicitly present in the constructor
    {
        parent = new int[n];
        rank = new int[n];
        for(int i=0 ; i < n ; i++ )
        {
            parent[i]=i;
            rank[i]=0;
        }
    }

    int find_set(int x)
    {
        if(parent[x]==x)
            return x;
        parent[x]=find_set(parent[x]);
        return parent[x];
    }

    void link(int x, int y)
    {
        if(x==y)
        {
            printf("%d and %d are already linked\n",x,y );
            return;
        }
        if( rank[x] > rank[y] )
            parent[y]=x;
        else
        {
            parent[x]=y;
            if(rank[x]==rank[y])
                rank[y]++;
        }
        return;
    }

    void UNION(int x, int y)
    {
        link(find_set(x),find_set(y));
    }

    void print_parent()
    {
        cout<<"\nThe parent pointers are: \n";
        for(int i=0;i<n;i++)
            cout<<setw(5)<<parent[i];
        cout<<"\n";
    }
};

int main()
{
    node_uf n(10);
    n.UNION(2,1);
    n.print_parent();
    n.UNION(4,3);
    n.UNION(8,4);
    n.print_parent();
}