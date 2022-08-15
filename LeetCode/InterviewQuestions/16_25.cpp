#include <bits/stdc++.h>
using namespace std;
class LRUCache
{
public:
    typedef struct linknode
    {
        linknode *pre = NULL, *next = NULL;
        int val, key;

        linknode(int _key, int _val) : key(_key), val(_val)
        {
        }

    } * LinkNode;

    unordered_map<int, LinkNode> _map;

    int cap;

    LinkNode head;
    LRUCache(int capacity)
    {
        cap = capacity;
        head = new linknode(0, 0);
        head->pre = head;
        head->next = head;
    }

    int get(int key)
    {
        if (_map.find(key) == _map.end())
            return -1;
        // 调整位置
        LinkNode node = _map[key];
        node->pre->next = node->next;
        node->next->pre = node->pre;
        node->next = head->next;
        head->next->pre = node;
        node->pre = head;
        head->next = node;
        return node->val;
    }

    void put(int key, int value)
    {
        // 先找key 有没有存在
        if (_map.find(key) == _map.end())
        {
            LinkNode node = new linknode(key, value);
            // 判断有没有超出
            LinkNode tail = head->pre;
            //新插入的时候是插在头节点 !!!
            if (_map.size() == cap)
            {
                _map.erase(tail->key);

                tail->pre->next = head;
                head->pre = tail->pre;
                delete tail;
            }

            head->next->pre = node;
            node->next = head->next;
            node->pre = head;
            head->next = node;
            _map[key] = node;
        }
        else
        {
            // 更新值
            LinkNode node = _map[key];
            node->val = value;

            node->pre->next = node->next;
            node->next->pre = node->pre;
            node->next = head->next;
            head->next->pre = node;
            node->pre = head;
            head->next = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */