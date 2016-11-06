#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;

struct tree_node
{
    int key;
    int degree;
    tree_node *parent;
    tree_node *child;
    tree_node *sibling;
    tree_node(int k=0,int d=0,tree_node *p=NULL,tree_node *c=NULL,tree_node *s=NULL) : key(k) , degree(d) , parent(p) , child(c) , sibling(s) {}
};

void printTREE(tree_node *tree)
{
    tree_node *t=tree, *temp=t->sibling;
    t->sibling=NULL;

    deque<tree_node*> dq;
    dq.push_back(t);
    while(!dq.empty())
    {
        tree_node *tt=dq.front();
        dq.pop_front();
        if(tt->sibling)
            dq.push_front(tt->sibling);
        if(tt->child)
            dq.push_back(tt->child);
        cout<<"\t"<<tt->key;
    }

    tree->sibling=temp;
    return;
}

void print(tree_node *h)
{
    cout<<"\nThe heap is:\n";
    while(h)
    {
        printTREE(h);
        h=h->sibling;
        cout<<"\n";
    }
    cout<<"\nNULL\n";
}

tree_node* binomial_heap_min(tree_node *heap)
{
    tree_node *t=NULL;
    int y=INT_MAX;
    while(heap)
    {
        if(heap->key < y)
        {
            y=heap->key;
            t=heap;
        }
        heap=heap->sibling;
    }
    return t;
}

void binomial_link(tree_node *x, tree_node *y)
{
    x->parent=y;
    x->sibling=y->child;
    y->child=x;
    y->degree++;
}

tree_node* binomial_heap_merge(tree_node *h1, tree_node *h2)
{
    tree_node *h=NULL,*heap=NULL;

    if(h1==NULL)
        return h2;
    if(h2==NULL)
        return h1;

    tree_node *t1,*t2;

    while(h1 && h2)
    {
        if( (h1->degree < h2->degree) || ((h1->degree==h2->degree)&&(h1->key < h2->key)) )
        {
            t1=h1;t2=h2;

            h1=h1->sibling;
            h2=h2->sibling;
            if(h)
                h->sibling=t1;
            else
                h=heap=t1;
            t1->sibling=t2;
            t2->sibling=NULL;
            h=t2;
        }
        else
        {
            t1=h1;t2=h2;

            h1=h1->sibling;
            h2=h2->sibling;
            if(h)
                h->sibling=t2;
            else
                h=heap=t2;
            t2->sibling=t1;
            t1->sibling=NULL;
            h=t1;
        }
    }

    while(h1)
    {
        h=h->sibling=h1;
        h1=h1->sibling;
    }

    while(h2)
    {
        h=h->sibling=h2;
        h2=h2->sibling;
    }    

    return heap;
}

tree_node* binomial_heap_union(tree_node *&h1, tree_node *&h2)
{   
    tree_node *h=binomial_heap_merge(h1,h2);
    h1=h2=NULL;
    if(h==NULL)
        return h;
    tree_node *prev=NULL,*x=h,*next=x->sibling;
    while(next)
    {
        if( (x->degree != next->degree) || ( next->sibling!=NULL && next->sibling->degree == next->degree ) )
        {
            prev=x;
            x=next;
        }
        else if(x->key <= next->key)
        {
            x->sibling=next->sibling;
            binomial_link(next,x);
        }
        else
        {
            if(prev==NULL)
                h=next;
            else
                prev->sibling=next;
            binomial_link(x,next);
            x=next;
        }
        next=x->sibling;
    }
    return h;
}

void binomial_heap_insert(tree_node *&heap, tree_node *key)
{
    heap=binomial_heap_union(heap,key);
}

void form_new_heap_util(tree_node *&c)
{
    tree_node *prev=NULL , *current=c, *next;
    while(current)
    {
        current->parent=NULL;
        next=current->sibling;
        current->sibling=prev;
        prev=current;
        current=next;
    }
    c=prev;
}

tree_node* binomial_heap_extract_min(tree_node *&heap)
{
    tree_node *m=binomial_heap_min(heap);
    tree_node *h=heap;
    if(h==m)
        heap=m->sibling;
    else
    {
        while(h->sibling != m)
            h=h->sibling;
        h->sibling=m->sibling;
    }
    m->sibling=NULL;
    if(m->degree!=0)
    {
        tree_node *c=m->child;
        m->child=NULL;
        m->degree=0;
        form_new_heap_util(c);
        heap=binomial_heap_union(heap,c);
    }
    return m;
}

void binomial_heap_decrease_key(tree_node *heap , tree_node *x, int new_key)
{
    if(x->key < new_key)
    {
        cout<<"\ncannot decrease key to new_key value\n";
        return;
    }
    x->key = new_key;
    while(x->parent != NULL && x->parent->key > x->key )
    {
        swap(x->parent->key , x->key);
        x=x->parent;
    }
}

void binomial_heap_delete(tree_node *&heap , tree_node *x)
{
    binomial_heap_decrease_key(heap,x,INT_MIN);
    binomial_heap_extract_min(heap);
}

int main()
{
    tree_node *heap=new tree_node(12);
    for(int i=1;i<=10;i++)
    {
        binomial_heap_insert(heap,new tree_node(i));
        print(heap);
    }
    binomial_heap_extract_min(heap);
    print(heap);
    binomial_heap_extract_min(heap);
    print(heap);
    binomial_heap_extract_min(heap);
    print(heap);
    binomial_heap_extract_min(heap);
    print(heap);

    binomial_heap_insert(heap,new tree_node(11));
    print(heap);

    binomial_heap_decrease_key(heap,heap->child->child,2);
    print(heap);

    binomial_heap_delete(heap,heap->child->sibling->child);
    print(heap);
    return 0;
}