class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        res = []

        def dfs(nums: List[int], tmp: List[int]) -> None:
            if len(tmp) > 1:
                res.append(tmp)
            curPres = defaultdict(int)
            for inx, i in enumerate(nums):
                if curPres[i]:
                    continue
                if not tmp or i >= tmp[-1]:
                    curPres[i] = 1
                    dfs(nums[inx+1:], tmp+[i])

        dfs(nums, [])
        return res

