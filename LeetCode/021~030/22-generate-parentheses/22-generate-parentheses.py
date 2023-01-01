class Solution:
    
    n = 0
    stack = []
    cur = ""
    res = []
    
    def dfs(self, idx, cnt):
        if idx == self.n*2:
            self.res.append(self.cur)
            return
        
        if cnt < self.n:
            self.cur += "("
            self.dfs(idx+1, cnt+1)
            self.cur = self.cur[:-1]
            
        if cnt > 0 and len(self.cur) < cnt*2:
            self.cur += ")"
            self.dfs(idx+1, cnt)
            self.cur = self.cur[:-1]
    
    def generateParenthesis(self, n: int) -> List[str]:
        self.n = n
        self.stack = []
        self.cur = ""
        self.res = []
        
        self.dfs(0,0)
        
        return self.res
                