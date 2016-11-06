#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <stack>
 
using namespace std;

struct node
{
    int key;
    node *left,*right,*nextright;
    node(int d, node* l=NULL , node *r=NULL, node *ne=NULL): key(d) , left(l) , right(r) , nextright(ne) {}
};

void print(node* t)
{
    while(t)
    {
        cout<<"\t"<<t->key;
        t=t->nextright;
    }
    cout<<"\n";
}

int main()
{
    node *tree=new node(1,new node(2, new node(4, new node(8), new node(9) ) , new node(5) ), new node(3, new node(6) , new node(7, new node(10) , new node(11) ) ) );
    queue<node*> q;
    q.push(tree);
    q.push(NULL);
    tree->nextright=NULL;
    while(!q.empty())
    {
        node *t=q.front();
        q.pop();
        if(t==NULL)
        {
            if(q.front()!=NULL)
                q.push(NULL);
        }
        else
        {
            t->nextright=q.front();
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right); 
        }
    }
    print(tree);
    print(tree->left);
    print(tree->left->left);
    print(tree->left->left->left);
    return 0;
}
