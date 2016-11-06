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

node* buildTree(int in[] ,int i1,int f1, int pre[], int i2, int f2)
{
	node *root;
	for(int i=i1 ; i<=f1; i++ )
		if(pre[i2]==in[i])
		{
			root=new node( pre[i2] , buildTree(in,i1,i-1,pre,i2+1,i2+(i-i1)) , buildTree(in,i+1,f1,pre,i2+(i+1-i1),f2));
			return root;
		}
	return NULL;
}

// tried again sometime later :p freak try again
// void printroot(std::vector<int> v, node *head)
// {
//     if (head==NULL)
//         return;
//     v.push_back(head->d);

//     if(head->left==NULL && head->right==NULL)
//         print(v);
//     else if(head->left==NULL)
//         printroot(v,head->right);
//     else if(head->right==NULL)
//         printroot(v,head->left);
//     else
//     {
//         printroot(v,head->left);
//         printroot(v,head->right);
//     }
//     return;
// }

int main()
{
	node* a=NULL;
	int in[]={3,5,2,7,11,4,9,8,10};
	int pre[]={2,3,5,4,7,11,8,9,10};
	a=buildTree(in,0,8,pre,0,8);
	vector<int> v,vv;
    printPathRootLeaf(a,v);
    cout<<endl<<endl;
    printroot(vv,a);
}