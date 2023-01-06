class Solution:
    def solve(self, n):
        if n == 1:
            return "1"
        
        subStr = self.solve(n-1)

        print(subStr, len(subStr))

        if len(subStr) == 1:
            return "11"

        retStr = ""
        prior = subStr[0]
        acc = 1
        for idx, c in enumerate(subStr):
            if idx == 0:
                continue

            if c == prior:
                acc += 1
            else:
                retStr += (str(acc) + prior)
                acc = 1
                prior = c

        retStr += (str(acc) + subStr[-1])

        return retStr


    def countAndSay(self, n: int) -> str:

        return self.solve(n)
