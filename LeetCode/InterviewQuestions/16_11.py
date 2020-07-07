from typing import List


class Solution:
    def divingBoard(self, shorter: int, longer: int, k: int) -> List[int]:
        l = []
        if k == 0:
            return l
        elif shorter == longer:
            l.append(longer * k)
        else:
            for i in range(k + 1):
                l.append(longer * i + (k - i) * shorter)
        return l
