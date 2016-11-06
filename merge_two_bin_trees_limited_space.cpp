#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <stack>
 
using namespace std;

struct node
{
    int data;
    node *left,*right;
    node(int d, node* l=NULL , node *r=NULL): data(d) , left(l) , right(r) {}
};

void inorder(node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<"\t"<<root->data;
    inorder(root->right);
}

// void print_merge(node *root1, node *root2)
// {
//     stack<node*> s1,s2;
//     node *current1, *current2;
//     current1=root1;
//     current2=root2;
//     if(root1==NULL)
//         inorder(root2);
//     else if(root2==NULL)
//         inorder(root1);
//     else
//     {
//         while( current1!=NULL || current2!=NULL || !s1.empty() || !s2.empty() )
//         {
//             if( current1!=NULL || current2!=NULL )
//             {
//                 while(current1)
//                 {
//                     s1.push(current1);
//                     current1=current1->left;
//                 }
//                 while(current2)
//                 {
//                     s2.push(current2);
//                     current2=current2->left;
//                 }
//             }
//             else
//             {
//                 if(s1.empty())
//                 {
//                     while(!s2.empty())
//                     {
//                         current2=s2.top();
//                         s2.pop();
//                         current2->left=NULL;
//                         inorder(current2);
//                     }
//                     return;
//                 }
//                 if(s2.empty())
//                 {
//                     while(!s1.empty())
//                     {
//                         current1=s1.top();
//                         s1.pop();
//                         current1->left=NULL;
//                         inorder(current1);
//                     }
//                     return;

//                 }
//                 current1=s1.top();
//                 s1.pop();
//                 current2=s2.top();
//                 s2.pop();
//                 if(current1->data < current2->data)
//                 {
//                     cout<<"\t"<<current1->data;
//                     current1=current1->right;
//                     s2.push(current2);
//                     current2=NULL;
//                 }
//                 else
//                 {
//                     cout<<"\t"<<current2->data;
//                     current2 = current2->right;
//                     s1.push(current1);
//                     current1 = NULL;
//                 }
//             }
//         }
//     }       
// }

void print_merge(node *r1,  node *r2)
{
    node *c1 = r1 , *c2 = r2;
    stack<node*> s1,s2;
    while( c1 || c2 || !s1.empty() || !s2.empty() )
    {
        while(c1)
        {
            s1.push(c1);
            c1=c1->left;
        }
        while(c2)
        {
            s2.push(c2);
            c2=c2->left;
        }

        if( !s1.empty() || !s2.empty() )
        {
            if( !s1.empty() && !s2.empty() )
            {
                node *t1 = s1.top();
                node *t2 = s2.top();
                if( t1->data > t2->data )
                {
                    printf("%d , ",t2->data );
                    s2.pop();
                    c2 = t2->right;
                }
                else
                {
                    printf("%d , ",t1->data );
                    s1.pop();
                    c1 = t1->right;
                }
            }
            else if( !s1.empty() )
            {
                printf("%d , ",s1.top()->data );
                c1=s1.top()->right;
                s1.pop();
            }
            else if( !s2.empty() )
            {
                printf("%d , ",s2.top()->data );
                c2=s2.top()->right;
                s2.pop();
            }
        }
    }
}

int main()
{
    node *root1 = new node( 4, new node(2, NULL, new node(3)) , new node(6, NULL, new node(7)) );
    node *root2 = new node(5, new node(1) , new node(8) );
    print_merge(root1,root2);
    cout<<"\n";
    inorder(root1);
    cout<<"\n";
    inorder(root2);
    cout<<"\n";
    return 0;
}


// The function to print data of two BSTs in sorted order
// void  merge(struct node *root1, struct node *root2)
// {
//     // s1 is stack to hold nodes of first BST
//     struct snode *s1 = NULL;
 
//     // Current node of first BST
//     struct node  *current1 = root1;
 
//     // s2 is stack to hold nodes of second BST
//     struct snode *s2 = NULL;
 
//     // Current node of second BST
//     struct node  *current2 = root2;
 
//     // If first BST is empty, then output is inorder
//     // traversal of second BST
//     if (root1 == NULL)
//     {
//         inorder(root2);
//         return;
//     }
//     // If second BST is empty, then output is inorder
//     // traversal of first BST
//     if (root2 == NULL)
//     {
//         inorder(root1);
//         return ;
//     }
 
//     // Run the loop while there are nodes not yet printed.
//     // The nodes may be in stack(explored, but not printed)
//     // or may be not yet explored
//     while (current1 != NULL || !isEmpty(s1) ||
//           current2 != NULL || !isEmpty(s2))
//     {
//         // Following steps follow iterative Inorder Traversal
//         if (current1 != NULL || current2 != NULL )
//         {
//             // Reach the leftmost node of both BSTs and push ancestors of
//             // leftmost nodes to stack s1 and s2 respectively
//             if (current1 != NULL)
//             {
//                 push(&s1, current1);
//                 current1 = current1->left;
//             }
//             if (current2 != NULL)
//             {
//                 push(&s2, current2);
//                 current2 = current2->left;
//             }
 
//         }
//         else
//         {
//             // If we reach a NULL node and either of the stacks is empty,
//             // then one tree is exhausted, ptint the other tree
//             if (isEmpty(s1))
//             {
//                 while (!isEmpty(s2))
//                 {
//                     current2 = pop (&s2);
//                     current2->left = NULL;
//                     inorder(current2);
//                 }
//                 return ;
//             }
//             if (isEmpty(s2))
//             {
//                 while (!isEmpty(s1))
//                 {
//                     current1 = pop (&s1);
//                     current1->left = NULL;
//                     inorder(current1);
//                 }
//                 return ;
//             }
 
//             // Pop an element from both stacks and compare the
//             // popped elements
//             current1 = pop(&s1);
//             current2 = pop(&s2);
 
//             // If element of first tree is smaller, then print it
//             // and push the right subtree. If the element is larger,
//             // then we push it back to the corresponding stack.
//             if (current1->data < current2->data)
//             {
//                 printf("%d ", current1->data);
//                 current1 = current1->right;
//                 push(&s2, current2);
//                 current2 = NULL;
//             }
//             else
//             {
//                 printf("%d ", current2->data);
//                 current2 = current2->right;
//                 push(&s1, current1);
//                 current1 = NULL;
//             }
//         }
//     }
// }