class Solution:
    def romanToInt(self, s: str) -> int:
        res = 0
        ndic = {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}
        it = iter(enumerate(s))
        
        for idx, val in it:
            if idx != len(s)-1 and val == "I" and (s[idx+1] == "V" or s[idx+1] == "X"):
                res = res + ndic.get(s[idx+1]) - ndic.get(val)
                next(it)
            elif idx != len(s)-1 and val == "X" and (s[idx+1] == "L" or s[idx+1] == "C"):
                res = res + ndic.get(s[idx+1]) - ndic.get(val)
                next(it)
            elif idx != len(s)-1 and val == "C" and (s[idx+1] == "D" or s[idx+1] == "M"):
                res = res + ndic.get(s[idx+1]) - ndic.get(val)
                next(it)
            else:
                res = res + ndic.get(val)
                
            print(res)
           
        return res
