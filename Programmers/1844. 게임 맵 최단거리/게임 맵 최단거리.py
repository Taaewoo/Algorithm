from collections import deque

dirs = [[0,1],[1,0],[0,-1],[-1,0]]
visit = [[False]*100] * 100

def solution(maps):
    q = deque()
    q.append([[0,0],1])
    while q:
        cur, num = q.popleft()
            
        for d in dirs:
            nx, ny = cur[0]+d[0], cur[1]+d[1]
            
            
            if nx < 0 or nx >= len(maps) or ny < 0 or ny >= len(maps[0]) or maps[nx][ny]==0:
                continue
            
            if maps[nx][ny] == 1 or maps[nx][ny] > num + 1:
                print(nx,ny)
                maps[nx][ny] = num + 1
                q.append([[nx,ny], num+1])
            
    
    return maps[-1][-1] if maps[-1][-1]!=1 else -1