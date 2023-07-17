N = int(input())  # 2 ≤ N ≤ 11
A = list(map(int, input().split()))   # 1 ≤ Ai ≤ 100
op = list(map(int, input().split()))  # 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수

min_value = 1000000000
max_value = -1000000000

dic = {0:'+', 1:'-', 2:'*', 3:'//'}
def backtracking(sum, d, op):
    global max_value, min_value

    if d == N-1:
        max_value = max(max_value, sum)
        min_value = min(min_value, sum)
        return
    
    for i in range(4):
        if op[i] >0:
            op[i]-=1
            if sum < 0 and dic[i]=='//':
                backtracking(-eval(f'{-sum}{dic[i]}{A[d+1]}'), d+1, op)
            else:
                backtracking(eval(f'{sum}{dic[i]}{A[d+1]}'), d+1, op)
            op[i]+=1

backtracking(A[0], 0, op)
print(max_value)
print(min_value)
