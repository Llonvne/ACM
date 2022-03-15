// 输入： 数组A 数组长度n
void insertion_sort(int A[], int n)
{
    for (int i = 1; i < n; i++) // 从第二个开始处理
    {
        int key = A[i]; // 将待插入的元素赋值 key
        // 将 key 插入前面 [0,i)
        for (int j = i - 1; i >= 0; j--)
        {
            if (A[j] > key) // 插入元素小于被插入元素，即还需要往前面找
            {
                A[j + 1] = A[j]; // 把A[j] -> A[j+1] ,因为 A[i] 已经被备份到 key
                // 所以这种操作是安全的
            }
            else
            { // 一旦 key > A[j] 说明找到了插入位置
                A[j+1] = key; // 此时 A[j+1] == A[j+2] 所以这种赋值也是安全的
                break;
            }
        }
    }
}
#ifdef TEST
// 测试实例
#include <iostream>
using namespace std;
int main(){
    int a[] = {1,23,45,34,123123,346,34,6};
    insertion_sort(a,8);
    for (int i = 0; i < 8; i++)
    {
        cout << a[i] << " ";
    }
}
#endif