#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <stack>
 
using namespace std;

struct node
{
    string key;
    node *left,*right;
    node(string d, node* l=NULL , node *r=NULL): key(d) , left(l) , right(r){}
};

string getpre(node *tree)
{
    if(tree==NULL)
        return "$";
    return tree->key+getpre(tree->left)+getpre(tree->right);
}

string getin(node *tree)
{
    if(tree==NULL)
        return "$";
    return getin(tree->left)+tree->key+getin(tree->right);
}

int main()
{
    node *tree=new node("a",new node("b",new node("c")),new node("d",NULL,new node("e")));
    node *subtree=new node("b",new node("c"));
    string pretree=getpre(tree),intree=getin(tree),presub=getpre(subtree),insub=getin(subtree);

    cout<<"\n"<<pretree<<"\t"<<presub;
    cout<<"\n"<<intree<<"\t"<<insub;

    cout<<"\n\n";

    if(pretree.find(presub)!=string::npos && intree.find(insub)!=string::npos)
        cout<<"Found";
    else
        cout<<"NOT found";
    return 0;
}
