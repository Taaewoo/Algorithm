class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        cur = 987654321;
        res = 987654321;
        
        for i in range(0,len(nums)-2):
            l,r = i+1, len(nums)-1
            
            while l < r:
                ts = nums[i] + nums[l] + nums[r]
                
                if abs(ts-target) < cur:
                    res = ts
                    cur = abs(ts-target)
                    
                if cur == 0:
                    break
                                      
                if ts > target:
                    r -= 1
                else:
                    l += 1  
                    
        return res
