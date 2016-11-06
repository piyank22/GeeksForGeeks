#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <cstring>

using namespace std;

bool isbalanced(char s[])
{
    stack <char> st;
    for(int i=0;i<strlen(s);i++)
        if(s[i]=='{'||s[i]=='['||s[i]=='(')
            st.push(s[i]);
        else
        {
            if(st.empty())
                return false;
            else
            {
                char t=st.top();
                char c=s[i];
                st.pop();
                if(c=='}' && t!='{')
                    return false;
                else if(c==']' && t!='[')
                    return false;
                else if(c==')' && t!='(')
                    return false;
            }
        }
    return true;
}

int main()
{
    //code
    int n;
    cin>>n;
    while(n)
    {
        n--;
        char s[101];
        cin>>s;
        printf("%s\n",(isbalanced(s)?"balanced":"not balanced"));
    }
    return 0;
}