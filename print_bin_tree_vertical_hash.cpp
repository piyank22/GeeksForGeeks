#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct node
{
    int key;
    node *left;
    node *right;
    node(int k, node *l=NULL, node *r=NULL) : key(k) , left(l) , right(r) { }
};

void printvertical(node *tree , int hd ,map< int,vector<int> > &m )
{
    if(tree==NULL)
        return;
    if( m.find(hd) != m.end() )
        m[hd].push_back(tree->key);
    else
    {
        vector<int> v;
        v.push_back(tree->key);
        m[hd]=v;
    }
    printvertical(tree->left,hd-1,m);
    printvertical(tree->right,hd+1,m);
}

void printvec(vector<int> v)
{
    for(int i=0;i<v.size();i++)
        printf("%d\t",v.at(i));
    printf("\n");
}


int main()
{
    node *tree=new node(1, new node(2,new node(4),new node(5)) , new node(3,new node(6,NULL,new node(8)),new node(7,NULL,new node(9))));
    map < int,vector<int> > m;
    printvertical(tree,0,m);
    for(map<int , vector<int> >::iterator it=m.begin() ; it!=m.end() ; it++)
    {
        printf("%d\t: ",it->first );
        printvec(it->second);
    }
}