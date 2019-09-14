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

//计算这个数在一个ushort里面所在的第几个位置 除16取余即可，之后向右移变能算出位置
unsigned short BitMask(int x){
    return 1<<(x&15);
}

//初始化set
Set InitSet(int size)
{
    Set _set = new Bitset;
    _set->size = size;
    _set->arraysize = (size+15)>>4;
    _set->v = new unsigned short[_set->arraysize];
    for (int i = 0; i < size; i++)
    {
        _set->v[i] = 0;
    }
    return _set;
}

//把a赋值给b
void SetAsign(Set a, Set b)
{
    if (a->size != b->size)
        return;
    for (int i = 0; i < a->size; i++)
    {
        b->v [i] = a->v[i];
    }
}

//检测元素是否存在
int SetMember(int x,Set set){
    if(x<0||x>set->size)
        return 0;
    //首先查找数组对应位置，与x相对的位置
    //如3 此时在数组第一个位置 BitMask值为1000 
    return set->v[ArrayIndex(x)]&BitMask(x);
}

//判断集合是否相等一一判断
int Equal(Set s1,Set s2){
    if(s1->size!=s2->size)
        return 0;
    for (int i = 0; i < s1->arraysize; i++)
    {
        if(s1->v[i]!=s2->v[i])
            return 0;
    }
    return 1;
}

//取并集  如s1=1100 s2=0100 此时第三个为并集
Set SetUnion(Set s1,Set s2){
    Set s=InitSet(s1->size);
    for (int i = 0; i < s->arraysize; i++)
    {
        //按位|
        s->v[i]=s1->v[i]|s2->v[i];
    }
}


//取交集  如s1=1100 s2=0100 此时第三个为并集
Set SetIntersection(Set s1,Set s2){
    Set s=InitSet(s1->size);
    for (int i = 0; i < s->arraysize; i++)
    {
        //按位&
        s->v[i]=s1->v[i]&s2->v[i];
    }
}

//取差集  如s1=1100 s2=0100 此时第三个为并集
Set SetDifference(Set s1,Set s2){
    Set s=InitSet(s1->size);
    for (int i = 0; i < s->arraysize; i++)
    {
        //按位& 再^
        s->v[i]=s1->v[i]^(s1->v[i]&s2->v[i]);
    }
}

//位插入运算 查找数组位置  找到x%16放置 用|运算
void SetInsert(int x,Set s){
    if(x<0||s->size<x)
        return;
    s->v[ArrayIndex(x)]|=BitMask(x);
}

//删除元素运算 先取反再去取
void SetDelete(int x,Set s ){
     if(x<0||s->size<x)
        return;
     s->v[ArrayIndex(x)]&=~BitMask(x);
}

#pragma endregion