#include <bits/stdc++.h>
using namespace std;

class Iterator
{
    struct Data;
    Data *data;

public:
    Iterator(const vector<int> &nums);
    Iterator(const Iterator &iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator
{
public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums)
    {
        flag = Iterator::hasNext();
        if (flag)
        {
            nextElement = Iterator::next();
        }
    }

    int peek()
    {
        return nextElement;
    }

    int next()
    {
        int ret = nextElement;
        flag = Iterator::hasNext();
        if (flag)
        {
            nextElement = Iterator::next();
        }
        return ret;
    }

    bool hasNext() const
    {
        return flag;
    }

private:
    int nextElement;
    bool flag;
};
