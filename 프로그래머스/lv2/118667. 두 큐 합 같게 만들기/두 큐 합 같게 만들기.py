from collections import deque

def solution(queue1, queue2):
    answer = 0
    
    l = len(queue1)
    sum_q1, sum_q2 = sum(queue1), sum(queue2)
    total = sum_q1 + sum_q2
    
    queue1, queue2 = deque(queue1), deque(queue2)
    
    while answer < l*4:
        if sum_q1 > sum_q2:
            sum_q1 -= queue1[0]
            sum_q2 += queue1[0]
            queue2.append(queue1.popleft())
        elif sum_q1 < sum_q2:
            sum_q2 -= queue2[0]
            sum_q1 += queue2[0]
            queue1.append(queue2.popleft())
        else:
            return answer
        answer += 1
    
    return -1
