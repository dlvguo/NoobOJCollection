class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        numLst = []
        length = len(nums)
        visit = [0 for i in range(len(nums))]
        # 进行复制
        tempList = visit[:]

        def dfsSearch(index: int):
            if index == length:
                numLst.append(tempList[:])
            for i in range(length):
                # 去重
                if visit[i] == 1:
                    continue
                # 目的使重复的数字从左到右
                elif i > 0 and nums[i] == nums[i - 1] and visit[i - 1] == 0:
                    continue
                visit[i] = 1
                tempList[index] = nums[i]
                dfsSearch(index + 1)
                visit[i] = 0
        # 注意需要排序 否则不会进行正确的内容从左到右去重
        nums.sort()
        dfsSearch(0)
        return numLst