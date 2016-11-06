#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int sa, node *a=NULL, node *b=NULL) : data(sa) , left(a) , right(b) { }
};

void insert(node *&root , int data)
{
    if(root==NULL)
        root=new node(data);
    else if (root->data < data)
        insert(root->right , data);
    else
        insert(root->left , data);
}

void inorder_without_rec(node *root)
{
    if(root==NULL)
        return;
    stack<node*> st;
    node *current=root;
    while(current!=NULL || !st.empty())
    {
        while(current)
        {
            st.push(current);
            current=current->left;
        }
        if(!st.empty())
        {
            node *temp=st.top();
            st.pop();
            cout<<"\t"<<temp->data;
            current=temp->right;
        }
    }
    cout<<"\nDONE\n";
    return;
}

// bool isSUMpresent(node *root, int sum)
// {
//     if(root==NULL)
//         return false;
//     node *c1,*c2;
//     c1=c2=root;
//     stack<node*> s1,s2;
//     while(c1 || c2 || !s1.empty() || !s2.empty() )
//     {
//         while(c1)
//         {
//             s1.push(c1);
//             c1=c1->left;
//         }
//         while(c2)
//         {
//             s2.push(c2);
//             c2=c2->right;
//         }
//         if( !s1.empty() && !s2.empty() )
//         {
//             node *t1,*t2;
//             t1=s1.top();
//             t2=s2.top();
//             if(t1==t2)
//                 return false;
//             // if(t1 && t2)
//             //     printf("%d , %d\n", t1->data , t2->data );
//             if(t1->data + t2->data == sum)
//             {
//                 printf("%d + %d = %d\n",t1->data,t2->data,sum);
//                 return true;
//             }
//             else if(t1->data + t2->data > sum)
//             {
//                 s2.pop();
//                 c2=t2->left;
//             }
//             else
//             {
//                 s1.pop();
//                 c1=t1->right;
//             }
//         }
//     }
//     return false;
// }

bool isSUMpresent(node *root , int sum)
{
    if(root==NULL)
        return false;

    stack<node*> s1,s2;
    node *c1 = root , *c2 = root;
    while( c1 || c2 || !s1.empty() || !s2.empty() )
    {
        while(c1)
        {
            s1.push(c1);
            c1 = c1->left;
        }

        while(c2)
        {
            s2.push(c2);
            c2 = c2->right;
        }

        if( !s1.empty() && !s2.empty() )
        {
            node *t1 , *t2;
            t1 = s1.top();
            t2 = s2.top();
            printf("%d + %d = %d\n",t1->data , t2->data , t1->data + t2->data );
            if(t1==t2)
                return false;
            if(t1->data + t2->data == sum )
            {
                //printf("%d + %d = %d\n",t1->data , t2->data , sum );
                return true;
            }
            else if( t1->data +t2->data > sum)
            {
                s2.pop();
                c2 = t2->left;
            }
            else
            {
                s1.pop();
                c1 = t1->right;
            }
        }
    }

    return false;
}

int main()
{
    node *root=NULL;
    insert(root, 15);
    insert(root, 10);
    insert(root, 20);
    insert(root, 8);
    insert(root, 12);
    insert(root, 16);
    insert(root, 25);
    if (isSUMpresent(root,16))
        printf("Present");
    else
        printf("Not Present");
    return 0;
}