ans = 0 
numbers = []
def solution(n, target):
    global ans, numbers
    numbers = n
    bt(0, 0, target)
    return ans

def bt(idx, sum_val, t):
    global ans
    if idx == len(numbers):
        if sum_val == t:
            ans += 1
        sum_val = 0
        return 
    
    bt(idx+1, sum_val+numbers[idx], t)
    bt(idx+1, sum_val-numbers[idx], t)

'''
backtracking 문제 
'''