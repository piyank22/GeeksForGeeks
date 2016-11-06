#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node* next;
};

void push(node **n , int data )
{
	node *temp=new node;
	temp->data=data;
	temp->next=*n;
	*n=temp;
	temp=NULL;
	delete temp;
}

int main()
{
	int n;
	int i;
	int index;
	node *temp,*a=NULL;
	int data;

	cout<<"\nenter n ";
	cin>>n;

	for(i=0;i<n;i++)
	{
		cout<<"\nenter data ";
		cin>>data;
		push(&a,data);
	}

	do
	{
		cout<<"\nenter valid index to view: ";
		cin>>index;
	}while( !(index<n && index>=0) );

	temp=a;
	for(i=0;i<index;i++)
		temp=temp->next;
	cout<<"\nValue is : "<<temp->data;
	temp=NULL;
	delete temp;

	return 0;
}

/*

Given only a pointer/reference to a node to be deleted in a singly linked list, how do you delete it?

say i want to delete the nth node:
then
node_nth->data=node_n+1th->data;
node_nth->next=node_n+1th->next;
delete the n+1 th node
its values will be in the previous one and it will work

take care of all posible boundary conditions

void deleteNode(node *node_ptr)   
{
   struct node *temp = node_ptr->next;
   node_ptr->data    = temp->data;
   node_ptr->next    = temp->next;
   delete temp;
}

this method wont work for the last node since we dont have the previous nodes values
*/	