import copy

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        tmpMatrix = copy.deepcopy(matrix)

        for i in range(len(tmpMatrix)):
            for j in range(len(tmpMatrix)):
                matrix[i][j] = tmpMatrix[len(tmpMatrix)-j-1][i]
