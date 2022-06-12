class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        start, end = 0, 0
        res = 0
        dic = {}
        
        if len(s) == 0 : return 0
        
        while True:
            if s[end] not in dic:
                dic[s[end]] = 1
                end = end + 1
                res = max(res, end - start)
            else:
                del dic[s[start]]
                start = start +1
        
            if end == len(s):
                break
                
        return res
