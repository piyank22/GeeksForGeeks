#include <iostream>
#include <cmath>
#include <bitset>
#include <queue>
#include <vector>

using namespace std;

struct node
{
	int d;
	node *left;
	node *right;
	node(int d=0,node *l=NULL,node *r=NULL) : d(d) , left(l) , right(r) { }
};

node* lca(node *a, int n1, int n2,bool &v1, bool &v2)//taking such that n1 < n2 , assuming distinct
{
	if(a==NULL)
		return NULL;
	if(a->d == n1 )
	{
		v1=true;
		return a;
	}
	if(a->d == n2 )
	{
		v2=true;
		return a;
	}

	if(a->d > n1 && a->d <n2)
		return a;


	else if( n1 > a->d )
		return lca(a->right, n1 , n2,v1,v2);
	else 
		return lca(a->left, n1 , n2,v1,v2);
}

bool find(node *a, int d)
{
	if(a==NULL)
		return false;
	if(a->d==d)
		return true;
	else if(find(a->left,d)||find(a->right,d))
		return true;
	else 
		return false;
}

node* lca_corner_case(node *a, int n1, int n2)
{
	bool v1=false,v2=false;
	node *temp=lca(a,n1,n2,v1,v2);
	if(v1==true)
		if(find(a,n2))
			return temp;
		else 
			return NULL;

	if(v2==true)
		if(find(a,n1))
			return temp;
		else 
			return NULL;

	if(find(a,n1)&&find(a,n2))
		return temp;
	else
		return NULL;

}



int main()
{
	node *a=new node(20 , new node (8 , new node(4) , new node(12, new node(10) , new node(14) ) ) , new node(22) );
	node *ans=lca_corner_case(a, 8 , 22);
	if(ans==NULL)
		cout<<"ops";
	else
		cout << ans->d ;
	return 0;
}