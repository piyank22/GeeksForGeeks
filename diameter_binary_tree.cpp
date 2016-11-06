#include <iostream>
#include <queue>
#include <string>
 
using namespace std;

struct node
{
    int data;
    node *left,*right;
    node(int d=0, node* l=NULL , node *r=NULL): data(d) , left(l) , right(r) {}
};

int height(node *root);

int diameter(node *root)
{
    if(root==NULL)
        return 0;
    else if(root->left==NULL && root->right==NULL)
        return 1;
    int m1=diameter(root->left);
    int m2=diameter(root->right);
    int m3=height(root->left)+height(root->right)+3;
    return max(m3,max(m1,m2));
}

int height(node *root)
{
    if(root==NULL)
        return -1;
    if(root->left==NULL && root->right==NULL)
        return 0;
    else 
        return max(height(root->left),height(root->right))+1;
}

int main()
{
    node *root=new node(1, new node( 2, new node(4), new node(5) ) , new node(3) );
    cout<<diameter(root);
}