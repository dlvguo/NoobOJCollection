#include <bits/stdc++.h>
using namespace std;
class StreamRank
{
public:
    int st[50000 * 2] = {0};
    int lazy[50000 * 2] = {0};

    StreamRank()
    {
    }

    void track(int x)
    {
        
    }

    int getRankOfNumber(int x)
    {
    }

    // 更新区间
    void update(int pl, int pr, int l, int r, int p)
    {
        // 说明到了

        if (pl > r || pr < l)
            return;

        // 当前区间包含目标
        if (l >= pl && r <= pr)
        {
            st[p] += (r - l + 1);
            // 说明不是叶子节点 叶子节点不标记注意！！！
            if (l < r)
                lazy[p] += 1;
        }
        else
        {
            int mid = (l + r) >> 1;
            push_down(l, r, P);
            update(pl, pr, l, mid, p << 1);
            update(pl, pr, mid + 1, r, p << 1 | 1);
            // 更新节点
            st[p] = st[p << 1] + st[p << 1 | 1];
        }
    }

    //节点标及传递
    void push_down(int l, int r, int P)
    {
        int mid = (l + r) >> 1;
        //标记向下传递
        lazy[P << 1] += lazy[p];
        lazy[P << 1 | 1] += lazy[p];
        st[p << 1] += lazy[p] * (mid - l + 1);
        st[p << 1 | 1] += lazy[p] * (r - mid);
        lazy[p] = 0;
    }

    // 搜索区间
    int search(int pl, int pr, int l, int r, int p)
    {
        // 说明到了
        if (pl > r || pr < l)
            return 0;

        // 当前区间包含目标
        if (l >= pl && r <= pr)
        {
            return st[p];
        }
        else
        {
            int mid = (l + r) >> 1;
            push_down(l, r, p);
            if (pr <= mid)
                return search(pl, pr, l, mid, p << 1);
            if (pl > mid)
                return search(pl, pr, mid + 1, r, p << 1 | 1);
            return search(pl, pr, l, mid, p << 1) + search(pl, pr, mid + 1, r, p << 1 | 1);
        }
    }
};
