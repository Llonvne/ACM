#include "bits/stdc++.h"
using namespace std;

#define MAX_NUMBER_OF_DOCUMENT 105
#define MAXIMUM_ROW_WIDTH 60
int main(){

    int numberOfDocument = 0;
    while(cin >> numberOfDocument && numberOfDocument){

        string nameOfDocument[MAX_NUMBER_OF_DOCUMENT];
        int maxLengthOfNameOFDocument = 0;
        for (int i = 0; i < numberOfDocument;i++){
            cin >> nameOfDocument[i];
            if (nameOfDocument[i].length() > maxLengthOfNameOFDocument){
                maxLengthOfNameOFDocument = (int)nameOfDocument[i].length();
            }
        }
        sort(nameOfDocument,nameOfDocument + numberOfDocument);

        printf("%s\n", string(60,'-').c_str());

        // 计算行数和列数
        int widthOfLastColumn = maxLengthOfNameOFDocument;
        int widthOfNotLastColumn = widthOfLastColumn + 2;

        int remainingWidthDividingfLastColumn = MAXIMUM_ROW_WIDTH - widthOfLastColumn;
        int totalColumns = 1 + remainingWidthDividingfLastColumn / widthOfNotLastColumn;
        int totalRows = numberOfDocument / totalColumns;

        for (int i = 0; i < totalRows; ++i) {//输出R行
            for (int j = 0; j < totalColumns; ++j) {//每行输出C列
                if (i + j * totalRows >= numberOfDocument)
                    continue;
                printf("%s", nameOfDocument[i + j * totalRows].c_str());
                int len = (j == totalColumns - 1) ? maxLengthOfNameOFDocument : maxLengthOfNameOFDocument + 2;
                for (int k = 0; k < len - nameOfDocument[i + j * totalRows].size(); ++k)
                    printf(" ");
            }
            puts("");//换行
        }
    }
}

