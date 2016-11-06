#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>

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

void level_order(node *tree)
{
    queue<node*> q;
    q.push(tree);
    q.push(NULL);
    while(!q.empty())
    {
        node *t=q.front();
        q.pop();
        if(t!=NULL)
        {
            cout<<"\t"<<t->data;
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }
        else
            if(q.front()==NULL)
            {
                cout<<"\nFinished\n";
                break;
            }
            else
            {
                cout<<"\n";
                q.push(NULL);
            }
    }
}

void inorder(node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}

void convert_to_vector(node *a, vector<int> &v)
{
    if(a==NULL)
        return;
    convert_to_vector(a->left,v);
    v.push_back(a->data);
    convert_to_vector(a->right,v);
    return;
}

vector<int> merge_vectors(vector<int> a, vector<int> b)
{
    vector<int> c;
    int i=0,j=0;
    while( i < a.size() && j < b.size() )
    {
        if(a[i]>b[j])
            c.push_back(b[j++]);
        else if(a[i]<b[j])
            c.push_back(a[i++]);
        else
        {
            i++;
            c.push_back(b[j++]);
        }
    }
    while(i<a.size())
        c.push_back(a[i++]);
    while(j<b.size())
        c.push_back(b[j++]);
    return c;
}

node* vector_to_bst(vector<int> &a, int n, int i=0)
{
    if(i>n)
        return NULL;
    else if(i==n)
        return new node(a[i]);
    else
    {
        int mid=(i+n)/2;
        return new node(a[mid],vector_to_bst(a,mid-1,i),vector_to_bst(a,n,mid+1));
    }
}

node* merge(node *a, node *b)
{
    vector<int> aa;
    convert_to_vector(a,aa);

    vector<int> bb;
    convert_to_vector(b,bb);

    vector<int> cc=merge_vectors(aa,bb);

    // for(int i=0;i<cc.size();i++)
    //     cout<<"\t"<<cc[i];
    // cout<<"\n";
    return vector_to_bst(cc,cc.size()-1);
    //return NULL;
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

    node *r=NULL;
    insert(r,21);
    insert(r,13);
    insert(r,26);

    node *merge_tree=merge(root,r);

    level_order(merge_tree);
    printf("\n\n\n");
    inorder(merge_tree);

    return 0;
}