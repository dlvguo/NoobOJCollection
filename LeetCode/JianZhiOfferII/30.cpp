#include <iostream>
#include <unordered_map>
#include <cstdlib>
#include <vector>
using namespace std;
class RandomizedSet
{
public:
    unordered_map<int, int> num_idx;
    vector<int> nums;

    /** Initialize your data structure here. */
    RandomizedSet()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (num_idx.find(val) != num_idx.end())
            return false;
        num_idx[val] = (int)nums.size();
        nums.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (num_idx.find(val) == num_idx.end())
            return false;
        int idx = num_idx[val];
        int last_num = nums.back();
        nums[idx] = last_num;
        num_idx[last_num] = idx;
        num_idx.erase(val);
        nums.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        int idx = rand() % (int)nums.size();
        return nums[idx];
    }
};
