#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <stack>
#include <cstdio>

using namespace std;

struct node
{
    int key;
    node *left,*right;
    node(int d, node* l=NULL , node *r=NULL): key(d) , left(l) , right(r) { }
};

int ceil(node *root , int input)
{
    if(root==NULL)
        return INT_MIN;
    else if(root->key==input)
        return root->key;
    else if(root->key < input)
        return ceil(root->right , input);
    else
    {
        int temp=ceil(root->left,input);
        return (temp >= input)?temp:root->key;
    }
}

int floor(node *root, int input)
{
    if(root==NULL)
        return INT_MAX;
    else if(root->key==input)
        return root->key;
    else if(root->key > input)
        return floor(root->left,input);
    else
    {
        int temp=floor(root->right,input);
        return (temp <= input)?temp:root->key;
    }
}

int main()
{
    node *root=new node(8 , new node(4, new node(2) , new node(6) ) , new node(12 , new node(10) , new node(14) ) );
    for(int i=0;i<16;i++)
        printf("%d :- %d\n",i,floor(root,i));
    return 0;
}