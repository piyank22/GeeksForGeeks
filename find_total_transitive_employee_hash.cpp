#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

void print_vec( vector<string> v )
{
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<"\t";
    cout<<"\n";
}

int calculate( map< string, vector<string> > rev , map<string,int> &mc , string s)
{
    int temp=0;
    for(int i=0 ; i<rev[s].size() ; i++)
    {
        if( mc.find(rev[s][i]) != mc.end() )
            temp+=mc[rev[s][i]]+1;
        else
            temp+=calculate(rev,mc,rev[s][i]);
    }
    return temp;
}

void print_count(map<string,string> dataSet)
{
    map<string, vector<string> > rev;
    map<string, string>::iterator it;
    map<string, vector<string> >::iterator itt;
    for(it=dataSet.begin() ; it!=dataSet.end() ; it++ )
    {
        if ( rev.find(it->second) != rev.end() && it->first!=it->second )
            rev[it->second].push_back(it->first);
        else if(it->first != it->second)
        {
            vector<string> v;
            v.push_back(it->first);
            rev[it->second]= v;
        }
    }
    for( itt=rev.begin() ; itt!=rev.end() ; itt++ )
    {
        cout<<itt->first<<" : ";
        print_vec(itt->second);   
    }
    cout<<"\n";
    map<string,int> mc;
    for(it=dataSet.begin() ; it!=dataSet.end() ; it++ )
    {

        if ( mc.find(it->first) == mc.end() )
        {
            if( rev.find(it->first) == rev.end() )
                mc[it->first]=0;
            else
                mc[it->first]=calculate(rev, mc, it->first);
        }
        cout<<it->first<<" : "<<mc[it->first]<<"\n";
    }


}
int main()
{
    map<string, string> dataSet;
    dataSet["A"] = "C";
    dataSet["B"] = "C";
    dataSet["C"] = "F";
    dataSet["D"] = "E";
    dataSet["E"] = "F";
    dataSet["F"] = "F";
    print_count(dataSet);
    return 0;
}