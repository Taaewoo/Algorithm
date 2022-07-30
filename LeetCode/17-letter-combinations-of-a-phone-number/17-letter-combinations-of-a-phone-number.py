class Solution:
    res = []
    
    digit_map = [[],[],['a','b','c'],['d','e','f'],
                    ['g','h','i'],['j','k','l'],['m','n','o'],
                    ['p','q','r','s'],['t','u','v'],['w','x','y','z']]
    res = []
    digits = ""
    
    def dfs(self, idx, cur):
        if(idx==len(self.digits)):
            self.res.append(cur)
            return
        
        phone_num = int(self.digits[idx])
        
        for n in self.digit_map[phone_num]:
            self.dfs(idx+1, cur+n)
    
    def letterCombinations(self, digits: str) -> List[str]:
        self.res = []
        self.digits = digits
        
        if len(digits) == 0:
            return self.res
        
        self.dfs(0, "")
        
        return self.res
        
        
        
            