class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        left=0
        mincount=float('inf')
        cursum=0
        
        for right in range(len(nums)):
            cursum+=nums[right]
            
            while cursum>=s:
                mincount=min(mincount,right-left+1)
                cursum=cursum-nums[left]
                left+=1
        
        return mincount if mincount!=float('inf') else 0

