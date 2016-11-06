#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

struct node
{
    int key;
    int degree;
    bool mark;
    node *parent;
    node *child;
    node *left;
    node *right;
    node(int k=0,int d=0,bool m=false,node *p=NULL, node *c=NULL,node *l=NULL,node *r=NULL) : key(k) , degree(d) , mark(m) , parent(p) , child(c) , left(l) , right(r) {}
};

node *create(int key=0)
{
    node *t=new node(key);
    t->left=t->right=t;
    return t;
}

struct fib_heap
{
    node *min;
    int n;
    fib_heap(node *m=NULL, int nn=0) : min(m) , n(nn) {}
};

void join_circular_DLL(node *&a, node *&b)
{
    if(a==NULL)
    {
        a=b;
        return;
    }
    else if(b==NULL)
        return;
    node *temp=a->left;
    temp->right=b;
    a->left=b->left;
    b->left->right=a;
    b->left=temp;
}

void print_Circular_DLL(node *kk)
{
    node *k=kk;
    if(k==NULL)
    {
        cout<<"\nEMPTY!!\n" ;
        return;
    }
    while(k->right != kk)
    {
        printf("\t(%d,%d)",k->key,k->degree);
        k=k->right;
    }
    printf("\t(%d,%d)\n",k->key,k->degree);
    return;
}

void fib_heap_insert(fib_heap &heap , node *x)
{
    if(heap.min==NULL)
        heap.min=x;
    else
    {
        join_circular_DLL(heap.min,x);
        if(x->key < heap.min->key)
            heap.min=x;
    }
    heap.n++;
}

fib_heap fib_heap_union(fib_heap &h1, fib_heap &h2)
{
    if(h1.min==NULL)
        return h2;
    else if(h2.min==NULL)
        return h1;
    fib_heap h(h1);
    h.n=h1.n+h2.n;
    join_circular_DLL(h.min,h2.min);
    if(h1.min->key > h2.min->key)
        h.min=h2.min;
    return h;
}

void fib_heap_link(node *&y, node *&x)
{
    join_circular_DLL(x->child,y);
    y->parent=x;
    x->degree++;
    y->mark=false;
}

void swap_util(node *x,node *y)
{
    node *prev_x=x->left, *next_x=x->right;
    node *prev_y=y->left, *next_y=y->right;

    prev_x->right=y;
    next_x->left=y;
    y->left=prev_x;
    y->right=next_x;

    prev_y->right=x;
    next_y->left=x;
    x->left=prev_y;
    x->right=next_y;
}

void CONSOLIDATE(fib_heap &heap)
{
    //print_Circular_DLL(heap.min);
    int ccc=ceil(log2(heap.n)+1)+3;
    vector<node*> a( ccc , NULL );
    node *t=heap.min;
    if(t==NULL)
        return;
    vector<node*> heap_list;
    do
    {
        heap_list.push_back(t);
        t=t->right;
        //printf("%d %d\n",t->key,t->degree );
    }while( t != heap.min );

    for(int i=0;i<heap_list.size();i++)
    {
        heap_list[i]->left = heap_list[i]->right = heap_list[i];
    }

    for(int i=0;i<heap_list.size();i++)
    {

        node *x=heap_list[i];
        int d=x->degree;
        //printf("%d %d\n",x->key,x->degree );
        //cout<<"\n"<<d<<"\t"<<x->key;
        while(a.at(d)!=NULL)
        {
            node *y=a.at(d);
            if(y->key < x->key )
            {
                swap(x,y);
                //cout<<"\n"<<i<<"\t"<<x->key<<"\t"<<y->key;
            }
            
            join_circular_DLL(x->child,y);
            y->parent=x;
            x->degree++;
            y->mark=false;
            
            //cout<<"\n\t"<<x->degree<<"\t"<<y->degree;
            a.at(d)=NULL;
            d=d+1;
        }
        //cout<<"\n"<<d<<"\t"<<x->key;
        //cout<<"\n";
        a.at(d)=x;
    }

    // for(int i=0;i<ccc;i++)
    //     if(a[i])
    //         cout<<"\t"<<i<<"\t"<<a[i]->key<<"\t"<<a[i]->degree<<"\n";

    heap.min=NULL;
    for(int i=0;i<ccc;i++)
    {
        if(a[i] != NULL)
        {
            if(heap.min == NULL)
                heap.min=a[i];
            else
            {
                //cout<<"has entered";
                join_circular_DLL(heap.min,a[i]);
                //print_Circular_DLL(heap.min);
                if(heap.min->key > a[i]->key)
                    heap.min=a[i];
            }
        }
    }
}

node* fib_heap_extract_min(fib_heap &heap)
{
    node *z=heap.min;
    if(z)
    {
        node *c=z->child;
        if(c!=NULL)
        {
            while(c->right != z->child)
            {
                c->parent=NULL;
                c=c->right;
            }
            c->parent=NULL;
        }
        //remove z from the root list

        node *prev = z->left , *next = z->right ;
        prev->right = next;
        next->left = prev;



        if(z==z->right)
            heap.min=NULL;
        else
        {
            heap.min=z->right;
            //print_Circular_DLL(heap.min);
            CONSOLIDATE(heap);
            //print_Circular_DLL(heap.min);
        }
        heap.n--;
    }

    return z;
}

void cut(fib_heap heap, node *x, node *y)
{
    // remove x from y
    if(y->child == x)
        y->child=x->right;
    if(y->child==x)
        y->child=NULL;
    else
    {
        node *prev=x->left , *next=x->right;
        prev->right=next;
        next->left=prev;
        x->right = x->left = x;
    }
    x->parent=NULL;
    join_circular_DLL(heap.min,x);
    x->mark=false;
    y->degree--;
}

void cascading_cut(fib_heap heap, node *x)
{
    node *z=x->parent;
    if(z!=NULL)
        if(x->mark==false)
            x->mark=true;
        else
        {
            cut(heap,x,z);
            cascading_cut(heap,z);
        }
}
    
void fib_heap_decrease_key(fib_heap &heap,node *x, int k)
{
    if(x->key < k )
    {
        cout<<"\n\nCannot be further decreased\n";
        return;
    }
    x->key=k;
    node *p=x->parent;
    if(p->key > x->key)
    {
        cut(heap,x,p);
        cascading_cut(heap,p);
    }
    if(x->key < heap.min->key)
        heap.min=x;
    return;
}

void fib_heap_delete(fib_heap &heap, node *x)
{
    fib_heap_decrease_key(heap,x,INT_MIN);
    fib_heap_extract_min(heap);
}

int main()
{
    fib_heap heap;

    fib_heap_insert(heap,create(100));
    fib_heap_insert(heap,create(21));
    fib_heap_insert(heap,create(1000));

    fib_heap heap1;

    fib_heap_insert(heap1,create(1));
    fib_heap_insert(heap1,create(2));
    fib_heap_insert(heap1,create(3));

    heap=fib_heap_union(heap,heap1);
    swap_util(heap.min->right->right,heap.min->left);

    print_Circular_DLL(heap.min);

    fib_heap_extract_min(heap);

    print_Circular_DLL(heap.min);

    // fib_heap_decrease_key(heap,heap.min->child,1);
    fib_heap_delete(heap,heap.min->child);
    print_Circular_DLL(heap.min);

    // checking children
    // cout<<"\n\n";

    // print_Circular_DLL(heap.min->child);
    // print_Circular_DLL(heap.min->child->right->child);

    return 0;
}