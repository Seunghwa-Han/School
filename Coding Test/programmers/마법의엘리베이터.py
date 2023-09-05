def solution(storey):
    answer = 0
    
    i = 0
    while i < len(str(storey)):
        num = int(str(storey)[-(i+1)])
        if num > 5:
            answer += 10-num
            storey += 10**i*(10-num)
        elif num == 5 and i+1<(len(str(storey))):
            next = int(str(storey)[-(i+2)])
            if next>=5:
                answer += 10-num
                storey += 10**i*(10-num)
            else:
                answer += num
                storey -= 10**i*num
        else:
            answer += num
            storey -= 10**i*num
        i += 1
    return answer