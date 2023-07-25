def add_time(time, duration):
    t_hour, t_min = map(int, time.split(":"))
    min = t_min+int(duration)
    hour = t_hour+int(min/60)
    min = int(min%60)
    return f'{hour:02d}:{min:02d}'

def get_duration(end_time, start_time):
    h1, m1 = end_time.split(":")
    h2, m2 = start_time.split(":")
    min = int(m1)-int(m2)
    if min <0:
        h1 = int(h1)-1
        min = min+60
    hour = int(h1)-int(h2)
    return min+60*hour
    
def solution(plans):
    answer = []
    stack = []
    plans.sort(key=lambda x: x[1])
    
    end_time = "00:00"
    for name, time, duration in plans:
        if stack:
            if end_time <= time: 
                # 이전 일 완료 
                answer.append(stack.pop()[0])
                # 미뤄둔 일이 있으면 
                while stack:
                    top = stack[-1]
                    e = add_time(end_time, top[1])
                    if e <= time:
                        # 가능하면 끝내기 
                        answer.append(stack.pop()[0])
                        end_time = e
                    else:
                        # 되는 시간만 일부 하기 
                        stack[-1][1] -= get_duration(time, end_time)
                        break 
            else:
                # 이전 일 완료 못함 
                stack[-1][1] = get_duration(end_time, time)
        # 새로운 일 시작 
        end_time = add_time(time, duration)
        stack.append([name, duration])
        
    while stack:
        answer.append(stack[-1][0])
        stack.pop()
    return answer