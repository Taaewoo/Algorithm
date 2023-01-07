iclass Solution:
    def lengthOfLastWord(self, s: str) -> int:

        print("   ".split(" "))
       
        sSplit = s.split(" ")
       
        for sub in reversed(sSplit):    
            print(sub) 
            if sub == "":
                continue
            return len(sub)
