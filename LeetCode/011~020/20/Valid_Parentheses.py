class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        reverse = { "(" : ")", "{" : "}", "[" : "]" }
        
        for x in s:
            if x in [ "(", "{", "["]:
                print(x)
                stack.append(x)
                
            elif x in [ ")", "}", "]"]:
                if len(stack) == 0:
                    return False
                
                if reverse[stack[-1]] == x:
                    stack.pop()
                else:
                    return False
        
        return len(stack) == 0
