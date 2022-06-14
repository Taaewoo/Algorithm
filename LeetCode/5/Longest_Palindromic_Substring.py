class Solution:
    def longestPalindrome(self, s: str) -> str:
        start, end = 0, 0
        res = ""
        
        if len(s) <= 1 : return s
        
        for i in range(len(s)):
            res1 = self.check_palindromic(s, i, i)
            res2 = self.check_palindromic(s, i, i+1)
            
            if len(res) < len(res1):
                res = res1
            if len(res) < len(res2):
                res = res2
            
        return res
            
            
    def check_palindromic(self, s, l, r):
        idx = -1
        for i in range(len(s)):
            if l-i < 0 or r+i >= len(s): break
            if s[l-i] != s[r+i]: break
                
            idx = i
                    
        return s[l-idx:r+idx+1] if idx != -1 else ""
