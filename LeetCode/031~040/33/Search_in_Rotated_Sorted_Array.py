class Solution:
    def binary_search(self, nums, target, left, right):
        if left > right:
            return -1
        
        mid = int( (left+right) / 2)

        if nums[mid] == target:
            return mid

        # pivot right
        if nums[mid] > nums[right]:
            if target < nums[mid] and target >= nums[left]:
                return self.binary_search(nums,target,left,mid-1)
            else:
                return self.binary_search(nums,target,mid+1,right)
        #pivot left
        else:
            if target > nums[mid] and target <= nums[right]:
                return self.binary_search(nums,target,mid+1,right)
            else:
                return self.binary_search(nums,target,left,mid-1)

    def search(self, nums: List[int], target: int) -> int:

        return self.binary_search(nums,target,0,len(nums)-1)
