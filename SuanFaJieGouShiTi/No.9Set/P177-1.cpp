#include <iostream>
using namespace std;

//建立Hash Table Hash函数为%m
typedef struct HashTable
{
    int *data, len;
};

void HashHanShu(HashTable &t, int key)
{
    int temp = key % t.len;
    while (t.data[temp])
    {
        temp = temp == t.len - 1 ? 0 : temp + 1;
    }
    t.data[temp] = key;
}

void CreateHashTable(int a[], int m)
{
    HashTable h;
    h.len = m;
    h.data = new int[m];
    for (int i = 1; i < =m; i++)
    {
        HashHanShu(h,a[i]);
    }
}