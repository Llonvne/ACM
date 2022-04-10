#include "bits/stdc++.h"
using namespace std;

// 最大行数
const int MAX_LINE = 1005;
// 最大列数 也就是单词数
const int MAX_WORD = 1000;
// 定义 Vector 来存储每一行
vector<string> lines[MAX_LINE];
// 定义 Array 来存储每一列
array<int, MAX_WORD> columnWordMax{};

int main()
{
    string lineBuffer,word;
    int row = 0;
    // 输入到 lineBuffer
    while (getline(cin,lineBuffer)){
        // 通过 stringstream 分割每一个单词
        stringstream words(lineBuffer);

        // 从 stream 中提取单词到 word
        while (words >> word){
            // 获得单词所在列 也就是添加前一个单词后 行单词到数量
            int column = (int)lines[row].size(); 
            // 与列单词最大值比较 取大者
            columnWordMax[column] = max(columnWordMax[column],(int)word.size()); // 求出每一列的单词的最大值
            // 添加到 lines 内
            lines[row].push_back(word);
        }

        // 每次处理一个列，列好递增
        row ++;
    }

    // 循环每一个列
    for (int line = 0;line < row;line ++){
        // 循环每一个单词，也是列
        for (int column = 0;column < lines[line].size(); ++column) {
            // 如果不是最后一个，最后一个不需要打印
            if (column != lines[line].size() - 1){
                // 补上空缺的空格，使当前单词的长度为最大长度
                lines[line][column] += string(columnWordMax[column] - lines[line][column].size() + 1,' ');
            }
            // 打印
            printf("%s",lines[line][column].c_str());
        }
        printf("\n");
    }
}