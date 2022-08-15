def solution(id_list, report, k):
    answer = []
    rep_name_dic = {}
    rep_cnt_dic = {}
    black_list = []
    mail_dic = {}
    
    for l in id_list:
        rep_name_dic[l] = {}
        rep_cnt_dic[l] = 0
        mail_dic[l] = 0
    
    for rep in report:
        info = rep.split(" ")
        
        if info[0] in rep_name_dic[info[1]]:
            continue
            
        rep_name_dic[info[1]][info[0]] = True
        rep_cnt_dic[info[1]] += 1
        
        if rep_cnt_dic[info[1]] == k:
            black_list.append(info[1])
            
    for black in black_list:
        for key in rep_name_dic[black].keys():
            if key in mail_dic:
                mail_dic[key] += 1
            else:
                mail_dic[key] = 1
    
    for l in id_list:
        answer.append(mail_dic[l])
    
    return answer
