#include<sstream>
#include <iostream>
#include <set>
using namespace std;
int main()
{
    string s,a;
    set<string>dict;
    while(getline(cin,s))
    {
        for(int i=0;i<s.length();i++)
            if(isalpha(s[i])) s[i]=tolower(s[i]);
            else s[i]=' ';
        stringstream ss(s);
        while(ss>>a)
            dict.insert(a);
    }
    for(set<string>::iterator it=dict.begin();it!=dict.end();it++)
        cout<<*it<<"\n";
    return 0;
}