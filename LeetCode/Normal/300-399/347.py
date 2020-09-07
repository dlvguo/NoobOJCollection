class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        Hash = {}
        for i in nums:
            Hash[i] = Hash.get(i, 0) + 1
        keyvalues = sorted(Hash.items(), key = lambda x: (x[1], x[0]), reverse=True)
        return [keyvalues[j][0] for j in range(k)]

