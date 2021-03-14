#include <bits/stdc++.h>
using namespace std;
class MyHashMap
{
private:
    vector<list<pair<int, int>>> data;
    static const int base = 769;
    static int hash(int key)
    {
        return key % base;
    }

public:
    /** Initialize your data structure here. */
    MyHashMap() : data(base) {}

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++)
        {
            if ((*it).first == key)
            {
                (*it).second = value;
                return;
            }
        }
        data[h].push_back(make_pair(key, value));
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++)
        {
            if ((*it).first == key)
            {
                return (*it).second;
            }
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++)
        {
            if ((*it).first == key)
            {
                data[h].erase(it);
                return;
            }
        }
    }
};
