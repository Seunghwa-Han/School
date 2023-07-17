def solution(record):
    answer = []
    dic = {}
    for line in record:
        if "Leave" in line:
            continue
        a, uid, name = line.split()
        dic[uid] = name
        
    for line in record:
        l = line.split()
        if l[0]=="Enter":
            answer.append(f'{dic[l[1]]}님이 들어왔습니다.')
        elif l[0]=="Leave":
            answer.append(f'{dic[l[1]]}님이 나갔습니다.')
            
    return answer