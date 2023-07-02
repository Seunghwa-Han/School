def solution(sequence, k):
    answer = []
    i, j = 0, 0
    sum = 0
    min = 1000001
    length = len(sequence)
    
    while True:
        if i >= length or j>=length:
            break
        
        sum += sequence[j]
        if sum >= k:
            if sum == k and min > j-i:
                answer = [i, j]
                min = j-i
            sum -= sequence[i]+sequence[j]
            i = i+1
        elif sum < k:
            j += 1
        
    return answer