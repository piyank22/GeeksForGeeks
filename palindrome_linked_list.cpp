#include <iostream>

using namespace std;

struct node
{
	int data;
	node *next;
	node(int data=0, node *next = NULL ): data(data) , next(next) { }
};


/*

1 2 3 4 5
	^ 		is middle

1 2 3 4
	^ 		is middle

to check if palindrome reverse the second half and move till firt beocmes null

*/

void print(node *a)
{
	cout<<"\n";
	while(a)
	{
		cout<<"\t"<<a->data;
		a=a->next;
	}
	cout<<"\n";
	return;
}

node* reverse(node *a)
{
	if(a==NULL)
		return NULL;
	if(a->next==NULL)
		return ( new node(a->data) );

	node *t=reverse(a->next);
	node *temp=t;
	while(temp->next)
		temp=temp->next;
	temp->next=new node(a->data);

	return t;
}

node* find_middle(node *a)
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
	return temp2;
}

bool palindrome(node *a)
{
	node *t=a;
	node *m=find_middle(a);
	node *r=reverse(m);
	while(r)
	{
		if(t->data != r->data)
			return false;
		t=t->next;
		r=r->next;
	}
	return true;
}


bool isPalindromeUtil(struct node **left, struct  node *right)
{
   if (right == NULL)
      return true;
   bool isp = isPalindromeUtil(left, right->next);
   if (isp == false)
      return false;
   bool isp1 = (right->data == (*left)->data);
   //cout<<"\nComparing "<<right->data<<" and "<<(*left)->data;
   *left = (*left)->next;
 
   return isp1;
}
 
bool isPalindrome_rec_way(struct node *head)
{
   isPalindromeUtil(&head, head);
}

int main()
{
	node *a=new node( 1,new node( 2,new node( 1,new node( 21,new node(21, new node( 1, new node(2 , new node(1) ) ) ) ) ) ) );
	cout<<isPalindrome_rec_way(a);
	return 0;
}
