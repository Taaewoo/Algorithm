class Solution:
    def isPalindrome(self, x: int) -> bool:
        xToString = str(x)
        for idx, val in enumerate(xToString):
            if(xToString[len(xToString)-idx-1] != val):
                return False
        return True
