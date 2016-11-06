#include <iostream>
#include <iomanip>
#include <cmath>
#include <bitset>
#include <map>

using namespace std;

struct node
{
	int data;
	node *next;
	node(int data=0, node *next = NULL ): data(data) , next(next) { }
};

bool checkloop(node *head)
{
	node *slow_ptr, *fast_ptr;
	slow_ptr=fast_ptr=head;
	while(slow_ptr && fast_ptr && fast_ptr->next)
	{
		slow_ptr=slow_ptr->next;
		fast_ptr=fast_ptr->next->next;
		if(slow_ptr == fast_ptr )
		{
			cout<<"loop found";
			return true;
		}	
	}
	return false;
}

int main()
{
	node *head=new node( 1, new node( 2,new node( 3 ) ) );
	head->next->next->next=head->next;
	cout<<checkloop(head);
	return 0;
}