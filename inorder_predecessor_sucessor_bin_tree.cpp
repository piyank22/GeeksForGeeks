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
    node(int d, node* l=NULL , node *r=NULL): key(d) , left(l) , right(r) {}
};

node* findMIN(node* t)
{
    while(t->left)
        t=t->left;
    return t;
}

node* findMAX(node* t)
{
    while(t->right)
        t=t->right;
    return t;
}

bool inorder_pre_suc(node *tree, int key, node *&suc, node *&pre)
{
    if(tree==NULL)
        return false;
    else if(tree->key==key)
    {
        if(tree->right != NULL)
            suc=findMIN(tree->right);
        if(tree->left != NULL)
            pre=findMAX(tree->left);
        return true;
    }
    else if(tree->key > key)
    {
        suc=tree;
        return inorder_pre_suc(tree->left,key,suc,pre);
    }
    else
    {
        pre=tree;
        return inorder_pre_suc(tree->right,key,suc,pre);
    }
}

int main()
{
    node *tree=new node(4,new node(2, new node(1) , new node(3) ), new node(6, new node(5) , new node(7) ) );
    node *pre=NULL, *suc=NULL;
    if(inorder_pre_suc(tree,10,suc,pre))
    {
        cout<<"FOUND\n";
        if(suc)
            cout<<"\nSuccesor is "<<suc->key;
        if(pre)
            cout<<"\nPredecessor is "<<pre->key;
    }
    else
    {
        cout<<"NOT FOUND\n";
        cout<<"The range it should lie in is :[ ";
        pre=findMIN(tree);
        suc=findMAX(tree);
        if(pre)
            cout<<pre->key;
        cout<<" , ";
        if(suc)
            cout<<suc->key;
        cout<<" ]\n";
    }
    return 0;
}