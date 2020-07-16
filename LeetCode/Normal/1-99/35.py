class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if target>nums[-1]:
            return len(nums)
        l,r = 0, len(nums)-1
        ans = -1
        while l<=r:
            mid = (l+r)//2
            if nums[mid]>=target:
                r = mid-1
                ans = mid
            else:
                l = mid+1
        return ans
