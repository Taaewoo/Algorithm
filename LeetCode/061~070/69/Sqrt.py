import sys

class Solution:
    diff = sys.maxsize
    ans = 0

    def binarySearch(self, x, left, right):
        if left > right:
            return

        mid = int((left+right)/2)

        if mid*mid > x:
            self.binarySearch(x, left, mid-1)
        elif mid*mid < x:
            if x - mid*mid < self.diff:
                self.diff = x - mid*mid
                self.ans = mid
            self.binarySearch(x, mid+1, right)
        else:
            self.ans = mid
            return

    def mySqrt(self, x: int) -> int:
        self.binarySearch(x,0,x)

        return self.ans
