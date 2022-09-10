import heapq

class node:
    def __init__(self, alp, cop, cost):
        self.alp = alp
        self.cop = cop
        self.cost = cost

    def __lt__(self, other):
        if self.cost < other.cost:   #오름차순
            return True
        return False
    
    def __str__(self):
        return '{}, {}, {} '.format(self.alp, self.cop, self.cost)

def solution(alp, cop, problems):
    answer = 150
    cost = [[150] * 250 for _ in range(250)]
    visit = [[False] * 250 for _ in range(250)]
    max_alp = 0
    max_cop = 0

    pq = []
    
    for p in problems:
        max_alp = max(max_alp, p[0])
        max_cop = max(max_cop, p[1])
    problems.append([0,0,1,0,1])
    problems.append([0,0,0,1,1])
        
    heapq.heappush(pq, node(alp,cop,0))
    
    while pq:
        cur = heapq.heappop(pq)
        cur.alp = min(cur.alp, max_alp)
        cur.cop = min(cur.cop, max_cop)
        
        if visit[cur.alp][cur.cop]: continue
        if cur.alp >= max_alp and cur.cop >= max_cop:
            
            return cur.cost
        
        visit[cur.alp][cur.cop] = True
        
        
        for p in problems:
            if cur.alp < p[0] or cur.cop < p[1]: continue
            if p[2] == 0 and p[3] == 0: continue
                
            next_alp = cur.alp + p[2]
            next_cop = cur.cop + p[3]
            
            if cur.alp > max_alp and p[3] == 0: continue
            if cur.cop > max_cop and p[2] == 0: continue
            if cost[next_alp][next_cop] <= cur.cost + p[4]: continue
            
            cost[next_alp][next_cop] = cur.cost + p[4]
            heapq.heappush(pq, node(next_alp,next_cop,cur.cost + p[4]))
            
    return answer 

