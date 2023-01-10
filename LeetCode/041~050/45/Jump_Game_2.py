class Solution:
    def jump(self, nums: List[int]) -> int:
        dp = [len(nums)]*len(nums)

        dp[0] = 0
        curMax = 0
        for i in range(len(nums)):
            if i + nums[i] <= curMax:
                continue

            for j in range(1,nums[i]+1):
                if i+j >= len(nums) or i+j <= curMax:
                    continue

                dp[i+j] = min(dp[i]+1, dp[i+j])

        return dp[-1]
