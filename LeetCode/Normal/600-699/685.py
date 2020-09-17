class UnionFind:
    def __init__(self, n):
        self.ancestor = list(range(n))
    
    # 将index1所在的集合加入到index2的集合中
    def union(self, index1: int, index2: int):
        self.ancestor[self.find(index1)] = self.find(index2)
    
    # 找到祖先
    def find(self, index: int) -> int:
        if self.ancestor[index] != index:
            self.ancestor[index] = self.find(self.ancestor[index])
        return self.ancestor[index]

class Solution:
    def findRedundantDirectedConnection(self, edges: List[List[int]]) -> List[int]:
        
        # 辅助数组parent以及并查集初始化
        nodesCount = len(edges)
        uf = UnionFind(nodesCount + 1)
        parent = list(range(nodesCount + 1))
        
        # 冲突/环标签
        conflict = -1
        cycle = -1
        
        # 开始遍历
        for i, (node1, node2) in enumerate(edges):
            if parent[node2] != node2:          # 产生冲突（有两个父节点）
                conflict = i
            else:
                parent[node2] = node1
                if uf.find(node1) == uf.find(node2):
                    cycle = i                   # 产生环（祖先相同）
                else:
                    uf.union(node1, node2)      # 合并

        # 获取有问题的边
        if conflict < 0:                                            # 没有冲突就是环的边
            return [edges[cycle][0], edges[cycle][1]]
        else:               
            conflictEdge = edges[conflict]
            if cycle >= 0:
                return [parent[conflictEdge[1]], conflictEdge[1]]   # 环的重要性比冲突大
            else:
                return [conflictEdge[0], conflictEdge[1]]           # 无环就是冲突边
