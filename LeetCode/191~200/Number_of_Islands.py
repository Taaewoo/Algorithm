from collections import deque

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        dirP = [[-1,0], [0,1], [1,0], [0,-1]]

        q = deque([])
        ans = 0
        
        for i in range(0,len(grid)):
            for j in range(0,len(grid[0])):
                if grid[i][j] == "0":
                    continue

                ans += 1

                q.append([i,j])
                grid[i][j] = "0"

                while len(q) != 0:
                    curP = q.popleft()
                    print(curP)

                    for d in dirP:
                        nextP = [curP[0] + d[0], curP[1] + d[1]]

                        if nextP[0] < 0 or nextP[0] >= len(grid) or nextP[1] < 0 or nextP[1] >= len(grid[0]):
                            continue

                        if grid[nextP[0]][nextP[1]] == "0":
                            continue
                        
                        q.append([nextP[0], nextP[1]])
                        grid[nextP[0]][nextP[1]] = "0"

        return ans
