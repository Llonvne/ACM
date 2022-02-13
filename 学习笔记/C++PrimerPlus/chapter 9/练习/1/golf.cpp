//
// Created by 华邵钶 on 2022/2/13.
//

#include "golf.h"
#include <cstring>
#include <iostream>

void setgolf(golf & g, const char * name, int hc)
{
    strcpy(g.fullname, name);
    handicap(g,hc);
}

int setgolf(golf & g){
    {
        using std::getline;
        using std::cin;
        using std::cout;
        using std::endl;

        golf buffer;
        cout << "Enter you fullname: ";
        while (!(cin.getline(buffer.fullname,Len))){
            cout << "Enter error,please re-enter!" << endl;
            cin.clear();
            while(cin.get() != '\n'){};
        }
        cout << "Enter you handicap: ";
        while (!(cin >> buffer.handicap)){
            cout << "Enter error,please re-enter!" << endl;
            cin.clear();
            while(cin.get() != '\n'){};
        }
        setgolf(g,buffer.fullname, buffer.handicap);
        return 0;
    }
}

void handicap(golf & g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf & g)
{
    using std::cout;
    using std::endl;

    cout << "You fullname: " << g.fullname << endl;
    cout << "You handicap: " << g.handicap << endl;
}
