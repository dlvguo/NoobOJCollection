class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        if not nums: return []
        
        sorted_nums = []
        ans = []
        for n in nums[::-1]:
            index = bisect.bisect_left(sorted_nums,n)
            bisect.insort(sorted_nums,n)
            ans.append(index)
        return ans[::-1]