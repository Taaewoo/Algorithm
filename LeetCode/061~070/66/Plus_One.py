class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:

        num = 0
        for idx, d in enumerate(reversed(digits)):
            num += 10 ** idx * d

        num += 1

        retList = []
        for d in str(num):
            retList.append(int(d))

        return retList
