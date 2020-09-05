class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        nums = [i for i in range(1, n+1)]
        for i in range(k-1):
            self.permute(nums)
        return "".join([str(i) for i in nums])
    
    def permute(self, nums: list) -> None:
        run = False
        for i in range(len(nums)-1, 0, -1):
            if nums[i] > nums[i-1]:
                for k in range(len(nums)-1, 0, -1):
                    if nums[k]>nums[i-1]:
                        nums[k], nums[i-1] = nums[i-1], nums[k]
                        nums[i:] = nums[i:][::-1]
                        return

