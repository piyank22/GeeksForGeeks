#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <stack>
 
using namespace std;

struct node
{
    int key;
    node *left,*right;
    node(int d=0, node* l=NULL , node *r=NULL): key(d) , left(l) , right(r){}
};

bool printancestor(node *tree, node *target)
{
    if(tree==NULL)
        return false;
    else if(tree==target)
        return true;
    else if( printancestor(tree->left,target) || printancestor(tree->right,target) )
    {
        cout<<tree->key<<"\n";
        return true;
    }
    return false;
}

int main()
{
    node *tree=new node(1,new node(2,new node(4), new node(5)),new node(3,NULL,new node(8,new node(6),new node(7))));

    node *target1=tree->right->right->right;
    node *target2=new node(1);

    if(!printancestor(tree,target1))
        cout<<"\nThis node doesnt belong to tree";
    
    if(!printancestor(tree,target2))
        cout<<"\nThis node doesnt belong to tree";

    return 0;
}
