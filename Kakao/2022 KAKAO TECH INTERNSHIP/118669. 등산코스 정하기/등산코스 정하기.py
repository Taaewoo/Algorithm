from collections import deque, defaultdict

def solution(n, paths, gates, summits):
    answer = [-1,10000001]
    con = defaultdict(list)
    summits_dic = {}
    intensity = [10000001 for _ in range(n+1)]
    
    for i,j,w in paths:
        con[i].append([j,w])
        con[j].append([i,w])
        
    q = deque()
    for g in gates:
        q.append([g,0])
        intensity[g]=0
        
    for s in summits:
        summits_dic[s] = 1
    
    while q:
        idx, cur_intensity = q.popleft()
        
        if idx in summits_dic:
            continue
        
        for j,w in con[idx]:
            new_intensity = max(cur_intensity, w)
            if new_intensity < intensity[j]:
                q.append([j,new_intensity])
                intensity[j] = new_intensity
            
    
    summits.sort()
    for s in summits:
        if intensity[s] < answer[1]:
            answer[0] = s
            answer[1] = intensity[s]
    
    return answer