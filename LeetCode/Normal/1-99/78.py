class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        lst = []
        lst.append([])

        length = len(nums)
        visit = [False for i in range(length)]

        def dfsAdd(index: int, tlen: int, temp: List[int], templen: int):
            if tlen == templen:
                lst.append(temp[:])
                return
            if index >= length or length - index < tlen - templen:
                return
            for i in range(index, length):
                if visit[i]:
                    continue
                visit[i] = True
                temp.append(nums[i])
                dfsAdd(i + 1, tlen, temp, templen + 1)
                visit[i] = False
                temp.pop()

        for i in range(1, length+1):
            tempLst = []
            dfsAdd(0, i, tempLst, 0)

        return lst