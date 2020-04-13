#include <bits/stdc++.h>
using namespace std;

class Twitter
{
    struct Node
    {
        // 哈希表存储关注人的 Id
        unordered_set<int> followee;
        // 用链表存储 tweetId
        list<int> tweet;
    };
    // getNewsFeed 检索的推文的上限以及 tweetId 的时间戳
    int recentMax, time;
    // tweetId 对应发送的时间
    unordered_map<int, int> tweetTime;
    // 每个用户存储的信息
    unordered_map<int, Node> user;

public:
    Twitter()
    {
        time = 0;
        recentMax = 10;
        user.clear();
    }

    // 初始化
    void init(int userId)
    {
        user[userId].followee.clear();
        user[userId].tweet.clear();
    }

    void postTweet(int userId, int tweetId)
    {
        if (user.find(userId) == user.end())
        {
            init(userId);
        }
        // 达到限制，剔除链表末尾元素
        if (user[userId].tweet.size() == recentMax)
        {
            user[userId].tweet.pop_back();
        }
        user[userId].tweet.push_front(tweetId);
        tweetTime[tweetId] = ++time;
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> ans;
        ans.clear();
        for (list<int>::iterator it = user[userId].tweet.begin(); it != user[userId].tweet.end(); ++it)
        {
            ans.emplace_back(*it);
        }
        for (int followeeId : user[userId].followee)
        {
            if (followeeId == userId)
                continue; // 可能出现自己关注自己的情况
            vector<int> res;
            res.clear();
            list<int>::iterator it = user[followeeId].tweet.begin();
            int i = 0;
            // 线性归并
            while (i < (int)ans.size() && it != user[followeeId].tweet.end())
            {
                if (tweetTime[(*it)] > tweetTime[ans[i]])
                {
                    res.emplace_back(*it);
                    ++it;
                }
                else
                {
                    res.emplace_back(ans[i]);
                    ++i;
                }
                // 已经找到这两个链表合起来后最近的 recentMax 条推文
                if ((int)res.size() == recentMax)
                    break;
            }
            for (; i < (int)ans.size() && (int)res.size() < recentMax; ++i)
                res.emplace_back(ans[i]);
            for (; it != user[followeeId].tweet.end() && (int)res.size() < recentMax; ++it)
                res.emplace_back(*it);
            ans.assign(res.begin(), res.end());
        }
        return ans;
    }

    void follow(int followerId, int followeeId)
    {
        if (user.find(followerId) == user.end())
        {
            init(followerId);
        }
        if (user.find(followeeId) == user.end())
        {
            init(followeeId);
        }
        user[followerId].followee.insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        user[followerId].followee.erase(followeeId);
    }
};
