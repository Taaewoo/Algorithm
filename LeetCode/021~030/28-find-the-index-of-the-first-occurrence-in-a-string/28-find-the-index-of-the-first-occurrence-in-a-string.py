class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        lps = [0] * len(needle)
        
        j = 0
        for i in range(1,len(needle)):
            while not( j == 0 or needle[i] == needle[j] ):
                j = lps[j-1]
                
            if needle[i] == needle[j]:
                j += 1
                lps[i] = j
                
        j = 0
        for i in range(0,len(haystack)):
            while not( j == 0 or haystack[i] == needle[j] ):
                j = lps[j-1]
                
            if haystack[i] == needle[j]:
                if j == len(needle)-1:
                    return i - j
                j += 1
        return -1
                
            