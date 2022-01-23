/*
\brief: Ackermann Recursion Algorithm 

@params: m,n Ackermann function Parameters

@return: Ackermann function result

\details: This function will calculate the value of the function recursively, 
generally up to a maximum of m:4,n:2.

\Additions:
// Baidu Baike : https://baike.baidu.com/item/阿克曼函数/10988285?fr=aladdin
// Ackermann函数定义如下：　若m=0，返回n+1。
// 若m>0且n=0，返回Ackermann(m-1,1)。
// 若m>0且n>0，返回Ackermann(m-1,Ackermann(m,n-1))。
*/

int ackermann(int m,int n){
    // If m=0, n+1 is returned.
    if (m == 0){
        return n + 1;
    }
    //If m>0 && n=0, return Ackermann(m-1,1).
    if (m > 0 && n == 0){
        return ackermann(m-1 , 1);
    }
    //If m>0 && n>0, return Ackermann(m-1,Ackermann(m,n-1)).
    return ackermann(m-1,ackermann(m,n-1));
}