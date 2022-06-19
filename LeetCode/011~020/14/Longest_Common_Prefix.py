class Solution:
    inputStrs = []
    minLen = 0
    
    def longestCommonPrefix(self, strs: List[str]) -> str:
        self.inputStrs = strs
        self.minLen = min([len(x) for x in strs])
        
        return self.devideAndConquer(0,len(strs)-1)
        
    def findLongestPrefix(self, str1, str2) -> str:
        for idx in range(0,self.minLen):
            if str1[idx] != str2[idx]:
                self.minLen = idx
                return str1[:idx]
            
        return str1[:self.minLen]
            
    def devideAndConquer(self, si: int, ei: int) -> str:
        if si == ei:
            return self.inputStrs[si]
        
        mid = int((si+ei)/2)
        res1 = self.devideAndConquer(si,mid)
        res2 = self.devideAndConquer(mid+1,ei)
        
        return self.findLongestPrefix(res1, res2)
