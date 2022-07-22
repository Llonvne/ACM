#include "bits/stdc++.h"
using namespace std;

// 打印排列
void print_permutation(int n, int* A, int cur){

    // 如果处理到尾部，直接打印结果，结束递归
	if (cur == n) {
		for (int i = 0; i < n; ++i) {
			printf("%d ", A[i]);
		}
		printf("\n");
	}
    // 否则
	else {
        // 找到一个不在A[cur]的数字，将其放在A[cur]的位置
		for (int i = 1; i <= n; ++i) {
			bool notChosen = true;
			for (int j = 0; j < cur; ++j) {
				if (A[j] == i) {
					notChosen = false;
				}
			}
			if (notChosen) {
				A[cur] = i;
				print_permutation(n, A, cur + 1);
			}
		}
	}
}