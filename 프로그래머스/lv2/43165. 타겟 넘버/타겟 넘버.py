from collections import deque

def solution(numbers, target):
    answer = 0
    
    q = deque()
    q.append([numbers[0],0])
    q.append([-numbers[0],0])
    
    while q:
        cur, idx = q.popleft()
        
        if idx+1 == len(numbers):
            if cur == target:
                answer += 1
            continue
                
        q.append([cur + numbers[idx+1], idx+1])
        q.append([cur - numbers[idx+1], idx+1])
    
    return answer