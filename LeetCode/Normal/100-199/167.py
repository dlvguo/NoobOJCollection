class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        index1, index2 = 0, len(numbers) - 1
        while index1 < index2:
            num = numbers[index1] + numbers[index2]
            if num == target:
                break
            elif num < target:
                index1 += 1
            else:
                index2 -= 1

        return [index1+1, index2+1]
