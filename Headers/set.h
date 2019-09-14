#include <iostream>
using namespace std;

#pragma region //辅助检测部分

void DfsPrint(int n)
{
    if (n / 2)
        DfsPrint(n / 2);
    cout << n % 2;
}
//输出二进制
void PrintBin(int n)
{
    DfsPrint(n);
    cout << endl;
}
//计算二进制大小
int FigureBinCount(int n)
{
    int count = 0;
    while (n)
    {
        n /= 2;
        count++;
    }
    return count;
}

//创建数组
int *CreateBinarr(int size, int n)
{
    int binc = FigureBinCount(n);
    int *p = new int[size];
    for (int i = 0; i < size - binc; i++)
    {
        p[i] = 0;
    }
    int s = size;
    do
    {
        p[--size] = n % 2;
        n /= 2;
    } while (n);
    cout << "Creat Bin Arr:";
    for (int i = 0; i < s; i++)
        cout << p[i];
    cout << endl;
    return p;
}

void CreatDoubleArr(int *&ap, int a, int *&bp, int b)
{
    int acount = FigureBinCount(a), bcount = FigureBinCount(b), maxcount = acount > bcount ? acount : bcount;
    ap = CreateBinarr(maxcount, a);
    bp = CreateBinarr(maxcount, b);
}

//位&运算
void BitPrintAnd(int a, int b)
{
    int maxcount = FigureBinCount(a) > FigureBinCount(b) ? FigureBinCount(a) : FigureBinCount(b);
    int *ap, *bp;
    CreatDoubleArr(ap, a, bp, b);
    cout << "And Bin :";
    for (int i = 0; i < maxcount; i++)
    {
        if (ap[i] && bp[i])
            cout << "1";
        else
            cout << "0";
    }
    cout << endl;
}

//位或运算
void BitPrintOr(int a, int b)
{
    int maxcount = FigureBinCount(a) > FigureBinCount(b) ? FigureBinCount(a) : FigureBinCount(b);
    int *ap, *bp;
    CreatDoubleArr(ap, a, bp, b);
    cout << "Or Bin :";
    for (int i = 0; i < maxcount; i++)
    {
        if (ap[i] || bp[i])
            cout << "1";
        else
            cout << "0";
    }
    cout << endl;
}
//位异或运算
void BitPrintXor(int a, int b)
{
    int maxcount = FigureBinCount(a) > FigureBinCount(b) ? FigureBinCount(a) : FigureBinCount(b);
    int *ap, *bp;
    CreatDoubleArr(ap, a, bp, b);
    cout << "Xor Bin :";
    for (int i = 0; i < maxcount; i++)
    {
        if (ap[i] != bp[i])
            cout << "1";
        else
            cout << "0";
    }
    cout << endl;
}

#pragma endregion

#pragma region 集合部分
typedef struct set
{
    int size;//能存储元素大小
    int arraysize;//数组大小应该看类型 如v为 ushort应该一个数可以存16个 大小为arr/16+1||(size+15)
    unsigned short *v;
} Bitset, *Set;

//计算位置大小 除类型的大小 UShort为16 故要/16 按位的话/4即可
int ArrayIndex(int x){
    return x>>4;
}

//计算这个数在一个ushort里面所在的第几个位置 除16取余+1即可
//输入10二进制为1010为15 1111 &计算得1010表示10 之后右移
unsigned short BitMask(int x){
    return 1<<(x&15);
}

//初始化set
Set InitSet(int size)
{
    Set _set = new Bitset;
    _set->size = size;
    //一个US类型可以表示16个 故数组大小为1+size/16
    //书中这种向右移动4位的运算方式等同于/16
    _set->arraysize = (size+15)>>4;
    //书中v大小为size 个人认为有错,有不同意见的朋友欢迎探讨
    _set->v = new unsigned short[_set->arraysize];
    for (int i = 0; i < size; i++)
    {
        _set->v[i] = 0;
    }
    return _set;
}

//把B赋值给A
void SetAsign(Set A, Set B)
{
    if (A->size != B->size)
        return;
    for (int i = 0; i < A->size; i++)
    {
        A->v [i] = B->v[i];
    }
}

//检测元素是否存在
int SetMember(int x,Set set){
    if(x<0||x>set->size)
        return 0;
    //首先查找数组对应位置，与x相对的位置
    //如3 此时在数组第一个位置 BitMask值为1000 表示第4数，第1个为0
    return set->v[ArrayIndex(x)]&BitMask(x);
}

//判断集合是否相等一一判断
int SetEqual(Set A,Set B){
    if(A->size! B->size)
        return 0;
    for (int i = 0; i < A->arraysize; i++)
    {
        if(A->v[i]! B->v[i])
            return 0;
    }
    return 1;
}

//取并集  如A=1100 B=0110=>1110 此时第2、3、4个为并集
Set SetUnion(Set A,Set B){
    Set s=InitSet(A->size);
    for (int i = 0; i < s->arraysize; i++)
    {
        //按位|
        s->v[i]=A->v[i] B->v[i];
    }
}


//取交集  如A=1100 B=0100=>0100 此时第3个为交集
Set SetIntersection(Set A,Set B){
    Set s=InitSet(A->size);
    for (int i = 0; i < s->arraysize; i++)
    {
        //按位&
        s->v[i]=A->v[i] B->v[i];
    }
}

//取差集  如A=111000 B=001000=>取&为001000 再异或110000 此时第5.6个为差集
Set SetDifference(Set A,Set B){
    Set s=InitSet(A->size);
    for (int i = 0; i < s->arraysize; i++)
    {
        //按位& 再^
        s->v[i]=A->v[i]^(A->v[i] B->v[i]);
    }
}

//位插入运算 查找数组位置  找到x%16放置 用|运算
//如17插入，此时数组v[1]中为00100000，表示第七个位置有东西，17%16+1=2 |运算后v[1]为00100010
void SetInsert(int x,Set s){
    if(x<0||s->size<x)
        return;
    s->v[ArrayIndex(x)]|=BitMask(x);
}

//删除元素运算 先取反再去取&
//如删除17，此时数组v[1]中为00100010，表示第2、7个位置有东西，17%16+1=2 ~2取反为11111101 &运算后v[1]为00100000
void SetDelete(int x,Set s ){
     if(x<0||s->size<x)
        return;
     s->v[ArrayIndex(x)]&=~BitMask(x);
}

#pragma endregion