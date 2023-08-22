def solution(number, k):

    s = 0
    max_val = max(number)
    while k>0:
        if number[s]==max_val:
            s += 1
            continue
        flag = 0
        for i in range(s, len(number)-1):
            if number[i]<number[i+1]:
                number = number[0:i]+number[i+1:]
                k -= 1
                flag = 1
                break 
        if flag == 0:
            if number[i]>number[i+1]:
                number = number[0:i+1]+number[i+2:]
                k -= 1
            else:
                break 
    if k >0:
        number = number[k:]
        
    return number