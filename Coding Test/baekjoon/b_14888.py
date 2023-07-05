N = int(input())  # 2 ≤ N ≤ 11
A = list(map(int, input().split()))   # 1 ≤ Ai ≤ 100
op = list(map(int, input().split()))  # 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수

expr = []
expr.append(A[0])
min_value = 1000000000
max_value = -1000000000

def backtracking(d):
    if d == N-1:

        return 
    for i in range(4):
        if op[i] > 0:
