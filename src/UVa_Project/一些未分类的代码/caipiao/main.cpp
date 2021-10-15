#include "stdio.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MM 7
#define NN 36
typedef int ElemTp;
typedef struct
{ ElemTp elem[MM+1];
    int len;
} VoteTp;
typedef struct
{ ElemTp elem[NN+1];
    int len;
} SourceTp;
SourceTp source;

void InitializeVote(VoteTp *vote);
void InitializeSource(SourceTp *source);
void SeqInsertVote(VoteTp *vote,int i,ElemTp x);
int SeqLocate(VoteTp v,ElemTp x);
VoteTp CreateAVote();
int RightNum(VoteTp vote,VoteTp answervote);

int main( )
{
    VoteTp vote;
    VoteTp answervote;
    int k,i;
    InitializeSource(&source);
    /* 初始化备选数表Source：放入3 6个数，将表长置为3 6 */
    answervote=CreateAVote(); /*   生成一组中奖号码 */
    printf("\n Press Any Key to continue ,0 to exit !");
    printf("\n 中奖号码: ");
    for (i=1;i<=MM;i++)
        printf("%3d ",answervote.elem[i]);
    printf("\n 你的彩票编码:\n");
    while (getchar()!='0')
    {
        vote=CreateAVote();
        for (i=1;i<=MM;i++)
            printf("  %-2d  ",vote.elem[i]);
        k=RightNum(vote,answervote);
        printf("  ---->>  %d \n",k);
    }
}

void InitializeVote(VoteTp *vote)
{
    vote->len=0;
}

void InitializeSource(SourceTp *Source)
{/* 初始化备选数表Source，在表中放入1～3 6共3 6个数，将表长置为36 */
    int i;
    for(i=1;i<=NN;i++)
        Source->elem[i]=i;
    Source->len=NN;
}

int SeqLocate(VoteTp v,ElemTp x)
{/* 在顺序表v中查找值为x的元素，返回该元素的位置序号，没有时返回0 */
    for (int i = 0;i < v.len;i++){
        if (v.elem[i] == x){
            return i;
        }
    }

    return 0;
}

void SeqInsertVote(VoteTp *vote,int i,ElemTp x)
{/* 在顺序表*p的第i个数据元素之前插入数据元素x */
    VoteTp v;
    v=*vote;
    if((i<1)||(i>v.len+1))
        printf(" error number!");
    else
    {
        v.len++;
        for (int j = v.len;j >=i -1;j--){
            v.elem[j+1] = v.elem[j];
        }

        v.elem[i] = x;
    }
    *vote=v;
}

VoteTp CreateAVote()  /* 生成一张彩票vote*/
{
    VoteTp vote;
    ElemTp k,temp;
    int i;
    InitializeVote(&vote);
    source.len=NN;    /*初始化备选数表source*/
    for(i=1;i<=MM;i++)
    {
        srand( (unsigned)time( NULL ) );
//设置随机数种子，使得每次产生不同的随机数列
        k= rand() % source.len+1;
//生成一个1—36的随机数，通用k=rand（）%Max+1；表示生成1—Max间的随机数
        /* 将source.elem[k]插入到彩票号码表vote中 , 产生一个l到source.len的随机数k */
        SeqInsertVote(&vote,vote.len+1,source.elem[k]);
        /*将备选数表source中的第k个元素删掉，Source.el em[k]与source.elem[source.len]交换，将备选数表表长source.1en减l  */
        temp=source.elem[k];
        source.elem[k]=source.elem[source.len];
        source.elem[source.len]=temp;
        source.len=source.len-1;
    }
    return vote;
}

int RightNum(VoteTp vote,VoteTp answervote) /*判断彩票的中奖情况*/
{/* 一张彩票vote和中奖号码表answervote相比，求出并返回猜对的号码个数*/
    int i,k;
    k=0;
    for (i=1;i<=MM;i++)
        if(SeqLocate(vote,answervote.elem[i])>0)
            k++;
    return(k);
}
