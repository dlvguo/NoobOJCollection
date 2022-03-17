#include <bits/stdc++.h>
using namespace std;
struct Node {
    string s;
    int v;
    Node *pre, *nxt;
    Node(string s):s(s), v(0), pre(nullptr), nxt(nullptr) {};
};

class AllOne {
    vector<pair<Node*, Node*>> mp1;
    map<string, Node*> mp2;
    Node *head, *tail;
public:
    AllOne():mp1(50002) {
        head = mp1[0].second = new Node("");
        tail = mp1.back().first = new Node("");
        head->nxt = tail;
        tail->pre = head;
    }
    // 将 it 节点插入 tar 节点后面
    void insert(Node *it, Node *tar) {
        it->nxt = tar->nxt;
        it->pre = tar;
        it->nxt->pre = it->pre->nxt = it;
        auto &[a, b] = mp1[it->v];
        if (!a && !b) {
            a = b = it;
        } else {
            a = it;
        }
    }
    // 将 it 节点从双向链表中删除
    void erase(Node *it) {
        it->pre->nxt = it->nxt;
        it->nxt->pre = it->pre;
        auto &[a, b] = mp1[it->v];
        if (a == it && b == it) {
            a = b = nullptr;
        } else if (a == it) {
            a = it->nxt;
        } else if (b == it) {
            b = it->pre;
        }
    }
    void inc(string key) {
        Node *cur = mp2.count(key) ? mp2[key] : new Node(key);
        if (cur->v) {
            erase(cur);
            cur->v++;
            if (mp1[cur->v - 1].second) {
                insert(cur, mp1[cur->v - 1].second);
            } else {
                insert(cur, cur->pre);
            }
        } else {
            mp2[key] = cur;
            cur->v++;
            insert(cur, head);
        }
    }
    
    void dec(string key) {
        Node *cur = mp2[key];
        erase(cur);
        if (cur->v == 1) {
            mp2.extract(key);
            delete cur;
        } else {
            cur->v--;
            if (mp1[cur->v].first) {
                insert(cur, mp1[cur->v].first->pre);
            } else {
                insert(cur, cur->pre);
            }
        }
    }
    
    string getMaxKey() {
        return tail->pre->s;
    }
    
    string getMinKey() {
        return head->nxt->s;
    }
};