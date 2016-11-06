#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

void printItinerary(map<string,string> dataSet)
{
    map<string,string> revMap;
    map<string,string>::iterator it;
    for(it=dataSet.begin() ; it!=dataSet.end() ; it++)
        revMap[it->second]=it->first;
    string start;
    for(it=dataSet.begin() ; it!=dataSet.end() ; it++)
        if(revMap.find(it->first)==revMap.end())
        {
            start=it->first;
            break;
        }
    if(start.empty())
    {
        cout<<"\nInvalid Input\n";
        return;
    }
    while(it!=dataSet.end())
    {
        cout<<it->first<<"->"<<it->second<<" , ";
        it=dataSet.find(it->second);
    }
    cout<<"trip end\n";
}

int main()
{
    map<string, string> dataSet;
    dataSet["Chennai"] = "Banglore";
    dataSet["Bombay"] = "Delhi";
    dataSet["Goa"] = "Chennai";
    dataSet["Delhi"] = "Goa";
 
    printItinerary(dataSet);
 
    return 0;
}