class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        one_dict = {}

        for n in nums:
            if n in one_dict:
                one_dict.pop(n)
            else:
                one_dict[n] = 1

        for k,v in one_dict.items():
            return k
