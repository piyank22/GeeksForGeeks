#include <iostream>
#include <cmath>
#include <bitset>
#include <queue>
#include <vector>
#include <map>

using namespace std;

struct node
{
	int d;
	node *left;
	node *right;
	node *parent;
	node(int d=0,node *l=NULL,node *r=NULL, node *p=NULL) : d(d) , left(l) , right(r) , parent(p) { }
};

node *insert(node *a,int key)
{
	if (a==NULL)
		return new node(key);
	if(key < a->d)
	{
		a->left=insert(a->left,key);
		a->left->parent=a;	
	}
	else if(key > a->d)
	{
		a->right=insert(a->right,key);
		a->right->parent=a;
	}
	return a;
}

node* LCA(node *n1,node *n2)
{
	map <node*,bool> ancestors;

	while(n1)
	{
		ancestors[n1]=true;
		n1=n1->parent;
	}

	while(n2)
	{
		if(ancestors.find(n2) != ancestors.end() )
			break;
		n2=n2->parent;
	}
	return n2;
}

int main()
{
	node *root=NULL;

    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);

    node *n1 = root->right;
    node *n2 = root->left->right->left;
    node *lca = LCA(n1, n2);

    printf("LCA of %d and %d is %d \n", n1->d, n2->d, lca->d);

    return 0;


}

/*

The above solution requires extra space because we need to use a hash table to store visited ancestors. We can solve the problem in O(1) extra space using following fact :
If both nodes are at same level and if we traverse up using parent pointers of both nodes, the first common node in the path to root is lca.
The idea is to find depths of given nodes and move up the deeper node pointer by the difference between depths. Once both nodes reach same level,
traverse them up and return the first common node.

// C++ program to find lowest common ancestor using parent pointer

int depth(Node *node)
{
    int d = -1;
    while (node)
    {
        ++d;
        node = node->parent;
    }
    return d;
}

// To find LCA of nodes n1 and n2 in Binary Tree
Node *LCA(Node *n1, Node *n2)
{
    // Find depths of two nodes and differences
    int d1 = depth(n1), d2 = depth(n2);
    int diff = d1 - d2;

    // If n2 is deeper, swap n1 and n2
    if (diff < 0)
    {
        Node * temp = n1;
        n1 = n2;
        n2 = temp;
        diff = -diff;
    }

    // Move n1 up until it reaches the same level as n2
    while (diff--)
        n1 = n1->parent;

    // Now n1 and n2 are at same levels
    while (n1 && n2)
    {
        if (n1 == n2)
            return n1;
        n1 = n1->parent;
        n2 = n2->parent;
    }

    return NULL;
}

// Driver method to test above functions
int main(void)
{
    Node * root = NULL;

    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);

    Node *n1 = root->left->right->left;
    Node *n2 = root->right;

    Node *lca = LCA(n1, n2);
    printf("LCA of %d and %d is %d \n", n1->key, n2->key, lca->key);

    return 0;
}

*/