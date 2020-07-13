class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()
        nums3 = []
        n1len = 0
        n2len = 0
        while n1len < len(nums1) and n2len < len(nums2):
            if nums1[n1len] == nums2[n2len]:
                nums3.append(nums1[n1len])
                n2len += 1
                n1len += 1
            elif nums1[n1len] > nums2[n2len]:
                n2len += 1
            else:
                n1len += 1
        return nums3