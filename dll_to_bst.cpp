#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <stack>
#include <cstdio>

using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;
    node(int d, node *a=NULL,  node *b=NULL) : data(d) , prev(a) , next(b) { }
};

int count_nodes(node *dll )
{
    int count =0;
    while(dll)
    {
        count++;
        dll=dll->next;
    }
    return count;
}

void inorder(node *dll)
{
    if(dll==NULL)
        return;
    inorder(dll->prev);
    printf(" --%d-- ",dll->data);
    inorder(dll->next);
    return;
}

node* dllTObst(node *&head , int n)
{
    // printf("%d       %d\n",head==NULL?-1:head->data,n );
    if(n<=0)
        return NULL;
    node *left=dllTObst(head,n/2);
    node *root=head;
    root->prev=left;
    head=head->next;
    root->next=dllTObst(head,n-n/2-1);
    return root;
}

void level_order(node *tree)
{
    queue<node*> q;
    q.push(tree);
    q.push(NULL);
    int i=0;
    int k=2;
    while(!q.empty())
    {
        node *t=q.front();
        q.pop();
        if(t!=NULL)
        {
            cout<<"\t"<<t->data;
            if(t->prev)
                q.push(t->prev);
            if(t->next)
                q.push(t->next);
        }
        else
            if(q.front()==NULL)
            {
                cout<<"\nFinished";
                break;
            }
            else
            {
                cout<<"\n";
                q.push(NULL);
                i++;
            }
    }
}

void dll_push(node *&dll,int d)
{
    if(dll==NULL)
    {
        dll=new node(d);
        return;
    }

    node *temp=new node(d);
    temp->next=dll;
    dll->prev=temp;
    dll=temp;
}

int main()
{
    node *dll=NULL;
    for(int i=5;i>=1;i--)
        dll_push(dll,i);
    node *temp=dll;
    // while(temp)
    // {
    //     cout<<"\t"<<temp->data;
    //     temp=temp->next;
    // }
    int n=count_nodes(dll);
    if(n>0)
        dll=dllTObst(dll,n);
    inorder(dll);
    cout<<"\n\n";
    level_order(dll);

    return 0;
}