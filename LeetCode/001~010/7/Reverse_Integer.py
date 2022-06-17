class Solution:
    def reverse(self, x: int) -> int:
        strX = str(x)
        
        if strX[0] == "-":
            reversedStrX = int("-" + strX[:0:-1])
        else:
            reversedStrX = int(strX[::-1])
            
        if reversedStrX > pow(2,31)-1 or reversedStrX < -1 * pow(2,31):
            return 0
            
        return reversedStrX 
