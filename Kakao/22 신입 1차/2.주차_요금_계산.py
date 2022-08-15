def solution(fees, records):
    answer = []
    car_dic = {}
    car_list = []
    time_table = [60,1]
    
    for r in records:
        info = r.split(" ")
        if not info[1] in car_dic:
            car_dic[info[1]] = []
            car_list.append(info[1])
            
        car_dic[info[1]].append(info[0])
        
    for k,v in car_dic.items():
        if len(car_dic[k])%2 == 1:
            car_dic[k].append("23:59")
    
    car_list.sort()
    
    for car in car_list:
        print("car : ", car)
        times = car_dic[car]
        time_sum = 0
        for i in range(0,len(times),2):
            time_m = sum([a*b for a,b in zip(time_table,map(int,times[i+1].split(":")))]) \
                    - sum([a*b for a,b in zip(time_table,map(int,times[i].split(":")))])
            time_sum += time_m
        
        time_tmp = time_sum-fees[0]
        if time_tmp < 0:
            time_tmp = 0
        
        if time_tmp % fees[2] == 0:
            time_tmp = int(time_tmp/fees[2])
        else:
            time_tmp = int(time_tmp/fees[2]) + 1
        
        fee_res = fees[1] + time_tmp*fees[3]
        
        answer.append(fee_res)
    
    return answer
