class Solution:
    def longestValidParentheses(self, s: str) -> int:
        if len(s) == 0:
            return 0

        stack = []
        longest = [0] * len(s)
        ans = 0

        for idx, c in enumerate(s):
            if c == ')':
                if len(stack) == 0:
                    continue
                # 매칭이 된 문자열 index 바로 앞의 longest와 
                # 서로 매칭이 된 문자열의 길이를 더해서 업데이트
                longest[idx] = longest[stack[-1]-1] + ( idx - stack.pop() + 1 )
                
                ans = max(ans,longest[idx]) 
                
            else:
                # stack에 넣으면 longest는 0
                stack.append(idx)

        return ans
