class Solution:
    def climbStairs(self, n: int) -> int:
        minus2 = 1
        minus1 = 1

        for i in range(2,n+1):
            minus1, minus2 = minus1+minus2, minus1

        return minus1
