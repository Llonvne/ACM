#include "bits/stdc++.h"
using namespace std;
#define MAX_WORD_COUNT 1000

int wordCount = 0;
struct word{
    string origin;
    string lowerCase;

    vector<int> hashCode;

    bool repeated = false;
};
bool wordCompare(const word& a,const word& b){
    return a.origin < b.origin;
}
word w[MAX_WORD_COUNT];

void initHashcodeVector(vector<int>& hashCode){
    for (int i = 0; i < 26; ++i) {
        hashCode.push_back(0);
    }
}

void transferWordToHashcode(word& a){

    initHashcodeVector(a.hashCode);

    for (int i = 0;i < a.lowerCase.length();i++) {
        int letterIndex = a.lowerCase[i] - 'a';
        a.hashCode[letterIndex]++;
    }
}
void input(){
    string wordBuffer;
    while(cin >> wordBuffer){

        if (wordBuffer == "#"){
            return;
        }

        w[wordCount].origin = wordBuffer;
        transform(wordBuffer.begin(), wordBuffer.end(),wordBuffer.begin(),::tolower);
        w[wordCount].lowerCase = wordBuffer;

        transferWordToHashcode(w[wordCount]);
        wordCount++;
    }
}



int main(){
    wordCount = 0;
    input();

    for (int i = 0; i < wordCount; ++i) {
        for (int j = i+1; j < wordCount; ++j) {
            if (w[i].hashCode == w[j].hashCode){
                w[i].repeated = true;
                w[j].repeated = true;
            }
        }
    }

    sort(w,w + wordCount,wordCompare);
    for (int i = 0; i < wordCount; ++i) {
        if (!w[i].repeated){
            cout << w[i].origin << endl;
        }
    }
}
