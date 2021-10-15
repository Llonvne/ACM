#include "bits/stdc++.h"

using namespace std;

struct word {
    string encrypted,decryption;

    vector<int> encrypted_Hashcode,decryption_Hashcode;
};

void initHashCode(word& w){
    w.encrypted_Hashcode.resize(26);
    w.decryption_Hashcode.resize(26);

    for (int i = 0; i < 26; ++i) {
        w.encrypted_Hashcode.push_back(0);
        w.decryption_Hashcode.push_back(0);
    }
}

void transferWordToHashCode(word& w){

    for(int i = 0; i < w.encrypted.size(); i++){
        char letterBuffer = w.encrypted[i];
        w.encrypted_Hashcode[letterBuffer - 'A']++;
    }

    for(int i = 0; i < w.decryption.size(); i++){
        char letterBuffer = w.decryption[i];
        w.decryption_Hashcode[letterBuffer - 'A']++;
    }

    sort(w.encrypted_Hashcode.begin(), w.encrypted_Hashcode.end());
    sort(w.decryption_Hashcode.begin(),w.decryption_Hashcode.end());
}


int main() {
    word w;
    while(cin >> w.encrypted >> w.decryption){
        initHashCode(w);
        transferWordToHashCode(w);
        if (w.encrypted_Hashcode == w.decryption_Hashcode){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}