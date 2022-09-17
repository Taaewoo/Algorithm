class Solution:
    
    def bs(self, n, l, r):
        if l == r:
            return False
    
        m = int((l+r)/2)
    
        if n / (2 ** m) < 1:
            return self.bs(n,l,m)
        elif n / (2 ** m) > 1:
            return self.bs(n,m+1,r)
        else:
            return True
    
    def isPowerOfTwo(self, n: int) -> bool:
    
        
        return self.bs(n,0,31)