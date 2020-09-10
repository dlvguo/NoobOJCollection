class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        self.res = []
        
        def dfs(num, sumn, tmp):
            if len(tmp)>k or sumn > n: # 当数组长度大于k或和大于n 已不符合要求 直接返回
                return
            if len(tmp)==k and sumn == n: # 满足要求加入res中
                self.res.append(tmp[:])   # 这里是tmp[:], 如写tmp 返回的都是空列表 我不知道原理是什么 有看到的大神能留言告诉我吗？
                return
            for i in range(num+1, 10):
                if sumn + i > n: # 简单的剪枝 sumn+i大于n 后面的数都大于i 加上sumn肯定都大于n了 不用找了 直接跳出
                    break
                dfs(i, sumn+i, tmp+[i])

        dfs(0, 0, [])
        return self.res 

