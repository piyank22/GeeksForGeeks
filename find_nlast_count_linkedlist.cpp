#include <iostream>

using namespace std;

struct node
{
	int data;
	node *next;
	node(int data=0, node *next = NULL ): data(data) , next(next) { }
};

int find_middle(node *a)
{
	node *temp1=a;
	node *temp2=a;
	while(temp1!=NULL)
	{
		temp1 = temp1->next;
		if(temp1 != NULL)
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}	
	}
	return temp2->data;
}

int find_count(node *a,int search_for)
{
	node *temp=a;
	int c=0;
	while(temp)
	{
		if(temp->data==search_for)
			c++;
		temp=temp->next;
	}
	return c;
}

int main()
{
	// node *a=new node(0);
	// for(int i=1;i<13;i++)
	// {
	// 	node *temp=new node(i,a);
	// 	a=temp;
	// }
	// node *aa=a;
	// while(aa!=NULL)
	// {
	// 	cout<<"\t"<<aa->data;
	// 	aa=aa->next;
	// }
	// int mid=find_middle(a);
	node *a=new node( 1,new node( 2,new node( 1,new node( 2,new node(1, new node( 3, new node(1) ) ) ) ) ) );
	cout<<find_count(a,1);
	return 0;
}
