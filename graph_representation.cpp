#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

struct node
{
    int destination;
    node *next;
    node(int i=0,node *n=NULL) : destination(i) , next(n) { }
};

struct graph
{
    int vertex;
    node **arr;
    graph(int v):vertex(v) 
    {
        arr= new node*[vertex];
        for(int i=0;i<vertex;i++)
            arr[i]=new node(i);
    }
};

void addEdge(graph &g, int i, int f)
{
    // edge added on both sides as the graph is undirected
    node *t=new node(f);
    node *temp=g.arr[i]->next;
    g.arr[i]->next=t;
    t->next=temp;

    node *tt=new node(i);
    temp=g.arr[f]->next;
    g.arr[f]->next=tt;
    tt->next=temp;
    
    temp=NULL;
    delete temp;
}

void printGraph(graph g)
{
    for(int i=0;i<g.vertex;i++)
    {
        cout<<i<<" -> ";
        node *t = g.arr[i]->next;
        while(t)
        {
            printf("-> %d",t->destination );
            t=t->next;
        }
        cout<<"\n";
    }
}

int main()
{
    graph g(5);
    addEdge(g, 0, 1);
    addEdge(g, 0, 4);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 3);
    addEdge(g, 3, 4);
    printGraph(g);
    return 0;
}
