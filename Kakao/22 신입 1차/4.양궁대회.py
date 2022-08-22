cur_ans = [-1]
max_score = 0

def check_bigger(arrow1, arrow2):
    for i in range(len(arrow1)-1,0,-1):
        if arrow1[i] == arrow2[i]:
            continue
        
        return False if arrow1[i] > arrow2[i] else True

def dfs(n,info,idx,arrow,score,a_score):
    global cur_ans, max_score
    
    if idx == 11:
        if score <= a_score:
            return
        
        if n > 0:
            arrow[-1] += n
        
        diff_score = score - a_score
        
        if max_score < diff_score or (max_score == diff_score and check_bigger(cur_ans,arrow)):
            cur_ans = arrow
            max_score = diff_score
        
        return
    
    if info[idx] < n:
        cur = info[idx]+1
        dfs(n - cur, info, idx+1, arrow+[cur], score+(10-idx), a_score)
    
    if info[idx] == 0:
        dfs(n,info,idx+1,arrow+[0],score, a_score)
    else:
        dfs(n,info,idx+1,arrow+[0],score, a_score+(10-idx))
        
    return 0

def solution(n, info):
    global cur_ans
    
    dfs(n,info,0,[],0,0)
    
    return cur_ans
