#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

struct node
{
    char data;
    int freq;
    node* left;
    node* right;
    node(int d, char a='-' , node* l=NULL, node* r=NULL) : data(a) , freq(d) , left(l) , right(r) { } 
};

class minheap
{
public:
    vector< node* > arr;
    int heapsize;

    minheap(int a[] , char b[] , int s) : heapsize(s) , arr(heapsize+100)
    {
        for(int i=0;i<heapsize;i++)
            arr[i]= new node( a[i] , b[i] );
    }
    int left(int i) { return 2*i+1; }
    int right(int i) { return 2*i+2; }
    int parent(int i) { return (i-1)/2; }

    void heapify(int i)
    {
        int l=left(i);
        int r=right(i);
        int smallest = i;
        if(l<heapsize && arr[l]->freq < arr[smallest]->freq )
            smallest = l;
        if(r<heapsize && arr[r]->freq < arr[smallest]->freq )
            smallest = r;
        if(smallest != i)
        {
            swap(arr[smallest] , arr[i] );
            heapify(smallest);
        }
    }

    void build_min_heap()
    {
        for(int i=parent(heapsize-1) ; i>=0 ; i-- )
            heapify(i);
    }

    node* extract_min()
    {
        swap( arr[--heapsize],arr[0] );
        heapify(0);
        return arr[heapsize];
    }

    void decrease_key(int i , node* z)
    {
        if(arr[i]->freq <= z->freq )
            return;
        arr[i]=z;
        while( i!=0 && arr[parent(i)]->freq > arr[i]->freq )
        {
            swap(arr[parent(i)] , arr[i]);
            i=parent(i);
        }
    }

    void insert(node* z)
    {
        arr[heapsize++]=new node(INT_MAX);
        decrease_key(heapsize-1,z);
    }

    void print()
    {
        printf("\n\n");
        for(int i=0;i<heapsize;i++)
            cout << setw(11) << arr[i]->freq ;
    }
};

void print_height_wise_tree(node * root)
{
    printf("\n\n\n\n\n");
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while( !q.empty() )
    {
        node *temp = q.front();
        q.pop();
        if(temp==NULL)
        {
            printf("\n");
            if( q.empty() )
                return;
            else
                q.push(NULL);
        }
        else
        {
            printf("( %c : %d )", temp->data , temp->freq );
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    } 
}

void print_inorder(node *root)
{
    if(root==NULL)
        return;
    print_inorder(root->left);
    printf("( %c : %d )\t",root->data, root->freq );
    print_inorder(root->right);
}

void print_huffman_codes(node* root , int code[],int top=0)
{
    if(root->data == '-')
    {
        code[top]=0;
        print_huffman_codes( root->left , code ,top+1);
        code[top]=1;
        print_huffman_codes( root->right , code ,top+1);
    }
    else
    {
        cout<<root->data<<"\t: ";
        for(int i=0;i<top;i++)
            cout<<code[i];
        cout<<"\n";
    }
}

int main()
{
    int a[] = {1,1,2,3,5,8};
    char b[] = {'a','b','c','d','e','f'};
    int n=sizeof(a)/sizeof(int);
    minheap mh(a,b,n);
    mh.build_min_heap();
    mh.print();
    for(int i=0;i<n-1;i++)
    {
        node *z;
        node* x=mh.extract_min();
        node* y=mh.extract_min();
        z = new node(x->freq + y->freq,'-',x,y) ;
        mh.insert(z);
        mh.print();
    }
    node * root = mh.extract_min();
    print_height_wise_tree(root);
    printf("\n\n\n\n");
    print_inorder(root);

    cout<<"\n\n\nNow finalling printing the final huffman codes:\n\n";
    int code[100];
    print_huffman_codes(root,code);
    return 0;
}
