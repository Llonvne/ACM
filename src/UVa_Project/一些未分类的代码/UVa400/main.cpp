#include "bits/stdc++.h"
using namespace std;

#define MAX_DOCUMENT_COUNT 105

void printLine(){
    printf("------------------------------------------------------------\n");
}

void getDocument(string document[],int documentCount){
    for (int i = 0; i < documentCount; ++i) {
        cin >> document[i];
    }
}

int GetLengthOfLongestFile(string document[],int documentCount){
    int maxLength = 0;
    for (int i = 0; i < documentCount; ++i) {
        if (document[i].length() > maxLength){
            maxLength = (int)document[i].length();
        }
    }
}

int main() {

    int documentCount;

    while(cin >> documentCount){

        printLine();

        string document[MAX_DOCUMENT_COUNT];
        getDocument(document,documentCount);

        int maxLength = GetLengthOfLongestFile(document,documentCount);
        int rightmostColumnWidth = maxLength;
        int otherColumnWidth = maxLength+2;



        printLine();
    }
}
