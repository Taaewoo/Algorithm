class Solution:
    def binary_search(self, nums, target, left, right):
        if left > right:
            return [-1,-1]

        mid = (left + right) // 2

        if nums[mid] == target:
            start = mid
            end = mid
            for i in range(1,(right-left)//2+2):
                start_check = start
                end_check = end
                
                if mid-i >= left and nums[mid-i] == nums[mid]:
                    start = mid - i
                if mid+i <= right and nums[mid+i] == nums[mid]:
                    end = mid + i

                if start_check == start and end_check == end:
                    return [start,end]
                
            return [start,end]

        if target > nums[mid]:
            return self.binary_search(nums,target,mid+1,right)
        else:
            return self.binary_search(nums,target,left,mid-1)
        

    def searchRange(self, nums: List[int], target: int) -> List[int]:

        return self.binary_search(nums,target,0,len(nums)-1)
