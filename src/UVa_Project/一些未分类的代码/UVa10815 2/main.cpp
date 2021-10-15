#include "bits/stdc++.h"
using namespace std;

int main(){
    set<string> dict;

    string buffer;
    while(cin >> buffer){

        if (buffer == "quit"){
            break;
        }

        transform(buffer.begin(),buffer.end(),buffer.begin(),::tolower);

        for (auto p = 0;p < buffer.size(); p++){
            if (buffer[p] < 'a' || buffer[p] > 'z'){
                buffer[p] == ' ';
            }
        }
        dict.insert(buffer);
    }

    for (auto & p : dict){
        cout << p << endl;
    }
}