class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        
        p1, p2 = 0, 0
        resList = []
        
        while(p1 < len(nums1) and p2 < len(nums2)):
            if nums1[p1] < nums2[p2]:
                resList.append( nums1[p1] )
                p1 += 1
            else:
                resList.append( nums2[p2] )
                p2 += 1
        
        
        if p1 == len(nums1):
            for x in nums2[p2:]:
                resList.append(x)
                        
        if p2 == len(nums2):
            for x in nums1[p1:]:
                resList.append(x)
        
        totalLen = len(nums1) + len(nums2)
        median = int(totalLen/2)
        
        res = resList[median] if totalLen%2 == 1 else (resList[median-1] + resList[median])/2
        
        return res
