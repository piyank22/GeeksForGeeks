#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

void print(std::vector<int> v)
{
    cout<<endl;
    for(int i=0;i<v.size();i++)
        cout<<"\t"<<v.at(i);
    cout<<endl;
}

struct node
{
    int d;
    node *left;
    node *right;
    node(int d=0,node *l=NULL,node *r=NULL) : d(d) , left(l) , right(r) { }
};

void printPathRootLeaf(node *root, vector<int> v)
{
    if(root==NULL)
        return;
    if(root!=NULL)
        v.push_back(root->d);
    if( root->left == NULL && root->right == NULL )
        print(v);
    else
    {
        printPathRootLeaf(root->left,v);
        printPathRootLeaf(root->right,v);
    }
}

int main()
{
    node *a=new node(20 , NULL,new node(21) );
    vector<int> v;
    printPathRootLeaf(a,v);
    return 0;
}