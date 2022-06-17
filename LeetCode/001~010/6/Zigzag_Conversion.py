class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1: return s
        
        str_list = [""]*numRows
                
        for idx, val in enumerate(s):
            res_idx = idx % (numRows*2 - 2) 
            
            if res_idx < (numRows*2 - 2) and res_idx >= numRows:
                str_list[(numRows*2 - 2) - res_idx] += val
            else:
                str_list[res_idx] += val
            
        return "".join(str_list)
