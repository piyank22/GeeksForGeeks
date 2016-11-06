#include <iostream>
#include <queue>
#include <string>
#include <stack>
 
using namespace std;

struct node
{
    int data;
    node *left,*right;
    node(int d=0, node* l=NULL , node *r=NULL): data(d) , left(l) , right(r) {}
};

// void print(node *a)
// {
//     if(a==NULL)
//         return;
//     stack<node *> st;
//     while(a)
//     {
//         st.push(a);
//         a=a->left;
//     }
//     while(!st.empty())
//     {
//         node* temp=st.top();
//         while(temp!=NULL)
//         {
//             cout<<"\t"<<temp->data;
//             st.pop();
//             temp=temp->right;
//             while(temp)
//             {
//                 st.push(temp);
//                 temp=temp->left;
//             }
//         }
//     }
// }

void print(node *a)
{
    if(a==NULL)
        return;
    stack<node*> s;
    while(a)
    {
        s.push(a);
        a=a->left;
    }
    while(!s.empty())
    {
        cout<<s.top()->data<<"\t";
        print(s.top()->right);
        s.pop();
    }
}

int main()
{
    node *a=new node(1, NULL, new node( 2,NULL,new node(3, NULL , new node(4) ) ) );
    print(a);
    return 0;
}

/*
1) Create an empty stack S.
2) Initialize current node as root
3) Push the current node to S and set current = current->left until current is NULL
4) If current is NULL and stack is not empty then 
     a) Pop the top item from stack.
     b) Print the popped item, set current = popped_item->right 
     c) Go to step 3.
5) If current is NULL and stack is empty then we are done.

*/
