class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:

        res = []

        ##明显回溯法
        ##因为只能使用一次，所以先排序，然后每次匹配的到数据时，看是否在res中，不在才append

        def backtrace(nums,curr_res,index):
            ##结束条件
            if  sum(curr_res)==target and curr_res not in res:
                res.append(curr_res[:])  ##注意这里的浅拷贝，否则res中的值位空
                return 
            
            if sum(curr_res)>target: ##如果大于target,后面的数就不用再执行了，返回去重新下一次
                return

            for i in range(index,len(candidates)):
                curr_res.append(candidates[i])
                backtrace(nums[i:],curr_res,i+1)
                curr_res.pop()

        candidates.sort()
        backtrace(candidates,[],0)
        return res  
            
