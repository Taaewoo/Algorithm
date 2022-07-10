class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        for i in range(0,len(nums)-2):
            if i>0 and nums[i]==nums[i-1]:
                continue
            l,r = i+1, len(nums)-1
            
            while l < r:
                sum_val = nums[i] + nums[l] + nums[r]
                if sum_val < 0:
                    l = self.next_index(nums,l,r,'l')
                elif sum_val > 0:
                    r = self.next_index(nums,l,r,'r')
                else:
                    res.append([nums[i],nums[l],nums[r]])
                    l = self.next_index(nums,l,r,'l')
                    r = self.next_index(nums,l,r,'r')
        return res    
                    
    def next_index(self, nums, l, r, d):
        if d == 'l':
            while l < r and nums[l] == nums[l+1]:
                l += 1
            return l+1
        elif d == 'r':
            while l < r and nums[r] == nums[r-1]:
                r -= 1
            return r-1
