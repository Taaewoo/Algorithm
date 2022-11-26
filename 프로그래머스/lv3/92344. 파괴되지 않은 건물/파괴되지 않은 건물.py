def solution(board, skill):
    answer = 0
    acc = [[0]*(len(board[0])+1) for _ in range(len(board)+1)]
     
    for t,r1,c1,r2,c2,d in skill:
        t = t if t==1 else -1
        
        acc[r1][c1] += -t * d
        acc[r1][c2+1] += t * d
        acc[r2+1][c1] += t * d
        acc[r2+1][c2+1] += -t * d
        
    
        
    for i in range(len(acc)):
        temp = 0
        for j in range(len(acc[0])):
            temp += acc[i][j]
            acc[i][j] = temp
            
    for j in range(len(acc[0])):
        temp = 0
        for i in range(len(acc)):
            temp += acc[i][j]
            acc[i][j] = temp
    
    for i in range(len(board)):
        for j in range(len(board[0])):
            board[i][j] += acc[i][j]
            if(board[i][j] > 0): answer += 1
    
    
    return answer